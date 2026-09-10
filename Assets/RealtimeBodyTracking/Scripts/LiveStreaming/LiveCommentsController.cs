using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Net.WebSockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Owns comment subscriptions. The panel calls StartReceiving only when it
    /// is visible, so closing the panel releases network activity immediately.
    public sealed class LiveCommentsController : MonoBehaviour
    {
        private Coroutine receiveRoutine;
        private Transform output;
        private LiveStreamProvider provider;
        private LiveStreamAccount account;
        private string nextPageToken;
        private int shown;
        private ClientWebSocket twitchSocket;
        private readonly ConcurrentQueue<string> pending = new ConcurrentQueue<string>();

        public bool IsReceiving { get; private set; }

        public void StartReceiving(LiveStreamProvider selectedProvider, Transform outputRoot)
        {
            StopReceiving();
            provider = selectedProvider; output = outputRoot;
            account = new LiveStreamAccountStore().Load().Find(x => x.provider == provider);
            IsReceiving = account != null && !string.IsNullOrEmpty(account.accessToken);
            receiveRoutine = StartCoroutine(ReceiveLoop());
        }

        public void StopReceiving()
        {
            if (receiveRoutine != null) StopCoroutine(receiveRoutine);
            if (twitchSocket != null) { try { twitchSocket.Abort(); twitchSocket.Dispose(); } catch { } twitchSocket = null; }
            receiveRoutine = null;
            output = null;
            IsReceiving = false;
        }

        private IEnumerator ReceiveLoop()
        {
            while (IsReceiving)
            {
                if (provider == LiveStreamProvider.YouTube && account != null && !string.IsNullOrEmpty(account.liveChatId)) yield return FetchYouTube();
                else if (provider == LiveStreamProvider.Twitch) { StartTwitchSocket(); while (IsReceiving && twitchSocket != null) { while (pending.TryDequeue(out var message)) AddLine(message); yield return null; } }
                else { AddLine(provider + "のコメント接続情報がありません。"); IsReceiving = false; }
                yield return new WaitForSeconds(3f);
            }
        }

        private async void StartTwitchSocket()
        {
            twitchSocket = new ClientWebSocket();
            try { await twitchSocket.ConnectAsync(new Uri("wss://irc-ws.chat.twitch.tv:443"), CancellationToken.None); await SendTwitch("PASS oauth:" + account.accessToken); await SendTwitch("NICK sandareyou"); await SendTwitch("JOIN #" + (string.IsNullOrEmpty(account.channelName) ? "sandareyou" : account.channelName)); _ = ReadTwitch(); }
            catch { pending.Enqueue("Twitchコメント接続に失敗しました。"); twitchSocket = null; }
        }
        private async Task SendTwitch(string value) { var bytes = Encoding.UTF8.GetBytes(value + "\r\n"); await twitchSocket.SendAsync(new ArraySegment<byte>(bytes), WebSocketMessageType.Text, true, CancellationToken.None); }
        private async Task ReadTwitch()
        {
            var buffer = new byte[8192];
            while (IsReceiving && twitchSocket != null && twitchSocket.State == WebSocketState.Open) { var result = await twitchSocket.ReceiveAsync(new ArraySegment<byte>(buffer), CancellationToken.None); if (result.MessageType == WebSocketMessageType.Close) break; var text = Encoding.UTF8.GetString(buffer, 0, result.Count); if (text.StartsWith("PING")) await SendTwitch("PONG :tmi.twitch.tv"); else if (text.Contains("PRIVMSG")) pending.Enqueue(ParseTwitchMessage(text)); }
        }
        private static string ParseTwitchMessage(string value) { var bang = value.IndexOf('!'); var colon = value.IndexOf(" :", StringComparison.Ordinal); var name = bang > 1 ? value.Substring(1, bang - 1) : "Twitch"; return name + ": " + (colon >= 0 ? value.Substring(colon + 2).Trim() : value); }

        private IEnumerator FetchYouTube()
        {
            var url = "https://www.googleapis.com/youtube/v3/liveChat/messages?part=snippet,authorDetails&maxResults=200&liveChatId=" + Uri.EscapeDataString(account.liveChatId);
            if (!string.IsNullOrEmpty(nextPageToken)) url += "&pageToken=" + Uri.EscapeDataString(nextPageToken);
            using (var request = UnityWebRequest.Get(url)) { request.SetRequestHeader("Authorization", "Bearer " + account.accessToken); yield return request.SendWebRequest(); if (request.result != UnityWebRequest.Result.Success) { AddLine("YouTubeコメント取得エラー: " + request.responseCode); yield break; } var response = JsonUtility.FromJson<YouTubeChatResponse>(request.downloadHandler.text); nextPageToken = response.nextPageToken; if (response.items == null) yield break; foreach (var item in response.items) AddLine(item.authorDetails.displayName + ": " + item.snippet.displayMessage); }
        }

        private void AddLine(string value) { if (output == null) return; if (shown >= 30 && output.childCount > 2) Destroy(output.GetChild(2).gameObject); else shown++; var text = new GameObject("Comment").AddComponent<Text>(); text.transform.SetParent(output, false); text.text = value; text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf"); text.fontSize = 16; text.color = Color.white; }

        [Serializable] private sealed class YouTubeChatResponse { public string nextPageToken; public YouTubeChatItem[] items; }
        [Serializable] private sealed class YouTubeChatItem { public YouTubeChatSnippet snippet; public YouTubeAuthor authorDetails; }
        [Serializable] private sealed class YouTubeChatSnippet { public string displayMessage; }
        [Serializable] private sealed class YouTubeAuthor { public string displayName; }

        private void OnDisable() => StopReceiving();
        private void OnDestroy() => StopReceiving();
    }
}

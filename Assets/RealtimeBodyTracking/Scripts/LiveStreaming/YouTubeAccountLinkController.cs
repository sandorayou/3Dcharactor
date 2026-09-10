using System;
using System.Collections;
using System.Security.Cryptography;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Google iOS OAuth using Authorization Code + PKCE. No client secret is
    /// embedded because this is a public native client.
    public sealed class YouTubeAccountLinkController : MonoBehaviour
    {
        private const string ClientId = "619136214643-6hsflt2isot3prrices9tu5nn5nvq355.apps.googleusercontent.com";
        private const string Scope = "https://www.googleapis.com/auth/youtube.force-ssl";
        private string verifier;
        private string redirectUri => "com.googleusercontent.apps.619136214643-6hsflt2isot3prrices9tu5nn5nvq355:/oauthredirect";

        private void OnEnable() => Application.deepLinkActivated += OnDeepLink;
        private void OnDisable() => Application.deepLinkActivated -= OnDeepLink;

        public void LinkYouTube()
        {
            verifier = Base64Url(RandomBytes(32));
            byte[] digest;
            using (var sha = SHA256.Create()) digest = sha.ComputeHash(Encoding.ASCII.GetBytes(verifier));
            var challenge = Base64Url(digest);
            var url = "https://accounts.google.com/o/oauth2/v2/auth?client_id=" + Uri.EscapeDataString(ClientId)
                + "&redirect_uri=" + Uri.EscapeDataString(redirectUri)
                + "&response_type=code&scope=" + Uri.EscapeDataString(Scope)
                + "&access_type=offline&prompt=consent&code_challenge_method=S256&code_challenge=" + challenge;
            Application.OpenURL(url);
        }

        private void OnDeepLink(string url)
        {
            if (!url.StartsWith("com.googleusercontent.apps.", StringComparison.OrdinalIgnoreCase)) return;
            var code = Query(url, "code");
            if (!string.IsNullOrEmpty(code) && !string.IsNullOrEmpty(verifier)) StartCoroutine(ExchangeAndCreate(code));
        }

        private IEnumerator ExchangeAndCreate(string code)
        {
            var body = "code=" + Uri.EscapeDataString(code) + "&client_id=" + Uri.EscapeDataString(ClientId)
                + "&redirect_uri=" + Uri.EscapeDataString(redirectUri)
                + "&grant_type=authorization_code&code_verifier=" + Uri.EscapeDataString(verifier);
            using (var request = UnityWebRequest.Post("https://oauth2.googleapis.com/token", body))
            {
                request.SetRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                var token = JsonUtility.FromJson<TokenResponse>(request.downloadHandler.text);
                if (string.IsNullOrEmpty(token.access_token)) yield break;
                yield return CreateYouTubeBroadcast(token.access_token);
            }
        }

        private IEnumerator CreateYouTubeBroadcast(string token)
        {
            var broadcastJson = "{\"snippet\":{\"title\":\"MyProject5 Live\",\"scheduledStartTime\":\""
                + DateTime.UtcNow.ToString("o") + "\"},\"status\":{\"privacyStatus\":\"public\"}}";
            using (var request = UnityWebRequest.Post("https://www.googleapis.com/youtube/v3/liveBroadcasts?part=snippet,status", broadcastJson))
            {
                SetJsonHeaders(request, token); yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                var broadcast = JsonUtility.FromJson<BroadcastResponse>(request.downloadHandler.text);
                yield return CreateYouTubeStream(token, broadcast.id);
            }
        }

        private IEnumerator CreateYouTubeStream(string token, string broadcastId)
        {
            const string json = "{\"snippet\":{\"title\":\"MyProject5 Stream\"},\"cdn\":{\"format\":\"720p\",\"ingestionType\":\"rtmp\"}}";
            using (var request = UnityWebRequest.Post("https://www.googleapis.com/youtube/v3/liveStreams?part=snippet,cdn", json))
            {
                SetJsonHeaders(request, token); yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                var stream = JsonUtility.FromJson<StreamResponse>(request.downloadHandler.text);
                yield return BindBroadcast(token, broadcastId, stream.id);
            }
        }

        private IEnumerator BindBroadcast(string token, string broadcastId, string streamId)
        {
            using (var request = UnityWebRequest.Post("https://www.googleapis.com/youtube/v3/liveBroadcasts/bind?id=" + Uri.EscapeDataString(broadcastId) + "&part=id,snippet,contentDetails,status&streamId=" + Uri.EscapeDataString(streamId), ""))
            {
                request.SetRequestHeader("Authorization", "Bearer " + token); yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                using (var get = UnityWebRequest.Get("https://www.googleapis.com/youtube/v3/liveStreams?part=cdn&id=" + Uri.EscapeDataString(streamId)))
                {
                    get.SetRequestHeader("Authorization", "Bearer " + token); yield return get.SendWebRequest();
                    if (get.result != UnityWebRequest.Result.Success) yield break;
                    var result = JsonUtility.FromJson<StreamListResponse>(get.downloadHandler.text);
                    if (result.items == null || result.items.Length == 0) yield break;
                    var info = result.items[0].cdn.ingestionInfo;
                    var accounts = new LiveStreamAccountStore().Load(); accounts.RemoveAll(x => x.provider == LiveStreamProvider.YouTube);
                    accounts.Add(new LiveStreamAccount { provider = LiveStreamProvider.YouTube, displayName = "YouTube", ingestUrl = info.ingestionAddress, streamKey = info.streamName });
                    new LiveStreamAccountStore().Save(accounts);
                }
            }
        }

        private static void SetJsonHeaders(UnityWebRequest request, string token) { request.SetRequestHeader("Content-Type", "application/json"); request.SetRequestHeader("Authorization", "Bearer " + token); }
        private static string Query(string url, string name) { var uri = new Uri(url); foreach (var pair in uri.Query.TrimStart('?').Split('&')) { var p = pair.Split('='); if (p.Length == 2 && p[0] == name) return Uri.UnescapeDataString(p[1]); } return null; }
        private static byte[] RandomBytes(int count) { var bytes = new byte[count]; using (var rng = RandomNumberGenerator.Create()) rng.GetBytes(bytes); return bytes; }
        private static string Base64Url(byte[] bytes) => Convert.ToBase64String(bytes).TrimEnd('=').Replace('+', '-').Replace('/', '_');
        [Serializable] private sealed class TokenResponse { public string access_token; }
        [Serializable] private sealed class BroadcastResponse { public string id; }
        [Serializable] private sealed class StreamResponse { public string id; }
        [Serializable] private sealed class StreamListResponse { public StreamItem[] items; }
        [Serializable] private sealed class StreamItem { public Cdn cdn; }
        [Serializable] private sealed class Cdn { public IngestionInfo ingestionInfo; }
        [Serializable] private sealed class IngestionInfo { public string ingestionAddress; public string streamName; }
    }
}

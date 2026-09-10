using System;
using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Starts provider authorization from the settings screen. Client IDs are
    /// intentionally configuration values, never embedded account credentials.
    public sealed class LiveStreamAccountLinkController : MonoBehaviour
    {
        [SerializeField] private string twitchClientId = "7sh6f19iuva2ep5b5eyedbf1mvphiw";
        [SerializeField] private string youtubeClientId = "619136214643-6hsflt2isot3prrices9tu5nn5nvq355.apps.googleusercontent.com";
        [SerializeField] private string callbackScheme = "myproject5";

        public void LinkTwitch()
        {
            if (string.IsNullOrWhiteSpace(twitchClientId)) return;
            StartCoroutine(TwitchDeviceFlow());
        }

        private IEnumerator TwitchDeviceFlow()
        {
            var body = Encoding.UTF8.GetBytes("client_id=" + Uri.EscapeDataString(twitchClientId)
                + "&scopes=" + Uri.EscapeDataString("channel:manage:broadcast channel:read:stream_key"));
            using (var request = new UnityWebRequest("https://id.twitch.tv/oauth2/device", "POST"))
            {
                request.uploadHandler = new UploadHandlerRaw(body);
                request.downloadHandler = new DownloadHandlerBuffer();
                request.SetRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                var device = JsonUtility.FromJson<TwitchDeviceResponse>(request.downloadHandler.text);
                Open(device.verification_uri);
                yield return PollTwitchToken(device.device_code, device.interval);
            }
        }

        private IEnumerator PollTwitchToken(string deviceCode, int interval)
        {
            var wait = Mathf.Max(5, interval);
            while (true)
            {
                yield return new WaitForSeconds(wait);
                var body = Encoding.UTF8.GetBytes("client_id=" + Uri.EscapeDataString(twitchClientId)
                    + "&device_code=" + Uri.EscapeDataString(deviceCode)
                    + "&grant_type=urn:ietf:params:oauth:grant-type:device_code");
                using (var request = UnityWebRequest.Post("https://id.twitch.tv/oauth2/token", ""))
                {
                    request.uploadHandler = new UploadHandlerRaw(body);
                    request.SetRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                    yield return request.SendWebRequest();
                    if (request.responseCode == 428 || request.responseCode == 400) continue;
                    if (request.result != UnityWebRequest.Result.Success) yield break;
                    var token = JsonUtility.FromJson<TwitchTokenResponse>(request.downloadHandler.text);
                    yield return FetchTwitchStreamKey(token.access_token);
                    yield break;
                }
            }
        }

        private IEnumerator FetchTwitchStreamKey(string accessToken)
        {
            using (var request = UnityWebRequest.Get("https://api.twitch.tv/helix/streams/key"))
            {
                request.SetRequestHeader("Client-Id", twitchClientId);
                request.SetRequestHeader("Authorization", "Bearer " + accessToken);
                yield return request.SendWebRequest();
                if (request.result != UnityWebRequest.Result.Success) yield break;
                var result = JsonUtility.FromJson<TwitchStreamKeyResponse>(request.downloadHandler.text);
                if (result.data == null || result.data.Length == 0) yield break;
                SaveTwitchAccount(result.data[0].stream_key);
            }
        }

        private void SaveTwitchAccount(string key)
        {
            var accounts = new LiveStreamAccountStore().Load();
            accounts.RemoveAll(x => x.provider == LiveStreamProvider.Twitch);
            accounts.Add(new LiveStreamAccount { provider = LiveStreamProvider.Twitch,
                displayName = "Twitch", ingestUrl = "rtmps://live.twitch.tv/app/", streamKey = key });
            new LiveStreamAccountStore().Save(accounts);
        }

        [Serializable] private sealed class TwitchDeviceResponse { public string device_code; public string verification_uri; public int interval = 5; }
        [Serializable] private sealed class TwitchTokenResponse { public string access_token; }
        [Serializable] private sealed class TwitchStreamKeyResponse { public TwitchStreamKey[] data; }
        [Serializable] private sealed class TwitchStreamKey { public string stream_key; }

        public void LinkYouTube()
        {
            if (string.IsNullOrWhiteSpace(youtubeClientId)) return;
            Open("https://accounts.google.com/o/oauth2/v2/auth?client_id=" + Uri.EscapeDataString(youtubeClientId)
                + "&redirect_uri=" + Uri.EscapeDataString(callbackScheme + "://oauth/youtube")
                + "&response_type=code&scope=" + Uri.EscapeDataString("https://www.googleapis.com/auth/youtube.force-ssl")
                + "&access_type=offline");
        }

        private static void Open(string url) => Application.OpenURL(url);
    }
}

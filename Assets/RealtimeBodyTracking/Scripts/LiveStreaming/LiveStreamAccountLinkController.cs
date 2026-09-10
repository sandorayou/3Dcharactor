using System;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Starts provider authorization from the settings screen. Client IDs are
    /// intentionally configuration values, never embedded account credentials.
    public sealed class LiveStreamAccountLinkController : MonoBehaviour
    {
        [SerializeField] private string twitchClientId;
        [SerializeField] private string youtubeClientId;
        [SerializeField] private string callbackScheme = "myproject5";

        public void LinkTwitch()
        {
            if (string.IsNullOrWhiteSpace(twitchClientId)) return;
            Open("https://id.twitch.tv/oauth2/authorize?client_id=" + Uri.EscapeDataString(twitchClientId)
                + "&redirect_uri=" + Uri.EscapeDataString(callbackScheme + "://oauth/twitch")
                + "&response_type=token&scope=channel%3Amanage%3Abroadcast%20channel%3Aread%3Astream_key");
        }

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

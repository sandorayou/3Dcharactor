using System;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    [Serializable]
    public sealed class LiveStreamSettings
    {
        public LiveStreamProvider provider = LiveStreamProvider.Twitch;
        [Tooltip("RTMPS ingest URL. Keep the stream key out of source control.")]
        public string ingestUrl;
        [Tooltip("Stream key. Store this in Keychain/secure storage in the production app.")]
        public string streamKey;
        [Range(15, 60)] public int frameRate = 30;
        [Range(256, 12000)] public int videoBitrateKbps = 4500;
        [Range(32, 320)] public int audioBitrateKbps = 128;

        public bool IsValid => !string.IsNullOrWhiteSpace(ingestUrl)
            && !string.IsNullOrWhiteSpace(streamKey)
            && ingestUrl.StartsWith("rtmp", StringComparison.OrdinalIgnoreCase);
    }
}

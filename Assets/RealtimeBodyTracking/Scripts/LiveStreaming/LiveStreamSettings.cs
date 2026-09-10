using System;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    [Serializable]
    public sealed class LiveStreamSettings
    {
        public LiveStreamProvider provider = LiveStreamProvider.Twitch;
        public LiveStreamOrientation orientation = LiveStreamOrientation.Portrait;
        [Tooltip("RTMPS ingest URL. Keep the stream key out of source control.")]
        public string ingestUrl;
        [Tooltip("Stream key. Store this in Keychain/secure storage in the production app.")]
        public string streamKey;
        // Portrait-first mobile profile. The native publisher crops camera input
        // to this canvas; Unity controls are never part of the capture source.
        public int videoWidth => orientation == LiveStreamOrientation.Portrait ? 720 : 1280;
        public int videoHeight => orientation == LiveStreamOrientation.Portrait ? 1280 : 720;
        [Range(15, 60)] public int frameRate = 30;
        [Range(256, 12000)] public int videoBitrateKbps = 3500;
        [Range(32, 320)] public int audioBitrateKbps = 128;

        public bool IsValid => !string.IsNullOrWhiteSpace(ingestUrl)
            && !string.IsNullOrWhiteSpace(streamKey)
            && ingestUrl.StartsWith("rtmp", StringComparison.OrdinalIgnoreCase);
    }
}

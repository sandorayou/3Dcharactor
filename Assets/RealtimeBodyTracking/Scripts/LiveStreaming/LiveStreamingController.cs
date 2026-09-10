using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Unity-facing contract for the native iOS encoder/RTMPS module.
    /// The generated iOS project supplies the native implementation.
    public sealed class LiveStreamingController : MonoBehaviour
    {
        [SerializeField] private LiveStreamSettings settings = new LiveStreamSettings();
        [SerializeField] private bool useFrontCamera = true;
        public bool IsStreaming { get; private set; }
        public bool IsMuted { get; private set; }
        public LiveStreamProvider CurrentProvider => settings.provider;
        public LiveStreamOrientation CurrentOrientation => settings.orientation;

        private void OnApplicationPause(bool paused)
        {
            // Fail closed: leaving the app must never leave an unattended camera live.
            if (paused) StopStreaming();
        }

        private void OnApplicationFocus(bool focused)
        {
            if (!focused) StopStreaming();
        }

        private void OnDestroy() => StopStreaming();

        public void Configure(LiveStreamProvider provider, string ingestUrl, string streamKey)
        {
            settings.provider = provider;
            settings.ingestUrl = ingestUrl;
            settings.streamKey = streamKey;
        }

        public void SetOrientation(LiveStreamOrientation orientation)
        {
            if (IsStreaming) return;
            settings.orientation = orientation;
        }

        public void ToggleCamera()
        {
            useFrontCamera = !useFrontCamera;
            SetFrontCamera(useFrontCamera);
        }

        public bool StartStreaming()
        {
            if (!settings.IsValid || IsStreaming) return false;
            IsStreaming = NativeStart(settings.ingestUrl, settings.streamKey,
                settings.videoWidth, settings.videoHeight, settings.frameRate,
                settings.videoBitrateKbps, settings.audioBitrateKbps) == 0;
            return IsStreaming;
        }

        public void StopStreaming()
        {
            if (!IsStreaming) return;
            NativeStop();
            IsStreaming = false;
            IsMuted = false;
        }

        public void ToggleMute()
        {
            if (!IsStreaming) return;
            IsMuted = !IsMuted;
            NativeSetMuted(IsMuted ? 1 : 0);
        }

        private static void SetFrontCamera(bool front)
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativeSetCamera(front ? 1 : 0);
#endif
        }

#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativeStart(string url, string key, int width, int height, int fps, int videoKbps, int audioKbps);
        [DllImport("__Internal")] private static extern void NativeStop();
        [DllImport("__Internal")] private static extern void NativeSetCamera(int front);
        [DllImport("__Internal")] private static extern void NativeSetMuted(int muted);
#else
        private static int NativeStart(string url, string key, int width, int height, int fps, int videoKbps, int audioKbps) => -1;
        private static void NativeStop() { }
        private static void NativeSetCamera(int front) { }
        private static void NativeSetMuted(int muted) { }
#endif
    }
}

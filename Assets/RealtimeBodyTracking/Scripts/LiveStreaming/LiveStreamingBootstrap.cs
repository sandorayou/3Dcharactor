using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Makes the control surface available in every scene without requiring
    /// manual scene wiring. The generated UI remains outside the camera source.
    public static class LiveStreamingBootstrap
    {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
            if (Object.FindObjectOfType<LiveStreamingController>() != null) return;
            var root = new GameObject("LiveStreamingRuntime");
            Object.DontDestroyOnLoad(root);
            root.AddComponent<LiveStreamingController>();
            root.AddComponent<RealtimeBodyTracking.RuntimeLogCapture>();
            root.AddComponent<RealtimeBodyTracking.DeviceScreenRecorder>();
            root.AddComponent<LiveStreamAccountLinkController>();
            root.AddComponent<YouTubeAccountLinkController>();
            root.AddComponent<LiveStreamSettingsController>();
            root.AddComponent<LiveStreamControlPanel>();
        }
    }
}

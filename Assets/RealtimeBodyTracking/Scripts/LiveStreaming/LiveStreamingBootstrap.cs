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
            // Streaming is not part of the camera-avatar app.
        }
    }
}

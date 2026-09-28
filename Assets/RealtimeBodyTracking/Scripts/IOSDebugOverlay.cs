using UnityEngine;

namespace RealtimeBodyTracking
{
    /// <summary>Compatibility type for existing scenes. No diagnostic UI is installed.</summary>
    public sealed class IOSDebugOverlay : MonoBehaviour { }

    internal static class IOSDebugOverlayBootstrap
    {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install() { }
    }
}

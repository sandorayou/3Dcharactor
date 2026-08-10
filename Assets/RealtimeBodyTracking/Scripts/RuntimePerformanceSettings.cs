using UnityEngine;

namespace RealtimeBodyTracking
{
    public static class RuntimePerformanceSettings
    {
        private const int TargetFrameRate = 60;
        private const int MaximumWidth = 2560;
        private const int MaximumHeight = 1440;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void Apply()
        {
            QualitySettings.vSyncCount = 1;
            Application.targetFrameRate = TargetFrameRate;

            if (Screen.width > MaximumWidth || Screen.height > MaximumHeight)
            {
                Screen.SetResolution(
                    MaximumWidth,
                    MaximumHeight,
                    Screen.fullScreenMode,
                    TargetFrameRate);
            }
        }
    }
}

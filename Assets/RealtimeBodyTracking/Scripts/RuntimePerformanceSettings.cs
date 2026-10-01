using UnityEngine;

namespace RealtimeBodyTracking
{
    public static class RuntimePerformanceSettings
    {
        private const int TargetFrameRate = 60;
        private const int StandaloneQualityLevel = 3;
        private const int MaximumWidth = 1920;
        private const int MaximumHeight = 1080;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void Apply()
        {
#if (UNITY_STANDALONE || UNITY_IOS) && !UNITY_EDITOR
            QualitySettings.SetQualityLevel(StandaloneQualityLevel, true);
#if UNITY_STANDALONE_WIN || UNITY_IOS
            QualitySettings.shadowDistance = Mathf.Min(QualitySettings.shadowDistance, 28f);
#endif
#endif
            QualitySettings.vSyncCount = 0;
            Application.targetFrameRate = TargetFrameRate;

#if !UNITY_IOS || UNITY_EDITOR
            if (Screen.width > MaximumWidth || Screen.height > MaximumHeight)
            {
                Screen.SetResolution(
                    MaximumWidth,
                    MaximumHeight,
                    Screen.fullScreenMode,
                    TargetFrameRate);
            }
#endif
        }
    }
}

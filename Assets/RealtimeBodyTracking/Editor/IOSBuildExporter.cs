using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace RealtimeBodyTracking.Editor
{
    public static class IOSBuildExporter
    {
        [MenuItem("Build/Export updated iOS project")]
        public static void Export()
        {
            var scenes = EditorBuildSettings.scenes.Where(x => x.enabled).Select(x => x.path).ToArray();
            if (scenes.Length == 0)
                scenes = new[] { "Assets/Scenes/SampleScene.unity" };

            var oldAlpha = PlayerSettings.preserveFramebufferAlpha;
            var oldVersion = PlayerSettings.iOS.targetOSVersionString;
            var oldUsage = PlayerSettings.iOS.cameraUsageDescription;
            var oldBackend = PlayerSettings.GetScriptingBackend(BuildTargetGroup.iOS);
            try
            {
                // Both are necessary: transparent camera clear and an alpha-capable framebuffer.
                PlayerSettings.preserveFramebufferAlpha = true;
                PlayerSettings.iOS.targetOSVersionString = "15.0";
                PlayerSettings.iOS.cameraUsageDescription = "体・手・顔の動きを検出し、実写モザイクとアバターを表示するためにカメラを使います。";
                PlayerSettings.SetScriptingBackend(BuildTargetGroup.iOS, ScriptingImplementation.IL2CPP);
                var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
                {
                    scenes = scenes,
                    locationPathName = "Builds/iOS-WindowsPort",
                    target = BuildTarget.iOS,
                    options = BuildOptions.None
                });
                if (report.summary.result != BuildResult.Succeeded)
                    throw new BuildFailedException("iOS Xcode export failed: " + report.summary.result);
            }
            finally
            {
                PlayerSettings.preserveFramebufferAlpha = oldAlpha;
                PlayerSettings.iOS.targetOSVersionString = oldVersion;
                PlayerSettings.iOS.cameraUsageDescription = oldUsage;
                PlayerSettings.SetScriptingBackend(BuildTargetGroup.iOS, oldBackend);
            }
        }
    }
}

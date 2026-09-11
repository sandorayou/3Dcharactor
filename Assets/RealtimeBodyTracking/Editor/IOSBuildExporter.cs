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

            var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
            {
                scenes = scenes,
                locationPathName = "Builds/iOS",
                target = BuildTarget.iOS,
                options = BuildOptions.None
            });
            if (report.summary.result != BuildResult.Succeeded)
                throw new BuildFailedException("iOS Xcode export failed: " + report.summary.result);
        }
    }
}

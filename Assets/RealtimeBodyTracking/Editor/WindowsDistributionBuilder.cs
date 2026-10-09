using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace RealtimeBodyTracking.Editor
{
    public static class WindowsDistributionBuilder
    {
        [MenuItem("Build/Build Windows distribution")]
        public static void Build()
        {
            if (!BuildPipeline.IsBuildTargetSupported(BuildTargetGroup.Standalone, BuildTarget.StandaloneWindows64))
                throw new BuildFailedException("Windows x64 Build Support is not installed for this Unity Editor.");

            var scenes = EditorBuildSettings.scenes.Where(scene => scene.enabled).Select(scene => scene.path).ToArray();
            if (scenes.Length == 0) scenes = new[] { "Assets/Scenes/SampleScene.unity" };

            var projectRoot = Directory.GetParent(Application.dataPath).FullName;
            var outputDirectory = Path.Combine(projectRoot, "Builds", "Windows-" + DateTime.Now.ToString("yyyyMMdd-HHmmss"));
            Directory.CreateDirectory(outputDirectory);

            var oldName = PlayerSettings.productName;
            try
            {
                PlayerSettings.productName = "Realtime Body Tracker";
                var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
                {
                    scenes = scenes,
                    locationPathName = Path.Combine(outputDirectory, "RealtimeBodyTracker.exe"),
                    target = BuildTarget.StandaloneWindows64,
                    options = BuildOptions.CompressWithLz4HC
                });
                if (report.summary.result != BuildResult.Succeeded)
                    throw new BuildFailedException("Windows distribution build failed: " + report.summary.result);
                Debug.Log($"Windows distribution created at {outputDirectory} ({report.summary.totalSize} bytes)");
            }
            finally { PlayerSettings.productName = oldName; }
        }
    }
}

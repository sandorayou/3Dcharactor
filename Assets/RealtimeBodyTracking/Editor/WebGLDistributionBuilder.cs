using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace RealtimeBodyTracking.Editor
{
    public static class WebGLDistributionBuilder
    {
        [MenuItem("Build/Build WebGL distribution")]
        public static void Build()
        {
            if (!BuildPipeline.IsBuildTargetSupported(BuildTargetGroup.WebGL, BuildTarget.WebGL))
                throw new BuildFailedException("WebGL Build Support is not installed for this Unity Editor.");

            var scenes = EditorBuildSettings.scenes.Where(scene => scene.enabled).Select(scene => scene.path).ToArray();
            if (scenes.Length == 0) scenes = new[] { "Assets/Scenes/SampleScene.unity" };

            var projectRoot = Directory.GetParent(Application.dataPath).FullName;
            var output = Path.Combine(projectRoot, "Builds", "WebGL");
            if (Directory.Exists(output) && Directory.EnumerateFileSystemEntries(output).Any())
                output = Path.Combine(projectRoot, "Builds", "WebGL-" + DateTime.Now.ToString("yyyyMMdd-HHmmss"));
            Directory.CreateDirectory(output);

            var oldName = PlayerSettings.productName;
            var oldDecompressionFallback = PlayerSettings.WebGL.decompressionFallback;
            try
            {
                PlayerSettings.productName = "MyProject5 Web";
                // Keep the packaged build runnable when the static host cannot set Content-Encoding.
                PlayerSettings.WebGL.decompressionFallback = true;
                var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
                {
                    scenes = scenes,
                    locationPathName = output,
                    target = BuildTarget.WebGL,
                    options = BuildOptions.None
                });
                if (report.summary.result != BuildResult.Succeeded)
                    throw new BuildFailedException("WebGL distribution build failed: " + report.summary.result);
                Debug.Log($"WebGL distribution created at {output} ({report.summary.totalSize} bytes)");
            }
            finally
            {
                PlayerSettings.productName = oldName;
                PlayerSettings.WebGL.decompressionFallback = oldDecompressionFallback;
            }
        }
    }
}

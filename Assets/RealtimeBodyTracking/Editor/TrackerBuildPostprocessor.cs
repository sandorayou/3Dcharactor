using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace RealtimeBodyTracking.Editor
{
    public sealed class TrackerBuildPostprocessor : IPostprocessBuildWithReport
    {
        public int callbackOrder => 0;

        public void OnPostprocessBuild(BuildReport report)
        {
            var projectRoot = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            var source = Path.Combine(projectRoot, "python-tracker");
            var buildDirectory = Path.GetDirectoryName(report.summary.outputPath);
            if (!Directory.Exists(source) || string.IsNullOrEmpty(buildDirectory))
                throw new BuildFailedException($"Python tracker was not found: {source}");

            var destination = Path.Combine(buildDirectory, "python-tracker");
            CopyDirectory(source, destination);
            Debug.Log($"[TrackerBuildPostprocessor] Copied camera tracker to {destination}");
        }

        private static void CopyDirectory(string source, string destination)
        {
            Directory.CreateDirectory(destination);
            foreach (var file in Directory.GetFiles(source))
            {
                if (Path.GetExtension(file) == ".pyc") continue;
                File.Copy(file, Path.Combine(destination, Path.GetFileName(file)), true);
            }

            foreach (var directory in Directory.GetDirectories(source))
            {
                var name = Path.GetFileName(directory);
                if (name == "debug" || name == "__pycache__") continue;
                CopyDirectory(directory, Path.Combine(destination, name));
            }
        }
    }
}

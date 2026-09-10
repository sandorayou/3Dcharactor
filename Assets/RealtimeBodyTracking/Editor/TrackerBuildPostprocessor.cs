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
            if (report.summary.platform == BuildTarget.iOS)
            {
                ConfigureIosBuild(report.summary.outputPath);
                return;
            }

            if (report.summary.platform == BuildTarget.StandaloneWindows ||
                report.summary.platform == BuildTarget.StandaloneWindows64)
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
        }

        private static void ConfigureIosBuild(string pathToBuiltProject)
        {
            string plistPath = Path.Combine(pathToBuiltProject, "Info.plist");
            if (!File.Exists(plistPath)) return;

            try
            {
                string content = File.ReadAllText(plistPath);
                bool modified = false;

                if (!content.Contains("<key>NSCameraUsageDescription</key>"))
                {
                    string cameraEntry = "    <key>NSCameraUsageDescription</key>\n    <string>リアルタイム身体・背景トラッキングのためにカメラを使用します。</string>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0)
                    {
                        insertIndex += "<dict>".Length;
                        content = content.Insert(insertIndex, "\n" + cameraEntry);
                        modified = true;
                    }
                }

                if (!content.Contains("<key>NSMicrophoneUsageDescription</key>"))
                {
                    string microphoneEntry = "    <key>NSMicrophoneUsageDescription</key>\n    <string>ライブ配信の音声を送信するためにマイクを使用します。</string>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0) { content = content.Insert(insertIndex + "<dict>".Length, "\n" + microphoneEntry); modified = true; }
                }

                if (!content.Contains("<key>NSLocalNetworkUsageDescription</key>"))
                {
                    string networkEntry = "    <key>NSLocalNetworkUsageDescription</key>\n    <string>PCからの姿勢トラッキングデータを受信するためにローカルネットワークを使用します。</string>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0)
                    {
                        insertIndex += "<dict>".Length;
                        content = content.Insert(insertIndex, "\n" + networkEntry);
                        modified = true;
                    }
                }

                if (!content.Contains("<key>UIBackgroundModes</key>"))
                {
                    string backgroundEntry = "    <key>UIBackgroundModes</key>\n    <array>\n        <string>audio</string>\n    </array>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0) { content = content.Insert(insertIndex + "<dict>".Length, "\n" + backgroundEntry); modified = true; }
                }

                if (!content.Contains("myproject5"))
                {
                    string urlEntry = "    <key>CFBundleURLTypes</key>\n    <array>\n        <dict>\n            <key>CFBundleURLSchemes</key>\n            <array><string>myproject5</string></array>\n        </dict>\n    </array>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0) { content = content.Insert(insertIndex + "<dict>".Length, "\n" + urlEntry); modified = true; }
                }

                if (modified)
                {
                    File.WriteAllText(plistPath, content);
                    Debug.Log("[TrackerBuildPostprocessor] Added iOS Privacy descriptions to Info.plist.");
                }
            }
            catch (System.Exception ex)
            {
                Debug.LogWarning($"[TrackerBuildPostprocessor] Failed to update Info.plist: {ex.Message}");
            }
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

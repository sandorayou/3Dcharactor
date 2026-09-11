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
                GenerateMediaPipePodfile(report.summary.outputPath);
                return;
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

                if (!content.Contains("<key>NSPhotoLibraryAddUsageDescription</key>"))
                {
                    string photosEntry = "    <key>NSPhotoLibraryAddUsageDescription</key>\n    <string>デバッグ録画を写真アプリに保存するために使用します。</string>\n";
                    int insertIndex = content.IndexOf("<dict>");
                    if (insertIndex >= 0) { content = content.Insert(insertIndex + "<dict>".Length, "\n" + photosEntry); modified = true; }
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
                    string urlEntry = "    <key>CFBundleURLTypes</key>\n    <array>\n        <dict>\n            <key>CFBundleURLSchemes</key>\n            <array><string>myproject5</string><string>com.googleusercontent.apps.619136214643-6hsflt2isot3prrices9tu5nn5nvq355</string></array>\n        </dict>\n    </array>\n";
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

        private static void GenerateMediaPipePodfile(string pathToBuiltProject)
        {
            var podfile = Path.Combine(pathToBuiltProject, "Podfile");
            var content = "platform :ios, '12.0'\nuse_frameworks!\n\ntarget 'Unity-iPhone' do\n  pod 'MediaPipeTasksVision'\nend\n";
            if (!File.Exists(podfile) || File.ReadAllText(podfile) != content)
            {
                File.WriteAllText(podfile, content);
                Debug.Log($"[TrackerBuildPostprocessor] Generated MediaPipe Podfile: {podfile}");
            }

            var script = Path.Combine(pathToBuiltProject, "InstallMediaPipePods.command");
            File.WriteAllText(script, "#!/bin/sh\nset -eu\ncd \"$(dirname \"$0\")\"\npod install\nopen Unity-iPhone.xcworkspace\n");
            Debug.Log("[TrackerBuildPostprocessor] Run InstallMediaPipePods.command on macOS before opening the iOS project.");
        }

    }
}

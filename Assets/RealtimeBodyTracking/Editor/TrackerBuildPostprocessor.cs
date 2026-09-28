using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;
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
                RemoveUnneededStreamingFrameworks(report.summary.outputPath);
                ConfigureIosBuild(report.summary.outputPath);
                RemoveLegacyMediaPipeFramework(report.summary.outputPath);
                GenerateMediaPipePodfile(report.summary.outputPath);
                return;
            }

        }

        private static void RemoveUnneededStreamingFrameworks(string pathToBuiltProject)
        {
            var projectPath = PBXProject.GetPBXProjectPath(pathToBuiltProject);
            var project = new PBXProject();
            project.ReadFromFile(projectPath);
            var obsoletePaths = new[]
            {
                "LiveStreamingBridge.mm",
                "LiveStreamingBridge.swift",
            };
            foreach (var file in obsoletePaths)
            {
                var guid = project.FindFileGuidByProjectPath(file);
                if (string.IsNullOrEmpty(guid)) continue;
                project.RemoveFileFromBuild(project.GetUnityMainTargetGuid(), guid);
                project.RemoveFileFromBuild(project.GetUnityFrameworkTargetGuid(), guid);
                project.RemoveFile(guid);
            }
            project.WriteToFile(projectPath);
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

        private static void RemoveLegacyMediaPipeFramework(string pathToBuiltProject)
        {
            var projectPath = PBXProject.GetPBXProjectPath(pathToBuiltProject);
            var project = new PBXProject();
            project.ReadFromFile(projectPath);
            var frameworkPath = "Frameworks/com.github.homuler.mediapipe/Runtime/Plugins/iOS/MediaPipeUnity.framework";
            var fileGuid = project.FindFileGuidByProjectPath(frameworkPath);
            if (!string.IsNullOrEmpty(fileGuid))
            {
                project.RemoveFileFromBuild(project.GetUnityMainTargetGuid(), fileGuid);
                project.RemoveFileFromBuild(project.GetUnityFrameworkTargetGuid(), fileGuid);
                project.RemoveFile(fileGuid);
                project.WriteToFile(projectPath);
            }

            var frameworkDirectory = Path.Combine(pathToBuiltProject, frameworkPath);
            if (Directory.Exists(frameworkDirectory)) Directory.Delete(frameworkDirectory, true);
            Debug.Log("[TrackerBuildPostprocessor] Removed legacy MediaPipeUnity.framework from iOS export.");
        }

        private static void GenerateMediaPipePodfile(string pathToBuiltProject)
        {
            var podfile = Path.Combine(pathToBuiltProject, "Podfile");
            var content = "platform :ios, '15.0'\nuse_frameworks! :linkage => :static\n\ntarget 'UnityFramework' do\n  pod 'MediaPipeTasksVision'\nend\n";
            if (!File.Exists(podfile) || File.ReadAllText(podfile) != content)
                File.WriteAllText(podfile, content);

            var script = Path.Combine(pathToBuiltProject, "InstallMediaPipePods.command");
            File.WriteAllText(script, "#!/bin/sh\nset -eu\ncd \"$(dirname \"$0\")\"\npod install\nopen Unity-iPhone.xcworkspace\n");
            Debug.Log("[TrackerBuildPostprocessor] Run InstallMediaPipePods.command on macOS before opening the iOS project.");
        }

    }
}

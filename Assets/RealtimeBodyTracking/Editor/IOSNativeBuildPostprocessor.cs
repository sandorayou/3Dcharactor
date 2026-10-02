#if UNITY_IOS
using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;

namespace RealtimeBodyTracking.Editor
{
    public sealed class IOSNativeBuildPostprocessor : IPostprocessBuildWithReport
    {
        public int callbackOrder => 100;
        public void OnPostprocessBuild(BuildReport report)
        {
            if (report.summary.platform != BuildTarget.iOS) return;
            var output = report.summary.outputPath;
            var projectPath = PBXProject.GetPBXProjectPath(output);
            var project = new PBXProject();
            project.ReadFromFile(projectPath);
            var framework = project.GetUnityFrameworkTargetGuid();
            foreach (var name in new[] { "AVFoundation.framework", "CoreMedia.framework", "CoreVideo.framework",
                "Vision.framework", "CoreImage.framework", "QuartzCore.framework", "UIKit.framework", "Metal.framework", "ReplayKit.framework" })
                project.AddFrameworkToProject(framework, name, false);
            project.AddBuildProperty(framework, "OTHER_LDFLAGS", "-ObjC");
            project.SetBuildProperty(framework, "CLANG_ENABLE_MODULES", "YES");
            project.WriteToFile(projectPath);
            File.WriteAllText(Path.Combine(output, "Podfile"),
                "platform :ios, '15.0'\nuse_frameworks! :linkage => :static\n" +
                "target 'UnityFramework' do\n  pod 'MediaPipeTasksVision', '0.10.21'\nend\n");
            // Consumers must be able to distinguish this player from the old checked-in export.
            File.WriteAllText(Path.Combine(output, "windows-port-export.txt"), "WindowsPort-PoseHandFace-Mosaic-v1\n");
        }
    }
}
#endif

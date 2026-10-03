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
            File.Copy(Path.Combine(UnityEngine.Application.dataPath, "Plugins/iOS/PrivacyMosaicCore.h"),
                Path.Combine(output, "Libraries/Plugins/iOS/PrivacyMosaicCore.h"), true);
            var projectPath = PBXProject.GetPBXProjectPath(output);
            var project = new PBXProject();
            project.ReadFromFile(projectPath);
            var framework = project.GetUnityFrameworkTargetGuid();
            var appTarget = project.GetUnityMainTargetGuid();
            project.SetBuildProperty(appTarget, "PRODUCT_BUNDLE_IDENTIFIER", IOSBuildExporter.AppBundleIdentifier);
            var infoPath = Path.Combine(output, "Info.plist");
            var info = new PlistDocument();
            info.ReadFromFile(infoPath);
            info.root.SetString("CFBundleDisplayName", IOSBuildExporter.AppDisplayName);
            info.root.SetString("CFBundleName", IOSBuildExporter.AppDisplayName);
            info.root.SetString("CFBundleIdentifier", IOSBuildExporter.AppBundleIdentifier);
            info.WriteToFile(infoPath);
            foreach (var name in new[] { "AVFoundation.framework", "CoreMedia.framework", "CoreVideo.framework",
                "CoreImage.framework", "QuartzCore.framework", "UIKit.framework", "Metal.framework", "ReplayKit.framework" })
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

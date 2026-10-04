using System.Linq;
using System.Collections.Generic;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace RealtimeBodyTracking.Editor
{
    public static class IOSBuildExporter
    {
        public const string AppDisplayName = "MyProject5";
        public const string AppBundleIdentifier = "com.sandorayou.myproject5";

        [MenuItem("Build/Export updated iOS project")]
        public static void Export()
        {
            ValidateHeadRotationCorrection();
            ValidateAvatarGaze();
            var scenes = EditorBuildSettings.scenes.Where(x => x.enabled).Select(x => x.path).ToArray();
            if (scenes.Length == 0)
                scenes = new[] { "Assets/Scenes/SampleScene.unity" };

            var oldProductName = PlayerSettings.productName;
            var oldIdentifier = PlayerSettings.GetApplicationIdentifier(BuildTargetGroup.iOS);
            var oldAlpha = PlayerSettings.preserveFramebufferAlpha;
            var oldVersion = PlayerSettings.iOS.targetOSVersionString;
            var oldUsage = PlayerSettings.iOS.cameraUsageDescription;
            var oldBackend = PlayerSettings.GetScriptingBackend(BuildTargetGroup.iOS);
            var oldStripping = PlayerSettings.GetManagedStrippingLevel(NamedBuildTarget.iOS);
            var oldGeneration = PlayerSettings.GetIl2CppCodeGeneration(NamedBuildTarget.iOS);
            var oldStripEngine = PlayerSettings.stripEngineCode;
            var textures = new List<(TextureImporter importer, TextureImporterPlatformSettings settings)>();
            try
            {
                PlayerSettings.productName = AppDisplayName;
                PlayerSettings.SetApplicationIdentifier(BuildTargetGroup.iOS, AppBundleIdentifier);
                // Both are necessary: transparent camera clear and an alpha-capable framebuffer.
                PlayerSettings.preserveFramebufferAlpha = true;
                PlayerSettings.iOS.targetOSVersionString = "15.0";
                PlayerSettings.iOS.cameraUsageDescription = "体・手・顔の動きを検出し、実写モザイクとアバターを表示するためにカメラを使います。";
                PlayerSettings.SetScriptingBackend(BuildTargetGroup.iOS, ScriptingImplementation.IL2CPP);
                PlayerSettings.SetManagedStrippingLevel(NamedBuildTarget.iOS, ManagedStrippingLevel.High);
                PlayerSettings.SetIl2CppCodeGeneration(NamedBuildTarget.iOS, Il2CppCodeGeneration.OptimizeSize);
                PlayerSettings.stripEngineCode = true;
                // Only textures reachable from the shipped scene receive iOS overrides.
                foreach (var path in AssetDatabase.GetDependencies(scenes, true).Distinct())
                {
                    if (!(AssetImporter.GetAtPath(path) is TextureImporter importer)) continue;
                    textures.Add((importer, importer.GetPlatformTextureSettings("iPhone")));
                    var settings = importer.GetPlatformTextureSettings("iPhone");
                    settings.name = "iPhone";
                    settings.overridden = true;
                    settings.maxTextureSize = System.Math.Min(importer.GetDefaultPlatformTextureSettings().maxTextureSize, 1024);
                    settings.format = path.Contains("Face") || path.Contains("Eye")
                        ? TextureImporterFormat.ASTC_4x4 : TextureImporterFormat.ASTC_6x6;
                    settings.compressionQuality = 100;
                    importer.SetPlatformTextureSettings(settings);
                    importer.SaveAndReimport();
                }
                var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
                {
                    scenes = scenes,
                    locationPathName = "Builds/iOS-WindowsPort",
                    target = BuildTarget.iOS,
                    options = BuildOptions.CompressWithLz4HC
                });
                if (report.summary.result != BuildResult.Succeeded)
                    throw new BuildFailedException("iOS Xcode export failed: " + report.summary.result);
            }
            finally
            {
                PlayerSettings.productName = oldProductName;
                PlayerSettings.SetApplicationIdentifier(BuildTargetGroup.iOS, oldIdentifier);
                PlayerSettings.preserveFramebufferAlpha = oldAlpha;
                PlayerSettings.iOS.targetOSVersionString = oldVersion;
                PlayerSettings.iOS.cameraUsageDescription = oldUsage;
                PlayerSettings.SetScriptingBackend(BuildTargetGroup.iOS, oldBackend);
                PlayerSettings.SetManagedStrippingLevel(NamedBuildTarget.iOS, oldStripping);
                PlayerSettings.SetIl2CppCodeGeneration(NamedBuildTarget.iOS, oldGeneration);
                PlayerSettings.stripEngineCode = oldStripEngine;
                foreach (var texture in textures)
                {
                    texture.importer.SetPlatformTextureSettings(texture.settings);
                    texture.importer.SaveAndReimport();
                }
            }
        }
        private static void ValidateHeadRotationCorrection()
        {
            // Evaluate the actual runtime conversion using Unity's quaternion implementation.
            foreach (var pitch in new[] { -30f, 0f, 30f })
            foreach (var yaw in new[] { -60f, 0f, 60f })
            foreach (var roll in new[] { -35f, 0f, 35f })
            {
                var input = UnityEngine.Quaternion.Euler(pitch, yaw, roll);
                var source = IOSNativePoseSource.CorrectNativeHeadRotation(input);
                var corrected = source.eulerAngles;
                if (UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.x, -pitch)) > .01f ||
                    UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.y, -yaw)) > .01f ||
                    UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.z, -roll)) > .01f)
                    throw new BuildFailedException("iOS head conversion must reverse pitch/yaw/roll before common mirroring.");
                var displayed = new UnityEngine.Quaternion(source.x, -source.y, -source.z, source.w).normalized;
                var expected = UnityEngine.Quaternion.Euler(-pitch, yaw, roll);
                if (UnityEngine.Quaternion.Angle(expected, displayed) > .05f)
                    throw new BuildFailedException("iOS displayed head must reverse only pitch and preserve verified yaw/roll.");
            }
        }
        private static void ValidateAvatarGaze()
        {
            var prefab = AssetDatabase.LoadAssetAtPath<UnityEngine.GameObject>("Assets/h.prefab");
            var instance = UnityEngine.Object.Instantiate(prefab);
            try
            {
                var animator = instance.GetComponent<UnityEngine.Animator>();
                var head = instance.GetComponent<VRM.VRMLookAtHead>();
                var applyer = instance.GetComponent<VRM.VRMLookAtBoneApplyer>();
                var eye = animator.GetBoneTransform(UnityEngine.HumanBodyBones.LeftEye);
                var headBone = animator.GetBoneTransform(UnityEngine.HumanBodyBones.Head);
                var restRotation = eye.localRotation;
                var restPosition = eye.localPosition;
                head.Head = headBone;
                applyer.SendMessage("Start");
                headBone.localRotation *= UnityEngine.Quaternion.Euler(20f, 30f, 15f);
                head.RaiseYawPitchChanged(0f, 0f);
                if (UnityEngine.Quaternion.Angle(eye.localRotation, restRotation) > .05f ||
                    UnityEngine.Vector3.Distance(eye.localPosition, restPosition) > .0001f)
                    throw new BuildFailedException("Eye neutral pose failed to follow the rotated head.");
            }
            finally { UnityEngine.Object.DestroyImmediate(instance); }
        }
    }
}

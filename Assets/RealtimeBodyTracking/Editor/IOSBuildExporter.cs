using System.Linq;
using System.Collections.Generic;
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
            ValidateHeadRollCorrection();
            ValidateAvatarGaze();
            var scenes = EditorBuildSettings.scenes.Where(x => x.enabled).Select(x => x.path).ToArray();
            if (scenes.Length == 0)
                scenes = new[] { "Assets/Scenes/SampleScene.unity" };

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
        private static void ValidateHeadRollCorrection()
        {
            // Evaluate the actual runtime conversion using Unity's quaternion implementation.
            foreach (var roll in new[] { -35f, 0f, 35f })
            {
                var input = UnityEngine.Quaternion.Euler(17f, 29f, roll);
                var corrected = IOSNativePoseSource.CorrectNativeHeadRoll(input).eulerAngles;
                if (UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.x, 17f)) > .01f ||
                    UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.y, 29f)) > .01f ||
                    UnityEngine.Mathf.Abs(UnityEngine.Mathf.DeltaAngle(corrected.z, -roll)) > .01f)
                    throw new BuildFailedException("iOS head-roll correction changed yaw/pitch or failed to reverse roll.");
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
                var packet = new PosePacket { version = 4, face_blendshapes = new List<FaceBlendshape>() };
                packet.face_blendshapes.Add(new FaceBlendshape { name = "eyeLookInLeft", score = 1f });
                packet.face_blendshapes.Add(new FaceBlendshape { name = "eyeLookOutRight", score = 1f });
                var gaze = IOSAvatarGaze.ReadMirroredGaze(packet);
                if (gaze.x >= 0f || UnityEngine.Mathf.Abs(gaze.y) > .01f)
                    throw new BuildFailedException("Mirrored horizontal gaze mapping failed.");
                head.RaiseYawPitchChanged(gaze.x, gaze.y);
                if (UnityEngine.Quaternion.Angle(eye.localRotation, restRotation) < .1f)
                    throw new BuildFailedException("Avatar eye did not respond to native gaze.");
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

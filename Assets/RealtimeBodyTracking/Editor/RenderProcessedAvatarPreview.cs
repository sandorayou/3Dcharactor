using System;
using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

namespace RealtimeBodyTracking.Editor
{
    [InitializeOnLoad]
    public static class RenderProcessedAvatarPreview
    {
        private const string PendingKey = "RealtimeBodyTracking.ProcessedPreview.Pending";
        private static double enteredPlayModeAt;
        private static bool idlePoseStarted;

        static RenderProcessedAvatarPreview()
        {
            EditorApplication.update -= ContinueRender;
            EditorApplication.update += ContinueRender;
        }

        public static void Render()
        {
            EditorSceneManager.OpenScene("Assets/Scenes/SampleScene.unity", OpenSceneMode.Single);
            AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
            SessionState.SetBool(PendingKey, true);
            enteredPlayModeAt = 0d;
            idlePoseStarted = false;
            EditorApplication.isPlaying = true;
        }

        private static void ContinueRender()
        {
            if (!SessionState.GetBool(PendingKey, false) || !EditorApplication.isPlaying) return;
            if (enteredPlayModeAt <= 0d)
            {
                enteredPlayModeAt = EditorApplication.timeSinceStartup;
                return;
            }
            if (EditorApplication.timeSinceStartup - enteredPlayModeAt < 2d) return;

            if (!idlePoseStarted)
            {
                var avatar = GameObject.Find("h");
                var animator = avatar != null ? avatar.GetComponentInChildren<Animator>() : null;
                var controller = Resources.Load<RuntimeAnimatorController>("VTuberAnimator");
                if (animator == null || controller == null)
                    throw new InvalidOperationException("Idle preview animation could not be loaded.");
                animator.runtimeAnimatorController = controller;
                animator.Play("Idle", 0, .25f);
                animator.Update(0f);
                idlePoseStarted = true;
                enteredPlayModeAt = EditorApplication.timeSinceStartup;
                return;
            }

            SessionState.SetBool(PendingKey, false);
            try
            {
                CaptureGameViewState();
                EditorApplication.Exit(0);
            }
            catch (Exception exception)
            {
                Debug.LogException(exception);
                EditorApplication.Exit(1);
            }
        }

        private static void CaptureGameViewState()
        {
            var avatar = GameObject.Find("h");
            if (avatar == null) throw new InvalidOperationException("Avatar root 'h' was not found.");
            var renderers = avatar.GetComponentsInChildren<Renderer>(true);
            if (renderers.Length == 0) throw new InvalidOperationException("No avatar renderers found.");

            var bounds = renderers[0].bounds;
            for (var index = 1; index < renderers.Length; index++) bounds.Encapsulate(renderers[index].bounds);

            var camera = Camera.main;
            if (camera == null) throw new InvalidOperationException("Main Camera was not found.");
            var height = bounds.size.y;
            var target = new Vector3(bounds.center.x, bounds.min.y + height * .72f, bounds.center.z);
            camera.transform.position = target + Vector3.forward * Mathf.Max(4f, height * 3f);
            camera.transform.rotation = Quaternion.LookRotation(Vector3.back, Vector3.up);
            camera.orthographic = true;
            camera.orthographicSize = height * .38f;
            camera.clearFlags = CameraClearFlags.SolidColor;
            camera.backgroundColor = Color.yellow;
            camera.allowHDR = false;
            camera.allowMSAA = true;

            const int size = 1024;
            var renderTexture = new RenderTexture(size, size, 24, RenderTextureFormat.ARGB32) { antiAliasing = 8 };
            var image = new Texture2D(size, size, TextureFormat.RGB24, false);
            var previousTarget = camera.targetTexture;
            var previousActive = RenderTexture.active;
            try
            {
                QualitySettings.antiAliasing = 8;
                Shader.WarmupAllShaders();
                camera.targetTexture = renderTexture;
                camera.Render();
                RenderTexture.active = renderTexture;
                image.ReadPixels(new Rect(0, 0, size, size), 0, 0);
                image.Apply(false, false);

                var output = Environment.GetEnvironmentVariable("UNITY_PREVIEW_OUTPUT");
                if (string.IsNullOrWhiteSpace(output)) output = "Output/unity-processed-preview.png";
                output = Path.GetFullPath(output);
                Directory.CreateDirectory(Path.GetDirectoryName(output) ?? ".");
                File.WriteAllBytes(output, image.EncodeToPNG());
                Debug.Log($"Processed avatar play-mode preview written to {output}");
            }
            finally
            {
                camera.targetTexture = previousTarget;
                RenderTexture.active = previousActive;
                UnityEngine.Object.DestroyImmediate(image);
                renderTexture.Release();
                UnityEngine.Object.DestroyImmediate(renderTexture);
            }
        }
    }
}

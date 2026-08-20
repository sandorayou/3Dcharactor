using System;
using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

namespace RealtimeBodyTracking.Editor
{
    public static class RenderProcessedAvatarPreview
    {
        public static void Render()
        {
            EditorSceneManager.OpenScene("Assets/Scenes/SampleScene.unity", OpenSceneMode.Single);
            AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);

            var renderers = UnityEngine.Object.FindObjectsOfType<Renderer>();
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

            foreach (var effect in camera.GetComponents<AnimeLinePostEffect>()) effect.enabled = false;

            const int size = 1024;
            var renderTexture = new RenderTexture(size, size, 24, RenderTextureFormat.ARGB32)
            {
                antiAliasing = 8
            };
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
                Debug.Log($"Processed avatar preview written to {output}");
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

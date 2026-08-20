using UnityEngine;

namespace RealtimeBodyTracking
{
    [ExecuteAlways]
    [RequireComponent(typeof(Camera))]
    public sealed class AnimeLinePostEffect : MonoBehaviour
    {
        private static readonly int LineColorId = Shader.PropertyToID("_LineColor");
        private static readonly int ThicknessId = Shader.PropertyToID("_Thickness");
        private static readonly int ThresholdId = Shader.PropertyToID("_Threshold");
        private static readonly int SoftnessId = Shader.PropertyToID("_Softness");
        private static readonly int StrengthId = Shader.PropertyToID("_Strength");

        private Material material;
        private float thickness = 1f;
        private float threshold = .115f;
        private float softness = .07f;
        private float strength = .82f;
        private Color lineColor = new Color(.008f, .01f, .016f, .92f);

        public void Configure(float newThickness, float newThreshold, float newSoftness,
            float newStrength, Color newLineColor)
        {
            thickness = Mathf.Max(.25f, newThickness);
            threshold = Mathf.Clamp01(newThreshold);
            softness = Mathf.Max(.001f, newSoftness);
            strength = Mathf.Clamp01(newStrength);
            lineColor = newLineColor;
        }

        private void OnDisable()
        {
            if (material == null) return;
            if (Application.isPlaying) Destroy(material);
            else DestroyImmediate(material);
            material = null;
        }

        private void OnRenderImage(RenderTexture source, RenderTexture destination)
        {
            if (!EnsureMaterial())
            {
                Graphics.Blit(source, destination);
                return;
            }
            material.SetColor(LineColorId, lineColor);
            material.SetFloat(ThicknessId, thickness);
            material.SetFloat(ThresholdId, threshold);
            material.SetFloat(SoftnessId, softness);
            material.SetFloat(StrengthId, strength);
            Graphics.Blit(source, destination, material);
        }

        private bool EnsureMaterial()
        {
            if (material != null) return true;
            var shader = Resources.Load<Shader>("AnimeLinePostEffect");
            if (shader == null || !shader.isSupported) return false;
            material = new Material(shader) { hideFlags = HideFlags.HideAndDontSave };
            return true;
        }
    }
}

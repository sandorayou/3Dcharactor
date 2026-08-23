using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;

namespace RealtimeBodyTracking
{
    /// <summary>Fades a runtime copy of the avatar materials without modifying imported assets.</summary>
    internal sealed class AvatarVisibilityFader
    {
        private sealed class RendererState
        {
            public Renderer Renderer;
            public Material[] OriginalMaterials;
            public Material[] FadeMaterials;
            public Color[] BaseColors;
        }

        private readonly List<RendererState> states = new();
        private float opacity = 1f;

        public void Initialize(Animator animator)
        {
            Dispose();
            if (animator == null) return;

            foreach (var renderer in animator.GetComponentsInChildren<Renderer>(true))
            {
                var originals = renderer.sharedMaterials;
                var copies = new Material[originals.Length];
                var colors = new Color[originals.Length];
                for (var i = 0; i < originals.Length; i++)
                {
                    var original = originals[i];
                    if (original == null) continue;
                    var copy = new Material(original) { name = original.name + " (Tracking Fade)" };
                    ConfigureTransparent(copy);
                    copies[i] = copy;
                    colors[i] = copy.HasProperty("_Color") ? copy.GetColor("_Color") : Color.white;
                }
                renderer.sharedMaterials = copies;
                states.Add(new RendererState
                {
                    Renderer = renderer,
                    OriginalMaterials = originals,
                    FadeMaterials = copies,
                    BaseColors = colors,
                });
            }
        }

        public void Update(bool visible, float fadeInSeconds, float fadeOutSeconds, float deltaTime)
        {
            var duration = visible ? fadeInSeconds : fadeOutSeconds;
            var target = visible ? 1f : 0f;
            opacity = duration <= 0f ? target : Mathf.MoveTowards(opacity, target, deltaTime / duration);

            foreach (var state in states)
            {
                if (state.Renderer == null) continue;
                state.Renderer.enabled = opacity > .001f;
                for (var i = 0; i < state.FadeMaterials.Length; i++)
                {
                    var material = state.FadeMaterials[i];
                    if (material == null || !material.HasProperty("_Color")) continue;
                    var color = state.BaseColors[i];
                    color.a *= opacity;
                    material.SetColor("_Color", color);
                }
            }
        }

        public void Dispose()
        {
            foreach (var state in states)
            {
                if (state.Renderer != null) state.Renderer.sharedMaterials = state.OriginalMaterials;
                foreach (var material in state.FadeMaterials)
                    if (material != null) Object.Destroy(material);
            }
            states.Clear();
            opacity = 1f;
        }

        private static void ConfigureTransparent(Material material)
        {
            if (material.HasProperty("_BlendMode")) material.SetFloat("_BlendMode", 3f);
            if (material.HasProperty("_SrcBlend")) material.SetInt("_SrcBlend", (int)BlendMode.SrcAlpha);
            if (material.HasProperty("_DstBlend")) material.SetInt("_DstBlend", (int)BlendMode.OneMinusSrcAlpha);
            if (material.HasProperty("_ZWrite")) material.SetInt("_ZWrite", 1);
            if (material.HasProperty("_AlphaToMask")) material.SetInt("_AlphaToMask", 0);
            material.SetOverrideTag("RenderType", "Transparent");
            material.DisableKeyword("_ALPHATEST_ON");
            material.EnableKeyword("_ALPHABLEND_ON");
            material.DisableKeyword("_ALPHAPREMULTIPLY_ON");
            material.renderQueue = (int)RenderQueue.Transparent;
        }
    }
}

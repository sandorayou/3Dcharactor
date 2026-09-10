using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Controls only the local Unity avatar renderers. It does not stop streaming
    /// or change the native camera source used by the iOS publisher.
    public sealed class LocalAvatarVisibilityController : MonoBehaviour
    {
        [SerializeField] private GameObject avatarRoot;
        [SerializeField] private bool visible = true;
        private Renderer[] renderers = new Renderer[0];

        public bool IsVisible => visible;

        private void Awake()
        {
            if (avatarRoot == null) avatarRoot = GameObject.Find("h");
            RefreshRenderers();
            Apply();
        }

        public void ToggleVisibility()
        {
            visible = !visible;
            Apply();
        }

        public void SetVisible(bool value)
        {
            visible = value;
            Apply();
        }

        private void RefreshRenderers()
        {
            renderers = avatarRoot == null ? new Renderer[0] : avatarRoot.GetComponentsInChildren<Renderer>(true);
        }

        private void Apply()
        {
            if (renderers == null || renderers.Length == 0) RefreshRenderers();
            foreach (var renderer in renderers)
                if (renderer != null) renderer.enabled = visible;
        }
    }
}

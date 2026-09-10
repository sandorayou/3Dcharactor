using UnityEngine;
using UnityEngine.UI;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Creates an always-on-top emergency stop control when attached to the
    /// streaming root. The control is Unity UI and is never captured by the
    /// native camera publisher.
    public sealed class LiveStreamSafetyOverlay : MonoBehaviour
    {
        [SerializeField] private LiveStreamingController controller;
        [SerializeField] private string label = "配信停止";

        private void Awake()
        {
            if (controller == null) controller = GetComponent<LiveStreamingController>();
            var canvasObject = new GameObject("LiveStreamSafetyCanvas");
            canvasObject.transform.SetParent(transform, false);
            var canvas = canvasObject.AddComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = 10000;
            canvasObject.AddComponent<CanvasScaler>();
            canvasObject.AddComponent<GraphicRaycaster>();

            var buttonObject = new GameObject("EmergencyStopButton");
            buttonObject.transform.SetParent(canvasObject.transform, false);
            var rect = buttonObject.AddComponent<RectTransform>();
            rect.anchorMin = new Vector2(1, 0); rect.anchorMax = new Vector2(1, 0);
            rect.pivot = new Vector2(1, 0); rect.anchoredPosition = new Vector2(-24, 24);
            rect.sizeDelta = new Vector2(220, 72);
            var image = buttonObject.AddComponent<Image>(); image.color = new Color(0.75f, 0.05f, 0.05f, 0.95f);
            var button = buttonObject.AddComponent<Button>(); button.onClick.AddListener(StopNow);
            var text = new GameObject("Label").AddComponent<Text>();
            text.transform.SetParent(buttonObject.transform, false); text.text = label;
            text.alignment = TextAnchor.MiddleCenter; text.color = Color.white; text.fontSize = 28; text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            text.rectTransform.anchorMin = Vector2.zero; text.rectTransform.anchorMax = Vector2.one;
            text.rectTransform.offsetMin = Vector2.zero; text.rectTransform.offsetMax = Vector2.zero;

            var muteObject = new GameObject("MuteButton");
            muteObject.transform.SetParent(canvasObject.transform, false);
            var muteRect = muteObject.AddComponent<RectTransform>();
            muteRect.anchorMin = new Vector2(1, 0); muteRect.anchorMax = new Vector2(1, 0);
            muteRect.pivot = new Vector2(1, 0); muteRect.anchoredPosition = new Vector2(-260, 24);
            muteRect.sizeDelta = new Vector2(220, 72);
            var muteImage = muteObject.AddComponent<Image>(); muteImage.color = new Color(0.12f, 0.12f, 0.12f, 0.95f);
            var muteButton = muteObject.AddComponent<Button>(); muteButton.onClick.AddListener(() => controller?.ToggleMute());
            var muteText = new GameObject("Label").AddComponent<Text>();
            muteText.transform.SetParent(muteObject.transform, false); muteText.text = "ミュート／解除";
            muteText.alignment = TextAnchor.MiddleCenter; muteText.color = Color.white; muteText.fontSize = 24; muteText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            muteText.rectTransform.anchorMin = Vector2.zero; muteText.rectTransform.anchorMax = Vector2.one;
            muteText.rectTransform.offsetMin = Vector2.zero; muteText.rectTransform.offsetMax = Vector2.zero;
        }

        private void StopNow() => controller?.StopStreaming();
    }
}

using UnityEngine;
using UnityEngine.UI;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Minimal OBS-like runtime panel. Attach this to the same object as the
    /// streaming controller; its controls are screen UI and are not captured.
    public sealed class LiveStreamControlPanel : MonoBehaviour
    {
        [SerializeField] private LiveStreamingController controller;
        [SerializeField] private LiveStreamAccountLinkController accountLink;
        [SerializeField] private YouTubeAccountLinkController youtubeLink;
        [SerializeField] private LiveStreamSettingsController settingsController;
        private Text status;
        private InputField ingestUrl;
        private InputField streamKey;
        private LiveStreamProvider selected = LiveStreamProvider.Twitch;

        private void Awake()
        {
            controller ??= GetComponent<LiveStreamingController>();
            accountLink ??= GetComponent<LiveStreamAccountLinkController>();
            youtubeLink ??= GetComponent<YouTubeAccountLinkController>();
            settingsController ??= GetComponent<LiveStreamSettingsController>();
            var canvasObject = new GameObject("LiveStreamControlCanvas");
            canvasObject.transform.SetParent(transform, false);
            var canvas = canvasObject.AddComponent<Canvas>(); canvas.renderMode = RenderMode.ScreenSpaceOverlay; canvas.sortingOrder = 9999;
            canvasObject.AddComponent<CanvasScaler>(); canvasObject.AddComponent<GraphicRaycaster>();
            var panel = new GameObject("Panel"); panel.transform.SetParent(canvasObject.transform, false);
            var panelRect = panel.AddComponent<RectTransform>(); panelRect.anchorMin = new Vector2(0, 1); panelRect.anchorMax = new Vector2(0, 1); panelRect.pivot = new Vector2(0, 1); panelRect.anchoredPosition = new Vector2(24, -24); panelRect.sizeDelta = new Vector2(360, 360);
            panel.AddComponent<Image>().color = new Color(0.04f, 0.04f, 0.06f, 0.94f);
            var layout = panel.AddComponent<VerticalLayoutGroup>(); layout.padding = new RectOffset(18, 18, 18, 18); layout.spacing = 8; layout.childForceExpandHeight = false;
            status = AddLabel(panel.transform, "配信先: Twitch / 待機中", 24);
            AddLabel(panel.transform, "手動設定（ニコニコ等）", 16);
            ingestUrl = AddInput(panel.transform, "配信URL");
            streamKey = AddInput(panel.transform, "配信キー");
            AddButton(panel.transform, "URL・キーを保存", SaveManualAccount);
            AddButton(panel.transform, "Twitch", () => Select(LiveStreamProvider.Twitch));
            AddButton(panel.transform, "YouTube", () => Select(LiveStreamProvider.YouTube));
            AddButton(panel.transform, "ニコニコ", () => Select(LiveStreamProvider.Niconico));
            AddButton(panel.transform, "アカウント連携／登録", LinkSelected);
            AddButton(panel.transform, "縦配信", () => controller?.SetOrientation(LiveStreamOrientation.Portrait));
            AddButton(panel.transform, "横配信", () => controller?.SetOrientation(LiveStreamOrientation.Landscape));
            AddButton(panel.transform, "配信開始", Start);
            AddButton(panel.transform, "ミュート／解除", () => controller?.ToggleMute());
            AddButton(panel.transform, "カメラ切替", () => controller?.ToggleCamera());
            AddButton(panel.transform, "配信停止", Stop);
        }

        private void Select(LiveStreamProvider provider) { selected = provider; controller?.LoadSavedAccount(provider); if (status) status.text = "配信先: " + provider + " / 待機中"; }
        private void LinkSelected() { if (selected == LiveStreamProvider.Twitch) accountLink?.LinkTwitch(); else if (selected == LiveStreamProvider.YouTube) youtubeLink?.LinkYouTube(); }
        private void SaveManualAccount() { if (settingsController == null || ingestUrl == null || streamKey == null) return; settingsController.SaveAccount(selected, selected.ToString(), ingestUrl.text, streamKey.text); controller?.Configure(selected, ingestUrl.text, streamKey.text); if (status) status.text = "配信先: " + selected + " / 保存済み"; }
        private void Start() { if (controller != null && controller.StartStreaming() && status) status.text = "配信先: " + selected + " / 配信中"; }
        private void Stop() { controller?.StopStreaming(); if (status) status.text = "配信先: " + selected + " / 停止"; }

        private static Text AddLabel(Transform parent, string value, int size) { var text = new GameObject("Status").AddComponent<Text>(); text.transform.SetParent(parent, false); text.text = value; text.fontSize = size; text.color = Color.white; text.alignment = TextAnchor.MiddleLeft; text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf"); return text; }
        private static InputField AddInput(Transform parent, string placeholder) { var obj = new GameObject(placeholder); obj.transform.SetParent(parent, false); obj.AddComponent<LayoutElement>().preferredHeight = 42; obj.AddComponent<Image>().color = Color.white; var input = obj.AddComponent<InputField>(); var text = new GameObject("Text").AddComponent<Text>(); text.transform.SetParent(obj.transform, false); text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf"); text.color = Color.black; text.fontSize = 18; text.rectTransform.anchorMin = Vector2.zero; text.rectTransform.anchorMax = Vector2.one; text.rectTransform.offsetMin = new Vector2(10, 0); text.rectTransform.offsetMax = new Vector2(-10, 0); input.textComponent = text; input.placeholder = AddLabel(obj.transform, placeholder, 18); input.placeholder.color = Color.gray; return input; }
        private static void AddButton(Transform parent, string label, UnityEngine.Events.UnityAction action) { var obj = new GameObject(label); obj.transform.SetParent(parent, false); obj.AddComponent<LayoutElement>().preferredHeight = 42; obj.AddComponent<Image>().color = new Color(0.18f, 0.18f, 0.22f, 1); var button = obj.AddComponent<Button>(); button.onClick.AddListener(action); var text = AddLabel(obj.transform, label, 20); text.alignment = TextAnchor.MiddleCenter; text.rectTransform.anchorMin = Vector2.zero; text.rectTransform.anchorMax = Vector2.one; text.rectTransform.offsetMin = Vector2.zero; text.rectTransform.offsetMax = Vector2.zero; }
    }
}

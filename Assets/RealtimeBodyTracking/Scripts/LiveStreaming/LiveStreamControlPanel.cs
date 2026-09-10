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
        [SerializeField] private LocalAvatarVisibilityController avatarVisibility;
        [SerializeField] private LiveCommentsController commentsController;
        private Text status;
        private InputField ingestUrl;
        private InputField streamKey;
        private LiveStreamProvider selected = LiveStreamProvider.Twitch;
        private GameObject settingsRoot;
        private GameObject commentsRoot;

        private void Awake()
        {
            controller ??= GetComponent<LiveStreamingController>();
            accountLink ??= GetComponent<LiveStreamAccountLinkController>();
            youtubeLink ??= GetComponent<YouTubeAccountLinkController>();
            settingsController ??= GetComponent<LiveStreamSettingsController>();
            avatarVisibility ??= GetComponent<LocalAvatarVisibilityController>();
            if (avatarVisibility == null) avatarVisibility = gameObject.AddComponent<LocalAvatarVisibilityController>();
            commentsController ??= GetComponent<LiveCommentsController>();
            if (commentsController == null) commentsController = gameObject.AddComponent<LiveCommentsController>();
            var canvasObject = new GameObject("LiveStreamControlCanvas");
            canvasObject.transform.SetParent(transform, false);
            var canvas = canvasObject.AddComponent<Canvas>(); canvas.renderMode = RenderMode.ScreenSpaceOverlay; canvas.sortingOrder = 9999;
            canvasObject.AddComponent<CanvasScaler>(); canvasObject.AddComponent<GraphicRaycaster>();
            var panel = new GameObject("Panel"); panel.transform.SetParent(canvasObject.transform, false);
            var panelRect = panel.AddComponent<RectTransform>(); panelRect.anchorMin = new Vector2(0, 1); panelRect.anchorMax = new Vector2(0, 1); panelRect.pivot = new Vector2(0, 1); panelRect.anchoredPosition = new Vector2(24, -24); panelRect.sizeDelta = new Vector2(420, 520);
            panel.AddComponent<Image>().color = new Color(0.04f, 0.04f, 0.06f, 0.94f);
            var layout = panel.AddComponent<VerticalLayoutGroup>(); layout.padding = new RectOffset(18, 18, 18, 18); layout.spacing = 8; layout.childForceExpandHeight = false;
            status = AddLabel(panel.transform, "配信先: Twitch / 待機中", 24);
            var toolbar = new GameObject("LiveControls"); toolbar.transform.SetParent(panel.transform, false); var toolbarLayout = toolbar.AddComponent<HorizontalLayoutGroup>(); toolbarLayout.spacing = 6; toolbarLayout.childForceExpandWidth = true; toolbar.AddComponent<LayoutElement>().preferredHeight = 48;
            AddButton(toolbar.transform, "開始", Start); AddButton(toolbar.transform, "停止", Stop); AddButton(toolbar.transform, "ミュート", () => controller?.ToggleMute()); AddButton(toolbar.transform, "カメラ", () => controller?.ToggleCamera()); AddButton(toolbar.transform, "キャラ", ToggleAvatarVisibility);
            AddButton(panel.transform, "コメントを表示／閉じる", ToggleComments);
            AddButton(panel.transform, "配信設定を開く／閉じる", ToggleSettings);
            settingsRoot = new GameObject("StreamingSettings"); settingsRoot.transform.SetParent(panel.transform, false); var settingsLayout = settingsRoot.AddComponent<VerticalLayoutGroup>(); settingsLayout.spacing = 6; settingsLayout.childForceExpandHeight = false;
            AddLabel(settingsRoot.transform, "配信設定", 16);
            ingestUrl = AddInput(settingsRoot.transform, "配信URL"); streamKey = AddInput(settingsRoot.transform, "配信キー"); AddButton(settingsRoot.transform, "URL・キーを保存", SaveManualAccount);
            var providers = new GameObject("Providers"); providers.transform.SetParent(settingsRoot.transform, false); var providerLayout = providers.AddComponent<HorizontalLayoutGroup>(); providerLayout.spacing = 6; providerLayout.childForceExpandWidth = true;
            AddButton(providers.transform, "Twitch", () => Select(LiveStreamProvider.Twitch)); AddButton(providers.transform, "YouTube", () => Select(LiveStreamProvider.YouTube)); AddButton(providers.transform, "ニコニコ", () => Select(LiveStreamProvider.Niconico));
            AddButton(settingsRoot.transform, "アカウント連携／登録", LinkSelected); AddButton(settingsRoot.transform, "縦配信", () => controller?.SetOrientation(LiveStreamOrientation.Portrait)); AddButton(settingsRoot.transform, "横配信", () => controller?.SetOrientation(LiveStreamOrientation.Landscape));
            commentsRoot = new GameObject("LocalComments"); commentsRoot.transform.SetParent(panel.transform, false); commentsRoot.AddComponent<Image>().color = new Color(0.1f, 0.1f, 0.14f, 0.96f); commentsRoot.AddComponent<LayoutElement>().preferredHeight = 150;
            AddLabel(commentsRoot.transform, "コメント", 18); AddLabel(commentsRoot.transform, "Twitch／YouTubeのコメントをここに表示します。\n配信映像には表示されません。", 16);
            settingsRoot.SetActive(false); commentsRoot.SetActive(false);
        }

        private void Select(LiveStreamProvider provider) { selected = provider; controller?.LoadSavedAccount(provider); if (status) status.text = "配信先: " + provider + " / 待機中"; }
        private void LinkSelected() { if (selected == LiveStreamProvider.Twitch) accountLink?.LinkTwitch(); else if (selected == LiveStreamProvider.YouTube) youtubeLink?.LinkYouTube(); }
        private void SaveManualAccount() { if (settingsController == null || ingestUrl == null || streamKey == null) return; settingsController.SaveAccount(selected, selected.ToString(), ingestUrl.text, streamKey.text); controller?.Configure(selected, ingestUrl.text, streamKey.text); if (status) status.text = "配信先: " + selected + " / 保存済み"; }
        private void Start() { if (controller != null && controller.StartStreaming() && status) status.text = "配信先: " + selected + " / 配信中"; }
        private void Stop() { controller?.StopStreaming(); if (status) status.text = "配信先: " + selected + " / 停止"; }
        private void ToggleAvatarVisibility() { avatarVisibility?.ToggleVisibility(); if (status) status.text = avatarVisibility != null && avatarVisibility.IsVisible ? "キャラ: 表示" : "キャラ: 非表示"; }
        private void ToggleSettings() { if (settingsRoot != null) settingsRoot.SetActive(!settingsRoot.activeSelf); }
        private void ToggleComments()
        {
            if (commentsRoot == null) return;
            var visible = !commentsRoot.activeSelf;
            commentsRoot.SetActive(visible);
            if (visible) commentsController?.StartReceiving(selected, commentsRoot.transform);
            else commentsController?.StopReceiving();
        }

        private static Text AddLabel(Transform parent, string value, int size) { var text = new GameObject("Status").AddComponent<Text>(); text.transform.SetParent(parent, false); text.text = value; text.fontSize = size; text.color = Color.white; text.alignment = TextAnchor.MiddleLeft; text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf"); return text; }
        private static InputField AddInput(Transform parent, string placeholder) { var obj = new GameObject(placeholder); obj.transform.SetParent(parent, false); obj.AddComponent<LayoutElement>().preferredHeight = 42; obj.AddComponent<Image>().color = Color.white; var input = obj.AddComponent<InputField>(); var text = new GameObject("Text").AddComponent<Text>(); text.transform.SetParent(obj.transform, false); text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf"); text.color = Color.black; text.fontSize = 18; text.rectTransform.anchorMin = Vector2.zero; text.rectTransform.anchorMax = Vector2.one; text.rectTransform.offsetMin = new Vector2(10, 0); text.rectTransform.offsetMax = new Vector2(-10, 0); input.textComponent = text; input.placeholder = AddLabel(obj.transform, placeholder, 18); input.placeholder.color = Color.gray; return input; }
        private static void AddButton(Transform parent, string label, UnityEngine.Events.UnityAction action) { var obj = new GameObject(label); obj.transform.SetParent(parent, false); obj.AddComponent<LayoutElement>().preferredHeight = 42; obj.AddComponent<Image>().color = new Color(0.18f, 0.18f, 0.22f, 1); var button = obj.AddComponent<Button>(); button.onClick.AddListener(action); var text = AddLabel(obj.transform, label, 20); text.alignment = TextAnchor.MiddleCenter; text.rectTransform.anchorMin = Vector2.zero; text.rectTransform.anchorMax = Vector2.one; text.rectTransform.offsetMin = Vector2.zero; text.rectTransform.offsetMax = Vector2.zero; }
    }
}

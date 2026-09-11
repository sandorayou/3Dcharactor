using UnityEngine;

namespace RealtimeBodyTracking
{
    /// Device-only diagnostic panel. It is deliberately independent from the
    /// streaming UI so tracking can be debugged with streaming disabled.
    public sealed class IOSDebugOverlay : MonoBehaviour
    {
        private bool visible = true;
        private Vector2 scroll;
        private GUIStyle textStyle;

        private void Awake()
        {
            DontDestroyOnLoad(gameObject);
        }

        private void OnGUI()
        {
            if (!visible) {
                if (GUI.Button(new Rect(12, 12, 150, 52), "ログ表示")) visible = true;
                return;
            }

            if (textStyle == null)
                textStyle = new GUIStyle(GUI.skin.label) { fontSize = 22, wordWrap = true };
            var width = Mathf.Min(Screen.width - 24, 900);
            var height = Mathf.Min(Screen.height * .42f, 620);
            GUILayout.BeginArea(new Rect(12, 12, width, height), GUI.skin.box);
            GUILayout.BeginHorizontal();
            GUILayout.Label("iPhone Tracking Log", textStyle);
            if (GUILayout.Button("閉じる", GUILayout.Width(110), GUILayout.Height(44))) visible = false;
            GUILayout.EndHorizontal();
            scroll = GUILayout.BeginScrollView(scroll, GUI.skin.box);
            GUILayout.Label(RuntimeLogCapture.GetText(), textStyle);
            GUILayout.EndScrollView();
            GUILayout.EndArea();
        }
    }

    internal static class IOSDebugOverlayBootstrap
    {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
#if UNITY_IOS && !UNITY_EDITOR
            if (Object.FindObjectOfType<RuntimeLogCapture>() == null)
                new GameObject("RuntimeLogCapture").AddComponent<RuntimeLogCapture>();
            if (Object.FindObjectOfType<IOSDebugOverlay>() == null)
                new GameObject("IOSDebugOverlay").AddComponent<IOSDebugOverlay>();
#endif
        }
    }
}

using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking
{
    // Native settings keep stream keys out of Unity UI, logs and PlayerPrefs.
    public sealed class IOSLiveStreaming : MonoBehaviour
    {
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern void MyProjectShowLiveStreaming(string receiver);
        [DllImport("__Internal")] private static extern void MyProjectStopLiveStreaming();
#endif
        [Serializable] private sealed class State { public bool active; public string summary; }
        private bool active;
        private string summary = "";

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
#if UNITY_IOS && !UNITY_EDITOR
            var host = new GameObject("IOSLiveStreaming");
            DontDestroyOnLoad(host);
            host.AddComponent<IOSLiveStreaming>();
#endif
        }

        [UnityEngine.Scripting.Preserve]
        public void OnLiveStreamingState(string json)
        {
            var state = JsonUtility.FromJson<State>(json);
            active = state.active;
            summary = state.summary;
        }

        private void OnGUI()
        {
#if UNITY_IOS && !UNITY_EDITOR
            if (GUI.Button(new Rect(16, 76, 180, 48), active ? "配信終了" : "ライブ配信"))
            {
                if (active) MyProjectStopLiveStreaming();
                else MyProjectShowLiveStreaming(gameObject.name);
            }
            if (!string.IsNullOrEmpty(summary)) GUI.Label(new Rect(16, 130, Screen.width - 32, 65), summary);
#endif
        }

        // Native didEnterBackground stops capture; transient permission dialogs
        // must not cancel a pending microphone/ReplayKit permission request.
        private void OnDisable() { Stop(); }
        private void Stop()
        {
#if UNITY_IOS && !UNITY_EDITOR
            MyProjectStopLiveStreaming();
#endif
        }
    }
}

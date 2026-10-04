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
            // Reserve the upper fifth for local controls; ReplayKit crops it.
            foreach (var camera in Camera.allCameras)
            {
                var rect = camera.rect;
                camera.rect = new Rect(rect.x, rect.y * .8f, rect.width, rect.height * .8f);
            }
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
            var previousMatrix = GUI.matrix;
            // A fixed logical toolbar fits every phone and orientation.
            GUI.matrix = Matrix4x4.Scale(new Vector3(Screen.width / 600f, Screen.height * .2f / 120f, 1));
            if (GUI.Button(new Rect(16, 12, 180, 48), active ? "配信終了" : "配信開始"))
            {
                if (active) MyProjectStopLiveStreaming();
                else MyProjectShowLiveStreaming(gameObject.name);
            }
            if (!string.IsNullOrEmpty(summary)) GUI.Label(new Rect(210, 12, 374, 96), summary);
            GUI.matrix = previousMatrix;
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

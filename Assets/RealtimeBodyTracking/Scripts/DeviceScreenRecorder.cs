using System.Runtime.InteropServices;
using UnityEngine;
namespace RealtimeBodyTracking
{
    public sealed class DeviceScreenRecorder : MonoBehaviour
    {
        public bool IsRecording { get; private set; }
        public bool StartRecording() { if (IsRecording) return true; IsRecording = NativeStartRecording() == 0; Debug.Log(IsRecording ? "[Recorder] started" : "[Recorder] unavailable"); return IsRecording; }
        public void StopRecording() { if (!IsRecording) return; NativeStopRecording(); IsRecording = false; Debug.Log("[Recorder] stopped; saved to Photos"); }
        private void OnApplicationPause(bool paused) { if (paused) StopRecording(); } private void OnDestroy() { StopRecording(); }
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativeStartRecording(); [DllImport("__Internal")] private static extern void NativeStopRecording();
#else
        private static int NativeStartRecording() => -1; private static void NativeStopRecording() { }
#endif
    }
}

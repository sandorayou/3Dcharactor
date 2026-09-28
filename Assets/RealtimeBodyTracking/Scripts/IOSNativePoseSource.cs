using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking
{
    /// Native iOS front-camera body pose source.
    [DisallowMultipleComponent]
    public sealed class IOSNativePoseSource : MonoBehaviour, LocalPosePacketSource
    {
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativePoseCaptureStart(string unityObjectName);
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetPaused(int paused);
        [DllImport("__Internal")] private static extern void NativePoseCaptureStop();
#endif
        private PosePacket latest;

        public void OnNativePoseJson(string json)
        {
            AcceptPoseJson(json);
        }

        private void AcceptPoseJson(string json)
        {
            if (string.IsNullOrEmpty(json)) return;
            try { latest = JsonUtility.FromJson<PosePacket>(json); }
            catch (System.ArgumentException error) { Debug.LogError("[Tracking] Invalid packet: " + error.Message, this); return; }
        }

        public void OnNativeCameraPermissionGranted(string ignored)
        {
#if UNITY_IOS && !UNITY_EDITOR
            if (!isActiveAndEnabled) return;
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0) Debug.LogError($"Native iOS camera start failed after permission: {result}", this);
#endif
        }

        public bool TryTakeLatest(out PosePacket packet)
        {
            packet = latest;
            latest = null;
            return packet != null;
        }

        // Compatibility for unused legacy streaming scripts; this app keeps the front camera fixed.
        public void SetFrontCamera(bool front) { }

        private void OnEnable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            var camera = Camera.main;
            if (camera != null)
            {
                camera.clearFlags = CameraClearFlags.SolidColor;
                camera.backgroundColor = Color.clear;
            }
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0 && result != 1 && result != -6) Debug.LogError($"Native iOS camera start failed: {result}", this);
#endif
        }

        private void OnDisable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureStop();
#endif
        }

        private void OnApplicationPause(bool paused)
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureSetPaused(paused ? 1 : 0);
#endif
        }
    }
}

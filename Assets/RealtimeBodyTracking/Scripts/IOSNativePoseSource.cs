using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking
{
    /// Native iOS camera/inference source contract.
    /// MediaPipe result decoding will be added after the AVFoundation hand-off
    /// is verified on a device.
    [DisallowMultipleComponent]
    public sealed class IOSNativePoseSource : MonoBehaviour, LocalPosePacketSource
    {
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativePoseCaptureStart(string unityObjectName);
        [DllImport("__Internal")] private static extern void NativePoseCaptureStop();
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetPaused(int paused);
#endif
        private PosePacket latest;

        public void OnNativePoseJson(string json)
        {
            if (!string.IsNullOrEmpty(json)) latest = JsonUtility.FromJson<PosePacket>(json);
        }

        public void OnNativeCameraPermissionGranted(string ignored)
        {
#if UNITY_IOS && !UNITY_EDITOR
            if (!isActiveAndEnabled) return;
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0) Debug.LogError($"Native iOS camera start failed after permission: {result}", this);
#endif
        }

        public void OnNativeCameraState(string state)
        {
            Debug.Log("[NativeCamera] " + state, this);
        }

        public bool TryTakeLatest(out PosePacket packet)
        {
            packet = latest;
            latest = null;
            return packet != null;
        }

        private void OnEnable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            var camera = Camera.main;
            if (camera != null)
            {
                camera.clearFlags = CameraClearFlags.SolidColor;
                var color = camera.backgroundColor;
                color.a = 0f;
                camera.backgroundColor = color;
            }
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0 && result != -6) Debug.LogError($"Native iOS camera start failed: {result}", this);
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

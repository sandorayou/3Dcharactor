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
#endif
        private PosePacket latest;

        public void OnNativePoseJson(string json)
        {
            if (!string.IsNullOrEmpty(json)) latest = JsonUtility.FromJson<PosePacket>(json);
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
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0) Debug.LogError($"Native iOS camera start failed: {result}", this);
#endif
        }

        private void OnDisable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureStop();
#endif
        }
    }
}

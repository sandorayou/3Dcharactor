using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking
{
    /// Feeds the common Windows avatar solver with on-device Pose/Hand/Face packets.
    [DisallowMultipleComponent]
    public sealed class IOSNativePoseSource : MonoBehaviour, LocalPosePacketSource
    {
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativePoseCaptureStart(string receiver);
        [DllImport("__Internal")] private static extern void NativePoseCaptureStop();
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetPaused(int paused);
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetFrontCamera(int front);
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetMosaicScale(float scale);
#endif
        private PosePacket latest;
        private long latestTimestampMs = -1;
        private IOSAvatarGaze gaze;
        private void OnEnable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            gaze = GetComponent<IOSAvatarGaze>() ?? gameObject.AddComponent<IOSAvatarGaze>();
            var camera = Camera.main;
            if (camera != null)
            {
                camera.clearFlags = CameraClearFlags.SolidColor;
                camera.backgroundColor = Color.clear;
                camera.allowHDR = false;
            }
            NativePoseCaptureSetFrontCamera(1);
            NativePoseCaptureSetMosaicScale(48f);
            StartCapture();
#endif
        }
        private void StartCapture()
        {
#if UNITY_IOS && !UNITY_EDITOR
            var result = NativePoseCaptureStart(gameObject.name);
            if (result != 0 && result != -6)
                Debug.LogError($"iOS camera/tracking initialization failed: {result}", this);
#endif
        }
        [UnityEngine.Scripting.Preserve]
        public void OnNativeCameraPermissionGranted(string unused) { if (isActiveAndEnabled) StartCapture(); }
        [UnityEngine.Scripting.Preserve]
        public void OnNativeCameraState(string state) { Debug.Log($"[iOS camera] {state}", this); }
        [UnityEngine.Scripting.Preserve]
        public void OnNativeCameraOrientationChanged(string unused)
        {
            latest = null;
            if (gaze != null) gaze.ResetNeutral();
            var driver = GetComponentInParent<HumanoidPoseDriver>();
            if (driver != null) driver.ResetCameraOrientationTracking();
        }
        [UnityEngine.Scripting.Preserve]
        public void OnNativePoseJson(string json)
        {
            if (!isActiveAndEnabled) return;
            try
            {
                var packet = JsonUtility.FromJson<PosePacket>(json);
                if (packet != null && packet.timestamp_ms > latestTimestampMs)
                {
                    latest = packet;
                    latestTimestampMs = packet.timestamp_ms;
                }
            }
            catch (System.ArgumentException exception) { Debug.LogWarning(exception.Message, this); }
        }
        public bool TryTakeLatest(out PosePacket packet)
        {
            packet = latest;
            latest = null;
            return packet != null;
        }
        private void OnApplicationPause(bool paused)
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureSetPaused(paused ? 1 : 0);
#endif
        }
        private void OnDisable()
        {
            latest = null;
            latestTimestampMs = -1;
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureStop();
#endif
        }
    }
}

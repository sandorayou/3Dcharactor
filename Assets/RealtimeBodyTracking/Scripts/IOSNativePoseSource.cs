using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking
{
    /// Native iOS camera/inference source contract.
    /// Receives combined native Pose/Hand/Face results on Unity's main thread.
    [DisallowMultipleComponent]
    public sealed class IOSNativePoseSource : MonoBehaviour, LocalPosePacketSource
    {
#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern int NativePoseCaptureStart(string unityObjectName);
        [DllImport("__Internal")] private static extern void NativePoseCaptureStop();
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetPaused(int paused);
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetFrontCamera(int front);
        [DllImport("__Internal")] private static extern void NativePoseCaptureSetMosaicScale(float scale);
#endif
        [SerializeField] private bool useFrontCamera = true;
        [SerializeField, Range(2f, 80f)] private float mosaicScale = 24f;
        private PosePacket latest;
        private float nextStatusLog;

        public void OnNativePoseJson(string json)
        {
            if (string.IsNullOrEmpty(json)) return;
            try { latest = JsonUtility.FromJson<PosePacket>(json); }
            catch (System.ArgumentException error) { Debug.LogError("[Tracking] Invalid packet: " + error.Message, this); return; }
            if (latest != null && Time.unscaledTime >= nextStatusLog)
            {
                nextStatusLog = Time.unscaledTime + 2f;
                Debug.Log($"[Tracking] frame={latest.frame} points={latest.points?.Count ?? 0} blendshapes={latest.face_blendshapes?.Count ?? 0}", this);
            }
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

        public void ToggleCamera()
        {
            SetFrontCamera(!useFrontCamera);
        }

        public void SetFrontCamera(bool front)
        {
            useFrontCamera = front;
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureSetFrontCamera(front ? 1 : 0);
#endif
            Debug.Log("[NativeCamera] selected=" + (front ? "front" : "rear"), this);
        }

        private void OnEnable()
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativePoseCaptureSetFrontCamera(useFrontCamera ? 1 : 0);
            NativePoseCaptureSetMosaicScale(mosaicScale);
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

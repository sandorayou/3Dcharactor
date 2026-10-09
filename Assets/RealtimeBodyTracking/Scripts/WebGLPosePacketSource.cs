using UnityEngine;
#if UNITY_WEBGL && !UNITY_EDITOR
using System.Runtime.InteropServices;
#endif

namespace RealtimeBodyTracking
{
    /// <summary>Receives the PosePacket JSON produced by the browser PWA.</summary>
    public sealed class WebGLPosePacketSource : MonoBehaviour, LocalPosePacketSource
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern void WebPwaSettings_SetAvatarStatus(string value);
#endif
        private readonly object sync = new object();
        private PosePacket latest;
        private WebVrmRuntimeLoader avatarLoader;
        private HumanoidPoseDriver poseDriver;
        private string lastAvatarStatus;

        private void Awake()
        {
            gameObject.name = "WebGLPosePacketSource";
            avatarLoader = GetComponent<WebVrmRuntimeLoader>() ?? gameObject.AddComponent<WebVrmRuntimeLoader>();
            poseDriver = FindObjectOfType<HumanoidPoseDriver>();
        }

        private void Update()
        {
#if UNITY_WEBGL && !UNITY_EDITOR
            var currentStatus = avatarLoader != null ? avatarLoader.Status : null;
            if (currentStatus == lastAvatarStatus) return;
            lastAvatarStatus = currentStatus;
            WebPwaSettings_SetAvatarStatus(currentStatus ?? string.Empty);
#endif
        }

        public void OpenAvatarPicker()
        {
            avatarLoader?.OpenFilePicker();
        }

        public void OnVrmFilePicked(string fileName)
        {
#if UNITY_WEBGL && !UNITY_EDITOR
            avatarLoader?.OnVrmFilePicked(fileName);
#endif
        }

        public void SetAnimeInternalLinesEnabled(string value)
        {
            var enabled = value == "1" || bool.TryParse(value, out var parsed) && parsed;
            if (poseDriver == null) poseDriver = FindObjectOfType<HumanoidPoseDriver>();
            poseDriver?.SetAnimeInternalLinesEnabled(enabled);
        }

        public void ReceivePoseJson(string json)
        {
            if (string.IsNullOrEmpty(json)) return;
            PosePacket packet;
            try { packet = JsonUtility.FromJson<PosePacket>(json); }
            catch { return; }
            if (packet == null || packet.version < 1) return;
            lock (sync) latest = packet;
        }

        public bool TryTakeLatest(out PosePacket packet)
        {
            lock (sync)
            {
                packet = latest;
                latest = null;
                return packet != null;
            }
        }
    }
}

using System.Collections;
using System.Collections.Generic;
using System.IO;
using Mediapipe;
using Mediapipe.Tasks.Vision.Core;
using Mediapipe.Tasks.Vision.PoseLandmarker;
using UnityEngine;

namespace RealtimeBodyTracking
{
    [DisallowMultipleComponent]
    public sealed class LocalMediaPipePoseSource : MonoBehaviour, LocalPosePacketSource
    {
        private static readonly string[] Names = { "nose", "left_eye_inner", "left_eye", "left_eye_outer", "right_eye_inner", "right_eye", "right_eye_outer", "left_ear", "right_ear", "mouth_left", "mouth_right", "left_shoulder", "right_shoulder", "left_elbow", "right_elbow", "left_wrist", "right_wrist", "left_pinky", "right_pinky", "left_index", "right_index", "left_thumb", "right_thumb", "left_hip", "right_hip", "left_knee", "right_knee", "left_ankle", "right_ankle", "left_heel", "right_heel", "left_foot_index", "right_foot_index" };
        [SerializeField] private int inputWidth = 640;
        [SerializeField] private int inputHeight = 480;
        [SerializeField] private float minimumVisibility = .35f;
        private PoseLandmarker landmarker;
        private Texture2D inputTexture;
        private PosePacket latest;
        private WebCamTexture cameraTexture;
        private long frame;

        private IEnumerator Start()
        {
#if UNITY_IOS || UNITY_ANDROID
            yield return new WaitUntil(() => TrackerVideoBackground.DeviceCamera != null && TrackerVideoBackground.DeviceCamera.width > 16);
            cameraTexture = TrackerVideoBackground.DeviceCamera;
            inputTexture = new Texture2D(inputWidth, inputHeight, TextureFormat.RGBA32, false);
            var modelPath = Path.Combine(Application.streamingAssetsPath, "pose_landmarker_full.bytes");
            if (!File.Exists(modelPath)) { Debug.LogError("MediaPipe pose model is missing: " + modelPath, this); enabled = false; yield break; }
            var options = new PoseLandmarkerOptions(new Mediapipe.Tasks.Core.BaseOptions(Mediapipe.Tasks.Core.BaseOptions.Delegate.CPU, modelAssetPath: modelPath), runningMode: Mediapipe.Tasks.Vision.Core.RunningMode.IMAGE, numPoses: 1, minPoseDetectionConfidence: .5f, minPosePresenceConfidence: .5f, minTrackingConfidence: .5f);
            landmarker = PoseLandmarker.CreateFromOptions(options);
#else
            enabled = false;
#endif
        }

        private void Update()
        {
            if (landmarker == null || cameraTexture == null || !cameraTexture.didUpdateThisFrame) return;
            inputTexture.SetPixels32(cameraTexture.GetPixels32());
            inputTexture.Apply(false, false);
            using (var image = new Image(inputTexture)) latest = Convert(landmarker.Detect(image), cameraTexture.width, cameraTexture.height);
        }

        public bool TryTakeLatest(out PosePacket packet) { packet = latest; latest = null; return packet != null; }

        private PosePacket Convert(PoseLandmarkerResult result, int width, int height)
        {
            var packet = new PosePacket { version = 4, frame = frame++, timestamp_ms = System.DateTimeOffset.UtcNow.ToUnixTimeMilliseconds(), source_width = width, source_height = height, points = new List<PosePoint>() };
            if (result.poseLandmarks == null || result.poseLandmarks.Count == 0 || result.poseLandmarks[0].landmarks == null) return packet;
            var normalized = result.poseLandmarks[0].landmarks;
            var world = result.poseWorldLandmarks != null && result.poseWorldLandmarks.Count > 0 ? result.poseWorldLandmarks[0].landmarks : null;
            for (var i = 0; i < normalized.Count && i < Names.Length; i++)
            {
                var n = normalized[i];
                var confidence = Mathf.Clamp01((n.visibility ?? 1f) * (n.presence ?? 1f));
                if (confidence < minimumVisibility) continue;
                var w = world != null && i < world.Count ? world[i] : default;
                packet.points.Add(new PosePoint { name = Names[i], x = w.x, y = w.y, z = w.z, confidence = confidence, image_x = n.x, image_y = n.y, image_z = n.z });
            }
            packet.tracking = packet.points.Count >= 4;
            return packet;
        }

        private void OnDestroy() { landmarker?.Close(); if (inputTexture != null) Destroy(inputTexture); }
    }
}

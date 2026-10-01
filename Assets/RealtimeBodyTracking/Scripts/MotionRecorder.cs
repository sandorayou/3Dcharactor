using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class MotionRecorder : MonoBehaviour
    {
        private static readonly HumanBodyBones[] AllBones = (HumanBodyBones[])Enum.GetValues(typeof(HumanBodyBones));
        private static readonly string[] BoneNames = Array.ConvertAll(AllBones, bone => bone.ToString());
        [SerializeField] private Animator targetAnimator;
        [SerializeField] private string outputFileName = "recording.motion.json";
        [SerializeField] private bool recordOnStart;

        [Serializable] private sealed class Frame { public float timestamp; public Vector3 hips; public bool tracking; public List<Rotation> rotations = new(); }
        [Serializable] private sealed class Rotation { public string bone; public Quaternion value; }
        [Serializable] private sealed class Recording { public List<Frame> frames = new(); }
        private readonly Recording recording = new();
        public bool IsRecording { get; private set; }

        private void Start()
        {
            if (targetAnimator == null) targetAnimator = GetComponentInChildren<Animator>();
            IsRecording = recordOnStart;
        }

        private void LateUpdate()
        {
            if (!IsRecording || targetAnimator == null) return;
            var frame = new Frame { timestamp = Time.time, tracking = true };
            var hips = targetAnimator.GetBoneTransform(HumanBodyBones.Hips);
            if (hips != null) frame.hips = hips.position;
            for (var index = 0; index < AllBones.Length; index++)
            {
                var bone = AllBones[index];
                if (bone == HumanBodyBones.LastBone) continue;
                var transform = targetAnimator.GetBoneTransform(bone);
                if (transform != null) frame.rotations.Add(new Rotation { bone = BoneNames[index], value = transform.rotation });
            }
            recording.frames.Add(frame);
        }

        public void StartRecording() => IsRecording = true;

        public void StopAndSave()
        {
            IsRecording = false;
            var path = Path.Combine(Application.persistentDataPath, outputFileName);
            File.WriteAllText(path, JsonUtility.ToJson(recording));
            Debug.Log($"Motion recording saved: {path}");
            recording.frames.Clear();
        }
    }
}

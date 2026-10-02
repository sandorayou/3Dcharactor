using UnityEngine;
using VRM;

namespace RealtimeBodyTracking
{
    // Apply after the body/head solver and manual animation, using VRM's eye limits.
    [DefaultExecutionOrder(10001)]
    public sealed class IOSAvatarGaze : MonoBehaviour
    {
        private VRMLookAtHead lookAt;
        private Transform leftEye, rightEye;
        private Vector3 leftPosition, rightPosition;
        private Vector2 target, filtered;
        private float lastFaceTime = float.NegativeInfinity;

        private void Start()
        {
            var driver = GetComponentInParent<HumanoidPoseDriver>();
            var animator = driver != null ? driver.GetComponentInChildren<Animator>() : null;
            if (animator == null || !animator.isHuman) { enabled = false; return; }
            lookAt = animator.GetComponent<VRMLookAtHead>();
            leftEye = animator.GetBoneTransform(HumanBodyBones.LeftEye);
            rightEye = animator.GetBoneTransform(HumanBodyBones.RightEye);
            if (leftEye != null) leftPosition = leftEye.localPosition;
            if (rightEye != null) rightPosition = rightEye.localPosition;
        }

        public static Vector2 ReadMirroredGaze(PosePacket packet)
        {
            var yaw = (packet.GetFaceBlendshape("eyeLookInLeft") - packet.GetFaceBlendshape("eyeLookOutLeft") +
                packet.GetFaceBlendshape("eyeLookOutRight") - packet.GetFaceBlendshape("eyeLookInRight")) * .5f;
            var pitch = (packet.GetFaceBlendshape("eyeLookDownLeft") + packet.GetFaceBlendshape("eyeLookDownRight") -
                packet.GetFaceBlendshape("eyeLookUpLeft") - packet.GetFaceBlendshape("eyeLookUpRight")) * .5f;
            // Front-camera reflection changes horizontal gaze; VRM maps these inputs to safe eye rotations.
            return new Vector2(-Mathf.Clamp(yaw, -1f, 1f) * 90f, Mathf.Clamp(pitch, -1f, 1f) * 90f);
        }

        public void SetFace(PosePacket packet)
        {
            if (packet?.face_blendshapes == null || packet.face_blendshapes.Count == 0) return;
            target = ReadMirroredGaze(packet);
            lastFaceTime = Time.unscaledTime;
        }

        public void ResetNeutral()
        {
            target = filtered = Vector2.zero;
            lastFaceTime = float.NegativeInfinity;
            ApplyEyes();
        }

        private void LateUpdate()
        {
            if (Time.unscaledTime - lastFaceTime > .2f) target = Vector2.zero;
            filtered = Vector2.Lerp(filtered, target, 1f - Mathf.Exp(-18f * Time.unscaledDeltaTime));
            ApplyEyes();
        }

        private void ApplyEyes()
        {
            if (leftEye != null) leftEye.localPosition = leftPosition;
            if (rightEye != null) rightEye.localPosition = rightPosition;
            // Reapply in head-local coordinates after fallback poses, avoiding world-fixed eyeballs.
            if (lookAt != null) lookAt.RaiseYawPitchChanged(filtered.x, filtered.y);
        }
    }
}

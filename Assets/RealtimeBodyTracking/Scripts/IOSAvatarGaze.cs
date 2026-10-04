using UnityEngine;
using VRM;

namespace RealtimeBodyTracking
{
    // Keep the eyes centered relative to the head after body/manual animation.
    [DefaultExecutionOrder(10001)]
    public sealed class IOSAvatarGaze : MonoBehaviour
    {
        private VRMLookAtHead lookAt;
        private Transform leftEye, rightEye;
        private Vector3 leftPosition, rightPosition;
        private Quaternion leftRotation, rightRotation;

        private void Start()
        {
            var driver = GetComponentInParent<HumanoidPoseDriver>();
            var animator = driver != null ? driver.GetComponentInChildren<Animator>() : null;
            if (animator == null || !animator.isHuman) { enabled = false; return; }
            lookAt = animator.GetComponent<VRMLookAtHead>();
            leftEye = animator.GetBoneTransform(HumanBodyBones.LeftEye);
            rightEye = animator.GetBoneTransform(HumanBodyBones.RightEye);
            if (leftEye != null)
            {
                leftPosition = leftEye.localPosition;
                leftRotation = leftEye.localRotation;
            }
            if (rightEye != null)
            {
                rightPosition = rightEye.localPosition;
                rightRotation = rightEye.localRotation;
            }
        }

        public void ResetNeutral()
        {
            ApplyEyes();
        }

        private void LateUpdate()
        {
            ApplyEyes();
        }

        private void ApplyEyes()
        {
            if (lookAt != null) lookAt.RaiseYawPitchChanged(0f, 0f);
            // Local rotations follow the head while keeping the pupils centered.
            if (leftEye != null)
            {
                leftEye.localPosition = leftPosition;
                leftEye.localRotation = leftRotation;
            }
            if (rightEye != null)
            {
                rightEye.localPosition = rightPosition;
                rightEye.localRotation = rightRotation;
            }
        }
    }
}

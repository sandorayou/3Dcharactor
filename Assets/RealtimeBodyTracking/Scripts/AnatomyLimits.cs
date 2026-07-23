using UnityEngine;

namespace RealtimeBodyTracking
{
    public static class AnatomyLimits
    {
        public static Quaternion ClampSwing(HumanBodyBones bone, Quaternion rest, Quaternion target)
        {
            return Quaternion.RotateTowards(rest, target, GetMaxSwingDegrees(bone));
        }

        public static float GetMaxSwingDegrees(HumanBodyBones bone)
        {
            switch (bone)
            {
                case HumanBodyBones.Head:
                    return 75f;
                case HumanBodyBones.Neck:
                    return 45f;
                case HumanBodyBones.Spine:
                    return 25f;
                case HumanBodyBones.Chest:
                case HumanBodyBones.UpperChest:
                    return 25f;
                case HumanBodyBones.LeftShoulder:
                case HumanBodyBones.RightShoulder:
                    return 20f;
                case HumanBodyBones.LeftUpperArm:
                case HumanBodyBones.RightUpperArm:
                    return 170f;
                case HumanBodyBones.LeftLowerArm:
                case HumanBodyBones.RightLowerArm:
                    return 175f;
                case HumanBodyBones.LeftHand:
                case HumanBodyBones.RightHand:
                    return 45f;
                case HumanBodyBones.LeftUpperLeg:
                case HumanBodyBones.RightUpperLeg:
                    return 80f;
                case HumanBodyBones.LeftLowerLeg:
                case HumanBodyBones.RightLowerLeg:
                    return 120f;
                case HumanBodyBones.LeftFoot:
                case HumanBodyBones.RightFoot:
                    return 45f;
                case HumanBodyBones.Hips:
                    return 25f;
                default:
                    return 75f;
            }
        }
    }
}

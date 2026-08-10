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
                    return 155f;
                case HumanBodyBones.LeftLowerArm:
                case HumanBodyBones.RightLowerArm:
                    return 175f;
                case HumanBodyBones.LeftHand:
                case HumanBodyBones.RightHand:
                    return 45f;
                case HumanBodyBones.LeftThumbProximal:
                case HumanBodyBones.RightThumbProximal:
                    return 75f;
                case HumanBodyBones.LeftThumbIntermediate:
                case HumanBodyBones.RightThumbIntermediate:
                    return 90f;
                case HumanBodyBones.LeftThumbDistal:
                case HumanBodyBones.RightThumbDistal:
                    return 80f;
                case HumanBodyBones.LeftIndexProximal:
                case HumanBodyBones.RightIndexProximal:
                case HumanBodyBones.LeftMiddleProximal:
                case HumanBodyBones.RightMiddleProximal:
                case HumanBodyBones.LeftRingProximal:
                case HumanBodyBones.RightRingProximal:
                case HumanBodyBones.LeftLittleProximal:
                case HumanBodyBones.RightLittleProximal:
                    return 95f;
                case HumanBodyBones.LeftIndexIntermediate:
                case HumanBodyBones.RightIndexIntermediate:
                case HumanBodyBones.LeftMiddleIntermediate:
                case HumanBodyBones.RightMiddleIntermediate:
                case HumanBodyBones.LeftRingIntermediate:
                case HumanBodyBones.RightRingIntermediate:
                case HumanBodyBones.LeftLittleIntermediate:
                case HumanBodyBones.RightLittleIntermediate:
                    return 120f;
                case HumanBodyBones.LeftIndexDistal:
                case HumanBodyBones.RightIndexDistal:
                case HumanBodyBones.LeftMiddleDistal:
                case HumanBodyBones.RightMiddleDistal:
                case HumanBodyBones.LeftRingDistal:
                case HumanBodyBones.RightRingDistal:
                case HumanBodyBones.LeftLittleDistal:
                case HumanBodyBones.RightLittleDistal:
                    return 90f;
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

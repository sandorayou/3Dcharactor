using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class BoneRotationSolver
    {
        private readonly Dictionary<HumanBodyBones, Quaternion> restRotations = new();
        private readonly Dictionary<HumanBodyBones, Vector3> restDirections = new();
        private readonly Dictionary<HumanBodyBones, Vector3> restUps = new();

        public void Initialize(Animator animator)
        {
            foreach (HumanBodyBones bone in System.Enum.GetValues(typeof(HumanBodyBones)))
            {
                if (bone == HumanBodyBones.LastBone) continue;
                var transform = animator.GetBoneTransform(bone);
                if (transform == null) continue;
                restRotations[bone] = transform.rotation;
                if (TryGetHandAxes(animator, bone, transform, out var handDirection, out var handAcross))
                {
                    restDirections[bone] = handDirection;
                    restUps[bone] = handAcross;
                    continue;
                }
                restUps[bone] = transform.up;
                var endpointBone = GetEndpointBone(bone);
                var endpoint = endpointBone != HumanBodyBones.LastBone ? animator.GetBoneTransform(endpointBone) : null;
                restDirections[bone] = endpoint != null
                    ? (endpoint.position - transform.position).normalized
                    : transform.forward;
            }
        }

        private static HumanBodyBones GetEndpointBone(HumanBodyBones bone)
        {
            return bone switch
            {
                HumanBodyBones.LeftUpperArm => HumanBodyBones.LeftLowerArm,
                HumanBodyBones.RightUpperArm => HumanBodyBones.RightLowerArm,
                HumanBodyBones.LeftLowerArm => HumanBodyBones.LeftHand,
                HumanBodyBones.RightLowerArm => HumanBodyBones.RightHand,
                HumanBodyBones.LeftUpperLeg => HumanBodyBones.LeftLowerLeg,
                HumanBodyBones.RightUpperLeg => HumanBodyBones.RightLowerLeg,
                HumanBodyBones.LeftLowerLeg => HumanBodyBones.LeftFoot,
                HumanBodyBones.RightLowerLeg => HumanBodyBones.RightFoot,
                _ => HumanBodyBones.LastBone,
            };
        }

        private static bool TryGetHandAxes(Animator animator, HumanBodyBones bone, Transform hand,
            out Vector3 direction, out Vector3 across)
        {
            var left = bone == HumanBodyBones.LeftHand;
            if (!left && bone != HumanBodyBones.RightHand)
            {
                direction = default;
                across = default;
                return false;
            }
            var index = animator.GetBoneTransform(left ? HumanBodyBones.LeftIndexProximal : HumanBodyBones.RightIndexProximal);
            var middle = animator.GetBoneTransform(left ? HumanBodyBones.LeftMiddleProximal : HumanBodyBones.RightMiddleProximal);
            var little = animator.GetBoneTransform(left ? HumanBodyBones.LeftLittleProximal : HumanBodyBones.RightLittleProximal);
            if (index == null || middle == null || little == null)
            {
                direction = default;
                across = default;
                return false;
            }
            direction = (middle.position - hand.position).normalized;
            var handAcross = (index.position - little.position).normalized;
            across = Vector3.Cross(handAcross, direction).normalized;
            return direction.sqrMagnitude > .000001f && across.sqrMagnitude > .000001f;
        }

        public bool TrySolve(HumanBodyBones bone, Vector3 worldDirection, Vector3 upHint, Quaternion rootRotationDelta, bool useRollCorrection, out Quaternion target)
        {
            if (!restRotations.TryGetValue(bone, out var rest) || !restDirections.TryGetValue(bone, out var restDirection) || worldDirection.sqrMagnitude < .000001f)
            {
                target = default;
                return false;
            }
            var direction = worldDirection.normalized;
            var rotatedRest = rootRotationDelta * rest;
            var rotatedRestDirection = rootRotationDelta * restDirection;
            target = Quaternion.FromToRotation(rotatedRestDirection, direction) * rotatedRest;
            if (useRollCorrection && upHint.sqrMagnitude > .000001f && restUps.TryGetValue(bone, out var restUp))
            {
                restUp = rootRotationDelta * restUp;
                var currentUp = Vector3.ProjectOnPlane(target * Quaternion.Inverse(rotatedRest) * restUp, direction);
                var desiredUp = Vector3.ProjectOnPlane(upHint, direction);
                if (currentUp.sqrMagnitude > .000001f && desiredUp.sqrMagnitude > .000001f)
                    target = Quaternion.AngleAxis(Vector3.SignedAngle(currentUp, desiredUp, direction), direction) * target;
            }
            return true;
        }

        public bool TryGetRestRotation(HumanBodyBones bone, out Quaternion rotation) => restRotations.TryGetValue(bone, out rotation);

        public bool TryClampHand(HumanBodyBones bone, Quaternion target, Quaternion rootRotationDelta, out Quaternion clamped)
        {
            if ((bone != HumanBodyBones.LeftHand && bone != HumanBodyBones.RightHand) ||
                !restRotations.TryGetValue(bone, out var rest) ||
                !restDirections.TryGetValue(bone, out var restDirection) ||
                !restUps.TryGetValue(bone, out var restUp))
            {
                clamped = target;
                return false;
            }
            var baseRotation = rootRotationDelta * rest;
            var axis = (rootRotationDelta * restDirection).normalized;
            var up = Vector3.ProjectOnPlane(rootRotationDelta * restUp, axis).normalized;
            var side = Vector3.Cross(up, axis).normalized;
            var delta = target * Quaternion.Inverse(baseRotation);
            var desiredDirection = delta * axis;
            var forward = Mathf.Max(Vector3.Dot(desiredDirection, axis), .001f);
            var flex = Mathf.Clamp(Mathf.Atan2(Vector3.Dot(desiredDirection, up), forward) * Mathf.Rad2Deg, -60f, 60f);
            var radial = Mathf.Clamp(Mathf.Atan2(Vector3.Dot(desiredDirection, side), forward) * Mathf.Rad2Deg, -25f, 25f);
            var clampedDirection = (axis + up * Mathf.Tan(flex * Mathf.Deg2Rad) +
                                    side * Mathf.Tan(radial * Mathf.Deg2Rad)).normalized;
            var swing = Quaternion.FromToRotation(axis, clampedDirection);
            var swungUp = swing * up;
            var desiredUp = Vector3.ProjectOnPlane(delta * up, clampedDirection);
            var twist = desiredUp.sqrMagnitude > .000001f
                ? Mathf.Clamp(Vector3.SignedAngle(swungUp, desiredUp, clampedDirection), -25f, 25f)
                : 0f;
            clamped = Quaternion.AngleAxis(twist, clampedDirection) * swing * baseRotation;
            return true;
        }
    }
}

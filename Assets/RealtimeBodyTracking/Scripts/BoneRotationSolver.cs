using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class BoneRotationSolver
    {
        private readonly Dictionary<HumanBodyBones, Quaternion> restRotations = new();
        private readonly Dictionary<HumanBodyBones, Quaternion> restLocalRotations = new();
        private readonly Dictionary<HumanBodyBones, Vector3> restDirections = new();
        private readonly Dictionary<HumanBodyBones, Vector3> restUps = new();
        private readonly Dictionary<HumanBodyBones, Transform> handParents = new();
        private readonly Dictionary<HumanBodyBones, Transform> boneTransforms = new();
        public string LastFailure { get; private set; }
        public string DebugSummary =>
            $"rest={restRotations.Count}, local={restLocalRotations.Count}, directions={restDirections.Count}, transforms={boneTransforms.Count}";

        public void Initialize(Animator animator)
        {
            restRotations.Clear();
            restLocalRotations.Clear();
            restDirections.Clear();
            restUps.Clear();
            handParents.Clear();
            boneTransforms.Clear();
            LastFailure = string.Empty;
            RefreshMissingBones(animator);
        }

        public int RefreshMissingBones(Animator animator)
        {
            var added = 0;
            foreach (HumanBodyBones bone in System.Enum.GetValues(typeof(HumanBodyBones)))
            {
                if (bone == HumanBodyBones.LastBone || restRotations.ContainsKey(bone)) continue;
                var transform = animator.GetBoneTransform(bone);
                if (transform == null) continue;
                added++;
                restRotations[bone] = transform.rotation;
                restLocalRotations[bone] = transform.localRotation;
                boneTransforms[bone] = transform;
                if (TryGetHandAxes(animator, bone, transform, out var handDirection, out var handAcross))
                {
                    restDirections[bone] = handDirection;
                    restUps[bone] = handAcross;
                    if (transform.parent != null) handParents[bone] = transform.parent;
                    continue;
                }
                restUps[bone] = transform.up;
                var endpointBone = GetEndpointBone(bone);
                var endpoint = endpointBone != HumanBodyBones.LastBone ? animator.GetBoneTransform(endpointBone) : null;
                if (endpoint != null)
                {
                    restDirections[bone] = (endpoint.position - transform.position).normalized;
                }
                else if (transform.childCount > 0)
                {
                    restDirections[bone] = (transform.GetChild(0).position - transform.position).normalized;
                }
                else if (transform.parent != null && (transform.position - transform.parent.position).sqrMagnitude > .000001f)
                {
                    // Fallback for Distal finger tip bones without children: inherit finger chain extension direction from parent
                    restDirections[bone] = (transform.position - transform.parent.position).normalized;
                }
                else
                {
                    restDirections[bone] = transform.forward;
                }
            }
            return added;
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
                HumanBodyBones.LeftThumbProximal => HumanBodyBones.LeftThumbIntermediate,
                HumanBodyBones.LeftThumbIntermediate => HumanBodyBones.LeftThumbDistal,
                HumanBodyBones.LeftIndexProximal => HumanBodyBones.LeftIndexIntermediate,
                HumanBodyBones.LeftIndexIntermediate => HumanBodyBones.LeftIndexDistal,
                HumanBodyBones.LeftMiddleProximal => HumanBodyBones.LeftMiddleIntermediate,
                HumanBodyBones.LeftMiddleIntermediate => HumanBodyBones.LeftMiddleDistal,
                HumanBodyBones.LeftRingProximal => HumanBodyBones.LeftRingIntermediate,
                HumanBodyBones.LeftRingIntermediate => HumanBodyBones.LeftRingDistal,
                HumanBodyBones.LeftLittleProximal => HumanBodyBones.LeftLittleIntermediate,
                HumanBodyBones.LeftLittleIntermediate => HumanBodyBones.LeftLittleDistal,
                HumanBodyBones.RightThumbProximal => HumanBodyBones.RightThumbIntermediate,
                HumanBodyBones.RightThumbIntermediate => HumanBodyBones.RightThumbDistal,
                HumanBodyBones.RightIndexProximal => HumanBodyBones.RightIndexIntermediate,
                HumanBodyBones.RightIndexIntermediate => HumanBodyBones.RightIndexDistal,
                HumanBodyBones.RightMiddleProximal => HumanBodyBones.RightMiddleIntermediate,
                HumanBodyBones.RightMiddleIntermediate => HumanBodyBones.RightMiddleDistal,
                HumanBodyBones.RightRingProximal => HumanBodyBones.RightRingIntermediate,
                HumanBodyBones.RightRingIntermediate => HumanBodyBones.RightRingDistal,
                HumanBodyBones.RightLittleProximal => HumanBodyBones.RightLittleIntermediate,
                HumanBodyBones.RightLittleIntermediate => HumanBodyBones.RightLittleDistal,
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
                LastFailure = $"solve:{bone}, rest={restRotations.ContainsKey(bone)}, direction={restDirections.ContainsKey(bone)}, input={worldDirection.sqrMagnitude:F6}";
                target = default;
                return false;
            }
            LastFailure = string.Empty;
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

        public bool TryGetHandBaseAxes(HumanBodyBones bone, Quaternion parentRotation,
            out Vector3 direction, out Vector3 palmNormal)
        {
            if ((bone != HumanBodyBones.LeftHand && bone != HumanBodyBones.RightHand) ||
                !restRotations.TryGetValue(bone, out var rest) ||
                !restLocalRotations.TryGetValue(bone, out var localRest) ||
                !restDirections.TryGetValue(bone, out var restDirection) ||
                !restUps.TryGetValue(bone, out var restUp))
            {
                direction = default;
                palmNormal = default;
                return false;
            }
            var baseRotation = parentRotation * localRest;
            var restInverse = Quaternion.Inverse(rest);
            direction = (baseRotation * (restInverse * restDirection)).normalized;
            palmNormal = (baseRotation * (restInverse * restUp)).normalized;
            return direction.sqrMagnitude > .000001f && palmNormal.sqrMagnitude > .000001f;
        }

        public bool TryGetRestRotation(HumanBodyBones bone, out Quaternion rotation) => restRotations.TryGetValue(bone, out rotation);

        public bool TryGetRestLocalRotation(HumanBodyBones bone, out Quaternion rotation) =>
            restLocalRotations.TryGetValue(bone, out rotation);

        public bool TrySolveFinger(HumanBodyBones bone, Vector3 worldDirection, float maxSwingDegrees,
            out Quaternion target)
        {
            if (!boneTransforms.TryGetValue(bone, out var transform) || transform.parent == null ||
                !restRotations.TryGetValue(bone, out var rest) ||
                !restLocalRotations.TryGetValue(bone, out var localRest) ||
                !restDirections.TryGetValue(bone, out var restDirection) ||
                worldDirection.sqrMagnitude < .000001f)
            {
                LastFailure = $"finger:{bone}, transform={boneTransforms.ContainsKey(bone)}, parent={transform != null && transform.parent != null}, " +
                              $"rest={restRotations.ContainsKey(bone)}, local={restLocalRotations.ContainsKey(bone)}, " +
                              $"direction={restDirections.ContainsKey(bone)}, input={worldDirection.sqrMagnitude:F6}";
                target = default;
                return false;
            }
            LastFailure = string.Empty;
            var parentRest = transform.parent.rotation * localRest;
            var localDirection = Quaternion.Inverse(rest) * restDirection;
            var parentRestDirection = parentRest * localDirection;
            target = Quaternion.FromToRotation(parentRestDirection, worldDirection.normalized) * parentRest;
            target = Quaternion.RotateTowards(parentRest, target, maxSwingDegrees);
            return true;
        }

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
            if (handParents.TryGetValue(bone, out var parent) && restLocalRotations.TryGetValue(bone, out var localRest))
                baseRotation = parent.rotation * localRest;
            var restInverse = Quaternion.Inverse(rest);
            var axis = (baseRotation * (restInverse * restDirection)).normalized;
            var up = Vector3.ProjectOnPlane(baseRotation * (restInverse * restUp), axis).normalized;
            var side = Vector3.Cross(up, axis).normalized;
            var desiredDirection = target * (restInverse * restDirection);
            var forward = Mathf.Max(Vector3.Dot(desiredDirection, axis), .001f);
            var flex = Mathf.Clamp(Mathf.Atan2(Vector3.Dot(desiredDirection, up), forward) * Mathf.Rad2Deg, -90f, 90f);
            var radial = Mathf.Clamp(Mathf.Atan2(Vector3.Dot(desiredDirection, side), forward) * Mathf.Rad2Deg, -25f, 25f);
            var clampedDirection = (axis + up * Mathf.Tan(flex * Mathf.Deg2Rad) +
                                    side * Mathf.Tan(radial * Mathf.Deg2Rad)).normalized;
            var swing = Quaternion.FromToRotation(axis, clampedDirection);
            var swungUp = swing * up;
            var desiredUp = Vector3.ProjectOnPlane(target * (restInverse * restUp), clampedDirection);
            var twist = desiredUp.sqrMagnitude > .000001f
                ? Mathf.Clamp(Vector3.SignedAngle(swungUp, desiredUp, clampedDirection), -25f, 25f)
                : 0f;
            clamped = Quaternion.AngleAxis(twist, clampedDirection) * swing * baseRotation;
            return true;
        }
    }
}

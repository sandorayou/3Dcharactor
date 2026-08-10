using System.Collections.Generic;
using UnityEngine;

namespace CameraVrmMocap
{
    public sealed class CameraVrmDriver : MonoBehaviour
    {
        [SerializeField] private Animator avatar;
        [SerializeField] private UdpTrackingReceiver receiver;
        [SerializeField, Range(0f, 1f)] private float minimumConfidence = .5f;
        [SerializeField, Range(0f, .25f)] private float motionDeadZone = .1f;
        [SerializeField, Range(1f, 30f)] private float followSpeed = 12f;
        [SerializeField, Range(.1f, 3f)] private float lateralScale = 1f;
        [SerializeField, Range(.1f, 5f)] private float returnSpeed = 2f;
        [SerializeField, Range(.05f, .5f)] private float torsoPadding = .14f;
        [SerializeField, Range(.1f, 1f)] private float lossTimeout = .25f;

        private readonly Dictionary<HumanBodyBones, Quaternion> rest = new();
        private readonly Dictionary<HumanBodyBones, Vector3> restAxes = new();
        private readonly Dictionary<string, Vector3> stable = new();
        private Vector3 rootRest;
        private float lastPacketTime = float.NegativeInfinity;
        private float centerOrigin;
        private float shoulderWidthOrigin;
        private bool calibrated;

        private static readonly HumanBodyBones[] ControlledBones = {
            HumanBodyBones.Hips, HumanBodyBones.Spine, HumanBodyBones.Chest, HumanBodyBones.UpperChest,
            HumanBodyBones.Neck, HumanBodyBones.Head, HumanBodyBones.LeftUpperArm, HumanBodyBones.LeftLowerArm,
            HumanBodyBones.LeftHand, HumanBodyBones.RightUpperArm, HumanBodyBones.RightLowerArm, HumanBodyBones.RightHand,
            HumanBodyBones.LeftThumbProximal, HumanBodyBones.LeftThumbIntermediate, HumanBodyBones.LeftThumbDistal,
            HumanBodyBones.LeftIndexProximal, HumanBodyBones.LeftIndexIntermediate, HumanBodyBones.LeftIndexDistal,
            HumanBodyBones.LeftMiddleProximal, HumanBodyBones.LeftMiddleIntermediate, HumanBodyBones.LeftMiddleDistal,
            HumanBodyBones.LeftRingProximal, HumanBodyBones.LeftRingIntermediate, HumanBodyBones.LeftRingDistal,
            HumanBodyBones.LeftLittleProximal, HumanBodyBones.LeftLittleIntermediate, HumanBodyBones.LeftLittleDistal,
            HumanBodyBones.RightThumbProximal, HumanBodyBones.RightThumbIntermediate, HumanBodyBones.RightThumbDistal,
            HumanBodyBones.RightIndexProximal, HumanBodyBones.RightIndexIntermediate, HumanBodyBones.RightIndexDistal,
            HumanBodyBones.RightMiddleProximal, HumanBodyBones.RightMiddleIntermediate, HumanBodyBones.RightMiddleDistal,
            HumanBodyBones.RightRingProximal, HumanBodyBones.RightRingIntermediate, HumanBodyBones.RightRingDistal,
            HumanBodyBones.RightLittleProximal, HumanBodyBones.RightLittleIntermediate, HumanBodyBones.RightLittleDistal,
        };

        private void Awake()
        {
            if (avatar == null) avatar = GetComponentInChildren<Animator>();
            if (receiver == null) receiver = GetComponent<UdpTrackingReceiver>();
            rootRest = avatar.transform.position;
            foreach (var bone in ControlledBones)
            {
                var target = avatar.GetBoneTransform(bone);
                if (target != null)
                {
                    rest[bone] = target.rotation;
                    if (target.childCount > 0) restAxes[bone] = (target.GetChild(0).position - target.position).normalized;
                }
            }
        }

        private void LateUpdate()
        {
            if (receiver != null && receiver.TryTakeLatest(out var packet))
            {
                lastPacketTime = Time.unscaledTime;
                Apply(packet.Index());
            }
            if (Time.unscaledTime - lastPacketTime > lossTimeout) ReturnAll();
        }

        private void Apply(Dictionary<string, TrackingPoint> p)
        {
            if (!Try(p, "left_shoulder", out var ls) || !Try(p, "right_shoulder", out var rs))
            {
                ReturnAll();
                return;
            }
            var shoulderCenter = (ls + rs) * .5f;
            var shoulderWidth = Mathf.Max(Vector3.Distance(ls, rs), .01f);
            if (!calibrated)
            {
                centerOrigin = (p["left_shoulder"].u + p["right_shoulder"].u) * .5f;
                shoulderWidthOrigin = Mathf.Abs(p["right_shoulder"].u - p["left_shoulder"].u);
                calibrated = true;
            }

            ApplyRootTranslation(p, shoulderWidth);
            var forward = ResolveFacing(ls, rs);
            var torso = ResolveTorso(p, shoulderCenter, shoulderWidth);
            Aim(HumanBodyBones.Spine, Vector3.up, torso, forward);
            Aim(HumanBodyBones.Chest, Vector3.up, torso, forward);
            Aim(HumanBodyBones.UpperChest, Vector3.up, torso, forward);
            ApplyHead(p, forward);
            ApplyArm(p, true, shoulderCenter, shoulderWidth, forward);
            ApplyArm(p, false, shoulderCenter, shoulderWidth, forward);
        }

        private Vector3 ResolveFacing(Vector3 left, Vector3 right)
        {
            var across = (right - left).normalized;
            var facing = Vector3.Cross(Vector3.up, across).normalized;
            if (facing.z > 0f) facing = -facing;
            var yaw = Mathf.Atan2(facing.x, facing.z) * Mathf.Rad2Deg + 180f;
            avatar.transform.rotation = Quaternion.RotateTowards(avatar.transform.rotation,
                Quaternion.Euler(0f, yaw, 0f), followSpeed * 30f * Time.deltaTime);
            return facing;
        }

        private Vector3 ResolveTorso(Dictionary<string, TrackingPoint> p, Vector3 shoulderCenter, float width)
        {
            if (Try(p, "left_hip", out var lh) && Try(p, "right_hip", out var rh))
                return Filter("torso", shoulderCenter - (lh + rh) * .5f, width).normalized;
            if (Try(p, "nose", out var nose))
                return Filter("torso", nose - shoulderCenter, width).normalized;
            return Vector3.up;
        }

        private void ApplyRootTranslation(Dictionary<string, TrackingPoint> p, float width)
        {
            var center = (p["left_shoulder"].u + p["right_shoulder"].u) * .5f;
            var normalized = (center - centerOrigin) / Mathf.Max(shoulderWidthOrigin, .01f);
            normalized = DeadZone(normalized, motionDeadZone);
            var target = rootRest + Vector3.left * normalized * lateralScale;
            avatar.transform.position = Vector3.Lerp(avatar.transform.position, target, Exp(followSpeed));
        }

        private void ApplyHead(Dictionary<string, TrackingPoint> p, Vector3 bodyForward)
        {
            if (!Try(p, "nose", out var nose) || !Try(p, "left_ear", out var le) || !Try(p, "right_ear", out var re))
            {
                Return(HumanBodyBones.Neck); Return(HumanBodyBones.Head); return;
            }
            var across = (re - le).normalized;
            var up = (nose - (le + re) * .5f).normalized;
            var forward = Vector3.Cross(across, up).normalized;
            if (Vector3.Dot(forward, bodyForward) < 0f) forward = -forward;
            Aim(HumanBodyBones.Head, Vector3.forward, forward, up);
            Aim(HumanBodyBones.Neck, Vector3.forward, Vector3.Slerp(bodyForward, forward, .5f), up);
        }

        private void ApplyArm(Dictionary<string, TrackingPoint> p, bool left, Vector3 torsoCenter, float width, Vector3 forward)
        {
            var side = left ? "left" : "right";
            var upperBone = left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm;
            var lowerBone = left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm;
            var handBone = left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand;
            if (!Try(p, side + "_shoulder", out var shoulder) || !TryHandWrist(p, side, out var wrist))
            {
                Return(upperBone); Return(lowerBone); Return(handBone); return;
            }
            wrist = Filter(side + "_wrist", wrist, width);
            Vector3 elbow;
            if (!Try(p, side + "_elbow", out elbow))
            {
                var direction = (wrist - shoulder).normalized;
                var pole = (left ? Vector3.left : Vector3.right) + Vector3.forward * .35f;
                elbow = Vector3.Lerp(shoulder, wrist, .5f) + Vector3.ProjectOnPlane(pole, direction).normalized * width * .35f;
            }
            elbow = Filter(side + "_elbow", elbow, width);
            elbow = OutsideTorso(elbow, torsoCenter, width, left);
            wrist = OutsideTorso(wrist, torsoCenter, width, left);
            Aim(upperBone, left ? Vector3.left : Vector3.right, elbow - shoulder, forward);
            Aim(lowerBone, left ? Vector3.left : Vector3.right, wrist - elbow, forward);
            ApplyHand(p, side, handBone, forward);
        }

        private void ApplyHand(Dictionary<string, TrackingPoint> p, string side, HumanBodyBones bone, Vector3 forward)
        {
            if (!Try(p, side + "_hand_wrist", out var wrist) ||
                !Try(p, side + "_hand_index_mcp", out var index) ||
                !Try(p, side + "_hand_little_mcp", out var little) ||
                !Try(p, side + "_hand_middle_mcp", out var middle))
            { Return(bone); return; }
            var direction = middle - wrist;
            var palmNormal = Vector3.Cross(index - little, direction).normalized;
            if (Vector3.Dot(palmNormal, forward) < 0f) palmNormal = -palmNormal;
            Aim(bone, Vector3.forward, direction, palmNormal);
            ApplyFingers(p, side);
        }

        private void ApplyFingers(Dictionary<string, TrackingPoint> p, string side)
        {
            var left = side == "left";
            ApplyFinger(p, side, "thumb", left ? HumanBodyBones.LeftThumbProximal : HumanBodyBones.RightThumbProximal,
                left ? HumanBodyBones.LeftThumbIntermediate : HumanBodyBones.RightThumbIntermediate,
                left ? HumanBodyBones.LeftThumbDistal : HumanBodyBones.RightThumbDistal, "thumb_cmc", "thumb_mcp", "thumb_ip", "thumb_tip");
            ApplyFinger(p, side, "index", left ? HumanBodyBones.LeftIndexProximal : HumanBodyBones.RightIndexProximal,
                left ? HumanBodyBones.LeftIndexIntermediate : HumanBodyBones.RightIndexIntermediate,
                left ? HumanBodyBones.LeftIndexDistal : HumanBodyBones.RightIndexDistal, "index_mcp", "index_pip", "index_dip", "index_tip");
            ApplyFinger(p, side, "middle", left ? HumanBodyBones.LeftMiddleProximal : HumanBodyBones.RightMiddleProximal,
                left ? HumanBodyBones.LeftMiddleIntermediate : HumanBodyBones.RightMiddleIntermediate,
                left ? HumanBodyBones.LeftMiddleDistal : HumanBodyBones.RightMiddleDistal, "middle_mcp", "middle_pip", "middle_dip", "middle_tip");
            ApplyFinger(p, side, "ring", left ? HumanBodyBones.LeftRingProximal : HumanBodyBones.RightRingProximal,
                left ? HumanBodyBones.LeftRingIntermediate : HumanBodyBones.RightRingIntermediate,
                left ? HumanBodyBones.LeftRingDistal : HumanBodyBones.RightRingDistal, "ring_mcp", "ring_pip", "ring_dip", "ring_tip");
            ApplyFinger(p, side, "little", left ? HumanBodyBones.LeftLittleProximal : HumanBodyBones.RightLittleProximal,
                left ? HumanBodyBones.LeftLittleIntermediate : HumanBodyBones.RightLittleIntermediate,
                left ? HumanBodyBones.LeftLittleDistal : HumanBodyBones.RightLittleDistal, "little_mcp", "little_pip", "little_dip", "little_tip");
        }

        private void ApplyFinger(Dictionary<string, TrackingPoint> p, string side, string key,
            HumanBodyBones proximal, HumanBodyBones intermediate, HumanBodyBones distal,
            string aName, string bName, string cName, string dName)
        {
            if (!Try(p, side + "_hand_" + aName, out var a) || !Try(p, side + "_hand_" + bName, out var b) ||
                !Try(p, side + "_hand_" + cName, out var c) || !Try(p, side + "_hand_" + dName, out var d))
            { Return(proximal); Return(intermediate); Return(distal); return; }
            AimFinger(proximal, Filter(side + key + "0", b - a, .05f));
            AimFinger(intermediate, Filter(side + key + "1", c - b, .04f));
            AimFinger(distal, Filter(side + key + "2", d - c, .03f));
        }

        private void AimFinger(HumanBodyBones bone, Vector3 direction)
        {
            if (!rest.TryGetValue(bone, out var restRotation) || !restAxes.TryGetValue(bone, out var axis) || direction.sqrMagnitude < .000001f) return;
            var target = Quaternion.FromToRotation(axis, direction.normalized) * restRotation;
            var transform = avatar.GetBoneTransform(bone);
            transform.rotation = Quaternion.Slerp(transform.rotation, target, Exp(followSpeed));
        }

        private bool TryHandWrist(Dictionary<string, TrackingPoint> p, string side, out Vector3 value)
        {
            if (Try(p, side + "_hand_wrist", out value)) return true;
            return Try(p, side + "_wrist", out value);
        }

        private bool Try(Dictionary<string, TrackingPoint> p, string name, out Vector3 value)
        {
            if (p.TryGetValue(name, out var point) && point.confidence >= minimumConfidence &&
                point.u >= 0f && point.u <= 1f && point.v >= 0f && point.v <= 1f)
            { value = point.World; value.x = -value.x; return true; }
            value = default; return false;
        }

        private Vector3 Filter(string key, Vector3 candidate, float reference)
        {
            if (!stable.TryGetValue(key, out var previous)) { stable[key] = candidate; return candidate; }
            var delta = candidate - previous;
            var dead = Mathf.Max(reference * motionDeadZone, .001f);
            if (delta.magnitude <= dead) return previous;
            var target = previous + delta.normalized * (delta.magnitude - dead);
            stable[key] = Vector3.Lerp(previous, target, Exp(followSpeed));
            return stable[key];
        }

        private Vector3 OutsideTorso(Vector3 point, Vector3 center, float width, bool left)
        {
            var offset = point - center;
            var radius = width * .5f + torsoPadding;
            if (offset.magnitude >= radius) return point;
            var side = left ? Vector3.left : Vector3.right;
            return center + Vector3.Slerp(side, offset.normalized, .25f) * radius;
        }

        private void Aim(HumanBodyBones bone, Vector3 restAxis, Vector3 direction, Vector3 up)
        {
            if (!rest.TryGetValue(bone, out var restRotation) || direction.sqrMagnitude < .0001f) return;
            var target = Quaternion.FromToRotation(restRotation * restAxis, direction.normalized) * restRotation;
            var transform = avatar.GetBoneTransform(bone);
            transform.rotation = Quaternion.Slerp(transform.rotation, target, Exp(followSpeed));
        }

        private void ReturnAll()
        {
            foreach (var bone in ControlledBones) Return(bone);
            avatar.transform.position = Vector3.Lerp(avatar.transform.position, rootRest, Exp(returnSpeed));
            stable.Clear(); calibrated = false;
        }

        private void Return(HumanBodyBones bone)
        {
            if (!rest.TryGetValue(bone, out var rotation)) return;
            var target = avatar.GetBoneTransform(bone);
            if (target != null) target.rotation = Quaternion.Slerp(target.rotation, rotation, Exp(returnSpeed));
        }

        private float Exp(float speed) => 1f - Mathf.Exp(-speed * Time.deltaTime);
        private static float DeadZone(float value, float dead) => Mathf.Abs(value) <= dead ? 0f : Mathf.Sign(value) * (Mathf.Abs(value) - dead);
    }
}

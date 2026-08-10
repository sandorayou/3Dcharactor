using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class AvatarCollisionGeometry
    {
        private readonly Dictionary<HumanBodyBones, float> radii = new();
        private float torsoHalfWidth;
        private float torsoHalfDepth;

        public void Initialize(Animator animator)
        {
            radii.Clear();
            MeasureTorso(animator);
            foreach (var bone in new[]
                     {
                         HumanBodyBones.LeftUpperArm, HumanBodyBones.RightUpperArm,
                         HumanBodyBones.LeftLowerArm, HumanBodyBones.RightLowerArm,
                         HumanBodyBones.LeftHand, HumanBodyBones.RightHand,
                         HumanBodyBones.Head,
                     })
            {
                var start = animator.GetBoneTransform(bone);
                var end = GetEndpoint(animator, bone);
                var sphere = bone == HumanBodyBones.Head;
                if (start == null || (!sphere && end == null)) continue;
                var samples = new List<float>();
                foreach (var renderer in animator.GetComponentsInChildren<SkinnedMeshRenderer>(true))
                {
                    var mesh = renderer.sharedMesh;
                    if (mesh == null || mesh.boneWeights.Length != mesh.vertexCount) continue;
                    var boneIndex = System.Array.IndexOf(renderer.bones, start);
                    if (boneIndex < 0) continue;
                    var vertices = mesh.vertices;
                    var weights = mesh.boneWeights;
                    for (var index = 0; index < vertices.Length; index++)
                    {
                        if (GetWeight(weights[index], boneIndex) < .2f) continue;
                        var point = renderer.transform.TransformPoint(vertices[index]);
                        samples.Add(sphere
                            ? Vector3.Distance(point, start.position)
                            : DistanceToSegment(point, start.position, end.position));
                    }
                }
                var neck = animator.GetBoneTransform(HumanBodyBones.Neck);
                var length = sphere
                    ? neck != null ? Vector3.Distance(start.position, neck.position) * 2f : .2f
                    : Vector3.Distance(start.position, end.position);
                samples.Sort();
                var measured = samples.Count > 0 ? samples[Mathf.FloorToInt((samples.Count - 1) * .95f)] : length * .12f;
                radii[bone] = sphere
                    ? Mathf.Clamp(measured, length * .35f, length * 1.2f)
                    : Mathf.Clamp(measured, length * .06f, length * .32f);
            }
        }

        public float GetRadius(HumanBodyBones bone, float fallback)
        {
            return radii.TryGetValue(bone, out var radius) ? radius : fallback;
        }

        public Vector2 GetTorsoRadii(float fallbackWidth, float fallbackDepth)
        {
            return new Vector2(torsoHalfWidth > 0f ? torsoHalfWidth : fallbackWidth,
                torsoHalfDepth > 0f ? torsoHalfDepth : fallbackDepth);
        }

        public string DebugSummary =>
            $"torso=({torsoHalfWidth:F3},{torsoHalfDepth:F3}), " +
            $"head={GetRadius(HumanBodyBones.Head, 0f):F3}, " +
            $"upper=({GetRadius(HumanBodyBones.LeftUpperArm, 0f):F3},{GetRadius(HumanBodyBones.RightUpperArm, 0f):F3}), " +
            $"lower=({GetRadius(HumanBodyBones.LeftLowerArm, 0f):F3},{GetRadius(HumanBodyBones.RightLowerArm, 0f):F3}), " +
            $"hand=({GetRadius(HumanBodyBones.LeftHand, 0f):F3},{GetRadius(HumanBodyBones.RightHand, 0f):F3})";

        private void MeasureTorso(Animator animator)
        {
            var hips = animator.GetBoneTransform(HumanBodyBones.Hips);
            var leftShoulder = animator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var rightShoulder = animator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (hips == null || leftShoulder == null || rightShoulder == null) return;
            var shoulderCenter = (leftShoulder.position + rightShoulder.position) * .5f;
            var lateral = (rightShoulder.position - leftShoulder.position).normalized;
            var vertical = (shoulderCenter - hips.position).normalized;
            var forward = Vector3.Cross(lateral, vertical).normalized;
            var center = (shoulderCenter + hips.position) * .5f;
            var widths = new List<float>();
            var depths = new List<float>();
            foreach (var renderer in animator.GetComponentsInChildren<SkinnedMeshRenderer>(true))
            {
                var mesh = renderer.sharedMesh;
                if (mesh == null || mesh.boneWeights.Length != mesh.vertexCount) continue;
                var torsoIndices = new List<int>();
                foreach (var torsoBone in new[]
                         {
                             HumanBodyBones.Hips, HumanBodyBones.Spine, HumanBodyBones.Chest, HumanBodyBones.UpperChest,
                             HumanBodyBones.LeftShoulder, HumanBodyBones.RightShoulder,
                         })
                {
                    var transform = animator.GetBoneTransform(torsoBone);
                    if (transform != null)
                    {
                        var boneIndex = System.Array.IndexOf(renderer.bones, transform);
                        if (boneIndex >= 0) torsoIndices.Add(boneIndex);
                    }
                }
                var vertices = mesh.vertices;
                var weights = mesh.boneWeights;
                for (var index = 0; index < vertices.Length; index++)
                {
                    var weight = 0f;
                    foreach (var boneIndex in torsoIndices) weight += GetWeight(weights[index], boneIndex);
                    if (weight < .1f) continue;
                    var offset = renderer.transform.TransformPoint(vertices[index]) - center;
                    widths.Add(Mathf.Abs(Vector3.Dot(offset, lateral)));
                    depths.Add(Mathf.Abs(Vector3.Dot(offset, forward)));
                }
            }
            widths.Sort();
            depths.Sort();
            if (widths.Count > 0) torsoHalfWidth = widths[Mathf.FloorToInt((widths.Count - 1) * .98f)];
            if (depths.Count > 0) torsoHalfDepth = depths[Mathf.FloorToInt((depths.Count - 1) * .98f)];
        }

        private static Transform GetEndpoint(Animator animator, HumanBodyBones bone)
        {
            return bone switch
            {
                HumanBodyBones.LeftUpperArm => animator.GetBoneTransform(HumanBodyBones.LeftLowerArm),
                HumanBodyBones.RightUpperArm => animator.GetBoneTransform(HumanBodyBones.RightLowerArm),
                HumanBodyBones.LeftLowerArm => animator.GetBoneTransform(HumanBodyBones.LeftHand),
                HumanBodyBones.RightLowerArm => animator.GetBoneTransform(HumanBodyBones.RightHand),
                HumanBodyBones.LeftHand => PalmCenter(animator, true),
                HumanBodyBones.RightHand => PalmCenter(animator, false),
                _ => null,
            };
        }

        private static Transform PalmCenter(Animator animator, bool left)
        {
            return animator.GetBoneTransform(left ? HumanBodyBones.LeftMiddleProximal : HumanBodyBones.RightMiddleProximal);
        }

        private static float GetWeight(BoneWeight weight, int boneIndex)
        {
            var result = 0f;
            if (weight.boneIndex0 == boneIndex) result += weight.weight0;
            if (weight.boneIndex1 == boneIndex) result += weight.weight1;
            if (weight.boneIndex2 == boneIndex) result += weight.weight2;
            if (weight.boneIndex3 == boneIndex) result += weight.weight3;
            return result;
        }

        private static float DistanceToSegment(Vector3 point, Vector3 start, Vector3 end)
        {
            var segment = end - start;
            if (segment.sqrMagnitude < .000001f) return Vector3.Distance(point, start);
            var t = Mathf.Clamp01(Vector3.Dot(point - start, segment) / segment.sqrMagnitude);
            return Vector3.Distance(point, start + segment * t);
        }
    }
}

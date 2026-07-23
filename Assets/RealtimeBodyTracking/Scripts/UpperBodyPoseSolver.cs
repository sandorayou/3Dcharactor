using UnityEngine;

namespace RealtimeBodyTracking
{
    public static class UpperBodyPoseSolver
    {
        private const float MaxElbowBendDegrees = 145f;
        private const int CandidateCount = 72;

        public static ArmPose SolveArm(Vector3 shoulder, Vector3 targetWrist, Vector3 elbowHint, UpperBodyPose body,
            bool left, float upperLength, float lowerLength, float collisionRadiusScale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius,
            float upperRadius, float lowerRadius, float handRadius,
            bool hasPreviousArm, ArmPose previousArm, bool hasOtherArm, ArmPose otherArm)
        {
            var wrist = targetWrist;
            var minReach = Mathf.Sqrt(Mathf.Max(
                upperLength * upperLength + lowerLength * lowerLength +
                2f * upperLength * lowerLength * Mathf.Cos(MaxElbowBendDegrees * Mathf.Deg2Rad), .000001f));
            var direction = Vector3.down;
            var distance = minReach;
            for (var iteration = 0; iteration < 3; iteration++)
            {
                wrist = ProjectPointOutsideBody(wrist, body, left, collisionRadiusScale,
                    torsoRadiusX, torsoRadiusZ, headRadius, handRadius);
                var toWrist = wrist - shoulder;
                direction = toWrist.sqrMagnitude > .000001f ? toWrist.normalized : Vector3.down;
                distance = Mathf.Clamp(toWrist.magnitude, minReach, upperLength + lowerLength - .001f);
                wrist = shoulder + direction * distance;
            }

            var along = (upperLength * upperLength - lowerLength * lowerLength + distance * distance) / (2f * distance);
            var bendRadius = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - along * along, 0f));
            var circleCenter = shoulder + direction * along;
            var pole = Vector3.ProjectOnPlane(elbowHint - circleCenter, direction);
            if (pole.sqrMagnitude < .0001f)
            {
                var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
                pole = Vector3.ProjectOnPlane(
                    lateral * (left ? -1f : 1f) + body.Forward * .2f + Vector3.down * .2f, direction);
            }
            if (pole.sqrMagnitude < .0001f) pole = Vector3.ProjectOnPlane(body.Forward, direction);
            pole.Normalize();

            var bestElbow = circleCenter + pole * bendRadius;
            var bestScore = float.PositiveInfinity;
            var bestCollision = float.PositiveInfinity;
            var shoulderWidth = Mathf.Max(body.Lateral.magnitude, .05f);
            for (var index = 0; index < CandidateCount; index++)
            {
                var angle = index == 0 ? 0f : ((index + 1) / 2) * (360f / CandidateCount) * (index % 2 == 0 ? -1f : 1f);
                var candidateElbow = circleCenter + Quaternion.AngleAxis(angle, direction) * pole * bendRadius;
                var candidate = new ArmPose(shoulder, candidateElbow, wrist);
                if (hasPreviousArm)
                {
                    var previousBendNormal = Vector3.Cross(
                        previousArm.Wrist - previousArm.Shoulder, previousArm.Elbow - previousArm.Shoulder);
                    var candidateBendNormal = Vector3.Cross(wrist - shoulder, candidateElbow - shoulder);
                    if (previousBendNormal.sqrMagnitude > .000001f && candidateBendNormal.sqrMagnitude > .000001f &&
                        Vector3.Dot(previousBendNormal, candidateBendNormal) < 0f) continue;
                }
                var hintError = (candidateElbow - elbowHint).sqrMagnitude / (shoulderWidth * shoulderWidth);
                var collision = ArmCollisionPenalty(candidate, body, collisionRadiusScale,
                    torsoRadiusX, torsoRadiusZ, headRadius, upperRadius, lowerRadius);
                var otherCollision = hasOtherArm
                    ? ArmPairCollisionPenalty(candidate, otherArm, Mathf.Max(upperRadius, lowerRadius) * 2f)
                    : 0f;
                var combinedCollision = collision + otherCollision;
                var score = hintError;
                if (combinedCollision > bestCollision + .0000001f ||
                    (Mathf.Abs(combinedCollision - bestCollision) <= .0000001f && score >= bestScore)) continue;
                bestCollision = combinedCollision;
                bestScore = score;
                bestElbow = candidateElbow;
            }
            return new ArmPose(shoulder, bestElbow, wrist);
        }

        private static Vector3 ProjectPointOutsideBody(Vector3 point, UpperBodyPose body, bool left, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float padding)
        {
            for (var iteration = 0; iteration < 3; iteration++)
            {
                var torsoCorrection = TorsoCorrection(point, body, left, scale, torsoRadiusX, torsoRadiusZ, padding);
                var headCorrection = HeadCorrection(point, body, left, headRadius, padding);
                point += torsoCorrection.sqrMagnitude > headCorrection.sqrMagnitude ? torsoCorrection : headCorrection;
            }
            return point;
        }

        private static float ArmCollisionPenalty(ArmPose arm, UpperBodyPose body, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float upperRadius, float lowerRadius)
        {
            var penalty = SegmentCollisionPenalty(arm.Shoulder, arm.Elbow, body, scale,
                              torsoRadiusX, torsoRadiusZ, headRadius, upperRadius, 2) +
                          SegmentCollisionPenalty(arm.Elbow, arm.Wrist, body, scale,
                              torsoRadiusX, torsoRadiusZ, headRadius, lowerRadius, 0);
            return penalty;
        }

        private static float SegmentCollisionPenalty(Vector3 start, Vector3 end, UpperBodyPose body, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float padding, int firstSample)
        {
            var penalty = 0f;
            for (var index = firstSample; index <= 10; index++)
            {
                var point = Vector3.Lerp(start, end, index / 10f);
                var torso = TorsoCorrection(point, body, false, scale, torsoRadiusX, torsoRadiusZ, padding).magnitude;
                var head = HeadCorrection(point, body, false, headRadius, padding).magnitude;
                penalty += torso * torso + head * head;
            }
            return penalty;
        }

        private static float ArmPairCollisionPenalty(ArmPose arm, ArmPose other, float radius)
        {
            return SegmentPairPenalty(arm.Shoulder, arm.Elbow, other.Shoulder, other.Elbow, radius) +
                   SegmentPairPenalty(arm.Shoulder, arm.Elbow, other.Elbow, other.Wrist, radius) +
                   SegmentPairPenalty(arm.Elbow, arm.Wrist, other.Shoulder, other.Elbow, radius) +
                   SegmentPairPenalty(arm.Elbow, arm.Wrist, other.Elbow, other.Wrist, radius);
        }

        private static float SegmentPairPenalty(Vector3 start, Vector3 end, Vector3 otherStart, Vector3 otherEnd, float radius)
        {
            var penalty = 0f;
            for (var index = 1; index <= 8; index++)
            {
                var point = Vector3.Lerp(start, end, index / 8f);
                var other = ClosestPointOnSegment(point, otherStart, otherEnd);
                var overlap = radius - Vector3.Distance(point, other);
                if (overlap > 0f) penalty += overlap * overlap;
            }
            return penalty;
        }

        private static Vector3 ClosestPointOnSegment(Vector3 point, Vector3 start, Vector3 end)
        {
            var segment = end - start;
            if (segment.sqrMagnitude < .000001f) return start;
            return start + segment * Mathf.Clamp01(Vector3.Dot(point - start, segment) / segment.sqrMagnitude);
        }

        private static Vector3 TorsoCorrection(Vector3 point, UpperBodyPose body, bool left, float scale,
            float torsoRadiusX, float torsoRadiusZ, float padding)
        {
            if (scale <= 0f) return Vector3.zero;
            var torsoAxis = body.HipCenter - body.ShoulderCenter;
            var torsoHeight = torsoAxis.magnitude;
            if (torsoHeight < .001f) return Vector3.zero;
            var vertical = torsoAxis / torsoHeight;
            var height = Vector3.Dot(point - body.ShoulderCenter, vertical);
            if (height < -torsoHeight * .1f || height > torsoHeight * 1.12f) return Vector3.zero;
            var lateral = Vector3.ProjectOnPlane(body.Lateral, vertical).normalized;
            if (lateral.sqrMagnitude < .000001f) lateral = Vector3.right;
            var forward = Vector3.Cross(lateral, vertical).normalized;
            if (Vector3.Dot(forward, body.Forward) < 0f) forward = -forward;
            var center = body.ShoulderCenter + vertical * Mathf.Clamp(height, 0f, torsoHeight);
            var offset = point - center;
            var x = Vector3.Dot(offset, lateral);
            var z = Vector3.Dot(offset, forward);
            var radiusX = Mathf.Max(torsoRadiusX * (Mathf.Clamp01(scale) + .15f) + padding, .025f);
            var radiusZ = Mathf.Max(torsoRadiusZ * (Mathf.Clamp01(scale) + .15f) + padding, .02f);
            var radial = Mathf.Sqrt(x * x / (radiusX * radiusX) + z * z / (radiusZ * radiusZ));
            if (radial >= 1f) return Vector3.zero;
            if (radial < .001f) return forward * radiusZ;
            var surface = center + lateral * (x / radial) + forward * (z / radial) +
                          vertical * (height - Mathf.Clamp(height, 0f, torsoHeight));
            return surface - point;
        }

        private static Vector3 HeadCorrection(Vector3 point, UpperBodyPose body, bool left, float headRadius, float padding)
        {
            var torsoAxis = body.HipCenter - body.ShoulderCenter;
            var torsoHeight = torsoAxis.magnitude;
            if (torsoHeight < .001f) return Vector3.zero;
            var up = -torsoAxis / torsoHeight;
            var head = SphereCorrection(point, body.ShoulderCenter + up * torsoHeight * .62f, headRadius + padding, body, left);
            var neck = SphereCorrection(point, body.ShoulderCenter + up * torsoHeight * .18f, headRadius * .52f + padding, body, left);
            return head.sqrMagnitude > neck.sqrMagnitude ? head : neck;
        }

        private static Vector3 SphereCorrection(Vector3 point, Vector3 center, float radius, UpperBodyPose body, bool left)
        {
            var offset = point - center;
            var distance = offset.magnitude;
            if (distance >= radius) return Vector3.zero;
            if (distance < .001f)
            {
                offset = body.Forward.sqrMagnitude > .000001f ? body.Forward.normalized : Vector3.forward;
            }
            return offset.normalized * (radius - distance);
        }
    }
}

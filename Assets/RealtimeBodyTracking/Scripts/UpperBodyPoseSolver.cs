using UnityEngine;

namespace RealtimeBodyTracking
{
    public readonly struct ArmSolveDiagnostics
    {
        public readonly bool UsedBoundaryRetreat;
        public readonly int BodyCollisionRejects;
        public readonly float SelectedPoleAngle;
        public readonly float LeastCollisionPenalty;

        public ArmSolveDiagnostics(bool usedBoundaryRetreat, int bodyCollisionRejects,
            float selectedPoleAngle, float leastCollisionPenalty)
        {
            UsedBoundaryRetreat = usedBoundaryRetreat;
            BodyCollisionRejects = bodyCollisionRejects;
            SelectedPoleAngle = selectedPoleAngle;
            LeastCollisionPenalty = leastCollisionPenalty;
        }

        public override string ToString()
        {
            return $"stage={(UsedBoundaryRetreat ? "boundary_retreat" : "collision_free")}, " +
                   $"bodyRejects={BodyCollisionRejects}, poleAngle={SelectedPoleAngle:F1}, " +
                   $"leastCollision={LeastCollisionPenalty:F4}";
        }
    }

    public static class UpperBodyPoseSolver
    {
        private const float MaxElbowBendDegrees = 145f;
        private const int CandidateCount = 72;

        public static ArmPose SolveArm(Vector3 shoulder, Vector3 targetWrist, Vector3 elbowHint, UpperBodyPose body,
            bool left, float lowElbowWeight, float upperLength, float lowerLength,
            Vector3 projectionDepthAxis, float projectionDepth, float collisionRadiusScale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius,
            float upperRadius, float lowerRadius, float handRadius,
            bool hasPreviousArm, ArmPose previousArm, bool hasOtherArm, ArmPose otherArm,
            out ArmSolveDiagnostics diagnostics)
        {
            var wrist = targetWrist;
            lowElbowWeight = Mathf.Clamp01(lowElbowWeight);
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
            var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
            var sideDir = lateral * (left ? 1f : -1f);
            var bodyDown = body.Torso.sqrMagnitude > .000001f ? -body.Torso.normalized : Vector3.down;
            var bodyUp = -bodyDown;

            // Calculate upper arm Z-axis displacement directly coupled from hand Z-axis (wrist Z -> upper arm Z)
            var wristZOffset = Vector3.Dot(wrist - shoulder, body.Forward);
            var upperArmZBias = wristZOffset * 0.55f;

            // With palm-only input (unseen elbow), place unseen elbow in front-downward position, extending upper arm forward Z-axis proportionally to hand Z
            var trackedPoleHint = elbowHint - circleCenter;
            if (trackedPoleHint.sqrMagnitude < .0001f)
                trackedPoleHint = sideDir * .65f + bodyDown * .65f + body.Forward * (.25f + upperArmZBias);
            var lowPoleHint = sideDir * .1f + bodyDown + body.Forward * (.2f + upperArmZBias * 0.5f);
            var poleHint = Vector3.Slerp(trackedPoleHint.normalized, lowPoleHint.normalized, lowElbowWeight);
            // When the wrist is raised overhead, bias the bend circle upward as well.
            // Otherwise the IK pole can leave the upper arm horizontal and satisfy the
            // high wrist target by bending only the forearm.
            var wristElevation = Vector3.Dot(wrist - shoulder, bodyUp) / Mathf.Max(upperLength, .0001f);
            var raisedArmWeight = Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(.2f, .85f, wristElevation));
            var raisedPoleHint = (bodyUp + sideDir * .15f + body.Forward * upperArmZBias).normalized;
            poleHint = Vector3.Slerp(poleHint, raisedPoleHint, raisedArmWeight);
            // Palm-only tracking normally puts the elbow forward/down near the torso.
            // Release that drop continuously only for a genuinely overhead wrist.
            var minimumElbowDrop = upperLength * .96f * lowElbowWeight * (1f - raisedArmWeight);

            var anatomicalPole = Vector3.ProjectOnPlane(poleHint + body.Forward * upperArmZBias, direction);
            if (anatomicalPole.sqrMagnitude < .0001f)
            {
                anatomicalPole = Vector3.ProjectOnPlane(sideDir + body.Forward * (1f + upperArmZBias), direction);
                if (anatomicalPole.sqrMagnitude < .0001f)
                    anatomicalPole = Vector3.ProjectOnPlane(Vector3.down + body.Forward * upperArmZBias, direction);
            }
            anatomicalPole.Normalize();

            // poleHint already combines the observed/fallback elbow with the raised-arm
            // correction. Re-reading elbowHint here bypassed that result whenever the
            // low-elbow weight was zero, so the upper arm stayed on the old pole.
            var pole = anatomicalPole;
            if (pole.sqrMagnitude < .0001f) pole = Vector3.ProjectOnPlane(body.Forward, direction);
            pole.Normalize();

            // Direct Analytical IK Solve: Calculate exact elbow position directly coupled with hand Z-axis
            var bestElbow = circleCenter + pole * bendRadius + body.Forward * upperArmZBias;
            var oppositeElbow = circleCenter - (bestElbow - circleCenter);
            if (ElbowFlexionDirectionScore(shoulder, bestElbow, wrist, body.Forward) < 0f &&
                ElbowFlexionDirectionScore(shoulder, oppositeElbow, wrist, body.Forward) > 0f)
                bestElbow = oppositeElbow;
            // Do not aim a palm-only upper arm directly at the wrist: for a palm at
            // shoulder height that creates an immediate horizontal 90-degree humerus.
            // Only a reliably observed elbow receives a small wrist-direction blend.
            var solvedUpperDirection = (bestElbow - shoulder).normalized;
            solvedUpperDirection = Vector3.Slerp(
                solvedUpperDirection, direction, .15f * (1f - lowElbowWeight));
            bestElbow = shoulder + solvedUpperDirection * upperLength;
            var armPose = new ArmPose(shoulder, bestElbow, wrist);

            // Ensure elbow stays outside torso/head body boundaries
            armPose = RetreatToBodyBoundary(armPose, body, left, collisionRadiusScale,
                torsoRadiusX, torsoRadiusZ, headRadius, upperRadius, lowerRadius, handRadius,
                upperLength, lowerLength, minimumElbowDrop);
            var finalDepth = float.IsNaN(projectionDepth) ? wristZOffset * .55f : projectionDepth;
            var finalDepthAxis = float.IsNaN(projectionDepth) ? body.Forward : projectionDepthAxis;
            armPose = ApplyElbowDepth(armPose, finalDepthAxis, finalDepth, upperLength);

            diagnostics = new ArmSolveDiagnostics(false, 0, 0f, 0f);
            return armPose;
        }

        public static Vector3 ProjectHandOutsideBody(Vector3 hand, UpperBodyPose body, bool left,
            float collisionRadiusScale, float torsoRadiusX, float torsoRadiusZ,
            float headRadius, float handRadius)
        {
            return ProjectPointOutsideBody(hand, body, left, collisionRadiusScale,
                torsoRadiusX, torsoRadiusZ, headRadius, handRadius);
        }

        private static float ElbowFlexionDirectionScore(
            Vector3 shoulder, Vector3 elbow, Vector3 wrist, Vector3 bodyForward)
        {
            var upper = elbow - shoulder;
            var forearm = wrist - elbow;
            if (upper.sqrMagnitude < .000001f || forearm.sqrMagnitude < .000001f ||
                bodyForward.sqrMagnitude < .000001f)
                return 0f;

            // The humeroulnar joint is a hinge: flexion must stay on the anterior
            // side of the upper arm. Pronation/supination rotates the forearm around
            // its own axis; it does not permit the elbow to bend backwards.
            var upperDirection = upper.normalized;
            var flexion = Vector3.ProjectOnPlane(forearm.normalized, upperDirection);
            var anterior = Vector3.ProjectOnPlane(bodyForward.normalized, upperDirection);
            if (flexion.sqrMagnitude < .000001f || anterior.sqrMagnitude < .000001f)
                return 0f;
            return Vector3.Dot(flexion.normalized, anterior.normalized);
        }

        private static ArmPose ApplyElbowDepth(ArmPose arm, Vector3 forward, float depth, float upperLength)
        {
            if (forward.sqrMagnitude < .000001f) return arm;
            forward.Normalize();
            depth = Mathf.Clamp(depth, -upperLength * .9f, upperLength * .9f);
            var upper = arm.Elbow - arm.Shoulder;
            var planar = Vector3.ProjectOnPlane(upper, forward);
            if (planar.sqrMagnitude < .000001f) planar = Vector3.down;
            var planarLength = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - depth * depth, 0f));
            var elbow = arm.Shoulder + planar.normalized * planarLength + forward * depth;
            return new ArmPose(arm.Shoulder, elbow, arm.Wrist);
        }

        private static ArmPose RetreatToBodyBoundary(ArmPose arm, UpperBodyPose body, bool left, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float upperRadius, float lowerRadius, float handRadius,
            float upperLength, float lowerLength, float minimumElbowDrop)
        {
            var elbow = arm.Elbow;
            var wrist = arm.Wrist;
            for (var iteration = 0; iteration < 12; iteration++)
            {
                for (var sample = 5; sample <= 20; sample++)
                {
                    var samplePoint = Vector3.Lerp(arm.Shoulder, elbow, sample / 20f);
                    PushSampleOutsideBody(ref samplePoint, ref elbow, body, left, scale, torsoRadiusX, torsoRadiusZ, headRadius, upperRadius);
                }
                for (var sample = 5; sample <= 20; sample++)
                {
                    var samplePoint = Vector3.Lerp(elbow, wrist, sample / 20f);
                    PushSampleOutsideBody(ref samplePoint, ref wrist, body, left, scale, torsoRadiusX, torsoRadiusZ, headRadius, lowerRadius);
                }
                elbow = ProjectPointOutsideBody(elbow, body, left, scale, torsoRadiusX, torsoRadiusZ, headRadius, upperRadius);
                wrist = ProjectPointOutsideBody(wrist, body, left, scale, torsoRadiusX, torsoRadiusZ, headRadius, handRadius);
                var bodyDown = body.Torso.sqrMagnitude > .000001f ? -body.Torso.normalized : Vector3.down;
                var upperDirection = ClampToMinimumDrop(elbow - arm.Shoulder, bodyDown, upperLength, minimumElbowDrop);
                elbow = arm.Shoulder + upperDirection;
                KeepForearmReasonable(ref wrist, arm.Shoulder, elbow, upperLength, lowerLength);
            }
            return new ArmPose(arm.Shoulder, elbow, wrist);
        }

        private static Vector3 ClampToMinimumDrop(Vector3 direction, Vector3 down, float length, float minimumDrop)
        {
            var normalized = direction.sqrMagnitude > .000001f ? direction.normalized : down;
            if (minimumDrop <= 0f) return normalized * length;
            var minimumRatio = Mathf.Clamp01(minimumDrop / Mathf.Max(length, .0001f));
            if (Vector3.Dot(normalized, down) >= minimumRatio) return normalized * length;
            var side = Vector3.ProjectOnPlane(normalized, down);
            if (side.sqrMagnitude < .000001f) side = Vector3.Cross(down, Vector3.forward);
            if (side.sqrMagnitude < .000001f) side = Vector3.right;
            return (down * minimumRatio + side.normalized * Mathf.Sqrt(1f - minimumRatio * minimumRatio)) * length;
        }

        private static Vector3 ProjectPointOutsideBody(Vector3 point, UpperBodyPose body, bool left, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float pointRadius)
        {
            var result = point;
            PushPointOutsideTorso(ref result, body, scale, torsoRadiusX, torsoRadiusZ, pointRadius);
            PushPointOutsideHead(ref result, body, left, headRadius, pointRadius);
            return result;
        }

        private static void PushSampleOutsideBody(ref Vector3 samplePoint, ref Vector3 pointToAdjust, UpperBodyPose body, bool left, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float pointRadius)
        {
            var adjusted = samplePoint;
            PushPointOutsideTorso(ref adjusted, body, scale, torsoRadiusX, torsoRadiusZ, pointRadius);
            PushPointOutsideHead(ref adjusted, body, left, headRadius, pointRadius);
            pointToAdjust += adjusted - samplePoint;
        }

        private static void PushPointOutsideTorso(ref Vector3 point, UpperBodyPose body, float scale, float rx, float rz, float pointRadius)
        {
            var torsoHeight = Mathf.Max(Mathf.Abs(body.ShoulderCenter.y - body.HipCenter.y), .001f);
            if (point.y > body.ShoulderCenter.y + torsoHeight * .35f || point.y < body.HipCenter.y - torsoHeight * .25f) return;
            var heightRatio = Mathf.Clamp01((point.y - body.HipCenter.y) / torsoHeight);
            var center = Vector3.Lerp(body.HipCenter, body.ShoulderCenter, heightRatio);
            var rel = point - center;
            var localX = Vector3.Dot(rel, body.Lateral.normalized);
            var localZ = Vector3.Dot(rel, body.Forward);
            var effRx = (rx + pointRadius) * Mathf.Clamp01(scale);
            var effRz = (rz + pointRadius) * Mathf.Clamp01(scale);
            if (effRx < .001f || effRz < .001f) return;
            var ellipseVal = (localX * localX) / (effRx * effRx) + (localZ * localZ) / (effRz * effRz);
            if (ellipseVal < 1f)
            {
                // Preserve the tracked screen-space hand position and move it to the
                // front surface of the torso. A radial push moved chest-crossing hands
                // sideways, and a point exactly on the torso axis was not moved at all.
                var normalizedX = Mathf.Clamp(localX / effRx, -1f, 1f);
                var surfaceZ = effRz * Mathf.Sqrt(Mathf.Max(1f - normalizedX * normalizedX, 0f));
                point += body.Forward * (surfaceZ - localZ);
            }
        }

        private static void PushPointOutsideHead(ref Vector3 point, UpperBodyPose body, bool left, float headRadius, float pointRadius)
        {
            var headCenter = body.ShoulderCenter + Vector3.up * (headRadius * 1.1f);
            var effRadius = (headRadius + pointRadius) * 0.75f; // Softened head collision to allow hands near face
            var delta = point - headCenter;
            if (delta.sqrMagnitude < effRadius * effRadius && delta.sqrMagnitude > .000001f)
            {
                // A radial push sends a hand below the face when it approaches from underneath.
                // Preserve its tracked height and retreat to the avatar's own side instead.
                var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
                var side = left ? 1f : -1f;
                var vertical = Vector3.Dot(delta, Vector3.up);
                var forward = Vector3.Dot(delta, body.Forward);
                var requiredLateral = Mathf.Sqrt(Mathf.Max(
                    effRadius * effRadius - vertical * vertical - forward * forward, 0f));
                var currentLateral = Vector3.Dot(delta, lateral);
                point += lateral * (side * requiredLateral - currentLateral);
            }
        }

        private static void KeepForearmReasonable(ref Vector3 wrist, Vector3 shoulder, Vector3 elbow, float upperLength, float lowerLength)
        {
            var upper = elbow - shoulder;
            var fore = wrist - elbow;
            if (upper.sqrMagnitude < .000001f || fore.sqrMagnitude < .000001f) return;
            var upperDir = upper.normalized;
            var foreLength = fore.magnitude;
            var dot = Vector3.Dot(upperDir, fore.normalized);
            if (dot < -.85f)
                wrist = elbow + Vector3.ProjectOnPlane(fore, upperDir).normalized * foreLength;
        }

        private static float ArmCollisionPenalty(ArmPose arm, UpperBodyPose body, float scale,
            float torsoRadiusX, float torsoRadiusZ, float headRadius, float upperRadius, float lowerRadius)
        {
            var penalty = 0f;
            for (var sample = 1; sample <= 5; sample++)
            {
                var segmentT = sample / 5f;
                var upperSample = Vector3.Lerp(arm.Shoulder, arm.Elbow, segmentT);
                var shoulderPortal = Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(.2f, .8f, segmentT));
                penalty += PointCollisionPenalty(
                    upperSample, body, scale, torsoRadiusX, torsoRadiusZ, headRadius,
                    upperRadius * shoulderPortal, true, arm.Shoulder);
                var lowerSample = Vector3.Lerp(arm.Elbow, arm.Wrist, segmentT);
                penalty += PointCollisionPenalty(lowerSample, body, scale, torsoRadiusX, torsoRadiusZ, headRadius, lowerRadius);
            }
            return penalty;
        }

        private static float PointCollisionPenalty(Vector3 point, UpperBodyPose body, float scale,
            float rx, float rz, float headRadius, float pointRadius,
            bool allowShoulderSeam = false, Vector3 shoulder = default)
        {
            var torsoHeight = Mathf.Max(Mathf.Abs(body.ShoulderCenter.y - body.HipCenter.y), .001f);
            var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
            var pointLateral = Vector3.Dot(point - body.ShoulderCenter, lateral);
            var shoulderLateral = Vector3.Dot(shoulder - body.ShoulderCenter, lateral);
            var inShoulderSeam = allowShoulderSeam &&
                                 pointLateral * shoulderLateral > 0f &&
                                 Mathf.Abs(pointLateral) >= Mathf.Abs(shoulderLateral) * .82f;
            if (!inShoulderSeam &&
                point.y <= body.ShoulderCenter.y + torsoHeight * .35f &&
                point.y >= body.HipCenter.y - torsoHeight * .25f)
            {
                var heightRatio = Mathf.Clamp01((point.y - body.HipCenter.y) / torsoHeight);
                var center = Vector3.Lerp(body.HipCenter, body.ShoulderCenter, heightRatio);
                var rel = point - center;
                var localX = Vector3.Dot(rel, lateral);
                var localZ = Vector3.Dot(rel, body.Forward);
                var effRx = (rx + pointRadius) * Mathf.Clamp01(scale);
                var effRz = (rz + pointRadius) * Mathf.Clamp01(scale);
                if (effRx > .001f && effRz > .001f)
                {
                    var val = (localX * localX) / (effRx * effRx) + (localZ * localZ) / (effRz * effRz);
                    if (val < 1f) return 1f - val;
                }
            }
            var headCenter = body.ShoulderCenter + Vector3.up * (headRadius * 1.1f);
            var effHeadRadius = (headRadius + pointRadius) * 0.75f;
            var distSq = (point - headCenter).sqrMagnitude;
            if (distSq < effHeadRadius * effHeadRadius)
            {
                return 1f - Mathf.Sqrt(distSq) / effHeadRadius;
            }
            return 0f;
        }

        private static float ArmPairCollisionPenalty(ArmPose arm, ArmPose other, float minDist)
        {
            var distSq = (arm.Wrist - other.Wrist).sqrMagnitude;
            if (distSq < minDist * minDist) return 1f - Mathf.Sqrt(distSq) / minDist;
            return 0f;
        }
    }
}

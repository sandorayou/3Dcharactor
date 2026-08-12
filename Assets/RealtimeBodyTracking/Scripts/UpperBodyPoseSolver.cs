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
        public static ArmPose SolveArm(Vector3 shoulder, Vector3 targetWrist, Vector3 elbowHint,
            UpperBodyPose body, bool left, bool elbowObserved, float upperLength, float lowerLength,
            out ArmSolveDiagnostics diagnostics)
        {
            var wrist = targetWrist;
            var minReach = Mathf.Abs(upperLength - lowerLength) + .0001f;
            var toWrist = wrist - shoulder;
            var direction = toWrist.sqrMagnitude > .000001f ? toWrist.normalized : Vector3.down;
            var maximumReach = upperLength + lowerLength - .0001f;
            var requestedDistance = toWrist.magnitude;
            if (elbowObserved)
            {
                var observedUpper = Vector3.Distance(shoulder, elbowHint);
                var observedLower = Vector3.Distance(elbowHint, targetWrist);
                var observedPath = observedUpper + observedLower;
                if (observedPath > .001f)
                {
                    var straightness = Vector3.Distance(shoulder, targetWrist) / observedPath;
                    if (straightness > .9f) requestedDistance = maximumReach;
                }
            }
            var distance = Mathf.Clamp(requestedDistance, minReach, maximumReach);
            wrist = shoulder + direction * distance;
            var along = (upperLength * upperLength - lowerLength * lowerLength + distance * distance) / (2f * distance);
            var bendRadius = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - along * along, 0f));
            var circleCenter = shoulder + direction * along;
            var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
            var sideDir = lateral * (left ? 1f : -1f);
            var bodyDown = body.Torso.sqrMagnitude > .000001f ? -body.Torso.normalized : Vector3.down;
            // A visible elbow supplies the pole directly. If it is hidden, use one
            // stable anatomical fallback: mostly down, slightly outward and forward.
            var poleHint = elbowObserved
                ? elbowHint - circleCenter
                : bodyDown * .9f + sideDir * .2f + body.Forward * .25f;
            var pole = Vector3.ProjectOnPlane(poleHint, direction);
            if (pole.sqrMagnitude < .0001f)
                pole = Vector3.ProjectOnPlane(bodyDown + sideDir * .2f + body.Forward * .25f, direction);
            if (pole.sqrMagnitude < .0001f) pole = Vector3.ProjectOnPlane(sideDir, direction);
            pole.Normalize();
            var armPose = new ArmPose(shoulder, circleCenter + pole * bendRadius, wrist);

            diagnostics = new ArmSolveDiagnostics(false, 0, 0f, 0f);
            return armPose;
        }

    }
}

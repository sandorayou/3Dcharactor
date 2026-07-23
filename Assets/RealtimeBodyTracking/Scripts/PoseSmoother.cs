using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class PoseSmoother
    {
        private readonly Dictionary<HumanBodyBones, Quaternion> stableTargets = new();

        public Quaternion Smooth(HumanBodyBones bone, Quaternion current, Quaternion target, float speed, float deadZoneDegrees, float deltaTime)
        {
            if (stableTargets.TryGetValue(bone, out var stable))
            {
                if (Quaternion.Dot(stable, target) < 0f)
                    target = new Quaternion(-target.x, -target.y, -target.z, -target.w);
                var delta = Quaternion.Angle(stable, target);
                if (delta <= deadZoneDegrees)
                    target = stable;
                else
                    target = Quaternion.RotateTowards(stable, target, delta - deadZoneDegrees);
            }
            stableTargets[bone] = target;
            var t = 1f - Mathf.Exp(-speed * deltaTime);
            return Quaternion.Slerp(current, target, t);
        }

        public void Reset()
        {
            stableTargets.Clear();
        }
    }
}

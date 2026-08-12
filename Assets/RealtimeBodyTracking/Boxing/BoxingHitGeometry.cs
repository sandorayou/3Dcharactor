using UnityEngine;

namespace RealtimeBodyTracking.Boxing
{
    internal static class BoxingHitGeometry
    {
        public static float PointSegmentDistance(Vector3 point, Vector3 start, Vector3 end)
        {
            var segment = end - start;
            if (segment.sqrMagnitude < .000001f) return Vector3.Distance(point, start);
            var t = Mathf.Clamp01(Vector3.Dot(point - start, segment) / segment.sqrMagnitude);
            return Vector3.Distance(point, start + segment * t);
        }

        public static float SegmentSegmentDistance(Vector3 a0, Vector3 a1, Vector3 b0, Vector3 b1)
        {
            var u = a1 - a0;
            var v = b1 - b0;
            var w = a0 - b0;
            var a = Vector3.Dot(u, u);
            var b = Vector3.Dot(u, v);
            var c = Vector3.Dot(v, v);
            var d = Vector3.Dot(u, w);
            var e = Vector3.Dot(v, w);
            var denominator = a * c - b * b;
            var s = denominator < .000001f ? 0f : Mathf.Clamp01((b * e - c * d) / denominator);
            var t = c < .000001f ? 0f : Mathf.Clamp01((b * s + e) / c);
            if (a > .000001f) s = Mathf.Clamp01((b * t - d) / a);
            return Vector3.Distance(a0 + u * s, b0 + v * t);
        }
    }
}

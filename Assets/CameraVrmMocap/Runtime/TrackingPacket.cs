using System;
using System.Collections.Generic;
using UnityEngine;

namespace CameraVrmMocap
{
    [Serializable] public sealed class TrackingPoint
    {
        public string name;
        public float x, y, z, u, v, d, confidence;
        public Vector3 World => new(x, -y, -z);
        public Vector2 Image => new(u, v);
    }

    [Serializable] public sealed class TrackingPacket
    {
        public int frame;
        public long timestampMs;
        public TrackingPoint[] points;

        public Dictionary<string, TrackingPoint> Index()
        {
            var result = new Dictionary<string, TrackingPoint>();
            if (points == null) return result;
            foreach (var item in points)
                if (item != null && !string.IsNullOrEmpty(item.name)) result[item.name] = item;
            return result;
        }
    }
}

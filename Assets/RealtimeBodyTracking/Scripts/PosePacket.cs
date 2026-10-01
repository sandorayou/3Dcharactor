using System;
using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking
{
    [Serializable]
    public sealed class PosePoint
    {
        public string name;
        public float x;
        public float y;
        public float z;
        public float confidence;
        public float image_x;
        public float image_y;
        public float image_z;

        public Vector3 Position => new Vector3(x, y, z);
        public Vector3 ImagePosition => new Vector3(image_x, image_y, image_z);
    }

    [Serializable]
    public sealed class PoseRotation
    {
        public float x;
        public float y;
        public float z;
        public float w;

        public Quaternion Rotation => new Quaternion(x, y, z, w);
    }

    [Serializable]
    public sealed class FaceBlendshape
    {
        public string name;
        public float score;
    }

    [Serializable]
    public sealed class PosePacket
    {
        public int version;
        public long frame;
        public long timestamp_ms;
        public int source_width;
        public int source_height;
        public bool tracking;
        public PoseRotation head_rotation;
        public List<FaceBlendshape> face_blendshapes;
        public List<PosePoint> points;

        public float GetFaceBlendshape(string name)
        {
            if (version >= 4 && face_blendshapes != null)
            {
                foreach (var blendshape in face_blendshapes)
                    if (blendshape.name == name)
                        return Mathf.Clamp01(blendshape.score);
            }
            return 0f;
        }

        public bool TryGetHeadRotation(out Quaternion rotation)
        {
            if (version >= 3 && head_rotation != null)
            {
                rotation = head_rotation.Rotation.normalized;
                return true;
            }
            rotation = Quaternion.identity;
            return false;
        }

        public bool TryGet(string landmark, out Vector3 position)
        {
            return TryGet(landmark, 0.001f, out position);
        }

        public bool TryGet(string landmark, float minConfidence, out Vector3 position)
        {
            if (points != null)
            {
                foreach (var point in points)
                {
                    if (point.name == landmark && point.confidence >= minConfidence)
                    {
                        position = point.Position;
                        return true;
                    }
                }
            }
            position = default;
            return false;
        }

        public bool TryGetImage(string landmark, out Vector3 position)
        {
            return TryGetImage(landmark, 0.001f, out position);
        }

        public bool TryGetConfidence(string landmark, out float confidence)
        {
            if (points != null)
            {
                foreach (var point in points)
                {
                    if (point.name != landmark) continue;
                    confidence = point.confidence;
                    return true;
                }
            }
            confidence = 0f;
            return false;
        }

        public bool TryGetImage(string landmark, float minConfidence, out Vector3 position)
        {
            if (version >= 2 && points != null)
            {
                foreach (var point in points)
                {
                    if (point.name == landmark && point.confidence >= minConfidence)
                    {
                        position = point.ImagePosition;
                        return true;
                    }
                }
            }
            position = default;
            return false;
        }
    }
}

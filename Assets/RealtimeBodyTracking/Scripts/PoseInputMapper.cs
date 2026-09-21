using UnityEngine;

namespace RealtimeBodyTracking
{
    public readonly struct UpperBodyPose
    {
        public readonly Vector3 LeftShoulder;
        public readonly Vector3 RightShoulder;
        public readonly Vector3 ShoulderCenter;
        public readonly Vector3 HipCenter;
        public readonly Vector3 Lateral;
        public readonly Vector3 Torso;
        public readonly Vector3 Forward;
        public readonly Vector3 ImageLateral;
        public readonly bool HipsTracked;

        public UpperBodyPose(Vector3 leftShoulder, Vector3 rightShoulder, Vector3 hipCenter, bool hipsTracked, Vector3 facing = default, Vector3 imageLateral = default)
        {
            LeftShoulder = leftShoulder;
            RightShoulder = rightShoulder;
            ShoulderCenter = (leftShoulder + rightShoulder) * .5f;
            HipCenter = hipCenter;
            Lateral = rightShoulder - leftShoulder;
            Torso = ShoulderCenter - hipCenter;
            HipsTracked = hipsTracked;
            ImageLateral = imageLateral;
            var forward = Vector3.Cross(Lateral, Torso);
            Forward = facing.sqrMagnitude > .000001f ? facing.normalized : forward.sqrMagnitude > .000001f ? forward.normalized : Vector3.forward;
        }
    }

    public readonly struct ArmPose
    {
        public readonly Vector3 Shoulder;
        public readonly Vector3 Elbow;
        public readonly Vector3 Wrist;

        public ArmPose(Vector3 shoulder, Vector3 elbow, Vector3 wrist)
        {
            Shoulder = shoulder;
            Elbow = elbow;
            Wrist = wrist;
        }
    }

    public readonly struct ScreenBodyPose
    {
        public readonly Vector2 Anchor;
        public readonly Vector2 ShoulderCenter;
        public readonly float ShoulderWidth;
        public readonly float LeanSignal;
        public readonly int ShoulderMode;
        public readonly float ShoulderDirection;

        public ScreenBodyPose(Vector2 anchor, Vector2 shoulderCenter, float shoulderWidth, float leanSignal, int shoulderMode, float shoulderDirection)
        {
            Anchor = anchor;
            ShoulderCenter = shoulderCenter;
            ShoulderWidth = shoulderWidth;
            LeanSignal = leanSignal;
            ShoulderMode = shoulderMode;
            ShoulderDirection = shoulderDirection;
        }
    }

    public readonly struct ScreenAlignmentSolution
    {
        public readonly Vector2 SourceCenter;
        public readonly Vector2 AvatarCenter;
        public readonly float SourceWidth;
        public readonly float AvatarWidth;
        public readonly float TargetDepth;

        public ScreenAlignmentSolution(
            Vector2 sourceCenter, Vector2 avatarCenter,
            float sourceWidth, float avatarWidth, float targetDepth)
        {
            SourceCenter = sourceCenter;
            AvatarCenter = avatarCenter;
            SourceWidth = sourceWidth;
            AvatarWidth = avatarWidth;
            TargetDepth = targetDepth;
        }
    }

    public static class PoseInputMapper
    {
        public static Vector2 ImageToViewport(Vector2 image, int width, int height, float viewportAspect, bool mirror)
        {
            var point = new Vector2(mirror ? 1f - image.x : image.x, 1f - image.y);
            if (width <= 0 || height <= 0 || viewportAspect <= 0f) return point;
            var sourceAspect = (float)width / height;
            // The native preview fills its layer and crops the excess image.
            if (viewportAspect < sourceAspect)
                point.x = .5f + (point.x - .5f) * sourceAspect / viewportAspect;
            else
                point.y = .5f + (point.y - .5f) * viewportAspect / sourceAspect;
            return point;
        }

        public static bool TryReadPreviewShoulders(
            PosePacket pose, float viewportAspect, bool previewMirrored, float minConfidence,
            out Vector2 leftShoulder, out Vector2 rightShoulder)
        {
            leftShoulder = default;
            rightShoulder = default;
            if (pose == null ||
                !pose.TryGetImage("left_shoulder", minConfidence, out var left) ||
                !pose.TryGetImage("right_shoulder", minConfidence, out var right) ||
                !IsFiniteImagePoint(left) || !IsFiniteImagePoint(right))
                return false;

            leftShoulder = ImageToViewport(
                new Vector2(left.x, left.y), pose.source_width, pose.source_height,
                viewportAspect, previewMirrored);
            rightShoulder = ImageToViewport(
                new Vector2(right.x, right.y), pose.source_width, pose.source_height,
                viewportAspect, previewMirrored);
            return Vector2.Distance(leftShoulder, rightShoulder) >= .01f;
        }

        public static bool TrySolveScreenAlignment(
            Vector2 sourceLeft, Vector2 sourceRight,
            Vector2 avatarLeft, Vector2 avatarRight,
            float currentDepth, float minimumDepth, float maximumDepth,
            out ScreenAlignmentSolution solution)
        {
            solution = default;
            var sourceWidth = Vector2.Distance(sourceLeft, sourceRight);
            var avatarWidth = Vector2.Distance(avatarLeft, avatarRight);
            if (!IsFinite(sourceWidth) || !IsFinite(avatarWidth) || !IsFinite(currentDepth) ||
                sourceWidth < .01f || avatarWidth < .0001f || currentDepth <= .05f)
                return false;

            var targetDepth = Mathf.Clamp(
                currentDepth * avatarWidth / sourceWidth,
                Mathf.Max(minimumDepth, .05f), Mathf.Max(maximumDepth, minimumDepth));
            solution = new ScreenAlignmentSolution(
                (sourceLeft + sourceRight) * .5f,
                (avatarLeft + avatarRight) * .5f,
                sourceWidth, avatarWidth, targetDepth);
            return true;
        }

        private static bool IsFiniteImagePoint(Vector3 point)
        {
            return IsFinite(point.x) && IsFinite(point.y);
        }

        private static bool IsFinite(float value)
        {
            return !float.IsNaN(value) && !float.IsInfinity(value);
        }

        public static bool SourceIsLeftForAvatarSide(bool avatarLeft, bool displayedPreviewMirrored)
        {
            // A mirrored preview swaps which anatomical limb is drawn under each
            // screen-space avatar limb. Rear/unmirrored preview preserves it.
            return avatarLeft != displayedPreviewMirrored;
        }

        public static bool TryGet(PosePacket pose, string name, bool mirror, out Vector3 position)
        {
            return TryGet(pose, name, mirror, 0.001f, out position);
        }

        public static bool TryGet(PosePacket pose, string name, bool mirror, float minConfidence, out Vector3 position)
        {
            if (!pose.TryGet(name, minConfidence, out var mediaPipe)) { position = default; return false; }
            position = new Vector3(mediaPipe.x, -mediaPipe.y, -mediaPipe.z);
            if (mirror) position.x = -position.x;
            return true;
        }

        public static bool TryGetVisible(PosePacket pose, string name, bool mirror, float minConfidence, out Vector3 position)
        {
            if (!TryGet(pose, name, mirror, minConfidence, out position) || !pose.TryGetImage(name, minConfidence, out var image))
            {
                position = default;
                return false;
            }
            if (!IsInsideImage(image))
            {
                position = default;
                return false;
            }
            return true;
        }

        public static bool TryReadUpperBody(PosePacket pose, bool mirror, float bodyMinConfidence, out UpperBodyPose upperBody)
        {
            if (!TryGet(pose, "left_shoulder", mirror, bodyMinConfidence, out var leftShoulder) ||
                !TryGet(pose, "right_shoulder", mirror, bodyMinConfidence, out var rightShoulder))
            {
                upperBody = default;
                return false;
            }

            var hasLeftHip = TryGet(pose, "left_hip", mirror, bodyMinConfidence, out var leftHip) && TryGetVisibleImage(pose, "left_hip", bodyMinConfidence, out _);
            var hasRightHip = TryGet(pose, "right_hip", mirror, bodyMinConfidence, out var rightHip) && TryGetVisibleImage(pose, "right_hip", bodyMinConfidence, out _);
            var hipsTracked = hasLeftHip && hasRightHip;
            var shoulderCenter = (leftShoulder + rightShoulder) * .5f;
            var shoulderWidth = Mathf.Max((rightShoulder - leftShoulder).magnitude, .001f);
            var hipCenter = hipsTracked ? (leftHip + rightHip) * .5f : shoulderCenter + Vector3.down * Mathf.Max(shoulderWidth * 1.45f, .35f);
            var hasImageFacing = TryReadImageFacing(pose, mirror, bodyMinConfidence, out var imageFacing, out var imageLateral);
            upperBody = new UpperBodyPose(leftShoulder, rightShoulder, hipCenter, hipsTracked, hasImageFacing ? imageFacing : Vector3.zero, imageLateral);
            return true;
        }

        private static bool TryReadImageFacing(PosePacket pose, bool mirror, float minConfidence, out Vector3 facing, out Vector3 imageLateral)
        {
            if (!TryGetVisibleImage(pose, "left_shoulder", minConfidence, out var leftShoulder) ||
                !TryGetVisibleImage(pose, "right_shoulder", minConfidence, out var rightShoulder) ||
                !TryGetVisibleImage(pose, "left_hip", minConfidence, out var leftHip) ||
                !TryGetVisibleImage(pose, "right_hip", minConfidence, out var rightHip))
            {
                facing = default;
                imageLateral = default;
                return false;
            }
            leftShoulder = MapImagePoint(leftShoulder, mirror);
            rightShoulder = MapImagePoint(rightShoulder, mirror);
            leftHip = MapImagePoint(leftHip, mirror);
            rightHip = MapImagePoint(rightHip, mirror);
            imageLateral = rightShoulder - leftShoulder + (rightHip - leftHip) * .5f;
            var torsoHeight = Mathf.Max(Mathf.Abs((leftShoulder.y + rightShoulder.y - leftHip.y - rightHip.y) * .5f), .001f);
            imageLateral /= torsoHeight;
            imageLateral.y = 0f;
            facing = Vector3.Cross(imageLateral, Vector3.up);
            return facing.sqrMagnitude > .000001f;
        }

        private static bool TryGetVisibleImage(PosePacket pose, string name, float minConfidence, out Vector3 image)
        {
            return pose.TryGetImage(name, minConfidence, out image) && IsInsideImage(image);
        }

        private static bool IsInsideImage(Vector3 image)
        {
            const float edgeMargin = .06f;
            return image.x >= edgeMargin && image.x <= 1f - edgeMargin && image.y >= edgeMargin && image.y <= 1f - edgeMargin;
        }

        public static bool TryReadScreenBody(PosePacket pose, bool mirror, float minConfidence, out ScreenBodyPose body)
        {
            // Keep following landmarks a little beyond the frame. MediaPipe still
            // returns useful shoulder positions while a person walks out of shot.
            var hasLeft = TryGetFramingImage(pose, "left_shoulder", minConfidence, out var leftShoulder);
            var hasRight = TryGetFramingImage(pose, "right_shoulder", minConfidence, out var rightShoulder);
            if (!hasLeft && !hasRight)
            {
                if (!TryGetFramingImage(pose, "left_eye", minConfidence, out var leftEye) ||
                    !TryGetFramingImage(pose, "right_eye", minConfidence, out var rightEye))
                {
                    body = default;
                    return false;
                }

                leftEye = MapImagePoint(leftEye, mirror);
                rightEye = MapImagePoint(rightEye, mirror);

                var eyeCenter = (leftEye + rightEye) * 0.5f;

                // 顔だけの場合はサイズ計算をApplyHipsへ渡さない
                body = new ScreenBodyPose(
                    eyeCenter,
                    eyeCenter,
                    0f,
                    0f,
                    2,
                    Mathf.Sign(rightEye.x - leftEye.x)
                );

                return true;
            }
            if (hasLeft) leftShoulder = MapImagePoint(leftShoulder, mirror);
            if (hasRight) rightShoulder = MapImagePoint(rightShoulder, mirror);
            if (hasLeft && hasRight)
            {
                var lateral = rightShoulder - leftShoulder;
                var width = Mathf.Abs(lateral.x);
                if (width < .05f || width > .9f) { body = default; return false; }
                var center = (leftShoulder + rightShoulder) * .5f;
                var lean = Mathf.Atan(lateral.y / lateral.x) * Mathf.Rad2Deg;
                var anchor = EstimateHipAnchor(pose, mirror, minConfidence, center, lateral, width);
                body = new ScreenBodyPose(anchor, new Vector2(center.x, center.y), width, lean, 0, Mathf.Sign(lateral.x));
                return true;
            }

            if (!TryGetFramingImage(pose, "nose", minConfidence, out var nose)) { body = default; return false; }
            nose = MapImagePoint(nose, mirror);
            var shoulder = hasLeft ? leftShoulder : rightShoulder;
            var single = new Vector2(shoulder.x, shoulder.y);
            var estimatedWidth = 0f;
            var estimatedCenter = single;
            var faceAnchor = nose;
            if (TryGetFramingImage(pose, "left_ear", minConfidence, out var leftEar) &&
                TryGetFramingImage(pose, "right_ear", minConfidence, out var rightEar))
            {
                leftEar = MapImagePoint(leftEar, mirror);
                rightEar = MapImagePoint(rightEar, mirror);
                faceAnchor = (leftEar + rightEar) * .5f;
                estimatedWidth = Mathf.Clamp(Mathf.Abs(rightEar.x - leftEar.x) * 3.2f, .08f, .65f);
                estimatedCenter.x += (hasLeft ? -1f : 1f) * estimatedWidth * .5f;
            }
            var faceOffset = faceAnchor - shoulder;
            if (estimatedWidth <= .001f)
            {
                estimatedWidth = Mathf.Clamp(Mathf.Abs(faceOffset.y) * 1.6f, .08f, .65f);
                estimatedCenter.x += (hasLeft ? -1f : 1f) * estimatedWidth * .5f;
            }
            var leanSignal = Mathf.Atan2(faceOffset.x, Mathf.Max(Mathf.Abs(faceOffset.y), .001f)) * Mathf.Rad2Deg;
            body = new ScreenBodyPose(single, estimatedCenter, estimatedWidth, leanSignal, hasLeft ? -1 : 1, 0f);
            return true;
        }

        private static bool TryGetFramingImage(PosePacket pose, string name, float minConfidence, out Vector3 image)
        {
            if (!pose.TryGetImage(name, minConfidence, out image)) return false;
            return image.x >= -.35f && image.x <= 1.35f && image.y >= -.25f && image.y <= 1.35f;
        }

        private static Vector2 EstimateHipAnchor(PosePacket pose, bool mirror, float minConfidence, Vector3 shoulderCenter, Vector3 lateral, float shoulderWidth)
        {
            if (TryGetVisibleImage(pose, "left_hip", minConfidence, out var leftHip) &&
                TryGetVisibleImage(pose, "right_hip", minConfidence, out var rightHip))
            {
                leftHip = MapImagePoint(leftHip, mirror);
                rightHip = MapImagePoint(rightHip, mirror);
                var hipCenter = (leftHip + rightHip) * .5f;
                return new Vector2(hipCenter.x, hipCenter.y);
            }
            var down = new Vector2(lateral.y, -lateral.x).normalized;
            if (down.y > 0f) down = -down;
            return new Vector2(shoulderCenter.x, shoulderCenter.y) + down * shoulderWidth * 1.45f;
        }

        public static bool TryReadHeadRoll(PosePacket pose, bool mirror, float minConfidence, out float roll)
        {
            var hasLeftEye = TryGetVisibleImage(pose, "left_eye", minConfidence, out var left);
            var hasRightEye = TryGetVisibleImage(pose, "right_eye", minConfidence, out var right);
            var hasEyes = hasLeftEye && hasRightEye;
            if (!hasEyes)
            {
                var hasLeftEar = TryGetVisibleImage(pose, "left_ear", minConfidence, out left);
                var hasRightEar = TryGetVisibleImage(pose, "right_ear", minConfidence, out right);
                if (!hasLeftEar || !hasRightEar)
                {
                    roll = 0f;
                    return false;
                }
            }
            left = MapImagePoint(left, mirror);
            right = MapImagePoint(right, mirror);
            var lateral = right - left;
            // A shoulder/eye line is an undirected roll axis. Anatomical right is
            // screen-left in an unmirrored front view; atan2 alone returns +/-180
            // there and flips sign whenever near-level landmark noise crosses zero.
            if (lateral.x < 0f) lateral = -lateral;
            roll = Mathf.Atan2(lateral.y, lateral.x) * Mathf.Rad2Deg;
            return Mathf.Abs(lateral.x) > (hasEyes ? .025f : .04f);
        }

        public static bool TryReadHeadFacing(PosePacket pose, bool mirror, float minConfidence, out Vector3 facing)
        {
            if (!pose.TryGetImage("nose", minConfidence, out var nose))
            {
                facing = default;
                return false;
            }
            var hasLeftEar = pose.TryGetImage("left_ear", minConfidence, out var leftEar);
            var hasRightEar = pose.TryGetImage("right_ear", minConfidence, out var rightEar);
            if (!hasLeftEar && !hasRightEar)
            {
                facing = default;
                return false;
            }
            nose = MapImagePoint(nose, mirror);
            if (hasLeftEar) leftEar = MapImagePoint(leftEar, mirror);
            if (hasRightEar) rightEar = MapImagePoint(rightEar, mirror);
            var earCenter = hasLeftEar && hasRightEar ? (leftEar + rightEar) * .5f : hasLeftEar ? leftEar : rightEar;
            facing = nose - earCenter;
            return facing.sqrMagnitude > .000001f;
        }

        private static Vector3 MapImagePoint(Vector3 point, bool mirror)
        {
            var mapped = new Vector3(point.x, -point.y, -point.z);
            if (mirror) mapped.x = -mapped.x;
            return mapped;
        }

        public static bool TryReadArm(PosePacket pose, bool mirror, bool left, Vector3 shoulder, out ArmPose arm)
        {
            var elbowName = left ? "left_elbow" : "right_elbow";
            var wristName = left ? "left_wrist" : "right_wrist";
            if (!TryGet(pose, elbowName, mirror, out var elbow) || !TryGet(pose, wristName, mirror, out var wrist))
            {
                arm = default;
                return false;
            }
            arm = new ArmPose(shoulder, elbow, wrist);
            return true;
        }
    }
}

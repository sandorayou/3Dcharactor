using System;
using UnityEngine;

namespace RealtimeBodyTracking
{
    [Serializable]
    public class ScreenSpaceFramingController
    {
        [Header("Framing Confidence & Timing")]
        [SerializeField] private float framingMinConfidence = 0.55f;
        [SerializeField] private int acquireFrames = 3;
        [SerializeField] private float lostHoldTime = 0.25f;

        [Header("Measurement Speed & Dead Zone")]
        [SerializeField] private float positionMeasurementSpeed = 10f;
        [SerializeField] private float sizeMeasurementSpeed = 6f;
        [SerializeField] private float positionDeadZone = 0.004f;
        [SerializeField] private float sizeDeadZoneRatio = 0.01f;

        [Header("Smoothing")]
        [SerializeField] private float xySmoothTime = 0.10f;
        [SerializeField] private float faceZoomSmoothTime = 0.18f;
        [SerializeField] private float maxXYSpeed = 2.0f;
        [SerializeField] private float maxCameraSpeed = 5.0f;

        [Header("Depth Limits")]
        [SerializeField] private float minimumCameraDistance = 0.55f;
        [SerializeField] private float maximumCameraDistance = 8.0f;

        [Header("Outlier Rejection")]
        [SerializeField] private float widthJumpMinRatio = 0.80f;
        [SerializeField] private float widthJumpMaxRatio = 1.25f;
        [SerializeField] private int outlierConfirmationFrames = 3;

        [Header("Mirror & Framing Options")]
        [SerializeField] private bool mirrorFramingX = true;
        [SerializeField] private bool resetRootPositionOnLongLost = false;

        // Internal states
        private Animator animator;
        private Camera camera;
        private Transform rootTransform;
        private Vector3 rootOriginPosition;
        private bool isInitialized;

        private Vector2 filteredSourceAnchor;
        private float filteredSourceWidth;
        private bool hasFilteredState;

        private Vector2 faceToShoulderOffset;
        private bool hasFaceToShoulderOffset;
        private float filteredSourceFaceWidth;
        private bool hasSourceFaceWidth;

        private int outlierCounter;
        private float pendingOutlierWidth;
        private Vector2 pendingOutlierAnchor;

        private int trackingAcquiredCounter;
        private float lostDuration;

        private float velocityX;
        private float velocityY;
        private float cameraDistanceVelocity;

        private double lastSubmitTime;

        public bool IsInitialized => isInitialized;

        public void Initialize(Animator targetAnimator, Camera trackingCamera)
        {
            if (targetAnimator == null || trackingCamera == null)
            {
                Debug.LogWarning("[ScreenSpaceFramingController] Animator or Camera is null.");
                return;
            }

            animator = targetAnimator;
            camera = trackingCamera;
            rootTransform = animator.transform;
            rootOriginPosition = rootTransform.position;

            hasFilteredState = false;
            hasFaceToShoulderOffset = false;
            hasSourceFaceWidth = false;
            outlierCounter = 0;
            trackingAcquiredCounter = 0;
            lostDuration = 0f;
            velocityX = 0f;
            velocityY = 0f;
            cameraDistanceVelocity = 0f;
            lastSubmitTime = Time.unscaledTimeAsDouble;

            isInitialized = true;
        }

        public void ResetTracking(bool resetRootPosition)
        {
            hasFilteredState = false;
            hasSourceFaceWidth = false;
            outlierCounter = 0;
            trackingAcquiredCounter = 0;
            lostDuration = 0f;
            velocityX = 0f;
            velocityY = 0f;
            cameraDistanceVelocity = 0f;

            if (resetRootPosition && isInitialized && rootTransform != null)
            {
                rootTransform.position = rootOriginPosition;
            }
        }

        private Vector2 SourceToViewport(Vector2 imagePoint, int sourceWidth, int sourceHeight, Camera cam)
        {
            if (sourceWidth <= 0 || sourceHeight <= 0 || cam == null)
            {
                return new Vector2(imagePoint.x, 1f - imagePoint.y);
            }

            float sourceAspect = (float)sourceWidth / sourceHeight;
            float targetAspect = cam.aspect;

            float x = imagePoint.x;
            float y = 1f - imagePoint.y;

            if (targetAspect > sourceAspect)
            {
                float contentWidth = sourceAspect / targetAspect;
                x = 0.5f + (x - 0.5f) * contentWidth;
            }
            else
            {
                float contentHeight = targetAspect / sourceAspect;
                y = 0.5f + (y - 0.5f) * contentHeight;
            }

            return new Vector2(x, y);
        }

        public void SubmitMeasurement(PosePacket pose)
        {
            if (!isInitialized || pose == null) return;

            double now = Time.unscaledTimeAsDouble;
            float measurementDeltaTime = (float)Math.Max(0.001, now - lastSubmitTime);
            lastSubmitTime = now;

            bool hasLeftShoulder = pose.TryGetImage("left_shoulder", framingMinConfidence, out var leftShoulderPos)
                                   && pose.TryGetConfidence("left_shoulder", out float leftConf) && leftConf >= framingMinConfidence;
            bool hasRightShoulder = pose.TryGetImage("right_shoulder", framingMinConfidence, out var rightShoulderPos)
                                    && pose.TryGetConfidence("right_shoulder", out float rightConf) && rightConf >= framingMinConfidence;

            bool hasNose = pose.TryGetImage("nose", framingMinConfidence, out var nosePos)
                           && pose.TryGetConfidence("nose", out float noseConf) && noseConf >= framingMinConfidence;
            bool hasLeftEar = pose.TryGetImage("left_ear", framingMinConfidence, out var leftEarPos);
            bool hasRightEar = pose.TryGetImage("right_ear", framingMinConfidence, out var rightEarPos);
            bool hasLeftEye = pose.TryGetImage("left_eye", framingMinConfidence, out var leftEyePos);
            bool hasRightEye = pose.TryGetImage("right_eye", framingMinConfidence, out var rightEyePos);

            int sourceW = pose.source_width > 0 ? pose.source_width : 640;
            int sourceH = pose.source_height > 0 ? pose.source_height : 480;

            if (hasLeftShoulder && hasRightShoulder)
            {
                Vector2 leftImg = new Vector2(leftShoulderPos.x, leftShoulderPos.y);
                Vector2 rightImg = new Vector2(rightShoulderPos.x, rightShoulderPos.y);

                if (mirrorFramingX)
                {
                    leftImg.x = 1f - leftImg.x;
                    rightImg.x = 1f - rightImg.x;
                }

                Vector2 leftViewport = SourceToViewport(leftImg, sourceW, sourceH, camera);
                Vector2 rightViewport = SourceToViewport(rightImg, sourceW, sourceH, camera);

                Vector2 viewportAnchor = (leftViewport + rightViewport) * 0.5f;
                float rawWidth = Vector2.Distance(leftViewport, rightViewport);

                if (hasNose)
                {
                    Vector2 noseRaw = new Vector2(nosePos.x, nosePos.y);
                    if (mirrorFramingX) noseRaw.x = 1f - noseRaw.x;
                    Vector2 faceViewport = SourceToViewport(noseRaw, sourceW, sourceH, camera);
                    faceToShoulderOffset = faceViewport - viewportAnchor;
                    hasFaceToShoulderOffset = true;
                }

                ProcessShoulderMeasurement(viewportAnchor, rawWidth, measurementDeltaTime);
                UpdateFaceMeasurement(
                    hasLeftEar, hasRightEar, leftEarPos, rightEarPos,
                    hasLeftEye, hasRightEye, leftEyePos, rightEyePos,
                    sourceW, sourceH, measurementDeltaTime);
            }
            else if (hasNose && hasFaceToShoulderOffset)
            {
                // Fallback: Face only
                Vector2 noseRaw = new Vector2(nosePos.x, nosePos.y);
                if (mirrorFramingX) noseRaw.x = 1f - noseRaw.x;
                Vector2 faceViewport = SourceToViewport(noseRaw, sourceW, sourceH, camera);
                Vector2 estimatedShoulderViewport = faceViewport - faceToShoulderOffset;

                ProcessPositionOnlyMeasurement(estimatedShoulderViewport, measurementDeltaTime);
                UpdateFaceMeasurement(
                    hasLeftEar, hasRightEar, leftEarPos, rightEarPos,
                    hasLeftEye, hasRightEye, leftEyePos, rightEyePos,
                    sourceW, sourceH, measurementDeltaTime);
            }
            else
            {
                lostDuration += measurementDeltaTime;
                if (lostDuration > lostHoldTime)
                {
                    trackingAcquiredCounter = 0;
                }
            }
        }

        private void UpdateFaceMeasurement(
            bool hasLeftEar, bool hasRightEar, Vector3 leftEar, Vector3 rightEar,
            bool hasLeftEye, bool hasRightEye, Vector3 leftEye, Vector3 rightEye,
            int sourceWidth, int sourceHeight, float deltaTime)
        {
            Vector3 left;
            Vector3 right;
            if (hasLeftEar && hasRightEar)
            {
                left = leftEar;
                right = rightEar;
            }
            else if (hasLeftEye && hasRightEye)
            {
                left = leftEye;
                right = rightEye;
            }
            else
            {
                return;
            }

            var leftViewport = SourceToViewport(new Vector2(left.x, left.y), sourceWidth, sourceHeight, camera);
            var rightViewport = SourceToViewport(new Vector2(right.x, right.y), sourceWidth, sourceHeight, camera);
            var faceWidth = Vector2.Distance(leftViewport, rightViewport);
            if (!hasSourceFaceWidth)
            {
                filteredSourceFaceWidth = faceWidth;
                hasSourceFaceWidth = true;
                return;
            }

            var t = 1f - Mathf.Exp(-sizeMeasurementSpeed * deltaTime);
            filteredSourceFaceWidth = Mathf.Lerp(filteredSourceFaceWidth, faceWidth, t);
        }

        private void ProcessShoulderMeasurement(Vector2 rawViewportAnchor, float rawWidth, float measurementDeltaTime)
        {
            if (!hasFilteredState)
            {
                filteredSourceAnchor = rawViewportAnchor;
                filteredSourceWidth = rawWidth;
                hasFilteredState = true;
                outlierCounter = 0;
                trackingAcquiredCounter = 1;
                lostDuration = 0f;
                return;
            }

            // Outlier rejection check
            float widthRatio = rawWidth / Mathf.Max(filteredSourceWidth, 0.001f);
            bool plausible = widthRatio >= widthJumpMinRatio && widthRatio <= widthJumpMaxRatio;

            if (!plausible)
            {
                outlierCounter++;
                pendingOutlierWidth = rawWidth;
                pendingOutlierAnchor = rawViewportAnchor;

                if (outlierCounter < outlierConfirmationFrames)
                {
                    // Ignore outlier frame
                    lostDuration = 0f;
                    return;
                }
                else
                {
                    // Accepted after confirmation
                    outlierCounter = 0;
                    rawWidth = pendingOutlierWidth;
                    rawViewportAnchor = pendingOutlierAnchor;
                }
            }
            else
            {
                outlierCounter = 0;
            }

            if (trackingAcquiredCounter < acquireFrames)
            {
                trackingAcquiredCounter++;
                if (trackingAcquiredCounter < acquireFrames)
                {
                    filteredSourceAnchor = rawViewportAnchor;
                    filteredSourceWidth = rawWidth;
                    lostDuration = 0f;
                    return;
                }
            }

            lostDuration = 0f;

            float distanceNoiseMultiplier = Mathf.Clamp(0.18f / Mathf.Max(rawWidth, 0.05f), 1f, 2.5f);
            float effPosDeadZone = positionDeadZone * distanceNoiseMultiplier;
            float effSizeDeadZone = sizeDeadZoneRatio * distanceNoiseMultiplier;

            Vector2 targetAnchor = rawViewportAnchor;
            if (Vector2.Distance(targetAnchor, filteredSourceAnchor) < effPosDeadZone)
            {
                targetAnchor = filteredSourceAnchor;
            }

            float targetWidth = rawWidth;
            if (Mathf.Abs(targetWidth - filteredSourceWidth) / Mathf.Max(filteredSourceWidth, 0.001f) < effSizeDeadZone)
            {
                targetWidth = filteredSourceWidth;
            }

            float positionT = 1f - Mathf.Exp(-positionMeasurementSpeed * measurementDeltaTime);
            float sizeT = 1f - Mathf.Exp(-sizeMeasurementSpeed * measurementDeltaTime);

            filteredSourceAnchor = Vector2.Lerp(filteredSourceAnchor, targetAnchor, positionT);
            filteredSourceWidth = Mathf.Lerp(filteredSourceWidth, targetWidth, sizeT);
        }

        private void ProcessPositionOnlyMeasurement(Vector2 estimatedViewportAnchor, float measurementDeltaTime)
        {
            if (!hasFilteredState || trackingAcquiredCounter < acquireFrames) return;

            lostDuration = 0f;

            float distanceNoiseMultiplier = Mathf.Clamp(0.18f / Mathf.Max(filteredSourceWidth, 0.05f), 1f, 2.5f);
            float effPosDeadZone = positionDeadZone * distanceNoiseMultiplier;

            Vector2 targetAnchor = estimatedViewportAnchor;
            if (Vector2.Distance(targetAnchor, filteredSourceAnchor) < effPosDeadZone)
            {
                targetAnchor = filteredSourceAnchor;
            }

            float positionT = 1f - Mathf.Exp(-positionMeasurementSpeed * measurementDeltaTime);
            filteredSourceAnchor = Vector2.Lerp(filteredSourceAnchor, targetAnchor, positionT);
        }

        public void Tick(float deltaTime)
        {
            if (!isInitialized || animator == null || camera == null) return;

            if (lostDuration > 0f)
            {
                lostDuration += deltaTime;
            }

            if (!hasFilteredState || trackingAcquiredCounter < acquireFrames) return;

            ApplyFaceZoom(deltaTime);

            if (lostDuration > 2.0f && resetRootPositionOnLongLost)
            {
                rootTransform.position = Vector3.Lerp(rootTransform.position, rootOriginPosition, deltaTime * 2f);
                return;
            }

            Transform leftShoulder = animator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            Transform rightShoulder = animator.GetBoneTransform(HumanBodyBones.RightUpperArm);

            if (leftShoulder == null || rightShoulder == null) return;

            Vector3 leftViewport = camera.WorldToViewportPoint(leftShoulder.position);
            Vector3 rightViewport = camera.WorldToViewportPoint(rightShoulder.position);

            Vector2 avatarAnchor = ((Vector2)leftViewport + (Vector2)rightViewport) * 0.5f;
            float avatarWidth = Vector2.Distance((Vector2)leftViewport, (Vector2)rightViewport);

            if (avatarWidth <= 0.0001f) return;

            Vector3 avatarAnchorWorld = (leftShoulder.position + rightShoulder.position) * 0.5f;

            float currentDepth = Vector3.Dot(avatarAnchorWorld - camera.transform.position, camera.transform.forward);

            Vector3 targetAnchorWorld = camera.ViewportToWorldPoint(new Vector3(filteredSourceAnchor.x, filteredSourceAnchor.y, currentDepth));

            Vector3 rootDelta = targetAnchorWorld - avatarAnchorWorld;
            Vector3 targetRootPosition = rootTransform.position + rootDelta;

            Vector3 currentLocal = camera.transform.InverseTransformPoint(rootTransform.position);
            Vector3 targetLocal = camera.transform.InverseTransformPoint(targetRootPosition);

            currentLocal.x = Mathf.SmoothDamp(currentLocal.x, targetLocal.x, ref velocityX, xySmoothTime, maxXYSpeed, deltaTime);
            currentLocal.y = Mathf.SmoothDamp(currentLocal.y, targetLocal.y, ref velocityY, xySmoothTime, maxXYSpeed, deltaTime);
            rootTransform.position = camera.transform.TransformPoint(currentLocal);
        }

        private void ApplyFaceZoom(float deltaTime)
        {
            if (!hasSourceFaceWidth) return;
            var leftEye = animator.GetBoneTransform(HumanBodyBones.LeftEye);
            var rightEye = animator.GetBoneTransform(HumanBodyBones.RightEye);
            if (leftEye == null || rightEye == null) return;

            var leftViewport = camera.WorldToViewportPoint(leftEye.position);
            var rightViewport = camera.WorldToViewportPoint(rightEye.position);
            if (leftViewport.z <= 0f || rightViewport.z <= 0f) return;

            var avatarFaceWidth = Vector2.Distance(leftViewport, rightViewport);
            var faceWorldCenter = (leftEye.position + rightEye.position) * .5f;
            var forward = camera.transform.forward;
            var currentDistance = Vector3.Dot(faceWorldCenter - camera.transform.position, forward);
            if (currentDistance <= .05f) return;

            var sizeRatio = avatarFaceWidth / Mathf.Max(filteredSourceFaceWidth, .001f);
            if (Mathf.Abs(sizeRatio - 1f) < sizeDeadZoneRatio) return;

            var targetDistance = Mathf.Clamp(
                currentDistance * sizeRatio, minimumCameraDistance, maximumCameraDistance);
            var smoothDistance = Mathf.SmoothDamp(
                currentDistance, targetDistance, ref cameraDistanceVelocity,
                faceZoomSmoothTime, maxCameraSpeed, deltaTime);
            camera.transform.position =
                camera.transform.position + forward * (currentDistance - smoothDistance);
        }
    }
}

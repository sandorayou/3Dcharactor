using UnityEngine;

namespace RealtimeBodyTracking
{
    [RequireComponent(typeof(UdpPoseReceiver))]
    public sealed class HumanoidPoseDriver : MonoBehaviour
    {
        [Header("References")]
        [SerializeField] private Animator targetAnimator;
        [SerializeField] private UdpPoseReceiver udpReceiver;
        [SerializeField] private Camera trackingCamera;
        [Header("Camera Framing")]
        [SerializeField] private bool autoFrameCamera = true;
        [SerializeField, Range(.2f, 3f)] private float cameraCalibrationSeconds = .75f;
        [SerializeField, Range(0f, .4f)] private float cameraFramingMargin = .12f;
        [SerializeField, Range(.35f, 2f)] private float cameraMinimumDistance = .5f;
        [Header("Tracking")]
        [SerializeField, Range(1f, 60f)] private float smoothingSpeed = 24f;
        [SerializeField, Range(0f, 10f)] private float rotationDeadZoneDegrees = 3f;
        [SerializeField] private bool avatarMirror;
        [SerializeField] private bool enableHipsPosition;
        [SerializeField, Range(0f, 5f)] private float hipsPositionScale = .25f;
        [SerializeField, Range(0f, 3f)] private float bodyDepthFromShoulderWidth = 1.2f;
        [SerializeField, Min(0f)] private float maxHipsSpeed = 1.5f;
        [SerializeField, Min(0f)] private float screenHorizontalRange = 1.2f;
        [SerializeField, Min(0f)] private float screenVerticalRange = .8f;
        [SerializeField, Min(0f)] private float maxDepthOffset = 1.5f;
        [SerializeField, Range(0f, .1f)] private float horizontalPositionDeadZone = .02f;
        [SerializeField, Range(0f, .1f)] private float verticalPositionDeadZone = .025f;
        [SerializeField, Range(0f, .25f)] private float depthPositionDeadZone = .06f;
        [SerializeField, Range(.5f, 30f)] private float positionMeasurementSmoothing = 4f;
        [SerializeField, Range(.5f, 30f)] private float positionFollowSpeed = 4f;
        [SerializeField, Range(0f, 1f)] private float positionMinConfidence = .1f;
        [SerializeField, Range(0f, 10f)] private float bodyLeanDeadZone = 2.5f;
        [SerializeField, Range(0f, 45f)] private float maxBodyLean = 25f;
        [SerializeField, Range(.5f, 30f)] private float bodyLeanSmoothing = 5f;
        [SerializeField, Range(.5f, 3f)] private float bodyLeanGain = 1.5f;
        [Header("Body Turn")]
        [SerializeField] private bool enableBodyTurn = true;
        [SerializeField, Min(0f)] private float bodyTurnSpeed = 360f;
        [SerializeField, Range(0f, 30f)] private float bodyTurnDeadZone = 2f;
        [SerializeField, Range(-180f, 180f)] private float avatarFacingOffsetDegrees = 180f;
        [SerializeField, Range(0f, 1f)] private float bodyTurnMinConfidence = .6f;
        [Header("Arm Stability")]
        [SerializeField, Range(0f, 1f)] private float bodyCollisionRadiusScale = .85f;
        [SerializeField, Range(0f, 1f)] private float wristMinConfidence = .5f;
        [SerializeField, Min(0f)] private float maxWristSpeed = 2.5f;
        [SerializeField, Min(0f)] private float maxElbowSpeed = 3f;
        [SerializeField, Range(1, 5)] private int armAcquireFrames = 2;
        [SerializeField, Range(0f, .3f)] private float armPointDeadZoneScale = .1f;
        [SerializeField, Min(0f)] private float wristHoldTime = .15f;
        [SerializeField, Range(0.5f, 3f)] private float maxForearmToUpperArmRatio = 1.8f;
        [SerializeField, Range(.1f, 5f)] private float armRelaxSpeed = 1.2f;
        [SerializeField, Range(.1f, 10f)] private float armRecoverSpeed = 4f;
        [SerializeField, Range(.1f, 1f)] private float handContactDistanceRatio = .45f;
        [SerializeField] private bool enableHead = true;
        [SerializeField] private bool enableArms = true;
        [SerializeField] private bool enableLegs = true;
        [SerializeField, Range(0f, 1f)] private float legMinConfidence = .75f;
        [Header("Head Tracking")]
        [SerializeField, Range(0f, 1f)] private float headMinConfidence = .1f;
        [SerializeField, Range(0f, 1f)] private float faceHoldTime = .25f;
        [SerializeField, Range(0f, 1f)] private float headRollMinConfidence = .6f;
        [SerializeField, Range(0f, 90f)] private float maxHeadYaw = 70f;
        [SerializeField, Range(0f, 60f)] private float maxHeadPitch = 35f;
        [SerializeField, Range(0f, 60f)] private float maxHeadRoll = 40f;
        [SerializeField, Range(.5f, 6f)] private float headYawGain = 4.8f;
        [SerializeField, Range(.5f, 4f)] private float headPitchGain = 2.2f;
        [SerializeField, Range(.5f, 3f)] private float headRollGain = 1.4f;
        [SerializeField, Range(15f, 180f)] private float maxHeadRollSpeed = 75f;
        [SerializeField, Range(0f, 1f)] private float neckRotationWeight = .35f;
        [SerializeField] private bool enableRollCorrection;
        [SerializeField] private bool enableAnatomyLimits = true;
        [SerializeField, Min(0f)] private float trackingTimeout = .5f;
        [SerializeField] private bool returnToRestPose = true;
        [SerializeField] private bool debugLogging;
        [SerializeField, Tooltip("Live state")] private bool tracking;
        [SerializeField, Tooltip("Live state")] private long latestFrame = -1;
        [SerializeField, Tooltip("Live state")] private int validPoints;
        [SerializeField, Tooltip("Live state")] private int appliedBones;
        [SerializeField, Tooltip("Live state")] private bool headTracking;
        [SerializeField, Tooltip("Live state")] private float headYawDegrees;
        [SerializeField, Tooltip("Live state")] private float headPitchDegrees;
        [SerializeField, Tooltip("Live state")] private float headRollDegrees;
        [SerializeField, Tooltip("Live state")] private int anatomyClampCount;
        [SerializeField, Tooltip("Live state")] private string lastAnatomyClamp;
        [SerializeField, Tooltip("Live state")] private bool handContactTracking;
        [SerializeField, Tooltip("Live state")] private float wristSeparationRatio;
        [SerializeField, Tooltip("Live state")] private bool bodyPositionTracking;
        [SerializeField, Tooltip("Live state")] private Vector3 bodyPositionOffset;
        [SerializeField, Tooltip("Live state")] private float bodyLeanDegrees;
        [SerializeField, Tooltip("Live state")] private int bodyShoulderMode;
        [SerializeField, Tooltip("Live state")] private float leftArmRelaxWeight;
        [SerializeField, Tooltip("Live state")] private float rightArmRelaxWeight;
        [SerializeField, Tooltip("Live state")] private string leftArmFilterState;
        [SerializeField, Tooltip("Live state")] private string rightArmFilterState;
        [SerializeField, Tooltip("Live state")] private int armCameraClampCount;
        [SerializeField, Tooltip("Live state")] private string lastArmCameraClamp;
        [SerializeField, Tooltip("Live state")] private string leftArmDepthState;
        [SerializeField, Tooltip("Live state")] private string rightArmDepthState;
        [SerializeField, Tooltip("Live state")] private string leftArmScreenState;
        [SerializeField, Tooltip("Live state")] private string rightArmScreenState;
        [SerializeField, Tooltip("Live state")] private string leftHandEvidenceState;
        [SerializeField, Tooltip("Live state")] private string rightHandEvidenceState;
        [SerializeField, Tooltip("Live state")] private bool cameraFramingReady;

        private readonly BoneRotationSolver solver = new();
        private readonly AvatarCollisionGeometry collisionGeometry = new();
        private readonly PoseSmoother smoother = new();
        private PosePacket lastTrackedPose;
        private float lastTrackingTime = float.NegativeInfinity;
        private float lastReliableFaceTime = float.NegativeInfinity;
        private float nextDebugLog;
        private Vector2 sourceScreenOrigin;
        private Vector2 filteredScreenCenter;
        private Vector2 stableScreenCenter;
        private Vector3 avatarHipOrigin;
        private float sourceShoulderWidthOrigin;
        private float filteredShoulderWidth;
        private float stableShoulderWidth;
        private float shoulderScreenDirection = -1f;
        private float filteredBodyLean;
        private float stableBodyLean;
        private float bodyLeanOrigin;
        private bool bodyLeanOriginInitialized;
        private float leftShoulderLeanOrigin;
        private float rightShoulderLeanOrigin;
        private bool leftShoulderLeanInitialized;
        private bool rightShoulderLeanInitialized;
        private int lastBodyShoulderMode = 99;
        private bool hipsInitialized;
        private Vector3 avatarRootOriginPosition;
        private Quaternion avatarRootOriginRotation;
        private Quaternion rootRotationDelta = Quaternion.identity;
        private float headPitchOrigin;
        private bool headPitchInitialized;
        private float headRollOrigin;
        private bool headRollInitialized;
        private float filteredHeadRoll;
        private float cameraCalibrationStarted = -1f;
        private Vector2 cameraCalibrationCenter;
        private float cameraCalibrationWidth;
        private float maxObservedBodySpan;
        private float bodyTurnSide = 1f;
        private float currentBodyYaw;
        private readonly PointContinuityFilter leftElbowFilter = new();
        private readonly PointContinuityFilter rightElbowFilter = new();
        private readonly PointContinuityFilter leftWristFilter = new();
        private readonly PointContinuityFilter rightWristFilter = new();
        private ArmPose leftConstrainedArm;
        private ArmPose rightConstrainedArm;
        private bool hasLeftConstrainedArm;
        private bool hasRightConstrainedArm;

        private static readonly (HumanBodyBones bone, string from, string to)[] LegChains =
        {
            (HumanBodyBones.LeftUpperLeg, "left_hip", "left_knee"),
            (HumanBodyBones.LeftLowerLeg, "left_knee", "left_ankle"),
            (HumanBodyBones.LeftFoot, "left_ankle", "left_foot_index"),
            (HumanBodyBones.RightUpperLeg, "right_hip", "right_knee"),
            (HumanBodyBones.RightLowerLeg, "right_knee", "right_ankle"),
            (HumanBodyBones.RightFoot, "right_ankle", "right_foot_index"),
        };

        private void Awake()
        {
            if (udpReceiver == null) udpReceiver = GetComponent<UdpPoseReceiver>();
            if (targetAnimator == null) targetAnimator = GetComponentInChildren<Animator>();
            if (trackingCamera == null) trackingCamera = Camera.main;
        }

        private void Start()
        {
            if (targetAnimator == null || !targetAnimator.isHuman)
            {
                Debug.LogError("HumanoidPoseDriver requires a Humanoid Animator.", this);
                enabled = false;
                return;
            }
            wristMinConfidence = Mathf.Max(wristMinConfidence, .5f);
            if (trackingCamera != null) trackingCamera.nearClipPlane = Mathf.Min(trackingCamera.nearClipPlane, .03f);
            avatarRootOriginPosition = targetAnimator.transform.position;
            avatarRootOriginRotation = targetAnimator.transform.rotation;
            solver.Initialize(targetAnimator);
            collisionGeometry.Initialize(targetAnimator);
            if (debugLogging) Debug.Log($"Avatar collision geometry measured: {collisionGeometry.DebugSummary}", this);
        }

        private void LateUpdate()
        {
            if (udpReceiver != null && udpReceiver.TryTakeLatest(out var packet))
            {
                latestFrame = packet.frame;
                if (packet.tracking || packet.points?.Count > 0)
                {
                    lastTrackedPose = packet;
                    lastTrackingTime = Time.unscaledTime;
                    tracking = true;
                }
            }
            if (lastTrackedPose == null) return;
            if (Time.unscaledTime - lastTrackingTime > trackingTimeout)
            {
                if (tracking)
                {
                    tracking = false;
                    ResetTrackingCalibration();
                }
                if (returnToRestPose) ReturnToRest();
            }
            else
            {
                ApplyPose(lastTrackedPose);
            }
            if (debugLogging && Time.unscaledTime >= nextDebugLog)
            {
                Debug.Log($"Pose UDP frame={latestFrame}, tracking={tracking}, points={validPoints}, appliedBones={appliedBones}, headTracking={headTracking}, headYaw={headYawDegrees:F1}, headPitch={headPitchDegrees:F1}, headRoll={headRollDegrees:F1}, bodyPosition={bodyPositionTracking}, offset={bodyPositionOffset}, bodyLean={bodyLeanDegrees:F1}, shoulderMode={bodyShoulderMode}, cameraFramed={cameraFramingReady}, handContact={handContactTracking}, wristRatio={wristSeparationRatio:F2}, armRelax=({leftArmRelaxWeight:F2},{rightArmRelaxWeight:F2}), handEvidenceL=[{leftHandEvidenceState}], handEvidenceR=[{rightHandEvidenceState}], armFilterL=[{leftArmFilterState}], armFilterR=[{rightArmFilterState}], armDepthL=[{leftArmDepthState}], armDepthR=[{rightArmDepthState}], armScreenL=[{leftArmScreenState}], armScreenR=[{rightArmScreenState}], armCameraClamps={armCameraClampCount}, lastArmCameraClamp={lastArmCameraClamp}, anatomyClamps={anatomyClampCount}, lastClamp={lastAnatomyClamp}, dropped={udpReceiver.DroppedPackets}", this);
                nextDebugLog = Time.unscaledTime + 1f;
            }
        }

        private void ApplyPose(PosePacket pose)
        {
            validPoints = pose.points?.Count ?? 0;
            appliedBones = 0;
            anatomyClampCount = 0;
            lastAnatomyClamp = string.Empty;
            armCameraClampCount = 0;
            lastArmCameraClamp = string.Empty;
            if (!PoseInputMapper.TryReadUpperBody(pose, avatarMirror, bodyTurnMinConfidence, out var upperBody))
            {
                bodyPositionTracking = false;
                handContactTracking = false;
                currentBodyYaw = Mathf.MoveTowardsAngle(currentBodyYaw, 0f, bodyTurnSpeed * Time.deltaTime);
                var root = targetAnimator.transform;
                var target = Quaternion.AngleAxis(currentBodyYaw + avatarFacingOffsetDegrees, Vector3.up) * avatarRootOriginRotation;
                root.rotation = Quaternion.RotateTowards(root.rotation, target, bodyTurnSpeed * Time.deltaTime);
                rootRotationDelta = root.rotation * Quaternion.Inverse(avatarRootOriginRotation);
                if (returnToRestPose) ReturnToRest();
                if (enableHead) ApplyHead(pose);
                return;
            }
            bodyPositionTracking = false;
            if (enableHipsPosition && PoseInputMapper.TryReadScreenBody(pose, false, positionMinConfidence, out var screenBody))
            {
                bodyPositionTracking = true;
                bodyLeanDegrees = ResolveBodyLean(screenBody);
                var screenCenter = ResolveScreenBody(screenBody, bodyLeanDegrees, out var effectiveShoulderWidth);
                TryCalibrateCameraFraming(screenBody, effectiveShoulderWidth);
                ApplyHips(screenCenter, effectiveShoulderWidth);
            }
            ApplyBodyTurn(upperBody);
            if (enableLegs && upperBody.HipsTracked) ApplyDirection(HumanBodyBones.Hips, upperBody.Torso, upperBody.Forward, bodyLeanDegrees * .15f);
            else ReturnBoneToRest(HumanBodyBones.Hips);
            ApplyDirection(HumanBodyBones.Spine, upperBody.Torso, upperBody.Forward, bodyLeanDegrees * .55f);
            ApplyRestBoneRoll(HumanBodyBones.Chest, bodyLeanDegrees * .8f);
            ApplyRestBoneRoll(HumanBodyBones.UpperChest, bodyLeanDegrees);
            if (enableArms)
            {
                ApplyRestBoneRoll(HumanBodyBones.LeftShoulder, bodyLeanDegrees);
                ApplyRestBoneRoll(HumanBodyBones.RightShoulder, bodyLeanDegrees);
                var faceObserved = PoseInputMapper.TryReadHeadFacing(pose, avatarMirror, headMinConfidence, out _);
                if (faceObserved) lastReliableFaceTime = Time.unscaledTime;
                var faceReliable = Time.unscaledTime - lastReliableFaceTime <= faceHoldTime;
                if (!faceReliable)
                {
                    handContactTracking = false;
                    RelaxArmsToRest();
                }
                else if (!TryApplyHandContact(pose, upperBody))
                {
                    ApplyArm(pose, true, upperBody);
                    ApplyArm(pose, false, upperBody);
                }
            }
            if (enableLegs)
                foreach (var chain in LegChains)
                    if (PoseInputMapper.TryGetVisible(pose, chain.from, avatarMirror, legMinConfidence, out var from) && PoseInputMapper.TryGetVisible(pose, chain.to, avatarMirror, legMinConfidence, out var to))
                        ApplyDirection(chain.bone, to - from, upperBody.Forward);
                    else
                        ReturnBoneToRest(chain.bone);
            if (enableHead) ApplyHead(pose);
        }

        private void ApplyDirection(HumanBodyBones bone, Vector3 direction, Vector3 upHint, float screenRoll = 0f)
        {
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            ApplyWorldDirection(bone, facingOffset * direction, facingOffset * upHint, screenRoll);
        }

        private void ApplyWorldDirection(HumanBodyBones bone, Vector3 direction, Vector3 upHint, float screenRoll = 0f)
        {
            if (!solver.TrySolve(bone, direction, upHint, rootRotationDelta, enableRollCorrection, out var target)) return; // Missing optional bones are skipped.
            if (Mathf.Abs(screenRoll) > .01f) target = Quaternion.AngleAxis(screenRoll, Vector3.forward) * target;
            if (enableAnatomyLimits && solver.TryClampHand(bone, target, rootRotationDelta, out var constrainedHand))
            {
                target = constrainedHand;
            }
            else if (enableAnatomyLimits && !IsIkArmBone(bone) && solver.TryGetRestRotation(bone, out var rest))
            {
                var maxSwing = AnatomyLimits.GetMaxSwingDegrees(bone);
                if (Quaternion.Angle(rootRotationDelta * rest, target) > maxSwing + .1f)
                {
                    anatomyClampCount++;
                    lastAnatomyClamp = bone.ToString();
                }
                target = AnatomyLimits.ClampSwing(bone, rootRotationDelta * rest, target);
            }
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform != null)
            {
                transform.rotation = smoother.Smooth(bone, transform.rotation, target, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
                appliedBones++;
            }
        }

        private static bool IsIkArmBone(HumanBodyBones bone)
        {
            return bone == HumanBodyBones.LeftUpperArm || bone == HumanBodyBones.RightUpperArm ||
                   bone == HumanBodyBones.LeftLowerArm || bone == HumanBodyBones.RightLowerArm;
        }

        private void ApplyBodyTurn(UpperBodyPose upperBody)
        {
            var root = targetAnimator.transform;
            if (enableBodyTurn)
            {
                var lateral = upperBody.ImageLateral;
                if (upperBody.HipsTracked && lateral.sqrMagnitude > .000001f)
                {
                    var span = Mathf.Abs(lateral.x);
                    maxObservedBodySpan = Mathf.Max(maxObservedBodySpan, span);
                    if (Mathf.Abs(lateral.z) > maxObservedBodySpan * .02f) bodyTurnSide = Mathf.Sign(-lateral.z);
                    var sideAngle = Mathf.Acos(Mathf.Clamp01(span / Mathf.Max(maxObservedBodySpan, .001f))) * Mathf.Rad2Deg;
                    var yaw = lateral.x >= 0f ? bodyTurnSide * sideAngle : bodyTurnSide * (180f - sideAngle);
                    currentBodyYaw = Mathf.Abs(yaw) >= bodyTurnDeadZone ? yaw : 0f;
                }
                var target = Quaternion.AngleAxis(currentBodyYaw + avatarFacingOffsetDegrees, Vector3.up) * avatarRootOriginRotation;
                if (Quaternion.Angle(root.rotation, target) > .5f)
                    root.rotation = Quaternion.RotateTowards(root.rotation, target, bodyTurnSpeed * Time.deltaTime);
            }
            rootRotationDelta = root.rotation * Quaternion.Inverse(avatarRootOriginRotation);
        }

        private void ApplyHead(PosePacket pose)
        {
            if (!PoseInputMapper.TryReadHeadFacing(pose, avatarMirror, headMinConfidence, out var headFacing))
            {
                headTracking = false;
                headYawDegrees = 0f;
                headPitchDegrees = 0f;
                headRollDegrees = 0f;
                ReturnBoneToRest(HumanBodyBones.Neck);
                ReturnBoneToRest(HumanBodyBones.Head);
                return;
            }
            var frontReference = avatarMirror ? Vector3.forward : Vector3.back;
            var horizontalHead = Vector3.ProjectOnPlane(headFacing, Vector3.up);
            if (horizontalHead.sqrMagnitude < .000001f) return;
            var headYaw = Vector3.SignedAngle(frontReference, horizontalHead.normalized, Vector3.up);
            var relativeYaw = Mathf.Clamp(Mathf.DeltaAngle(currentBodyYaw, headYaw) * headYawGain, -maxHeadYaw, maxHeadYaw);
            var rawPitch = Mathf.Atan2(headFacing.y, horizontalHead.magnitude) * Mathf.Rad2Deg;
            if (!headPitchInitialized) { headPitchOrigin = rawPitch; headPitchInitialized = true; }
            var pitch = Mathf.Clamp((rawPitch - headPitchOrigin) * headPitchGain, -maxHeadPitch, maxHeadPitch);
            var hasHeadRoll = PoseInputMapper.TryReadHeadRoll(pose, false, headRollMinConfidence, out var rawRoll);
            if (hasHeadRoll && !headRollInitialized)
            {
                headRollOrigin = rawRoll;
                headRollInitialized = true;
            }
            var targetRoll = hasHeadRoll
                ? Mathf.Clamp(Mathf.DeltaAngle(headRollOrigin, rawRoll) * headRollGain, -maxHeadRoll, maxHeadRoll)
                : 0f;
            filteredHeadRoll = Mathf.MoveTowardsAngle(filteredHeadRoll, targetRoll, maxHeadRollSpeed * Time.deltaTime);
            var roll = Mathf.Abs(filteredHeadRoll) >= 2f ? filteredHeadRoll : 0f;
            headTracking = true;
            headYawDegrees = relativeYaw;
            headPitchDegrees = pitch;
            headRollDegrees = roll;
            ApplyHeadRotation(HumanBodyBones.Neck, relativeYaw, pitch, roll, neckRotationWeight);
            ApplyHeadRotation(HumanBodyBones.Head, relativeYaw, pitch, roll, 1f);
        }

        private void ApplyHeadRotation(HumanBodyBones bone, float yaw, float pitch, float roll, float weight)
        {
            if (!solver.TryGetRestRotation(bone, out var rest)) return;
            var bodyRight = rootRotationDelta * Vector3.right;
            var target = Quaternion.AngleAxis(roll * weight, Vector3.forward) * Quaternion.AngleAxis(yaw * weight, Vector3.up) * Quaternion.AngleAxis(-pitch * weight, bodyRight) * (rootRotationDelta * rest);
            if (enableAnatomyLimits) target = AnatomyLimits.ClampSwing(bone, rootRotationDelta * rest, target);
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform == null) return;
            transform.rotation = smoother.Smooth(bone, transform.rotation, target, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
            appliedBones++;
        }

        private void ApplyRestBoneRoll(HumanBodyBones bone, float screenRoll)
        {
            if (!solver.TryGetRestRotation(bone, out var rest)) return;
            var baseRotation = rootRotationDelta * rest;
            var target = Quaternion.AngleAxis(screenRoll, Vector3.forward) * baseRotation;
            if (enableAnatomyLimits) target = AnatomyLimits.ClampSwing(bone, baseRotation, target);
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform == null) return;
            transform.rotation = smoother.Smooth(bone, transform.rotation, target, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
            appliedBones++;
        }

        private void ApplyArm(PosePacket pose, bool left, UpperBodyPose upperBody)
        {
            var sourceLeft = left != avatarMirror;
            var shoulder = sourceLeft ? upperBody.LeftShoulder : upperBody.RightShoulder;
            var elbowName = sourceLeft ? "left_elbow" : "right_elbow";
            var wristName = sourceLeft ? "left_wrist" : "right_wrist";
            var hasRawElbow = PoseInputMapper.TryGet(pose, elbowName, avatarMirror, .35f, out var rawElbow);
            var hasRawWrist = PoseInputMapper.TryGet(pose, wristName, avatarMirror, wristMinConfidence, out var rawWrist);
            var hasElbowImage = pose.TryGetImage(elbowName, .35f, out var elbowImage);
            pose.TryGetConfidence(elbowName, out var elbowConfidence);
            var hasWristImage = pose.TryGetImage(wristName, wristMinConfidence, out var wristImage);
            var handDepthZ = 0f;
            var hasHandEvidence = TryReadHandEvidence(
                pose, left, hasWristImage, wristImage, hasRawWrist ? rawWrist.z : shoulder.z,
                out wristImage, out handDepthZ);
            var elbow = Vector3.zero;
            var wrist = Vector3.zero;
            var hasElbow = hasRawElbow && hasElbowImage && IsInsideExtendedArmImage(elbowImage, .3f) &&
                           TryMapArmImagePoint(pose, left, shoulder, upperBody, elbowImage, rawElbow.z, out elbow);
            var hasWrist = hasHandEvidence && IsInsideExtendedArmImage(wristImage, .04f) &&
                           TryMapArmImagePoint(pose, left, shoulder, upperBody, wristImage, handDepthZ, out wrist);
            var elbowFilter = left ? leftElbowFilter : rightElbowFilter;
            var wristFilter = left ? leftWristFilter : rightWristFilter;
            var shoulderWidth = Mathf.Max(upperBody.Lateral.magnitude, .05f);
            if (hasWrist) ResolveArmDepth(pose, left, shoulder, rawElbow, hasElbow, shoulderWidth, ref elbow, ref wrist);
            pose.TryGetConfidence($"{SourceSide(left)}_hand_palm", out var handConfidence);
            if (hasWrist && handConfidence < .65f && wristFilter.TryGetLastStable(out var previousPalm))
                wrist = Vector3.Lerp(previousPalm, wrist, Mathf.InverseLerp(.35f, .65f, handConfidence));
            var hasStableWrist = wristFilter.TryGetStable(wrist, hasWrist, shoulderWidth, maxWristSpeed,
                wristHoldTime, armAcquireFrames, armPointDeadZoneScale, Time.unscaledTime, out wrist);
            if (hasElbow && hasStableWrist && !IsPlausibleElbow(shoulder, elbow, wrist, shoulderWidth))
                hasElbow = false;
            var elbowSource = "observed";
            if (hasElbow && hasStableWrist && elbowConfidence < .65f)
            {
                var inferred = InferElbow(shoulder, wrist, upperBody, left, elbowFilter);
                elbow = Vector3.Lerp(inferred, elbow, Mathf.InverseLerp(.35f, .65f, elbowConfidence));
                elbowSource = "blended_observation";
            }
            if (!hasElbow && hasStableWrist)
            {
                elbow = InferElbow(shoulder, wrist, upperBody, left, elbowFilter);
                hasElbow = true;
                elbowSource = "inferred_from_wrist";
            }
            var elbowDeadZone = elbowSource == "inferred_from_wrist" ? armPointDeadZoneScale * 1.6f : armPointDeadZoneScale;
            var hasStableElbow = elbowFilter.TryGetStable(elbow, hasElbow, shoulderWidth, maxElbowSpeed, wristHoldTime, armAcquireFrames, elbowDeadZone, Time.unscaledTime, out elbow);
            var filterState = $"elbow={elbowFilter.Stage}/{elbowFilter.RejectReason}/{elbowSource}, wrist={wristFilter.Stage}/{wristFilter.RejectReason}";
            if (left) leftArmFilterState = filterState; else rightArmFilterState = filterState;
            GetRelaxedArmPose(left, upperBody, out var relaxedUpper, out var relaxedLower);
            var relaxWeight = left ? leftArmRelaxWeight : rightArmRelaxWeight;
            relaxWeight = Mathf.MoveTowards(relaxWeight, hasStableWrist ? 0f : 1f, (hasStableWrist ? armRecoverSpeed : armRelaxSpeed) * Time.deltaTime);
            if (left) leftArmRelaxWeight = relaxWeight; else rightArmRelaxWeight = relaxWeight;
            var trackedUpper = hasStableElbow ? elbow - shoulder : relaxedUpper;
            var trackedLower = hasStableWrist ? wrist - elbow : relaxedLower;
            if (trackedUpper.sqrMagnitude < .000001f) trackedUpper = relaxedUpper;
            if (trackedLower.sqrMagnitude < .000001f) trackedLower = relaxedLower;
            var upperDirection = Vector3.Slerp(trackedUpper.normalized, relaxedUpper.normalized, relaxWeight);
            var lowerDirection = Vector3.Slerp(trackedLower.normalized, relaxedLower.normalized, relaxWeight);
            var upperBone = left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm;
            var lowerBone = left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm;
            var handBone = left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand;
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            ArmPose solvedArm;
            {
                var upperTransform = targetAnimator.GetBoneTransform(upperBone);
                var lowerTransform = targetAnimator.GetBoneTransform(lowerBone);
                var handTransform = targetAnimator.GetBoneTransform(handBone);
                var sourceShoulderWidth = Mathf.Max(upperBody.Lateral.magnitude, .05f);
                var upperLength = upperTransform != null && lowerTransform != null
                    ? Vector3.Distance(upperTransform.position, lowerTransform.position)
                    : sourceShoulderWidth * .78f;
                var lowerLength = lowerTransform != null && handTransform != null
                    ? Vector3.Distance(lowerTransform.position, handTransform.position)
                    : sourceShoulderWidth * .72f;
                var upperRadius = collisionGeometry.GetRadius(upperBone, upperLength * .13f);
                var lowerRadius = collisionGeometry.GetRadius(lowerBone, lowerLength * .11f);
                var handRadius = collisionGeometry.GetRadius(handBone, lowerLength * .16f);
                var torsoRadii = collisionGeometry.GetTorsoRadii(sourceShoulderWidth * .5f, sourceShoulderWidth * .29f);
                var headRadius = collisionGeometry.GetRadius(HumanBodyBones.Head, sourceShoulderWidth * .34f);
                var elbowHint = hasStableElbow ? elbow : shoulder + upperDirection.normalized * upperLength;
                var targetWrist = hasStableWrist ? wrist : elbowHint + lowerDirection.normalized * lowerLength;
                if (hasStableWrist && TryGetPalmAlignedWristTarget(
                        pose, left, shoulder, upperBody, handDepthZ, handBone, out var palmAlignedWrist))
                    targetWrist = palmAlignedWrist;
                var hasOtherArm = left ? hasRightConstrainedArm : hasLeftConstrainedArm;
                var otherArm = left ? rightConstrainedArm : leftConstrainedArm;
                var hasPreviousArm = left ? hasLeftConstrainedArm : hasRightConstrainedArm;
                var previousArm = left ? leftConstrainedArm : rightConstrainedArm;
                var arm = UpperBodyPoseSolver.SolveArm(
                    shoulder, targetWrist, elbowHint, upperBody, left, upperLength, lowerLength,
                    bodyCollisionRadiusScale, torsoRadii.x, torsoRadii.y, headRadius,
                    upperRadius, lowerRadius, handRadius,
                    hasPreviousArm, previousArm, hasOtherArm, otherArm);
                solvedArm = arm;
                if (left)
                {
                    leftConstrainedArm = arm;
                    hasLeftConstrainedArm = true;
                }
                else
                {
                    rightConstrainedArm = arm;
                    hasRightConstrainedArm = true;
                }
                upperDirection = arm.Elbow - arm.Shoulder;
                lowerDirection = arm.Wrist - arm.Elbow;
            }
            var worldUp = facingOffset * upperBody.Forward;
            ApplyTwoBoneArm(upperBone, lowerBone, solvedArm, facingOffset, worldUp);
            if (hasStableWrist) ApplyHandOrientation(
                pose, left, shoulder, upperBody, handDepthZ, lowerBone, handBone, facingOffset);
            else ReturnBoneToRest(handBone);
            UpdateArmScreenDiagnostics(left, pose, handBone, hasStableWrist);
        }

        private void ApplyTwoBoneArm(HumanBodyBones upperBone, HumanBodyBones lowerBone, ArmPose arm,
            Quaternion facingOffset, Vector3 upHint)
        {
            var upper = targetAnimator.GetBoneTransform(upperBone);
            var lower = targetAnimator.GetBoneTransform(lowerBone);
            if (upper == null || lower == null) return;
            var upperDirection = facingOffset * (arm.Elbow - arm.Shoulder);
            var lowerDirection = facingOffset * (arm.Wrist - arm.Elbow);
            var bendNormal = Vector3.Cross(upperDirection, lowerDirection);
            var upperUp = bendNormal.sqrMagnitude > .000001f ? bendNormal.normalized : upHint;
            ApplyWorldDirection(upperBone, upperDirection, upperUp);
            ApplyWorldDirection(lowerBone, lowerDirection, upHint);
        }

        private bool TryGetPalmAlignedWristTarget(PosePacket pose, bool left, Vector3 shoulder, UpperBodyPose body,
            float handDepthZ, HumanBodyBones handBone, out Vector3 wristTarget)
        {
            var side = SourceSide(left);
            if (!pose.TryGetImage($"{side}_hand_palm", .35f, out var palmImage) ||
                !pose.TryGetImage($"{side}_hand_wrist", .35f, out var handWristImage) ||
                !TryMapArmImagePoint(pose, left, shoulder, body, palmImage, handDepthZ, out var palmTarget) ||
                !TryMapArmImagePoint(pose, left, shoulder, body, handWristImage, handDepthZ, out var detectedWristTarget) ||
                !TryGetAvatarPalmCenter(left, out var palmCenter))
            {
                wristTarget = default;
                return false;
            }
            var hand = targetAnimator.GetBoneTransform(handBone);
            if (hand == null)
            {
                wristTarget = default;
                return false;
            }
            var palmDirection = palmTarget - detectedWristTarget;
            if (palmDirection.sqrMagnitude < .000001f)
            {
                wristTarget = default;
                return false;
            }
            wristTarget = palmTarget - palmDirection.normalized * Vector3.Distance(hand.position, palmCenter);
            return true;
        }

        private bool TryGetAvatarPalmCenter(bool left, out Vector3 center)
        {
            var index = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftIndexProximal : HumanBodyBones.RightIndexProximal);
            var middle = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftMiddleProximal : HumanBodyBones.RightMiddleProximal);
            var little = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftLittleProximal : HumanBodyBones.RightLittleProximal);
            if (index == null || middle == null || little == null)
            {
                center = default;
                return false;
            }
            center = (index.position + middle.position + little.position) / 3f;
            return true;
        }

        private void ApplyHandOrientation(PosePacket pose, bool left, Vector3 shoulder, UpperBodyPose body,
            float handDepthZ, HumanBodyBones lowerBone, HumanBodyBones handBone, Quaternion facingOffset)
        {
            var side = SourceSide(left);
            if (!pose.TryGetImage($"{side}_hand_wrist", .35f, out var wristImage) ||
                !pose.TryGetImage($"{side}_hand_palm", .35f, out var palmImage) ||
                !pose.TryGetImage($"{side}_hand_index_mcp", .35f, out var indexImage) ||
                !pose.TryGetImage($"{side}_hand_middle_mcp", .35f, out var middleImage) ||
                !pose.TryGetImage($"{side}_hand_pinky_mcp", .35f, out var pinkyImage) ||
                !pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulderImage) ||
                !pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulderImage)) return;
            var handDepthScale = Mathf.Max(body.Lateral.magnitude, .05f) /
                                 Mathf.Max(Vector2.Distance(leftShoulderImage, rightShoulderImage), .03f);
            var wristDepth = handDepthZ - (wristImage.z - palmImage.z) * handDepthScale;
            var indexDepth = handDepthZ - (indexImage.z - palmImage.z) * handDepthScale;
            var middleDepth = handDepthZ - (middleImage.z - palmImage.z) * handDepthScale;
            var pinkyDepth = handDepthZ - (pinkyImage.z - palmImage.z) * handDepthScale;
            if (!TryMapArmImagePoint(pose, left, shoulder, body, wristImage, wristDepth, out var wrist) ||
                !TryMapArmImagePoint(pose, left, shoulder, body, indexImage, indexDepth, out var index) ||
                !TryMapArmImagePoint(pose, left, shoulder, body, middleImage, middleDepth, out var middle) ||
                !TryMapArmImagePoint(pose, left, shoulder, body, pinkyImage, pinkyDepth, out var pinky)) return;
            var palmDirection = middle - wrist;
            var palmAcross = index - pinky;
            if (palmDirection.sqrMagnitude < .000001f || palmAcross.sqrMagnitude < .000001f) return;
            var palmNormal = Vector3.Cross(palmAcross, palmDirection);
            if (palmNormal.sqrMagnitude < .000001f) return;
            var worldPalmNormal = facingOffset * palmNormal;
            var lower = targetAnimator.GetBoneTransform(lowerBone);
            var hand = targetAnimator.GetBoneTransform(handBone);
            if (lower != null && hand != null)
            {
                var forearmDirection = hand.position - lower.position;
                var forearmUp = Vector3.Slerp(facingOffset * body.Forward, worldPalmNormal, .7f);
                ApplyWorldDirection(lowerBone, forearmDirection, forearmUp);
            }
            ApplyWorldDirection(handBone, facingOffset * palmDirection, worldPalmNormal);
        }

        private bool TryReadHandEvidence(PosePacket pose, bool left, bool hasPoseWrist, Vector3 poseWristImage, float wristDepthZ,
            out Vector3 handWristImage, out float handDepthZ)
        {
            var side = SourceSide(left);
            const float minHandConfidence = .35f;
            var hasDetectedWrist = pose.TryGetImage($"{side}_hand_wrist", minHandConfidence, out var detectedWrist);
            var hasPalm = pose.TryGetImage($"{side}_hand_palm", minHandConfidence, out var detectedPalm);
            handWristImage = detectedPalm;
            var hasLeftShoulder = pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulder);
            var hasRightShoulder = pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulder);
            var hasShoulders = hasLeftShoulder && hasRightShoulder;
            var shoulderWidth = hasShoulders ? Vector2.Distance(leftShoulder, rightShoulder) : .2f;
            var leftShoulderWorld = Vector3.zero;
            var rightShoulderWorld = Vector3.zero;
            var hasLeftWorldShoulder = pose.TryGet("left_shoulder", wristMinConfidence, out leftShoulderWorld);
            var hasRightWorldShoulder = pose.TryGet("right_shoulder", wristMinConfidence, out rightShoulderWorld);
            var hasWorldShoulders = hasLeftWorldShoulder && hasRightWorldShoulder;
            var clusterLimit = Mathf.Max(shoulderWidth * 1.1f, .14f);
            var associationDistance = hasDetectedWrist && hasPoseWrist
                ? Vector2.Distance(detectedWrist, poseWristImage)
                : 0f;
            // Hand Landmarker is authoritative for the hand. Pose wrist is diagnostic only;
            // it is commonly displaced or absent when the elbow/forearm is occluded.
            var associated = hasDetectedWrist;
            var accepted = associated ? 1 : 0;
            var maxClusterDistance = 0f;
            foreach (var suffix in new[] { "pinky", "index", "thumb" })
            {
                var name = $"{side}_hand_{suffix}";
                if (!pose.TryGetImage(name, minHandConfidence, out var image) ||
                    !IsInsideExtendedArmImage(image, .08f)) continue;
                var distance = Vector2.Distance(image, detectedWrist);
                maxClusterDistance = Mathf.Max(maxClusterDistance, distance);
                if (distance > clusterLimit) continue;
                accepted++;
            }
            var depthScale = hasShoulders && hasWorldShoulders
                ? Mathf.Max(Vector3.Distance(leftShoulderWorld, rightShoulderWorld), .001f) / Mathf.Max(shoulderWidth, .001f)
                : 1f;
            handDepthZ = wristDepthZ - (detectedPalm.z - detectedWrist.z) * depthScale;
            var valid = associated && hasPalm && accepted >= 3;
            var state = $"detectorPoints={accepted}/4, association={associationDistance:F3}, maxCluster={maxClusterDistance:F3}, limit={clusterLimit:F3}, valid={valid}";
            if (left) leftHandEvidenceState = state; else rightHandEvidenceState = state;
            return valid;
        }

        private bool TryMapArmImagePoint(PosePacket pose, bool left, Vector3 shoulder, UpperBodyPose body, Vector3 imagePoint, float sourceZ, out Vector3 point)
        {
            if (!pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulderImage) ||
                !pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulderImage))
            {
                point = default;
                return false;
            }
            var imageShoulderWidth = Vector2.Distance(leftShoulderImage, rightShoulderImage);
            if (imageShoulderWidth < .03f)
            {
                point = default;
                return false;
            }
            if (trackingCamera == null || targetAnimator == null ||
                !TryGetArmViewportTarget(pose, left, imagePoint, out var shoulderTransform, out var shoulderViewport, out var targetViewport))
            {
                point = default;
                return false;
            }
            targetViewport.z = Mathf.Max(
                trackingCamera.nearClipPlane + .08f,
                shoulderViewport.z - (sourceZ - shoulder.z));
            var worldTarget = trackingCamera.ViewportToWorldPoint(targetViewport);
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            point = shoulder + Quaternion.Inverse(facingOffset) * (worldTarget - shoulderTransform.position);
            return true;
        }

        private bool TryGetArmViewportTarget(PosePacket pose, bool left, Vector3 imagePoint,
            out Transform shoulderTransform, out Vector3 shoulderViewport, out Vector3 targetViewport)
        {
            shoulderTransform = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm);
            var leftShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var rightShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (shoulderTransform == null || leftShoulder == null || rightShoulder == null ||
                !pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulderImage) ||
                !pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulderImage))
            {
                shoulderViewport = default;
                targetViewport = default;
                return false;
            }
            shoulderViewport = trackingCamera.WorldToViewportPoint(shoulderTransform.position);
            var leftViewport = trackingCamera.WorldToViewportPoint(leftShoulder.position);
            var rightViewport = trackingCamera.WorldToViewportPoint(rightShoulder.position);
            var sourceLeft = ToPreviewViewport(leftShoulderImage);
            var sourceRight = ToPreviewViewport(rightShoulderImage);
            var sourcePoint = ToPreviewViewport(imagePoint);
            var sourceCenter = (sourceLeft + sourceRight) * .5f;
            var sourceAxis = sourceLeft - sourceRight;
            var sourceLengthSquared = sourceAxis.sqrMagnitude;
            if (sourceLengthSquared < .0009f)
            {
                targetViewport = default;
                return false;
            }
            var targetLeft = new Vector2(leftViewport.x, leftViewport.y);
            var targetRight = new Vector2(rightViewport.x, rightViewport.y);
            var targetCenter = (targetLeft + targetRight) * .5f;
            var targetAxis = targetLeft - targetRight;
            var delta = sourcePoint - sourceCenter;
            var screenScale = targetAxis.magnitude / Mathf.Sqrt(sourceLengthSquared);
            var mapped = targetCenter + delta * screenScale;
            targetViewport = new Vector3(mapped.x, mapped.y, shoulderViewport.z);
            return shoulderViewport.z > 0f && targetViewport.z > 0f;
        }

        private Vector2 ToPreviewViewport(Vector3 image)
        {
            return new Vector2(avatarMirror ? 1f - image.x : image.x, 1f - image.y);
        }

        private static bool IsInsideExtendedArmImage(Vector3 image, float margin)
        {
            return image.x >= -margin && image.x <= 1f + margin && image.y >= -margin && image.y <= 1f + margin;
        }

        private void UpdateArmScreenDiagnostics(bool left, PosePacket pose, HumanBodyBones handBone, bool tracked)
        {
            var state = tracked ? "tracked_no_projection" : "not_tracked";
            var palmName = $"{SourceSide(left)}_hand_palm";
            var hasSource = pose.TryGetImage(palmName, .5f, out var source);
            if (tracked && trackingCamera != null && TryGetAvatarPalmCenter(left, out var palmCenter) && hasSource &&
                TryGetArmViewportTarget(pose, left, source, out _, out _, out var targetViewport))
            {
                var actual = trackingCamera.WorldToViewportPoint(palmCenter);
                var target = new Vector2(targetViewport.x, targetViewport.y);
                var error = Vector2.Distance(new Vector2(actual.x, actual.y), target);
                var hand = targetAnimator.GetBoneTransform(handBone);
                var forearm = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm);
                var midpoint = hand != null && forearm != null ? (hand.position + forearm.position) * .5f : Vector3.zero;
                state = $"stage=palm_locked, source={palmName}, target={target:F3}, actual=({actual.x:F3}, {actual.y:F3}), " +
                        $"error={error:F4}, forearmMid={midpoint:F3}";
            }
            else if (tracked) state = $"stage=palm_unavailable, source={palmName}, reason=source_or_avatar_palm_missing";
            if (left) leftArmScreenState = state; else rightArmScreenState = state;
        }

        private void ResolveArmDepth(PosePacket pose, bool left, Vector3 shoulder, Vector3 rawElbow, bool elbowObserved, float worldShoulderWidth, ref Vector3 elbow, ref Vector3 wrist)
        {
            var side = SourceSide(left);
            var hasLeftShoulderImage = pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulderImage);
            var hasRightShoulderImage = pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulderImage);
            var hasShoulderImage = pose.TryGetImage($"{side}_shoulder", wristMinConfidence, out var shoulderImage);
            var hasElbowImage = pose.TryGetImage($"{side}_elbow", wristMinConfidence, out var elbowImage);
            var hasWristImage = pose.TryGetImage($"{side}_wrist", wristMinConfidence, out var wristImage);
            var hasShoulders = hasLeftShoulderImage && hasRightShoulderImage;
            var hasArmImages = hasShoulderImage && hasElbowImage && hasWristImage;
            var pathRatio = -1f;
            var depthEvidence = .35f;
            if (hasShoulders && hasArmImages)
            {
                var imageShoulderWidth = Mathf.Max(Vector2.Distance(leftShoulderImage, rightShoulderImage), .001f);
                var imageArmPath = Vector2.Distance(shoulderImage, elbowImage) + Vector2.Distance(elbowImage, wristImage);
                pathRatio = imageArmPath / imageShoulderWidth;
                depthEvidence = Mathf.InverseLerp(1.6f, .65f, pathRatio);
            }

            var rawDepth = wrist.z - shoulder.z;
            var maxDepth = worldShoulderWidth * 1.25f;
            var correctedDepth = Mathf.Clamp(rawDepth, -maxDepth, maxDepth);
            wrist.z = shoulder.z + correctedDepth;
            if (elbowObserved)
            {
                var elbowDepth = rawElbow.z - shoulder.z;
                elbow.z = shoulder.z + Mathf.Clamp(elbowDepth * Mathf.Lerp(.15f, 1f, depthEvidence), -maxDepth * .6f, maxDepth * .6f);
            }

            var state = $"pathRatio={pathRatio:F2}, evidence={depthEvidence:F2}, wristZ={rawDepth:F3}->{correctedDepth:F3}";
            if (left) leftArmDepthState = state; else rightArmDepthState = state;
        }

        private Vector3 ConstrainArmEndpointToCamera(HumanBodyBones bone, HumanBodyBones endpointBone, Vector3 worldDirection)
        {
            if (trackingCamera == null || worldDirection.sqrMagnitude < .000001f) return worldDirection;
            var start = targetAnimator.GetBoneTransform(bone);
            var endpoint = targetAnimator.GetBoneTransform(endpointBone);
            if (start == null || endpoint == null) return worldDirection;
            var boneLength = Vector3.Distance(start.position, endpoint.position);
            if (boneLength < .001f) return worldDirection;

            var desiredEnd = start.position + worldDirection.normalized * boneLength;
            var viewport = trackingCamera.WorldToViewportPoint(desiredEnd);
            var safeDepth = Mathf.Max(trackingCamera.nearClipPlane + .08f, .12f);
            var clampedViewport = new Vector3(
                Mathf.Clamp(viewport.x, .08f, .92f),
                Mathf.Clamp(viewport.y, .08f, .92f),
                Mathf.Max(viewport.z, safeDepth));
            if ((clampedViewport - viewport).sqrMagnitude < .000001f) return worldDirection;

            var clampedEnd = trackingCamera.ViewportToWorldPoint(clampedViewport);
            var constrained = clampedEnd - start.position;
            if (constrained.sqrMagnitude < .000001f) return worldDirection;
            armCameraClampCount++;
            lastArmCameraClamp = $"{bone}: viewport={viewport:F2} -> {clampedViewport:F2}";
            return constrained.normalized * worldDirection.magnitude;
        }

        private static Vector3 InferElbow(Vector3 shoulder, Vector3 wrist, UpperBodyPose body, bool left, PointContinuityFilter filter)
        {
            var chord = wrist - shoulder;
            var shoulderWidth = Mathf.Max(body.Lateral.magnitude, .05f);
            var upperLength = shoulderWidth * .78f;
            var lowerLength = shoulderWidth * .72f;
            var distance = Mathf.Clamp(chord.magnitude, Mathf.Abs(upperLength - lowerLength) + .001f, upperLength + lowerLength - .001f);
            var direction = chord / distance;
            if (direction.sqrMagnitude < .000001f) direction = Vector3.down;
            else direction.Normalize();
            var along = (upperLength * upperLength - lowerLength * lowerLength + distance * distance) / (2f * distance);
            var bendHeight = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - along * along, 0f));
            var pole = Vector3.zero;
            if (filter.TryGetLastStable(out var previousElbow))
            {
                pole = Vector3.ProjectOnPlane(previousElbow - shoulder, direction);
            }
            if (pole.sqrMagnitude < .0001f)
            {
                var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
                pole = Vector3.ProjectOnPlane(
                    lateral * (left ? -1f : 1f) + body.Forward * .2f + Vector3.down * .2f, direction);
            }
            return shoulder + direction * along + pole.normalized * bendHeight;
        }

        private static bool IsPlausibleElbow(Vector3 shoulder, Vector3 elbow, Vector3 palm, float shoulderWidth)
        {
            var upper = Vector3.Distance(shoulder, elbow);
            var lower = Vector3.Distance(elbow, palm);
            if (upper < shoulderWidth * .35f || upper > shoulderWidth * 1.25f) return false;
            if (lower < shoulderWidth * .3f || lower > shoulderWidth * 1.35f) return false;
            return lower / Mathf.Max(upper, .001f) <= 1.8f;
        }

        private bool TryApplyHandContact(PosePacket pose, UpperBodyPose upperBody)
        {
            handContactTracking = false;
            wristSeparationRatio = 0f;
            if (!PoseInputMapper.TryGetVisible(pose, "left_elbow", avatarMirror, wristMinConfidence, out var leftElbow) ||
                !PoseInputMapper.TryGetVisible(pose, "right_elbow", avatarMirror, wristMinConfidence, out var rightElbow) ||
                !PoseInputMapper.TryGetVisible(pose, "left_wrist", avatarMirror, wristMinConfidence, out var leftWrist) ||
                !PoseInputMapper.TryGetVisible(pose, "right_wrist", avatarMirror, wristMinConfidence, out var rightWrist)) return false;

            var sourceShoulderWidth = Mathf.Max(upperBody.Lateral.magnitude, .001f);
            wristSeparationRatio = Vector3.Distance(leftWrist, rightWrist) / sourceShoulderWidth;
            if (wristSeparationRatio > handContactDistanceRatio) return false;

            var leftUpperArm = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var rightUpperArm = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (leftUpperArm == null || rightUpperArm == null) return false;
            var avatarShoulderCenter = (leftUpperArm.position + rightUpperArm.position) * .5f;
            var scale = Vector3.Distance(leftUpperArm.position, rightUpperArm.position) / sourceShoulderWidth;
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            var sourceTarget = (leftWrist + rightWrist) * .5f;
            var target = avatarShoulderCenter + facingOffset * (sourceTarget - upperBody.ShoulderCenter) * scale;
            var upHint = facingOffset * upperBody.Forward;
            ApplyArmIk(true, target, facingOffset * (leftElbow - upperBody.LeftShoulder), upHint);
            ApplyArmIk(false, target, facingOffset * (rightElbow - upperBody.RightShoulder), upHint);
            handContactTracking = true;
            return true;
        }

        private void ApplyArmIk(bool left, Vector3 target, Vector3 poleHint, Vector3 upHint)
        {
            var upperBone = left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm;
            var lowerBone = left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm;
            var upper = targetAnimator.GetBoneTransform(upperBone);
            var lower = targetAnimator.GetBoneTransform(lowerBone);
            var hand = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand);
            if (upper == null || lower == null || hand == null) return;

            var upperLength = Vector3.Distance(upper.position, lower.position);
            var lowerLength = Vector3.Distance(lower.position, hand.position);
            var toTarget = target - upper.position;
            if (toTarget.sqrMagnitude < .000001f) return;
            var direction = toTarget.normalized;
            var distance = Mathf.Clamp(toTarget.magnitude, Mathf.Abs(upperLength - lowerLength) + .001f, upperLength + lowerLength - .001f);
            var along = (upperLength * upperLength - lowerLength * lowerLength + distance * distance) / (2f * distance);
            var height = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - along * along, 0f));
            var pole = Vector3.ProjectOnPlane(poleHint, direction);
            if (pole.sqrMagnitude < .000001f) pole = Vector3.ProjectOnPlane(Vector3.down, direction);
            var elbowTarget = upper.position + direction * along + pole.normalized * height;
            ApplyWorldDirection(upperBone, elbowTarget - upper.position, upHint);
            ApplyWorldDirection(lowerBone, target - lower.position, upHint);
        }

        private void GetRelaxedArmPose(bool left, UpperBodyPose upperBody, out Vector3 upperDirection, out Vector3 lowerDirection)
        {
            var lateral = upperBody.Lateral.sqrMagnitude > .000001f ? upperBody.Lateral.normalized : Vector3.right;
            var sourceLeft = left != avatarMirror;
            var side = sourceLeft ? -1f : 1f;
            var shoulder = sourceLeft ? upperBody.LeftShoulder : upperBody.RightShoulder;
            var hipTarget = upperBody.HipCenter + lateral * side * upperBody.Lateral.magnitude * .22f;
            var elbowTarget = Vector3.Lerp(shoulder, hipTarget, .52f) + lateral * side * upperBody.Lateral.magnitude * .08f;
            upperDirection = elbowTarget - shoulder;
            lowerDirection = hipTarget - elbowTarget;
            if (upperDirection.sqrMagnitude < .000001f) upperDirection = Vector3.down;
            if (lowerDirection.sqrMagnitude < .000001f) lowerDirection = Vector3.down;
        }

        private bool TryGet(PosePacket pose, string name, out Vector3 position)
        {
            return PoseInputMapper.TryGet(pose, name, avatarMirror, out position);
        }

        private string SourceSide(bool avatarLeft)
        {
            return avatarLeft != avatarMirror ? "left" : "right";
        }

        private Vector2 ResolveScreenBody(ScreenBodyPose body, float leanDegrees, out float shoulderWidth)
        {
            bodyShoulderMode = body.ShoulderMode;
            if (body.ShoulderMode == 0)
            {
                shoulderScreenDirection = Mathf.Abs(body.ShoulderDirection) > .01f ? body.ShoulderDirection : shoulderScreenDirection;
                shoulderWidth = body.ShoulderWidth;
                return body.Anchor;
            }

            shoulderWidth = body.ShoulderWidth > .001f ? body.ShoulderWidth : hipsInitialized ? sourceShoulderWidthOrigin : .45f;
            var center = body.ShoulderWidth > .001f ? body.ShoulderCenter : body.Anchor;
            if (body.ShoulderWidth <= .001f)
                center.x += body.ShoulderMode < 0 ? shoulderScreenDirection * shoulderWidth * .5f : -shoulderScreenDirection * shoulderWidth * .5f;
            var radians = leanDegrees * Mathf.Deg2Rad;
            return center + new Vector2(Mathf.Sin(radians), -Mathf.Cos(radians)) * shoulderWidth * 1.45f;
        }

        private void TryCalibrateCameraFraming(ScreenBodyPose body, float shoulderWidth)
        {
            if (!autoFrameCamera || cameraFramingReady || trackingCamera == null || shoulderWidth <= .001f) return;
            if (cameraCalibrationStarted < 0f)
            {
                cameraCalibrationStarted = Time.unscaledTime;
                cameraCalibrationCenter = body.ShoulderCenter;
                cameraCalibrationWidth = shoulderWidth;
                return;
            }
            var sampleT = 1f - Mathf.Exp(-5f * Time.deltaTime);
            cameraCalibrationCenter = Vector2.Lerp(cameraCalibrationCenter, body.ShoulderCenter, sampleT);
            cameraCalibrationWidth = Mathf.Lerp(cameraCalibrationWidth, shoulderWidth, sampleT);
            if (Time.unscaledTime - cameraCalibrationStarted < cameraCalibrationSeconds) return;

            var left = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var right = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (left == null || right == null) return;
            var avatarShoulderCenter = (left.position + right.position) * .5f;
            var avatarShoulderWidth = Vector3.Distance(left.position, right.position);
            var usableWidth = Mathf.Max(cameraCalibrationWidth * (1f - cameraFramingMargin), .03f);
            var verticalTan = Mathf.Tan(trackingCamera.fieldOfView * .5f * Mathf.Deg2Rad);
            var horizontalTan = verticalTan * trackingCamera.aspect;
            var distance = Mathf.Max(avatarShoulderWidth / (2f * usableWidth * horizontalTan), cameraMinimumDistance);
            var halfHeight = distance * verticalTan;
            var halfWidth = distance * horizontalTan;
            var viewportOffset = trackingCamera.transform.right * ((cameraCalibrationCenter.x - .5f) * 2f * halfWidth) +
                                 trackingCamera.transform.up * ((.5f + cameraCalibrationCenter.y) * 2f * halfHeight);
            var cameraCenter = avatarShoulderCenter - viewportOffset;
            trackingCamera.transform.position = cameraCenter - trackingCamera.transform.forward * distance;
            screenHorizontalRange = halfWidth * 2f;
            screenVerticalRange = halfHeight * 2f;
            cameraFramingReady = true;
        }

        private float ResolveBodyLean(ScreenBodyPose body)
        {
            var targetLean = body.LeanSignal;
            if (body.ShoulderMode == 0)
            {
                if (!bodyLeanOriginInitialized)
                {
                    bodyLeanOrigin = body.LeanSignal;
                    bodyLeanOriginInitialized = true;
                }
                targetLean = Mathf.DeltaAngle(bodyLeanOrigin, body.LeanSignal) * bodyLeanGain;
            }
            else if (body.ShoulderMode < 0)
            {
                if (!leftShoulderLeanInitialized || lastBodyShoulderMode != body.ShoulderMode)
                {
                    leftShoulderLeanOrigin = body.LeanSignal - filteredBodyLean;
                    leftShoulderLeanInitialized = true;
                }
                targetLean = Mathf.DeltaAngle(leftShoulderLeanOrigin, body.LeanSignal);
            }
            else if (body.ShoulderMode > 0)
            {
                if (!rightShoulderLeanInitialized || lastBodyShoulderMode != body.ShoulderMode)
                {
                    rightShoulderLeanOrigin = body.LeanSignal - filteredBodyLean;
                    rightShoulderLeanInitialized = true;
                }
                targetLean = Mathf.DeltaAngle(rightShoulderLeanOrigin, body.LeanSignal);
            }
            lastBodyShoulderMode = body.ShoulderMode;
            var t = 1f - Mathf.Exp(-bodyLeanSmoothing * Time.deltaTime);
            filteredBodyLean = Mathf.LerpAngle(filteredBodyLean, Mathf.Clamp(targetLean, -maxBodyLean, maxBodyLean), t);
            var delta = Mathf.DeltaAngle(stableBodyLean, filteredBodyLean);
            if (Mathf.Abs(delta) > bodyLeanDeadZone)
                stableBodyLean += Mathf.Sign(delta) * (Mathf.Abs(delta) - bodyLeanDeadZone);
            return Mathf.Clamp(stableBodyLean, -maxBodyLean, maxBodyLean);
        }

        private void ApplyHips(Vector2 screenCenter, float sourceShoulderWidth)
        {
            var root = targetAnimator.transform;
            if (root == null) return;
            if (!hipsInitialized)
            {
                if (sourceShoulderWidth <= .001f) return;
                sourceScreenOrigin = screenCenter;
                filteredScreenCenter = screenCenter;
                stableScreenCenter = screenCenter;
                sourceShoulderWidthOrigin = Mathf.Max(sourceShoulderWidth, .001f);
                filteredShoulderWidth = sourceShoulderWidthOrigin;
                stableShoulderWidth = sourceShoulderWidthOrigin;
                avatarHipOrigin = root.position;
                hipsInitialized = true;
            }

            var measurementT = 1f - Mathf.Exp(-positionMeasurementSmoothing * Time.deltaTime);
            filteredScreenCenter = Vector2.Lerp(filteredScreenCenter, screenCenter, measurementT);
            stableScreenCenter.x = FollowOutsideDeadZone(stableScreenCenter.x, filteredScreenCenter.x, horizontalPositionDeadZone);
            stableScreenCenter.y = FollowOutsideDeadZone(stableScreenCenter.y, filteredScreenCenter.y, verticalPositionDeadZone);
            if (sourceShoulderWidth > .001f)
            {
                filteredShoulderWidth = Mathf.Lerp(filteredShoulderWidth, sourceShoulderWidth, measurementT);
                stableShoulderWidth = FollowOutsideDeadZone(stableShoulderWidth, filteredShoulderWidth, sourceShoulderWidthOrigin * depthPositionDeadZone);
            }

            var screenDelta = stableScreenCenter - sourceScreenOrigin;
            var widthRatio = sourceShoulderWidthOrigin / Mathf.Max(stableShoulderWidth, .001f) - 1f;
            var depthOffset = Mathf.Clamp(widthRatio * bodyDepthFromShoulderWidth, -maxDepthOffset, maxDepthOffset);
            bodyPositionOffset = new Vector3(screenDelta.x * screenHorizontalRange, screenDelta.y * screenVerticalRange, depthOffset) * hipsPositionScale;
            var target = avatarHipOrigin + bodyPositionOffset;
            if (cameraFramingReady && trackingCamera != null)
            {
                var forwardDistance = Vector3.Dot(target - trackingCamera.transform.position, trackingCamera.transform.forward);
                if (forwardDistance < cameraMinimumDistance)
                    target += trackingCamera.transform.forward * (cameraMinimumDistance - forwardDistance);
            }
            var t = 1f - Mathf.Exp(-positionFollowSpeed * Time.deltaTime);
            var maxStep = maxHipsSpeed > 0f ? maxHipsSpeed * Time.deltaTime : float.PositiveInfinity;
            root.position = Vector3.MoveTowards(root.position, Vector3.Lerp(root.position, target, t), maxStep);
        }

        private static float FollowOutsideDeadZone(float current, float target, float deadZone)
        {
            var delta = target - current;
            var distance = Mathf.Abs(delta);
            return distance <= deadZone ? current : current + Mathf.Sign(delta) * (distance - deadZone);
        }

        private void ReturnToRest()
        {
            foreach (HumanBodyBones bone in System.Enum.GetValues(typeof(HumanBodyBones)))
            {
                if (bone == HumanBodyBones.LastBone || !solver.TryGetRestRotation(bone, out var rest)) continue;
                var transform = targetAnimator.GetBoneTransform(bone);
                if (transform != null) transform.rotation = smoother.Smooth(bone, transform.rotation, rootRotationDelta * rest, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
            }
        }

        private void ResetTrackingCalibration()
        {
            var root = targetAnimator.transform;
            root.position = avatarRootOriginPosition;
            root.rotation = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up) * avatarRootOriginRotation;
            rootRotationDelta = root.rotation * Quaternion.Inverse(avatarRootOriginRotation);
            currentBodyYaw = 0f;
            maxObservedBodySpan = 0f;
            bodyTurnSide = 1f;

            hipsInitialized = false;
            bodyPositionTracking = false;
            bodyPositionOffset = Vector3.zero;
            sourceScreenOrigin = Vector2.zero;
            filteredScreenCenter = Vector2.zero;
            stableScreenCenter = Vector2.zero;
            sourceShoulderWidthOrigin = 0f;
            filteredShoulderWidth = 0f;
            stableShoulderWidth = 0f;

            bodyLeanOriginInitialized = false;
            leftShoulderLeanInitialized = false;
            rightShoulderLeanInitialized = false;
            lastBodyShoulderMode = 99;
            filteredBodyLean = 0f;
            stableBodyLean = 0f;
            bodyLeanDegrees = 0f;

            headPitchInitialized = false;
            headRollInitialized = false;
            lastReliableFaceTime = float.NegativeInfinity;
            filteredHeadRoll = 0f;
            headTracking = false;
            headYawDegrees = 0f;
            headPitchDegrees = 0f;
            headRollDegrees = 0f;

            handContactTracking = false;
            leftArmRelaxWeight = 1f;
            rightArmRelaxWeight = 1f;
            leftElbowFilter.Reset();
            rightElbowFilter.Reset();
            leftWristFilter.Reset();
            rightWristFilter.Reset();
            hasLeftConstrainedArm = false;
            hasRightConstrainedArm = false;
            smoother.Reset();
        }

        private void ReturnBoneToRest(HumanBodyBones bone)
        {
            if (!solver.TryGetRestRotation(bone, out var rest)) return;
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform != null) transform.rotation = smoother.Smooth(bone, transform.rotation, rootRotationDelta * rest, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
        }

        private void RelaxArmsToRest()
        {
            leftArmRelaxWeight = Mathf.MoveTowards(leftArmRelaxWeight, 1f, armRelaxSpeed * Time.deltaTime);
            rightArmRelaxWeight = Mathf.MoveTowards(rightArmRelaxWeight, 1f, armRelaxSpeed * Time.deltaTime);
            ReturnBoneToRest(HumanBodyBones.LeftUpperArm);
            ReturnBoneToRest(HumanBodyBones.LeftLowerArm);
            ReturnBoneToRest(HumanBodyBones.LeftHand);
            ReturnBoneToRest(HumanBodyBones.RightUpperArm);
            ReturnBoneToRest(HumanBodyBones.RightLowerArm);
            ReturnBoneToRest(HumanBodyBones.RightHand);
        }

        private sealed class PointContinuityFilter
        {
            private bool hasStable;
            private bool acquiring;
            private int candidateFrames;
            private Vector3 stablePoint;
            private Vector3 pendingPoint;
            private Vector3 filteredVelocity;
            private float lastAcceptedTime;
            private float lastObservedTime;

            public string Stage { get; private set; } = "LOST";
            public string RejectReason { get; private set; } = "none";

            public bool TryGetLastStable(out Vector3 point)
            {
                point = stablePoint;
                return hasStable;
            }

            public void Reset()
            {
                hasStable = false;
                acquiring = false;
                candidateFrames = 0;
                stablePoint = Vector3.zero;
                pendingPoint = Vector3.zero;
                filteredVelocity = Vector3.zero;
                lastAcceptedTime = 0f;
                lastObservedTime = 0f;
                Stage = "LOST";
                RejectReason = "reset";
            }

            public bool TryGetStable(Vector3 candidate, bool hasCandidate, float referenceLength, float maxSpeed, float holdTime, int requiredFrames, float deadZoneScale, float now, out Vector3 point)
            {
                if (!hasCandidate)
                {
                    acquiring = false;
                    candidateFrames = 0;
                    RejectReason = "missing_or_anatomy";
                    if (hasStable && now - lastObservedTime <= holdTime)
                    {
                        var predictionStep = Mathf.Clamp(now - lastAcceptedTime, 0f, holdTime);
                        stablePoint += filteredVelocity * predictionStep;
                        lastAcceptedTime = now;
                        Stage = "PREDICTED";
                        point = stablePoint;
                        return true;
                    }
                    hasStable = false;
                    Stage = "LOST";
                    point = stablePoint;
                    return hasStable;
                }

                referenceLength = Mathf.Max(referenceLength, .001f);
                if (hasStable)
                {
                    var dt = Mathf.Clamp(now - lastAcceptedTime, .001f, .1f);
                    var allowedStep = referenceLength * .35f + maxSpeed * dt;
                    if (Vector3.Distance(stablePoint, candidate) > allowedStep)
                    {
                        RejectReason = "discontinuous_jump";
                        if (now - lastAcceptedTime <= holdTime)
                        {
                            Stage = "COASTING";
                            point = stablePoint;
                            return true;
                        }
                        hasStable = false;
                        acquiring = false;
                    }
                    else
                    {
                        var delta = candidate - stablePoint;
                        var distance = delta.magnitude;
                        var deadZone = referenceLength * deadZoneScale;
                        if (distance > deadZone)
                        {
                            var outsideDeadZone = stablePoint + delta / distance * (distance - deadZone);
                            var measuredVelocity = (outsideDeadZone - stablePoint) / dt;
                            var derivativeAlpha = OneEuroAlpha(1f, dt);
                            filteredVelocity = Vector3.Lerp(filteredVelocity, measuredVelocity, derivativeAlpha);
                            var xyCutoff = 1.5f + filteredVelocity.magnitude * .8f;
                            var zCutoff = .6f + Mathf.Abs(filteredVelocity.z) * .25f;
                            var xyT = OneEuroAlpha(xyCutoff, dt);
                            var zT = OneEuroAlpha(zCutoff, dt);
                            stablePoint = new Vector3(
                                Mathf.Lerp(stablePoint.x, outsideDeadZone.x, xyT),
                                Mathf.Lerp(stablePoint.y, outsideDeadZone.y, xyT),
                                Mathf.Lerp(stablePoint.z, outsideDeadZone.z, zT));
                            Stage = "TRACKED";
                        }
                        else
                        {
                            Stage = "TRACKED_HOLD";
                        }
                        lastAcceptedTime = now;
                        lastObservedTime = now;
                        RejectReason = "none";
                        point = stablePoint;
                        return true;
                    }
                }

                if (!hasStable)
                {
                    if (!acquiring || Vector3.Distance(pendingPoint, candidate) > referenceLength * .75f)
                    {
                        acquiring = true;
                        candidateFrames = 1;
                        pendingPoint = candidate;
                        Stage = "CANDIDATE";
                        RejectReason = "new_candidate";
                    }
                    else
                    {
                        candidateFrames++;
                        pendingPoint = new Vector3(
                            Mathf.Lerp(pendingPoint.x, candidate.x, .5f),
                            Mathf.Lerp(pendingPoint.y, candidate.y, .5f),
                            Mathf.Lerp(pendingPoint.z, candidate.z, .2f));
                    }
                    if (candidateFrames < requiredFrames)
                    {
                        point = pendingPoint;
                        return false;
                    }
                    stablePoint = pendingPoint;
                    filteredVelocity = Vector3.zero;
                    acquiring = false;
                    hasStable = true;
                    lastAcceptedTime = now;
                    lastObservedTime = now;
                    Stage = "TRACKED";
                    RejectReason = "none";
                }
                point = stablePoint;
                return true;
            }

            private static float OneEuroAlpha(float cutoff, float dt)
            {
                var tau = 1f / (2f * Mathf.PI * Mathf.Max(cutoff, .001f));
                return 1f / (1f + tau / Mathf.Max(dt, .001f));
            }
        }
    }
}

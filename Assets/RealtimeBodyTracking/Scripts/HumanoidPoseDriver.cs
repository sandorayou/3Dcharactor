using System;
using System.Collections.Generic;
using UnityEngine;
using VRM;

namespace RealtimeBodyTracking
{
    public sealed class HumanoidPoseDriver : MonoBehaviour
    {
        private const bool InputCoordinatesNeedMirror = false;
        [Header("References")]
        [SerializeField] private Animator targetAnimator;
        private LocalPosePacketSource localPoseSource;
        [SerializeField] private Camera trackingCamera;
        [Header("Camera Framing")]
        [SerializeField] private bool autoFrameCamera = true;
        [SerializeField, Range(.2f, 3f)] private float cameraCalibrationSeconds = .75f;
        [SerializeField, Range(0f, .4f)] private float cameraFramingMargin = .12f;
        [SerializeField, Range(.35f, 2f)] private float cameraMinimumDistance = .5f;
        [SerializeField, Range(-.2f, .2f)] private float avatarViewportVerticalOffset = -.02f;
        [Header("Anime Internal Lines")]
        [SerializeField] private bool enableAnimeInternalLines = false;
        [SerializeField, Range(.25f, 2.5f)] private float animeLineThickness = 1f;
        [SerializeField, Range(.02f, .4f)] private float animeLineThreshold = .115f;
        [SerializeField, Range(.005f, .2f)] private float animeLineSoftness = .07f;
        [SerializeField, Range(0f, 1f)] private float animeLineStrength = .82f;
        [SerializeField] private Color animeLineColor = new Color(.008f, .01f, .016f, .92f);
        [Header("Tracking")]
        [SerializeField, Range(1f, 60f)] private float smoothingSpeed = 24f;
        [SerializeField, Range(0f, 10f)] private float rotationDeadZoneDegrees = 3f;
        [SerializeField] private bool avatarMirror = true;
        [SerializeField] private bool enableHipsPosition = true;
        [SerializeField, Range(0f, 5f)] private float hipsPositionScale = .25f;
        [SerializeField, Range(0f, 3f)] private float bodyDepthFromShoulderWidth = 1.2f;
        [SerializeField, Min(0f)] private float maxHipsSpeed = .8f;
        [SerializeField, Min(0f)] private float screenHorizontalRange = 1.2f;
        [SerializeField, Min(0f)] private float screenVerticalRange = .8f;
        [SerializeField, Min(0f)] private float maxDepthOffset = 1.5f;
        [SerializeField, Range(0f, .1f)] private float horizontalPositionDeadZone = .02f;
        [SerializeField, Range(0f, .1f)] private float verticalPositionDeadZone = .025f;
        [SerializeField, Range(0f, .25f)] private float depthPositionDeadZone = .06f;
        [SerializeField, Range(.5f, 30f)] private float positionMeasurementSmoothing = 6f;
        [SerializeField, Range(.5f, 30f)] private float positionFollowSpeed = 5f;
        [SerializeField, Range(0f, 1f)] private float positionMinConfidence = .6f;
        [SerializeField, Range(0f, 10f)] private float bodyLeanDeadZone = .5f;
        [SerializeField, Range(0f, 45f)] private float maxBodyLean = 40f;
        [SerializeField, Range(.5f, 30f)] private float bodyLeanSmoothing = 14f;
        [SerializeField, Range(.5f, 3f)] private float bodyLeanGain = 1f;
        [SerializeField] private bool mirrorShoulderElevation = true;
        [Header("Face Zoom")]
        [SerializeField] private bool enableFaceZoom = true;
        [SerializeField, Min(.01f)] private float avatarFaceHeightMeters = .22f;
        [SerializeField, Range(0.05f, 1f)] private float faceZoomSmoothTime = 0.18f;
        [SerializeField, Min(0.15f)] private float minimumFaceCameraDistance = 0.28f;
        [SerializeField, Min(1f)] private float maximumFaceCameraDistance = 8f;
        [SerializeField, Range(0f, 0.2f)] private float faceSizeDeadZoneRatio = 0.025f;
        [SerializeField, Range(.75f, 1.25f)] private float avatarSizeMatchScale = .97f;
        [Header("Body Turn")]
        [SerializeField] private bool enableBodyTurn = true;
        [SerializeField, Min(0f)] private float bodyTurnSpeed = 360f;
        [SerializeField, Range(0f, 30f)] private float bodyTurnDeadZone = 2f;
        [SerializeField, Range(-180f, 180f)] private float avatarFacingOffsetDegrees = 180f;
        [SerializeField, Range(0f, 1f)] private float bodyTurnMinConfidence = .6f;
        [Header("Arm Stability")]
        [SerializeField, Range(0f, 1f)] private float bodyCollisionRadiusScale = 1f;
        [SerializeField, Range(0f, 1f)] private float wristMinConfidence = .5f;
        [SerializeField, Min(0f)] private float maxWristSpeed = 2.5f;
        [SerializeField, Min(0f)] private float maxElbowSpeed = 3f;
        [SerializeField, Range(.25f, 1.5f)] private float handHorizontalGain = 1f;
        [SerializeField, Range(.5f, 2f)] private float armVerticalGain = 1.5f;
        [SerializeField, Range(1, 5)] private int armAcquireFrames = 2;
        [SerializeField, Range(0f, .3f)] private float armPointDeadZoneScale = .03f;
        [SerializeField, Range(.5f, 5f)] private float armPositionSmoothingCutoff = 2f;
        [SerializeField, Range(0f, 2f)] private float armMotionResponsiveness = .25f;
        [SerializeField, Range(1f, 60f)] private float armRotationSmoothingSpeed = 14f;
        [SerializeField, Min(0f)] private float wristHoldTime = .15f;
        [SerializeField, Range(0.5f, 3f)] private float maxForearmToUpperArmRatio = 1.8f;
        [SerializeField, Range(.1f, 5f)] private float armRelaxSpeed = 1.2f;
        [SerializeField, Range(.1f, 10f)] private float armRecoverSpeed = 4f;
        [SerializeField, Range(.1f, 1f)] private float handContactDistanceRatio = .45f;
        [SerializeField, Range(.1f, 2f)] private float handDepthGain = 1f;
        [SerializeField, Range(.8f, 3f)] private float handNeutralProjectionRatio = 1.15f;
        [SerializeField, Range(0f, .25f)] private float handForwardOffsetShoulderWidths = .02f;
        [SerializeField, Range(0f, .1f)] private float handForwardOffsetMeters = .03f;
        [SerializeField, Range(0f, .3f)] private float maxPoseDepthCorrectionShoulderWidths = .1f;
        [SerializeField, Range(.25f, 1.5f)] private float maxHandDepthShoulderWidths = .85f;
        [SerializeField, Range(.5f, 30f)] private float handDepthSmoothing = 6f;
        [SerializeField] private float torsoChestWristTrackerZ = -.44f;
        [SerializeField] private float torsoExtendedWristTrackerZ = -.38f;
        [SerializeField, Range(0f, .5f)] private float torsoChestDepthShoulderWidths = .22f;
        [SerializeField, Range(0f, 100f)] private float maxForearmTwistDegrees = 85f;
        [SerializeField, Range(.5f, 30f)] private float handOrientationSmoothing = 8f;
        [SerializeField, Range(.5f, 30f)] private float fingerSmoothingSpeed = 9f;
        [SerializeField, Range(0f, 10f)] private float fingerRotationDeadZoneDegrees = 2f;
        [SerializeField, Range(0f, .5f)] private float fingerTrackingHoldTime = .2f;
        [SerializeField] private bool enableHead = true;
        [SerializeField] private bool enableArms = true;
        [SerializeField] private bool enableFingers = true;
        [SerializeField] private bool enableLegs = true;
        [SerializeField, Range(0f, 1f)] private float legMinConfidence = .75f;
        [Header("Head Tracking")]
        [SerializeField, Range(0f, 1f)] private float headMinConfidence = .1f;
        [SerializeField, Range(0f, 1f)] private float faceHoldTime = .25f;
        [SerializeField, Range(0f, 1f)] private float neckRotationWeight = .35f;
        [SerializeField] private bool mirrorHeadRotation = true;
        [SerializeField] private Vector3 headRotationOffsetEuler;
        [SerializeField, Range(1f, 40f)] private float headRotationSmoothing = 14f;
        [SerializeField] private bool enableFaceExpressions = true;
        [SerializeField, Range(1f, 40f)] private float faceExpressionSmoothing = 24f;
        [SerializeField] private bool enableRollCorrection;
        [SerializeField] private bool enableAnatomyLimits = true;
        [SerializeField, Min(0f)] private float trackingTimeout = .5f;
        [SerializeField] private bool returnToRestPose = true;
        [Header("Frame Exit")]
        [SerializeField] private bool finishHorizontalExitOnTrackingLost = true;
        [SerializeField, Min(0f)] private float horizontalExitLostDelay = .08f;
        [SerializeField, Range(0f, .2f)] private float horizontalExitMargin = .02f;
        [SerializeField, Range(.5f, 1f)] private float horizontalExitEdgeThreshold = .82f;
        [SerializeField, Min(0f)] private float horizontalExitMinimumSpeed = .12f;
        [SerializeField, Min(.1f)] private float horizontalExitViewportSpeed = 2.5f;
        [SerializeField] private bool finishBottomExitOnTrackingLost = true;
        [SerializeField, Range(0f, .5f)] private float bottomExitEdgeThreshold = .18f;
        [SerializeField, Min(0f)] private float bottomExitMinimumSpeed = .12f;
        [SerializeField, Min(.1f)] private float bottomExitViewportSpeed = 2.5f;
        [SerializeField, Min(0f)] private float bottomFallbackLostDelay = .3f;
        [Header("Debug")]
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
        [SerializeField, Tooltip("Ctrl+Numpad /: lock the waist at its current coordinates")] private bool waistCoordinatesLocked;
        [SerializeField, Tooltip("Live state")] private Vector3 bodyPositionOffset;
        [SerializeField, Tooltip("Live state")] private float bodyLeanDegrees;
        [SerializeField, Tooltip("Live state")] private int bodyShoulderMode;
        [SerializeField, Tooltip("Live state")] private float leftArmRelaxWeight;
        [SerializeField, Tooltip("Live state")] private float rightArmRelaxWeight;
        [SerializeField, Tooltip("Live state")] private string leftArmFilterState;
        [SerializeField, Tooltip("Live state")] private string rightArmFilterState;
        [SerializeField, Tooltip("Live state")] private string leftArmRollState;
        [SerializeField, Tooltip("Live state")] private string rightArmRollState;
        [SerializeField, Tooltip("Live state")] private string leftHandOrientationState;
        [SerializeField, Tooltip("Live state")] private string rightHandOrientationState;
        [SerializeField, Tooltip("Live state")] private string leftFingerState;
        [SerializeField, Tooltip("Live state")] private string rightFingerState;
        [SerializeField, Tooltip("Live state")] private int armCameraClampCount;
        [SerializeField, Tooltip("Live state")] private string lastArmCameraClamp;
        [SerializeField, Tooltip("Live state")] private string leftArmDepthState;
        [SerializeField, Tooltip("Live state")] private string rightArmDepthState;
        [SerializeField, Tooltip("Live state")] private string leftArmScreenState;
        [SerializeField, Tooltip("Live state")] private string rightArmScreenState;
        [SerializeField, Tooltip("Live state")] private string leftHandEvidenceState;
        [SerializeField, Tooltip("Live state")] private string rightHandEvidenceState;
        [SerializeField, Tooltip("Live state")] private bool cameraFramingReady;
        [SerializeField, Tooltip("Live state")] private string cameraFramingState;

        private readonly BoneRotationSolver solver = new();
        private readonly AvatarCollisionGeometry collisionGeometry = new();
        private readonly PoseSmoother smoother = new();
        private PosePacket lastTrackedPose;
        private UpperBodyPose lastUpperBody;
        private bool hasLastUpperBody;
        private Vector3 heldHipCenter;
        private bool heldHipCenterInitialized;
        private float lastTrackingTime = float.NegativeInfinity;
        private float lastReliableFaceTime = float.NegativeInfinity;
        private float nextDebugLog;
        private bool receivedNewPoseFrame;
        private bool receivedTrackedPoseFrame;
        private Vector2 previousFramingViewport;
        private float previousFramingViewportTime = float.NegativeInfinity;
        private float horizontalFramingVelocity;
        private float verticalFramingVelocity;
        private int pendingHorizontalExitDirection;
        private int horizontalExitDirection;
        private bool horizontalExitInProgress;
        private bool horizontalExitCompleted;
        private bool pendingBottomExit;
        private bool bottomExitInProgress;
        private bool bottomExitCompleted;
        private float filteredSourceFaceWidth;
        private float filteredSourceShoulderFramingWidth;
        private bool shoulderZoomInitialized;
        private float cameraDistanceVelocity;
        private bool faceZoomInitialized;
        private Vector2 sourceScreenOrigin;
        private Vector2 filteredScreenCenter;
        private Vector2 stableScreenCenter;
        private Vector3 avatarHipOrigin;
        private float sourceShoulderWidthOrigin;
        private float sourceCameraDistanceOrigin;
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
        private Quaternion filteredHeadRotation = Quaternion.identity;
        private bool filteredHeadRotationInitialized;
        private float lastHeadRotationTime = float.NegativeInfinity;
        private VRMBlendShapeProxy faceBlendShapeProxy;
        private float filteredBlinkLeft;
        private float filteredBlinkRight;
        private float filteredJawOpen;
        private float filteredSmile;
        private ManualAvatarController manualController;
        private float cameraCalibrationStarted = -1f;
        private Vector2 cameraCalibrationCenter;
        private float cameraCalibrationWidth;
        private float cameraCalibrationHeadTopY;
        private float maxObservedBodySpan;
        private float bodyTurnSide = 1f;
        private float currentBodyYaw;
        private readonly PointContinuityFilter leftElbowFilter = new();
        private readonly PointContinuityFilter rightElbowFilter = new();
        private readonly PointContinuityFilter leftWristFilter = new();
        private readonly PointContinuityFilter rightWristFilter = new();
        private readonly HandDepthTracker leftHandDepthTracker = new();
        private readonly HandDepthTracker rightHandDepthTracker = new();
        private readonly PalmProjectionTracker leftPalmProjectionTracker = new();
        private readonly PalmProjectionTracker rightPalmProjectionTracker = new();
        private Vector2 lastLeftHandWristImage;
        private Vector2 lastRightHandWristImage;
        private Vector3 lastLeftResolvedWrist;
        private Vector3 lastRightResolvedWrist;
        private bool leftResolvedWristInitialized;
        private bool rightResolvedWristInitialized;
        private bool leftWristWithinDeadZone;
        private bool rightWristWithinDeadZone;
        private string leftHandDepthInputState;
        private string rightHandDepthInputState;
        private float nextLeftUpperArmDepthErrorLog;
        private float nextRightUpperArmDepthErrorLog;
        private float nextLeftForearmDepthErrorLog;
        private float nextRightForearmDepthErrorLog;
        private ArmPose leftConstrainedArm;
        private ArmPose rightConstrainedArm;
        private bool hasLeftConstrainedArm;
        private bool hasRightConstrainedArm;
        private Vector3 filteredLeftHandDirection;
        private Vector3 filteredRightHandDirection;
        private Vector3 filteredLeftPalmNormal;
        private Vector3 filteredRightPalmNormal;
        private bool leftHandOrientationInitialized;
        private bool rightHandOrientationInitialized;
        private int leftHandOrientationReacquireFrames;
        private int rightHandOrientationReacquireFrames;
        private int leftPalmMissingFrames;
        private int rightPalmMissingFrames;
        private long leftPalmLastProcessedFrame = long.MinValue;
        private long rightPalmLastProcessedFrame = long.MinValue;
        private float lastLeftFingerTrackingTime = float.NegativeInfinity;
        private float lastRightFingerTrackingTime = float.NegativeInfinity;
        private Vector3 leftRestHandForwardLocal;
        private Vector3 leftRestHandAcrossLocal;
        private Vector3 rightRestHandForwardLocal;
        private Vector3 rightRestHandAcrossLocal;
        private bool leftRestHandBasisInitialized;
        private bool rightRestHandBasisInitialized;

        private static readonly (HumanBodyBones bone, string from, string to)[] LegChains =
        {
            (HumanBodyBones.LeftUpperLeg, "left_hip", "left_knee"),
            (HumanBodyBones.LeftLowerLeg, "left_knee", "left_ankle"),
            (HumanBodyBones.LeftFoot, "left_ankle", "left_foot_index"),
            (HumanBodyBones.RightUpperLeg, "right_hip", "right_knee"),
            (HumanBodyBones.RightLowerLeg, "right_knee", "right_ankle"),
            (HumanBodyBones.RightFoot, "right_ankle", "right_foot_index"),
        };

        private static readonly (string start, string middle, string end, string tip,
            HumanBodyBones leftProximal, HumanBodyBones leftIntermediate, HumanBodyBones leftDistal,
            HumanBodyBones rightProximal, HumanBodyBones rightIntermediate, HumanBodyBones rightDistal)[] FingerChains =
        {
            ("thumb_cmc", "thumb_mcp", "thumb_ip", "thumb",
                HumanBodyBones.LeftThumbProximal, HumanBodyBones.LeftThumbIntermediate, HumanBodyBones.LeftThumbDistal,
                HumanBodyBones.RightThumbProximal, HumanBodyBones.RightThumbIntermediate, HumanBodyBones.RightThumbDistal),
            ("index_mcp", "index_pip", "index_dip", "index",
                HumanBodyBones.LeftIndexProximal, HumanBodyBones.LeftIndexIntermediate, HumanBodyBones.LeftIndexDistal,
                HumanBodyBones.RightIndexProximal, HumanBodyBones.RightIndexIntermediate, HumanBodyBones.RightIndexDistal),
            ("middle_mcp", "middle_pip", "middle_dip", "middle",
                HumanBodyBones.LeftMiddleProximal, HumanBodyBones.LeftMiddleIntermediate, HumanBodyBones.LeftMiddleDistal,
                HumanBodyBones.RightMiddleProximal, HumanBodyBones.RightMiddleIntermediate, HumanBodyBones.RightMiddleDistal),
            ("ring_mcp", "ring_pip", "ring_dip", "ring",
                HumanBodyBones.LeftRingProximal, HumanBodyBones.LeftRingIntermediate, HumanBodyBones.LeftRingDistal,
                HumanBodyBones.RightRingProximal, HumanBodyBones.RightRingIntermediate, HumanBodyBones.RightRingDistal),
            ("pinky_mcp", "pinky_pip", "pinky_dip", "pinky",
                HumanBodyBones.LeftLittleProximal, HumanBodyBones.LeftLittleIntermediate, HumanBodyBones.LeftLittleDistal,
                HumanBodyBones.RightLittleProximal, HumanBodyBones.RightLittleIntermediate, HumanBodyBones.RightLittleDistal),
        };

        private void Awake()
        {
            localPoseSource = GetComponent<LocalPosePacketSource>();
#if UNITY_IOS
            if (localPoseSource == null) localPoseSource = gameObject.AddComponent<IOSNativePoseSource>();
#endif
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
            // Pose wrist depth can use almost the full arm length on the camera-depth axis.
            // Older serialized values capped it at less than one shoulder width.
            maxHandDepthShoulderWidths = Mathf.Max(maxHandDepthShoulderWidths, 1.35f);
            if (trackingCamera != null) trackingCamera.nearClipPlane = Mathf.Min(trackingCamera.nearClipPlane, .03f);
            avatarRootOriginPosition = targetAnimator.transform.position;
            avatarRootOriginRotation = targetAnimator.transform.rotation;
            ConfigureAnimeInternalLines();
            solver.Initialize(targetAnimator);
            faceBlendShapeProxy = targetAnimator.GetComponentInChildren<VRMBlendShapeProxy>(true);
            manualController = targetAnimator.GetComponent<ManualAvatarController>();
            if (manualController == null)
                manualController = targetAnimator.gameObject.AddComponent<ManualAvatarController>();
            manualController.Initialize(targetAnimator, this);
            collisionGeometry.Initialize(targetAnimator);
            CacheRestHandBasis(true);
            CacheRestHandBasis(false);
            if (debugLogging) Debug.Log($"Avatar collision geometry measured: {collisionGeometry.DebugSummary}", this);
        }

        private void ConfigureAnimeInternalLines()
        {
            if (trackingCamera == null) return;
            var effect = trackingCamera.GetComponent<AnimeLinePostEffect>();
            if (!enableAnimeInternalLines)
            {
                if (effect != null) effect.enabled = false;
                return;
            }
            if (effect == null) effect = trackingCamera.gameObject.AddComponent<AnimeLinePostEffect>();
            effect.enabled = true;
            effect.Configure(animeLineThickness, animeLineThreshold, animeLineSoftness,
                animeLineStrength, animeLineColor);
        }

        private void LateUpdate()
        {
            UpdateTrackingPose();
            // Eye rotations must remain relative to the moving head. A world-space
            // rest rotation (including after tracking loss) makes the eyes counter-
            // rotate against head pitch and appear to look upward.
            if (targetAnimator == null || solver == null) return;
            RestoreNeutralEye(HumanBodyBones.LeftEye);
            RestoreNeutralEye(HumanBodyBones.RightEye);
        }

        private void RestoreNeutralEye(HumanBodyBones bone)
        {
            var eye = targetAnimator.GetBoneTransform(bone);
            if (eye != null && solver.TryGetRestLocalRotation(bone, out var rest))
                eye.localRotation = rest;
        }

        private void UpdateTrackingPose()
        {
            receivedNewPoseFrame = false;
            receivedTrackedPoseFrame = false;
            PosePacket packet = null;
#if UNITY_IOS || UNITY_ANDROID
            var hasPacket = localPoseSource != null && localPoseSource.TryTakeLatest(out packet);
#else
            var hasPacket = localPoseSource != null && localPoseSource.TryTakeLatest(out packet);
#endif
            if (hasPacket)
            {
                receivedNewPoseFrame = true;
                var reacquired = !tracking || (latestFrame >= 0 && packet.frame < latestFrame);
                if (reacquired) ResetTrackingFiltersOnly();
                latestFrame = packet.frame;
                if (packet.tracking || packet.points?.Count > 0)
                {
                    receivedTrackedPoseFrame = true;
                    pendingHorizontalExitDirection = 0;
                    horizontalExitInProgress = false;
                    horizontalExitCompleted = false;
                    pendingBottomExit = false;
                    bottomExitInProgress = false;
                    bottomExitCompleted = false;
                    lastTrackedPose = packet;
                    lastTrackingTime = Time.unscaledTime;
                    tracking = true;
                }
            }
            if (lastTrackedPose != null)
            {
                if (Time.unscaledTime - lastTrackingTime > trackingTimeout)
                {
                    if (tracking)
                    {
                        tracking = false;
                        ResetTrackingFiltersOnly();
                    }
                    if (returnToRestPose) ReturnToRest();
                }
                else if (!horizontalExitInProgress && !horizontalExitCompleted &&
                         !bottomExitInProgress && !bottomExitCompleted)
                {
                    ApplyPose(lastTrackedPose);
                }
            }

            CompleteHorizontalExitIfNeeded();
            CompleteBottomExitIfNeeded();

            if (debugLogging && Time.unscaledTime >= nextDebugLog)
            {
                Debug.Log($"Pose frame={latestFrame}, tracking={tracking}, points={validPoints}, appliedBones={appliedBones}, headTracking={headTracking}, headYaw={headYawDegrees:F1}, headPitch={headPitchDegrees:F1}, headRoll={headRollDegrees:F1}, bodyPosition={bodyPositionTracking}, offset={bodyPositionOffset}, bodyLean={bodyLeanDegrees:F1}, shoulderMode={bodyShoulderMode}, handContact={handContactTracking}, framing={cameraFramingState}", this);
                nextDebugLog = Time.unscaledTime + 1f;
            }
        }

        private void ApplyPose(PosePacket pose)
        {
            solver.RefreshMissingBones(targetAnimator);
            validPoints = pose.points?.Count ?? 0;
            appliedBones = 0;
            anatomyClampCount = 0;
            lastAnatomyClamp = string.Empty;
            armCameraClampCount = 0;
            lastArmCameraClamp = string.Empty;
            if (manualController != null && manualController.ShouldBlockTracking)
                return;
            if (!PoseInputMapper.TryReadUpperBody(pose, InputCoordinatesNeedMirror, bodyTurnMinConfidence, out var upperBody))
            {
                bodyPositionTracking = false;
                handContactTracking = false;
                currentBodyYaw = Mathf.MoveTowardsAngle(currentBodyYaw, 0f, bodyTurnSpeed * Time.deltaTime);
                var root = targetAnimator.transform;
                var target = Quaternion.AngleAxis(currentBodyYaw + avatarFacingOffsetDegrees, Vector3.up) * avatarRootOriginRotation;
                root.rotation = Quaternion.RotateTowards(root.rotation, target, bodyTurnSpeed * Time.deltaTime);
                rootRotationDelta = root.rotation * Quaternion.Inverse(avatarRootOriginRotation);
                if (returnToRestPose && !waistCoordinatesLocked) ReturnToRest();
                if (enableHead) ApplyHead(pose);
                ApplyFaceExpressions(pose);
                ApplyFaceZoom(pose, Time.unscaledDeltaTime);
                return;
            }
            var hipsVisible = upperBody.HipsTracked;
            if (!waistCoordinatesLocked && hipsVisible)
            {
                heldHipCenter = upperBody.HipCenter;
                heldHipCenterInitialized = true;
            }
            else if (waistCoordinatesLocked && heldHipCenterInitialized)
            {
                upperBody = new UpperBodyPose(
                    upperBody.LeftShoulder,
                    upperBody.RightShoulder,
                    heldHipCenter,
                    false,
                    upperBody.Forward,
                    upperBody.ImageLateral);
            }
            lastUpperBody = upperBody;
            hasLastUpperBody = true;
            bodyPositionTracking = false;
            var hasScreenBody = PoseInputMapper.TryReadScreenBody(
                pose, false, positionMinConfidence, out var screenBody);

            if (!cameraFramingReady &&
                (hasScreenBody || TryReadExtendedCameraFrameBody(pose, out screenBody)))
            {
                TryCalibrateCameraFraming(pose, screenBody, screenBody.ShoulderWidth);
            }

            if (hasScreenBody)
            {
                bodyLeanDegrees = ResolveBodyLean(screenBody);
                if (enableHipsPosition && !waistCoordinatesLocked)
                {
                    bodyPositionTracking = true;
                    var screenCenter = ResolveScreenBody(screenBody, bodyLeanDegrees, out var shoulderWidth);
                    ApplyHips(pose, screenCenter, shoulderWidth, screenBody.ShoulderMode);
                }
            }

            ApplyBodyTurn(upperBody);
            if (!waistCoordinatesLocked && enableLegs && hipsVisible)
                ApplyDirection(HumanBodyBones.Hips, upperBody.Torso, upperBody.Forward, bodyLeanDegrees * .15f);
            else if (!waistCoordinatesLocked)
                ReturnBoneToRest(HumanBodyBones.Hips);
            ApplyDirection(HumanBodyBones.Spine, upperBody.Torso, upperBody.Forward, bodyLeanDegrees * .55f);
            ApplyRestBoneRoll(HumanBodyBones.Chest, bodyLeanDegrees * .8f);
            ApplyRestBoneRoll(HumanBodyBones.UpperChest, bodyLeanDegrees);
            if (enableArms)
            {
                // Keep clavicles at their local rest pose so they inherit the chest
                // roll. Resetting their world rotation here cancelled shoulder tilt.
                ReturnBoneToParentRest(HumanBodyBones.LeftShoulder);
                ReturnBoneToParentRest(HumanBodyBones.RightShoulder);
                var faceObserved = PoseInputMapper.TryReadHeadFacing(pose, InputCoordinatesNeedMirror, headMinConfidence, out _);
                if (faceObserved) lastReliableFaceTime = Time.unscaledTime;
                // A hand aimed at the camera commonly occludes an eye or ear. Face
                // confidence must not disable otherwise valid arm and hand tracking.
                if (!TryApplyHandContact(pose, upperBody))
                {
                    ApplyCalibratedIkArm(pose, true, upperBody);
                    ApplyCalibratedIkArm(pose, false, upperBody);
                }
                if (enableFingers)
                {
                    ApplyFingers(pose, true);
                    ApplyFingers(pose, false);
                }
                else
                {
                    ReturnFingersToRest(true);
                    ReturnFingersToRest(false);
                }
            }
            if (enableLegs && !waistCoordinatesLocked)
                foreach (var chain in LegChains)
                    if (PoseInputMapper.TryGetVisible(pose, chain.from, InputCoordinatesNeedMirror, legMinConfidence, out var from) && PoseInputMapper.TryGetVisible(pose, chain.to, InputCoordinatesNeedMirror, legMinConfidence, out var to))
                        ApplyDirection(chain.bone, to - from, upperBody.Forward);
                    else
                        ReturnBoneToRest(chain.bone);
            if (enableHead) ApplyHead(pose);
            ApplyFaceExpressions(pose);
            ApplyFaceZoom(pose, Time.unscaledDeltaTime);
        }

        public void RebaseBodyTracking()
        {
            hipsInitialized = false;
            bodyPositionTracking = false;
            sourceScreenOrigin = Vector2.zero;
            filteredScreenCenter = Vector2.zero;
            stableScreenCenter = Vector2.zero;
            filteredShoulderWidth = 0f;
            stableShoulderWidth = 0f;
            faceZoomInitialized = false;
            shoulderZoomInitialized = false;
            cameraDistanceVelocity = 0f;
            if (targetAnimator != null)
                avatarHipOrigin = targetAnimator.transform.position;
        }

        public void ToggleWaistCoordinateLock()
        {
            waistCoordinatesLocked = !waistCoordinatesLocked;
            if (waistCoordinatesLocked)
            {
                if (hasLastUpperBody)
                {
                    heldHipCenter = lastUpperBody.HipCenter;
                    heldHipCenterInitialized = true;
                }
            }
            else
            {
                heldHipCenterInitialized = false;
                RebaseBodyTracking();
            }
        }

        private void ApplyDirection(HumanBodyBones bone, Vector3 direction, Vector3 upHint, float screenRoll = 0f)
        {
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            ApplyWorldDirection(bone, facingOffset * direction, facingOffset * upHint, screenRoll);
        }

        private void ApplyWorldDirection(HumanBodyBones bone, Vector3 direction, Vector3 upHint,
            float screenRoll = 0f, bool forceRollCorrection = false)
        {
            if (!solver.TrySolve(bone, direction, upHint, rootRotationDelta,
                    enableRollCorrection || forceRollCorrection, out var target)) return; // Missing optional bones are skipped.
            if (Mathf.Abs(screenRoll) > .01f) target = Quaternion.AngleAxis(screenRoll, Vector3.forward) * target;
            var trackedHandOrientation = forceRollCorrection &&
                                         (bone == HumanBodyBones.LeftHand || bone == HumanBodyBones.RightHand);
            if (enableAnatomyLimits && !trackedHandOrientation &&
                solver.TryClampHand(bone, target, rootRotationDelta, out var constrainedHand))
            {
                target = constrainedHand;
            }
            else if (enableAnatomyLimits && !trackedHandOrientation && !IsIkArmBone(bone) &&
                     solver.TryGetRestRotation(bone, out var rest))
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
                if ((bone == HumanBodyBones.LeftHand || bone == HumanBodyBones.RightHand) &&
                    TryGetAvatarPalmCenter(bone == HumanBodyBones.LeftHand, out var palmCenter))
                {
                    var localPalmDirection = Quaternion.Inverse(transform.rotation) * (palmCenter - transform.position);
                    var predictedPalmDirection = target * localPalmDirection;
                    if (predictedPalmDirection.sqrMagnitude > .000001f &&
                        Vector3.Dot(predictedPalmDirection, direction) < 0f)
                        target = Quaternion.FromToRotation(predictedPalmDirection, direction) * target;
                }
                transform.rotation = smoother.Smooth(bone, transform.rotation, target, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
                if ((bone == HumanBodyBones.LeftHand || bone == HumanBodyBones.RightHand) &&
                    TryGetAvatarPalmCenter(bone == HumanBodyBones.LeftHand, out var correctedPalmCenter))
                {
                    var actualPalmDirection = correctedPalmCenter - transform.position;
                    var correctionFrom = actualPalmDirection;
                    var correctionTo = direction;
                    if (trackingCamera != null)
                    {
                        correctionFrom = Vector3.ProjectOnPlane(correctionFrom, trackingCamera.transform.forward);
                        correctionTo = Vector3.ProjectOnPlane(correctionTo, trackingCamera.transform.forward);
                    }
                    if (correctionFrom.sqrMagnitude > .000001f && correctionTo.sqrMagnitude > .000001f &&
                        Vector3.Dot(correctionFrom, correctionTo) < 0f)
                        transform.rotation = Quaternion.FromToRotation(correctionFrom, correctionTo) * transform.rotation;
                }
                appliedBones++;
            }
        }

        private static bool IsIkArmBone(HumanBodyBones bone)
        {
            return bone == HumanBodyBones.LeftLowerArm || bone == HumanBodyBones.RightLowerArm;
        }

        private void ApplyBodyTurn(UpperBodyPose upperBody)
        {
            var root = targetAnimator.transform;
            if (enableBodyTurn)
            {
                var lateral = upperBody.Lateral;
                if (lateral.sqrMagnitude > .000001f)
                {
                    // Dynamically calculate body yaw angle directly from current 3D body orientation vector
                    var yaw = Vector3.SignedAngle(Vector3.right, lateral.normalized, Vector3.up);
                    // The shoulder line has a 180-degree directional ambiguity.
                    // Select its equivalent nearest orientation so newly visible
                    // hips cannot flip a forward-facing avatar around.
                    if (yaw > 90f) yaw -= 180f;
                    else if (yaw < -90f) yaw += 180f;
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
            if (!pose.TryGetHeadRotation(out var absoluteHeadRotation))
            {
                if (filteredHeadRotationInitialized &&
                    Time.unscaledTime - lastHeadRotationTime <= faceHoldTime)
                {
                    headTracking = true;
                    ApplyHeadRotation(HumanBodyBones.Neck, filteredHeadRotation, neckRotationWeight);
                    ApplyHeadRotation(HumanBodyBones.Head, filteredHeadRotation, 1f);
                    return;
                }
                headTracking = false;
                headYawDegrees = 0f;
                headPitchDegrees = 0f;
                headRollDegrees = 0f;
                ReturnBoneToRest(HumanBodyBones.Neck);
                ReturnBoneToRest(HumanBodyBones.Head);
                filteredHeadRotation = Quaternion.identity;
                filteredHeadRotationInitialized = false;
                return;
            }
            lastHeadRotationTime = Time.unscaledTime;
            if (mirrorHeadRotation)
            {
                // Mirror the captured orientation across the camera's vertical plane.
                // Pitch stays unchanged; yaw and roll reverse so the avatar behaves
                // like the user's reflection instead of turning away from them.
                absoluteHeadRotation = new Quaternion(
                    absoluteHeadRotation.x,
                    -absoluteHeadRotation.y,
                    -absoluteHeadRotation.z,
                    absoluteHeadRotation.w).normalized;
            }
            absoluteHeadRotation = Quaternion.Euler(headRotationOffsetEuler) * absoluteHeadRotation;
            var bodyRotation = Quaternion.AngleAxis(currentBodyYaw, Vector3.up);
            var relativeHeadRotation = Quaternion.Inverse(bodyRotation) * absoluteHeadRotation;
            if (!filteredHeadRotationInitialized)
            {
                filteredHeadRotation = relativeHeadRotation;
                filteredHeadRotationInitialized = true;
            }
            else
            {
                var blend = 1f - Mathf.Exp(-headRotationSmoothing * Time.unscaledDeltaTime);
                filteredHeadRotation = Quaternion.Slerp(filteredHeadRotation, relativeHeadRotation, blend);
            }
            var angles = filteredHeadRotation.eulerAngles;
            var pitch = Mathf.DeltaAngle(0f, angles.x);
            var yaw = Mathf.DeltaAngle(0f, angles.y);
            var roll = Mathf.DeltaAngle(0f, angles.z);
            headTracking = true;
            headYawDegrees = yaw;
            headPitchDegrees = pitch;
            headRollDegrees = roll;
            ApplyHeadRotation(HumanBodyBones.Neck, filteredHeadRotation, neckRotationWeight);
            ApplyHeadRotation(HumanBodyBones.Head, filteredHeadRotation, 1f);
        }

        private void ApplyHeadRotation(HumanBodyBones bone, Quaternion relativeRotation, float weight)
        {
            if (!solver.TryGetRestRotation(bone, out var rest)) return;
            var target = rootRotationDelta * Quaternion.SlerpUnclamped(Quaternion.identity, relativeRotation, weight) * rest;
            if (enableAnatomyLimits) target = AnatomyLimits.ClampSwing(bone, rootRotationDelta * rest, target);
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform == null) return;
            transform.rotation = target;
            appliedBones++;
        }

        private void ApplyFaceExpressions(PosePacket pose)
        {
            if (!enableFaceExpressions || faceBlendShapeProxy == null) return;
            var t = 1f - Mathf.Exp(-faceExpressionSmoothing * Time.unscaledDeltaTime);
            var blinkStep = faceExpressionSmoothing * Time.unscaledDeltaTime;
            filteredBlinkLeft = Mathf.MoveTowards(filteredBlinkLeft,
                NormalizeBlink(pose.GetFaceBlendshape("eyeBlinkLeft")), blinkStep);
            filteredBlinkRight = Mathf.MoveTowards(filteredBlinkRight,
                NormalizeBlink(pose.GetFaceBlendshape("eyeBlinkRight")), blinkStep);
            filteredJawOpen = Mathf.Lerp(filteredJawOpen, pose.GetFaceBlendshape("jawOpen"), t);
            filteredSmile = Mathf.Lerp(filteredSmile,
                (pose.GetFaceBlendshape("mouthSmileLeft") + pose.GetFaceBlendshape("mouthSmileRight")) * .5f, t);

            faceBlendShapeProxy.SetValues(new[]
            {
                new KeyValuePair<BlendShapeKey, float>(
                    BlendShapeKey.CreateFromPreset(BlendShapePreset.Blink_L), filteredBlinkLeft),
                new KeyValuePair<BlendShapeKey, float>(
                    BlendShapeKey.CreateFromPreset(BlendShapePreset.Blink_R), filteredBlinkRight),
                new KeyValuePair<BlendShapeKey, float>(
                    BlendShapeKey.CreateFromPreset(BlendShapePreset.A), filteredJawOpen * (1f - filteredSmile)),
                new KeyValuePair<BlendShapeKey, float>(
                    BlendShapeKey.CreateFromPreset(BlendShapePreset.Joy), filteredSmile),
            });
        }

        private static float NormalizeBlink(float score)
        {
            // MediaPipe commonly reports a small non-zero blink score for fully open
            // eyes and may not reach 1 when closed. Remap that observed range to the
            // complete VRM 0..1 eyelid range.
            var normalized = Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(.08f, .45f, score));
            if (normalized < .02f) return 0f;
            if (normalized > .98f) return 1f;
            return normalized;
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

        // Directly scaling MediaPipe's pose-world wrist and elbow is kept as a
        // diagnostic reference only. Pose-world is body-relative and its depth
        // becomes least reliable when a hand occludes the torso.
        private void ApplyRawTrackerArm(PosePacket pose, bool left, UpperBodyPose upperBody)
        {
            var sourceLeft = left != avatarMirror;
            var side = sourceLeft ? "left" : "right";
            var shoulder = sourceLeft ? upperBody.LeftShoulder : upperBody.RightShoulder;
            var elbowName = side + "_elbow";
            var wristName = side + "_wrist";
            var hasRawElbow = PoseInputMapper.TryGet(
                pose, elbowName, InputCoordinatesNeedMirror, .35f, out var rawElbow);
            var hasRawWrist = PoseInputMapper.TryGet(
                pose, wristName, InputCoordinatesNeedMirror, wristMinConfidence, out var rawWrist);
            var hasElbowImage = pose.TryGetImage(elbowName, .35f, out var elbowImage) &&
                                IsInsideExtendedArmImage(elbowImage, .04f);
            var hasWristImage = pose.TryGetImage(wristName, wristMinConfidence, out var wristImage) &&
                                IsInsideExtendedArmImage(wristImage, .04f);
            var shoulderWidth = Mathf.Max(upperBody.Lateral.magnitude, .05f);
            var hasHandTracker = TryReadHandEvidence(
                pose, left, hasWristImage, wristImage, rawWrist.z,
                hasRawWrist, shoulder.z, shoulderWidth,
                out _, out _);

            var upperBone = left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm;
            var lowerBone = left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm;
            var handBone = left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand;
            var upperTransform = targetAnimator.GetBoneTransform(upperBone);
            var lowerTransform = targetAnimator.GetBoneTransform(lowerBone);
            var handTransform = targetAnimator.GetBoneTransform(handBone);
            if (upperTransform == null || lowerTransform == null || handTransform == null) return;

            var avatarLeftShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var avatarRightShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            var avatarShoulderWidth = avatarLeftShoulder != null && avatarRightShoulder != null
                ? Vector3.Distance(avatarLeftShoulder.position, avatarRightShoulder.position)
                : shoulderWidth;
            var trackerScale = avatarShoulderWidth / shoulderWidth;
            var trackedWrist = shoulder + (rawWrist - shoulder) * trackerScale;
            var trackedElbow = shoulder + (rawElbow - shoulder) * trackerScale;

            var wristFilter = left ? leftWristFilter : rightWristFilter;
            var elbowFilter = left ? leftElbowFilter : rightElbowFilter;
            var hasWrist = hasRawWrist && hasWristImage && hasHandTracker;
            var hasElbow = hasRawElbow && hasElbowImage;

            // A real hand tracker keeps its last transform when only an elbow
            // observation remains. Do not manufacture a hand target from the elbow.
            if (!hasWrist && hasElbow && wristFilter.TryGetLastStable(out var heldWrist))
            {
                trackedWrist = heldWrist;
                hasWrist = true;
            }

            var hasStableWrist = wristFilter.TryGetStable(
                trackedWrist, hasWrist, avatarShoulderWidth, maxWristSpeed,
                wristHoldTime, armAcquireFrames, armPointDeadZoneScale,
                armPositionSmoothingCutoff, armMotionResponsiveness,
                pose.frame, Time.unscaledTime, out trackedWrist);
            var hasStableElbow = elbowFilter.TryGetStable(
                trackedElbow, hasElbow, avatarShoulderWidth, maxElbowSpeed,
                wristHoldTime, armAcquireFrames, armPointDeadZoneScale,
                armPositionSmoothingCutoff, armMotionResponsiveness,
                pose.frame, Time.unscaledTime, out trackedElbow);

            var relaxWeight = left ? leftArmRelaxWeight : rightArmRelaxWeight;
            relaxWeight = Mathf.MoveTowards(
                relaxWeight, hasStableWrist ? 0f : 1f,
                (hasStableWrist ? armRecoverSpeed : armRelaxSpeed) * Time.deltaTime);
            if (left) leftArmRelaxWeight = relaxWeight; else rightArmRelaxWeight = relaxWeight;
            if (!hasStableWrist)
            {
                ResetHandOrientationFilter(left);
                ApplyAvatarRelaxedArm(left);
                ReturnBoneToRest(handBone);
                return;
            }

            var upperLength = Vector3.Distance(upperTransform.position, lowerTransform.position);
            var lowerLength = Vector3.Distance(lowerTransform.position, handTransform.position);
            var previousAvailable = left ? hasLeftConstrainedArm : hasRightConstrainedArm;
            var previousArm = left ? leftConstrainedArm : rightConstrainedArm;
            var solvedArm = SolveTrackerArm(
                shoulder, trackedWrist, hasStableElbow, trackedElbow,
                upperBody, left, upperLength, lowerLength,
                previousAvailable, previousArm);

            if (left)
            {
                leftConstrainedArm = solvedArm;
                hasLeftConstrainedArm = true;
                leftArmFilterState = $"tracker6dof wrist={wristFilter.Stage}, elbow={elbowFilter.Stage}";
            }
            else
            {
                rightConstrainedArm = solvedArm;
                hasRightConstrainedArm = true;
                rightArmFilterState = $"tracker6dof wrist={wristFilter.Stage}, elbow={elbowFilter.Stage}";
            }

            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            var hasOrientation = TryGetHandOrientation(
                pose, left, facingOffset, out var handDirection, out var palmNormal);
            ApplyTwoBoneArm(
                upperBone, lowerBone, handBone, solvedArm, upperBody.Forward,
                facingOffset, hasOrientation ? palmNormal : Vector3.zero);
            if (hasOrientation)
                ApplyWorldDirection(handBone, handDirection, palmNormal, 0f, true);
        }

        private static ArmPose SolveTrackerArm(
            Vector3 shoulder, Vector3 wristTarget, bool hasElbowTracker, Vector3 elbowTracker,
            UpperBodyPose body, bool left, float upperLength, float lowerLength,
            bool hasPrevious, ArmPose previous)
        {
            var toTarget = wristTarget - shoulder;
            var direction = toTarget.sqrMagnitude > .000001f ? toTarget.normalized : Vector3.down;
            var minimumReach = Mathf.Abs(upperLength - lowerLength) + .001f;
            var maximumReach = upperLength + lowerLength - .001f;
            var distance = Mathf.Clamp(toTarget.magnitude, minimumReach, maximumReach);
            var wrist = shoulder + direction * distance;
            var along = (upperLength * upperLength - lowerLength * lowerLength +
                         distance * distance) / (2f * distance);
            var bendRadius = Mathf.Sqrt(Mathf.Max(
                upperLength * upperLength - along * along, 0f));
            var circleCenter = shoulder + direction * along;

            Vector3 pole;
            if (hasElbowTracker)
                pole = elbowTracker - circleCenter;
            else if (hasPrevious)
                pole = previous.Elbow - circleCenter;
            else
            {
                var side = body.Lateral.sqrMagnitude > .000001f
                    ? body.Lateral.normalized * (left ? 1f : -1f)
                    : (left ? Vector3.left : Vector3.right);
                var down = body.Torso.sqrMagnitude > .000001f
                    ? -body.Torso.normalized
                    : Vector3.down;
                pole = side * .35f + down;
            }
            pole = Vector3.ProjectOnPlane(pole, direction);
            if (pole.sqrMagnitude < .000001f)
                pole = Vector3.ProjectOnPlane(Vector3.down, direction);
            if (pole.sqrMagnitude < .000001f)
                pole = Vector3.ProjectOnPlane(Vector3.right, direction);
            var elbow = circleCenter + pole.normalized * bendRadius;
            return new ArmPose(shoulder, elbow, wrist);
        }

        // Treat the observed palm/wrist as the endpoint tracker, then solve the
        // avatar-length arm around it. The elbow is a soft hint: when it is
        // occluded at the chest, the anatomical pole and the previous solution
        // keep the hinge stable instead of moving the hand target.
        private void ApplyCalibratedIkArm(PosePacket pose, bool left, UpperBodyPose upperBody)
        {
            // Mirroring is a coordinate transform, not an anatomical side swap.
            // MediaPipe's left/right labels remain tied to the performer.
            var sourceLeft = left != avatarMirror;
            var shoulder = sourceLeft ? upperBody.LeftShoulder : upperBody.RightShoulder;
            var elbowName = sourceLeft ? "left_elbow" : "right_elbow";
            var wristName = sourceLeft ? "left_wrist" : "right_wrist";
            var hasRawElbow = PoseInputMapper.TryGet(pose, elbowName, InputCoordinatesNeedMirror, .35f, out var rawElbow);
            var hasRawWrist = PoseInputMapper.TryGet(pose, wristName, InputCoordinatesNeedMirror, wristMinConfidence, out var rawWrist);
            var hasElbowImage = pose.TryGetImage(elbowName, .35f, out var elbowImage);
            pose.TryGetConfidence(elbowName, out var elbowConfidence);
            var hasWristImage = pose.TryGetImage(wristName, wristMinConfidence, out var wristImage);
            var shoulderWidth = Mathf.Max(upperBody.Lateral.magnitude, .05f);
            var handDepthZ = 0f;
            var hasHandEvidence = TryReadHandEvidence(
                pose, left, hasWristImage, wristImage, hasRawWrist ? rawWrist.z : shoulder.z,
                hasRawWrist, shoulder.z, shoulderWidth,
                out wristImage, out handDepthZ);
            var palmVisible = pose.TryGetImage($"{SourceSide(left)}_hand_palm", .35f, out _);
            var palmMissingFrames = left ? leftPalmMissingFrames : rightPalmMissingFrames;
            var palmLastProcessedFrame = left ? leftPalmLastProcessedFrame : rightPalmLastProcessedFrame;
            if (pose.frame != palmLastProcessedFrame)
            {
                palmMissingFrames = palmVisible ? 0 : palmMissingFrames + 1;
                if (left) leftPalmLastProcessedFrame = pose.frame; else rightPalmLastProcessedFrame = pose.frame;
            }
            if (left) leftPalmMissingFrames = palmMissingFrames; else rightPalmMissingFrames = palmMissingFrames;
            var elbow = Vector3.zero;
            var wrist = Vector3.zero;
            var elbowImageInView = hasElbowImage && IsInsideExtendedArmImage(elbowImage, .04f);
            var elbowImageWeight = hasElbowImage ? GetImageInteriorWeight(elbowImage, .12f) : 0f;
            var hasElbow = hasRawElbow && elbowImageInView;
            if (hasElbow)
            {
                // Put every arm target in the same calibrated avatar space. A pose-world
                // elbow is only the depth hint; its image point supplies the stable X/Y.
                if (!TryMapArmImagePoint(
                        pose, left, shoulder, upperBody, elbowImage, rawElbow.z, out elbow))
                    elbow = rawElbow;
            }
            var hasWrist = hasHandEvidence && hasRawWrist &&
                           IsInsideExtendedArmImage(wristImage, .04f);
            if (hasWrist)
            {
                // handDepthZ is reconstructed from palm projection plus bounded pose
                // depth. Previously it was calculated and then discarded here, leaving
                // the arm on MediaPipe pose-world Z even though that Z visibly diverges
                // when the hand crosses the chest.
                if (!TryMapArmImagePoint(
                        pose, left, shoulder, upperBody, wristImage, handDepthZ, out wrist))
                    wrist = new Vector3(rawWrist.x, rawWrist.y, handDepthZ);
            }
            var elbowFilter = left ? leftElbowFilter : rightElbowFilter;
            var wristFilter = left ? leftWristFilter : rightWristFilter;
            if (palmMissingFrames >= 5)
            {
                hasWrist = false;
                if (palmMissingFrames == 5)
                {
                    wristFilter.Reset();
                    ResetHandOrientationFilter(left);
                    if (left) hasLeftConstrainedArm = false; else hasRightConstrainedArm = false;
                }
            }
            // When the palm is occluded but the elbow is still visible, keep the last
            // accepted wrist endpoint. Inferring a new hand from the elbow alone made the
            // hand jump across the torso even though there was no hand measurement.
            var heldWrist = Vector3.zero;
            var holdWristFromVisibleElbow = !hasWrist && hasElbow &&
                                            wristFilter.TryGetLastStable(out heldWrist);
            if (holdWristFromVisibleElbow)
            {
                wrist = heldWrist;
                hasWrist = true;
            }
            pose.TryGetConfidence($"{SourceSide(left)}_hand_palm", out var handConfidence);
            if (hasWrist && handConfidence < .65f && wristFilter.TryGetLastStable(out var previousPalm))
                wrist = Vector3.Lerp(previousPalm, wrist, Mathf.InverseLerp(.35f, .65f, handConfidence));
            var hasStableWrist = wristFilter.TryGetStable(wrist, hasWrist, shoulderWidth, maxWristSpeed,
                wristHoldTime, armAcquireFrames, armPointDeadZoneScale, armPositionSmoothingCutoff,
                armMotionResponsiveness, pose.frame, Time.unscaledTime, out wrist);
            // A raised arm is strongly foreshortened in screen space: its visible forearm can
            // appear much longer than its upper arm. Keep a confident visible elbow instead of
            // replacing it with the palm-only horizontal fallback.
            if (hasElbow && hasStableWrist && elbowConfidence < .8f &&
                !IsPlausibleElbow(shoulder, elbow, wrist, shoulderWidth))
                hasElbow = false;
            var elbowSource = hasElbow
                ? "observed"
                : hasElbowImage && !elbowImageInView ? "palm_only_elbow_out_of_view" : "palm_only_elbow";
            var hasStableElbow = elbowFilter.TryGetStable(elbow, hasElbow, shoulderWidth, maxElbowSpeed,
                wristHoldTime, armAcquireFrames, armPointDeadZoneScale, armPositionSmoothingCutoff,
                armMotionResponsiveness, pose.frame, Time.unscaledTime, out elbow);
            var useObservedElbow = hasElbow && hasStableElbow;
            var filterState = $"elbow={elbowFilter.Stage}/{elbowFilter.RejectReason}/{elbowSource}, wrist={wristFilter.Stage}/{wristFilter.RejectReason}" +
                              (holdWristFromVisibleElbow ? "/held_from_visible_elbow" : "");
            if (left) leftArmFilterState = filterState; else rightArmFilterState = filterState;
            GetRelaxedArmPose(left, upperBody, out var relaxedUpper, out var relaxedLower);
            var relaxWeight = left ? leftArmRelaxWeight : rightArmRelaxWeight;
            relaxWeight = Mathf.MoveTowards(relaxWeight, hasStableWrist ? 0f : 1f, (hasStableWrist ? armRecoverSpeed : armRelaxSpeed) * Time.deltaTime);
            if (left) leftArmRelaxWeight = relaxWeight; else rightArmRelaxWeight = relaxWeight;
            if (!hasStableWrist)
            {
                ResetHandOrientationFilter(left);
                ApplyAvatarRelaxedArm(left);
                ReturnBoneToRest(left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand);
                UpdateArmScreenDiagnostics(left, pose, left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand, false);
                return;
            }
            var trackedUpper = useObservedElbow ? elbow - shoulder : relaxedUpper;
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
            var appliedUpperDepthAxis = upperBody.Forward;
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
                // The wrist target is converted from the detected palm below, including
                // the avatar's wrist-to-palm offset. Adding that full offset to the torso
                // collision radius a second time made a hand over the torso's X range sit
                // one palm-length in front of the chest. The measured hand radius already
                // represents the mesh thickness needed to prevent penetration.
                var torsoRadii = collisionGeometry.GetTorsoRadii(sourceShoulderWidth * .5f, sourceShoulderWidth * .29f);
                var targetWrist = wrist;
                if (TryGetPalmAlignedWristTarget(
                        pose, left, shoulder, upperBody, handDepthZ, handBone, torsoRadii,
                        out var palmAlignedWrist))
                    targetWrist = palmAlignedWrist;
                var observedElbowWeight = useObservedElbow
                    ? Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(.45f, .85f, elbowConfidence)) * elbowImageWeight
                    : 0f;
                // An overhead arm naturally puts the elbow close to the frame edge. The point
                // has already passed the extended-image and anatomy checks, so edge feathering
                // must not discard its bend direction and replace it with a downward pole.
                var reliableElbow = useObservedElbow && elbowConfidence >= .35f;
                var elbowHint = reliableElbow ? elbow : Vector3.zero;
                filterState += $", observedWeight={observedElbowWeight:F2}, fallback={!reliableElbow}";
                if (left) leftArmFilterState = filterState; else rightArmFilterState = filterState;
                var arm = UpperBodyPoseSolver.SolveArm(
                    shoulder, targetWrist, elbowHint, upperBody, left, reliableElbow,
                    upperLength, lowerLength, out var solveDiagnostics);
                filterState += $", solve={solveDiagnostics}";
                if (left) leftArmFilterState = filterState; else rightArmFilterState = filterState;
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
            var handDirection = Vector3.zero;
            var palmNormal = Vector3.zero;
            var hasHandOrientation = hasStableWrist && TryGetHandOrientation(
                pose, left, facingOffset, out handDirection, out palmNormal);
            ApplyTwoBoneArm(upperBone, lowerBone, handBone, solvedArm, appliedUpperDepthAxis, facingOffset,
                hasHandOrientation ? palmNormal : Vector3.zero);
            if (hasHandOrientation)
                ApplyWorldDirection(handBone, handDirection, palmNormal, 0f, true);
            else if (holdWristFromVisibleElbow)
            {
                // Preserve the last hand rotation until palm landmarks return.
            }
            else
            {
                ResetHandOrientationFilter(left);
                ReturnBoneToRest(handBone);
            }
            UpdateArmScreenDiagnostics(left, pose, handBone, hasStableWrist);
        }

        private void ApplyTwoBoneArm(HumanBodyBones upperBone, HumanBodyBones lowerBone, HumanBodyBones handBone,
            ArmPose arm, Vector3 depthAxis, Quaternion facingOffset, Vector3 palmNormal)
        {
            var upper = targetAnimator.GetBoneTransform(upperBone);
            var lower = targetAnimator.GetBoneTransform(lowerBone);
            var hand = targetAnimator.GetBoneTransform(handBone);
            if (upper == null || lower == null || hand == null) return;
            var upperVector = arm.Elbow - arm.Shoulder;
            var lowerVector = arm.Wrist - arm.Elbow;
            var upperDirection = facingOffset * upperVector;
            var lowerDirection = facingOffset * lowerVector;
            var avatarForward = facingOffset * depthAxis.normalized;
            var requestedWristDepth = Vector3.Dot(arm.Wrist - arm.Shoulder, depthAxis.normalized);
            var rawRequestedElbowDepth = Vector3.Dot(upperVector, depthAxis.normalized);
            var upperBoneLength = Vector3.Distance(upper.position, lower.position);
            var solverUpperLength = upperVector.magnitude;
            var requestedElbowDepth = (solverUpperLength > .0001f && upperBoneLength > .0001f)
                ? rawRequestedElbowDepth * (upperBoneLength / solverUpperLength)
                : rawRequestedElbowDepth;
            var rawRequestedForearmDepth = Vector3.Dot(lowerVector, depthAxis.normalized);
            var lowerBoneLength = Vector3.Distance(lower.position, hand.position);
            var solverLowerLength = lowerVector.magnitude;
            var requestedForearmDepth = (solverLowerLength > .0001f && lowerBoneLength > .0001f)
                ? rawRequestedForearmDepth * (lowerBoneLength / solverLowerLength)
                : rawRequestedForearmDepth;
            var beforeDepth = Vector3.Dot(lower.position - upper.position, avatarForward);
            var beforeForearmDepth = Vector3.Dot(hand.position - lower.position, avatarForward);

            // Ensure 3D upper arm direction with Z-axis displacement directly drives upper arm bone rotation
            var upperCorrection = ApplyCurrentBoneDirection(upperBone, upper, lower, upperDirection.normalized);
            var upperFailure = solver.LastFailure;

            var appliedDepth = Vector3.Dot(lower.position - upper.position, avatarForward);
            var lowerCorrection = ApplyForearmDirection(
                lowerBone, handBone, lower, hand, lowerDirection, palmNormal, out var forearmTwist);
            var lowerFailure = solver.LastFailure;
            var appliedForearmDepth = Vector3.Dot(hand.position - lower.position, avatarForward);

            var beforeDepthError = Mathf.Abs(requestedElbowDepth - beforeDepth);
            var depthError = Mathf.Abs(requestedElbowDepth - appliedDepth);
            var reason = depthError <= .02f
                ? "applied"
                : Mathf.Abs(requestedElbowDepth) < .01f && Mathf.Abs(requestedWristDepth) >= .03f
                    ? "upstream_elbow_depth_zero"
                : (depthError < beforeDepthError || Mathf.Abs(appliedDepth - beforeDepth) > .01f) ? "smoothing_in_progress"
                : upperCorrection <= .01f ? $"upper_solve_not_applied/{upperFailure}"
                : "upper_rotation_overwritten_or_axis_mismatch";

            var beforeForearmDepthError = Mathf.Abs(requestedForearmDepth - beforeForearmDepth);
            var forearmDepthError = Mathf.Abs(requestedForearmDepth - appliedForearmDepth);
            var forearmReason = forearmDepthError <= .02f
                ? "applied"
                : Mathf.Abs(requestedForearmDepth) < .01f && Mathf.Abs(requestedWristDepth) >= .03f
                    ? "upstream_forearm_depth_zero"
                : (forearmDepthError < beforeForearmDepthError || Mathf.Abs(appliedForearmDepth - beforeForearmDepth) > .01f) ? "smoothing_in_progress"
                : lowerCorrection <= .01f ? $"forearm_solve_not_applied/{lowerFailure}"
                : "forearm_rotation_overwritten_or_axis_mismatch";

            var rollState = $"rest_anchored correction=({upperCorrection:F1},{lowerCorrection:F1}), forearmTwist={forearmTwist:F1}, " +
                            $"depth[wristRequest={requestedWristDepth:F3}, elbowRequest={requestedElbowDepth:F3}, forearmRequest={requestedForearmDepth:F3}, " +
                            $"before=({beforeDepth:F3},{beforeForearmDepth:F3}), after=({appliedDepth:F3},{appliedForearmDepth:F3}), error=({depthError:F3},{forearmDepthError:F3}), stage=({reason},{forearmReason})]";
            if (upperBone == HumanBodyBones.LeftUpperArm) leftArmRollState = rollState;
            else rightArmRollState = rollState;
            LogUpperArmDepthFailure(
                upperBone, requestedWristDepth, requestedElbowDepth, beforeDepth, appliedDepth, reason, upperFailure);
            LogForearmDepthFailure(
                lowerBone, requestedWristDepth, requestedForearmDepth, beforeForearmDepth, appliedForearmDepth, forearmReason, lowerFailure);
        }

        private void LogUpperArmDepthFailure(HumanBodyBones bone, float requestedWristDepth,
            float requestedElbowDepth, float beforeDepth, float appliedDepth, string reason, string failure)
        {
            return;
            if (!debugLogging || reason == "applied" || reason == "smoothing_in_progress") return;
            var left = bone == HumanBodyBones.LeftUpperArm;
            var nextLog = left ? nextLeftUpperArmDepthErrorLog : nextRightUpperArmDepthErrorLog;
            if (Time.unscaledTime < nextLog) return;
            Debug.LogError(
                $"Upper-arm depth failure: bone={bone}, stage={reason}, " +
                $"wristRequest={requestedWristDepth:F4}, elbowRequest={requestedElbowDepth:F4}, " +
                $"boneDepth={beforeDepth:F4}->{appliedDepth:F4}, solver={failure}", this);
            if (left) nextLeftUpperArmDepthErrorLog = Time.unscaledTime + 1f;
            else nextRightUpperArmDepthErrorLog = Time.unscaledTime + 1f;
        }

        private void LogForearmDepthFailure(HumanBodyBones bone, float requestedWristDepth,
            float requestedForearmDepth, float beforeDepth, float appliedDepth, string reason, string failure)
        {
            return;
            if (!debugLogging || reason == "applied" || reason == "smoothing_in_progress") return;
            var left = bone == HumanBodyBones.LeftLowerArm;
            var nextLog = left ? nextLeftForearmDepthErrorLog : nextRightForearmDepthErrorLog;
            if (Time.unscaledTime < nextLog) return;
            Debug.LogError(
                $"Forearm depth failure: bone={bone}, stage={reason}, " +
                $"wristRequest={requestedWristDepth:F4}, forearmRequest={requestedForearmDepth:F4}, " +
                $"boneDepth={beforeDepth:F4}->{appliedDepth:F4}, solver={failure}", this);
            if (left) nextLeftForearmDepthErrorLog = Time.unscaledTime + 1f;
            else nextRightForearmDepthErrorLog = Time.unscaledTime + 1f;
        }

        private float ApplyForearmDirection(HumanBodyBones lowerBone, HumanBodyBones handBone,
            Transform lower, Transform hand, Vector3 desiredDirection, Vector3 palmNormal, out float forearmTwist)
        {
            forearmTwist = 0f;
            var currentDirection = hand.position - lower.position;
            if (currentDirection.sqrMagnitude < .000001f ||
                !solver.TrySolve(lowerBone, desiredDirection, Vector3.zero, rootRotationDelta, false, out var target))
                return 0f;
            var axis = desiredDirection.normalized;
            if (palmNormal.sqrMagnitude > .000001f &&
                solver.TryGetHandBaseAxes(handBone, target, out _, out var basePalmNormal))
            {
                var baseProjected = Vector3.ProjectOnPlane(basePalmNormal, axis);
                var desiredProjected = Vector3.ProjectOnPlane(palmNormal, axis);
                if (baseProjected.sqrMagnitude > .000001f && desiredProjected.sqrMagnitude > .000001f)
                {
                    forearmTwist = Mathf.Clamp(
                        Vector3.SignedAngle(baseProjected, desiredProjected, axis),
                        -maxForearmTwistDegrees, maxForearmTwistDegrees);
                    target = Quaternion.AngleAxis(forearmTwist, axis) * target;
                }
            }
            var correction = Quaternion.Angle(lower.rotation, target);
            lower.rotation = smoother.Smooth(
                lowerBone, lower.rotation, target, armRotationSmoothingSpeed, 0f, Time.deltaTime);
            appliedBones++;
            return correction;
        }

        private bool TryGetPalmAlignedWristTarget(PosePacket pose, bool left, Vector3 shoulder, UpperBodyPose body,
            float handDepthZ, HumanBodyBones handBone, Vector2 torsoRadii, out Vector3 wristTarget)
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
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            var avatarPalmOffset = Quaternion.Inverse(facingOffset) * (palmCenter - hand.position);
            if (avatarPalmOffset.sqrMagnitude < .000001f)
                avatarPalmOffset = palmDirection.normalized * Vector3.Distance(hand.position, palmCenter);

            var chest = targetAnimator.GetBoneTransform(HumanBodyBones.Chest);
            var avatarShoulder = targetAnimator.GetBoneTransform(
                left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm);
            if (chest != null && avatarShoulder != null)
            {
                var chestCenter = shoulder + Quaternion.Inverse(facingOffset) *
                    (chest.position - avatarShoulder.position);
                var front = Quaternion.Inverse(facingOffset) * targetAnimator.transform.forward;
                if (front.sqrMagnitude < .000001f) front = Vector3.forward;
                else front.Normalize();
                var rel = palmTarget - chestCenter;
                var chestHeight = Mathf.Max(Vector3.Distance(
                    chest.position,
                    targetAnimator.GetBoneTransform(HumanBodyBones.Hips)?.position ?? chest.position), .001f);
                if (Mathf.Abs(rel.x) <= torsoRadii.x && Mathf.Abs(rel.y) <= chestHeight * .55f)
                {
                    var frontSurface = Mathf.Max(torsoRadii.y, .001f);
                    var signedDepth = Vector3.Dot(rel, front);
                    if (signedDepth < frontSurface)
                        palmTarget += front * (frontSurface - signedDepth);
                }
            }
            wristTarget = palmTarget - avatarPalmOffset;
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

        private bool TryGetHandOrientation(PosePacket pose, bool left, Quaternion facingOffset,
            out Vector3 handDirection, out Vector3 palmNormal)
        {
            var side = SourceSide(left);
            if (!PoseInputMapper.TryGet(pose, $"{side}_hand_wrist", InputCoordinatesNeedMirror, .35f, out var worldWrist) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_index_mcp", InputCoordinatesNeedMirror, .35f, out var worldIndex) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_middle_mcp", InputCoordinatesNeedMirror, .35f, out var worldMiddle) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_pinky_mcp", InputCoordinatesNeedMirror, .35f, out var worldPinky))
            {
                handDirection = default;
                palmNormal = default;
                return false;
            }
            // Build the complete hand orientation in one coordinate system.  Previously the
            // forward axis came from two screen points reconstructed at the same depth (so its
            // Z component was always zero), while the palm normal came from Hand Landmarker
            // world points.  Mixing those frames rotated an otherwise correctly tracked hand.
            if (!TryBuildHandBasis(
                    worldMiddle - worldWrist,
                    worldIndex - worldPinky,
                    out var sourceForward, out _, out var sourceNormal))
            {
                handDirection = default;
                palmNormal = default;
                return false;
            }
            handDirection = (facingOffset * sourceForward).normalized;
            palmNormal = (facingOffset * sourceNormal).normalized;
            FilterHandOrientation(left, ref handDirection, ref palmNormal);
            var cameraDot = trackingCamera != null
                ? Vector3.Dot(palmNormal, -trackingCamera.transform.forward)
                : 0f;
            var state = $"source=hand_world_basis, palmCameraDot={cameraDot:F2}, direction={handDirection:F3}, normal={palmNormal:F3}";
            if (left) leftHandOrientationState = state; else rightHandOrientationState = state;
            return true;
        }

        private void ApplyFingers(PosePacket pose, bool left)
        {
            var side = SourceSide(left);
            if (!TryGetHandBasis(pose, side, out var sourceForward, out var sourceAcross, out var sourceNormal) ||
                !TryGetAvatarHandBasis(left, out var avatarForward, out var avatarAcross, out var avatarNormal))
            {
                var lastTracked = left ? lastLeftFingerTrackingTime : lastRightFingerTrackingTime;
                if (Time.unscaledTime - lastTracked > fingerTrackingHoldTime)
                    ReturnFingersToRest(left);
                if (left) leftFingerState = "hold/missing_hand21"; else rightFingerState = "hold/missing_hand21";
                return;
            }
            if (left) lastLeftFingerTrackingTime = Time.unscaledTime;
            else lastRightFingerTrackingTime = Time.unscaledTime;
            var applied = 0;
            var curl = 0f;
            var curlCount = 0;
            foreach (var chain in FingerChains)
            {
                if (!PoseInputMapper.TryGet(pose, $"{side}_hand_{chain.start}", InputCoordinatesNeedMirror, .35f, out var start) ||
                    !PoseInputMapper.TryGet(pose, $"{side}_hand_{chain.middle}", InputCoordinatesNeedMirror, .35f, out var middle) ||
                    !PoseInputMapper.TryGet(pose, $"{side}_hand_{chain.end}", InputCoordinatesNeedMirror, .35f, out var end) ||
                    !PoseInputMapper.TryGet(pose, $"{side}_hand_{chain.tip}", InputCoordinatesNeedMirror, .35f, out var tip))
                {
                    // Keep the last reliable bend. Returning one chain to rest for a
                    // single dropped landmark creates visible popping while waving.
                    continue;
                }
                var proximal = middle - start;
                var intermediate = end - middle;
                var distal = tip - end;
                var proximalBone = left ? chain.leftProximal : chain.rightProximal;
                var intermediateBone = left ? chain.leftIntermediate : chain.rightIntermediate;
                var distalBone = left ? chain.leftDistal : chain.rightDistal;
                if (ApplyFingerDirection(proximalBone, MapHandDirection(
                        proximal, sourceForward, sourceAcross, sourceNormal,
                        avatarForward, avatarAcross, avatarNormal))) applied++;
                if (ApplyFingerDirection(intermediateBone, MapHandDirection(
                        intermediate, sourceForward, sourceAcross, sourceNormal,
                        avatarForward, avatarAcross, avatarNormal))) applied++;
                if (ApplyFingerDirection(distalBone, MapHandDirection(
                        distal, sourceForward, sourceAcross, sourceNormal,
                        avatarForward, avatarAcross, avatarNormal))) applied++;
                if (chain.start != "thumb_cmc")
                {
                    curl += Vector3.Angle(sourceForward, proximal) +
                            Vector3.Angle(proximal, intermediate) +
                            Vector3.Angle(intermediate, distal);
                    curlCount++;
                }
            }
            var failure = applied < 15 ? $", failure={solver.LastFailure}" : string.Empty;
            var state = $"source=hand21, applied={applied}/15, inputCurl={curl / Mathf.Max(curlCount, 1):F1}, " +
                        $"avatarCurl={MeasureAvatarFingerCurl(left):F1}{failure}";
            if (left) leftFingerState = state; else rightFingerState = state;
        }

        private float MeasureAvatarFingerCurl(bool left)
        {
            var total = 0f;
            var fingers = 0;
            foreach (var chain in FingerChains)
            {
                if (chain.start == "thumb_cmc") continue;
                total += MeasureFingerBoneCurl(left ? chain.leftProximal : chain.rightProximal);
                total += MeasureFingerBoneCurl(left ? chain.leftIntermediate : chain.rightIntermediate);
                total += MeasureFingerBoneCurl(left ? chain.leftDistal : chain.rightDistal);
                fingers++;
            }
            return total / Mathf.Max(fingers, 1);
        }

        private float MeasureFingerBoneCurl(HumanBodyBones bone)
        {
            var transform = targetAnimator.GetBoneTransform(bone);
            return transform != null && solver.TryGetRestLocalRotation(bone, out var rest)
                ? Quaternion.Angle(rest, transform.localRotation)
                : 0f;
        }

        private bool TryGetHandBasis(PosePacket pose, string side,
            out Vector3 forward, out Vector3 across, out Vector3 normal)
        {
            if (!PoseInputMapper.TryGet(pose, $"{side}_hand_wrist", InputCoordinatesNeedMirror, .35f, out var wrist) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_index_mcp", InputCoordinatesNeedMirror, .35f, out var index) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_middle_mcp", InputCoordinatesNeedMirror, .35f, out var middle) ||
                !PoseInputMapper.TryGet(pose, $"{side}_hand_pinky_mcp", InputCoordinatesNeedMirror, .35f, out var pinky))
            {
                forward = across = normal = default;
                return false;
            }
            return TryBuildHandBasis(middle - wrist, index - pinky, out forward, out across, out normal);
        }

        private bool TryGetAvatarHandBasis(bool left,
            out Vector3 forward, out Vector3 across, out Vector3 normal)
        {
            var hand = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand);
            if (hand == null || !(left ? leftRestHandBasisInitialized : rightRestHandBasisInitialized))
            {
                forward = across = normal = default;
                return false;
            }
            var forwardLocal = left ? leftRestHandForwardLocal : rightRestHandForwardLocal;
            var acrossLocal = left ? leftRestHandAcrossLocal : rightRestHandAcrossLocal;
            return TryBuildHandBasis(hand.TransformDirection(forwardLocal), hand.TransformDirection(acrossLocal),
                out forward, out across, out normal);
        }

        private bool CacheRestHandBasis(bool left)
        {
            var hand = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand);
            var index = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftIndexProximal : HumanBodyBones.RightIndexProximal);
            var middle = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftMiddleProximal : HumanBodyBones.RightMiddleProximal);
            var little = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftLittleProximal : HumanBodyBones.RightLittleProximal);
            if (hand == null || index == null || middle == null || little == null)
                return false;
            var forwardLocal = hand.InverseTransformDirection(middle.position - hand.position).normalized;
            var acrossLocal = hand.InverseTransformDirection(index.position - little.position).normalized;
            if (forwardLocal.sqrMagnitude < .000001f || acrossLocal.sqrMagnitude < .000001f)
                return false;
            if (left)
            {
                leftRestHandForwardLocal = forwardLocal;
                leftRestHandAcrossLocal = acrossLocal;
                leftRestHandBasisInitialized = true;
            }
            else
            {
                rightRestHandForwardLocal = forwardLocal;
                rightRestHandAcrossLocal = acrossLocal;
                rightRestHandBasisInitialized = true;
            }
            return true;
        }

        private static bool TryBuildHandBasis(Vector3 forwardHint, Vector3 acrossHint,
            out Vector3 forward, out Vector3 across, out Vector3 normal)
        {
            forward = forwardHint.normalized;
            across = Vector3.ProjectOnPlane(acrossHint, forward).normalized;
            normal = Vector3.Cross(across, forward).normalized;
            return forward.sqrMagnitude > .000001f && across.sqrMagnitude > .000001f &&
                   normal.sqrMagnitude > .000001f;
        }

        private static Vector3 MapHandDirection(Vector3 direction,
            Vector3 sourceForward, Vector3 sourceAcross, Vector3 sourceNormal,
            Vector3 avatarForward, Vector3 avatarAcross, Vector3 avatarNormal)
        {
            var normalized = direction.normalized;
            return (avatarForward * Vector3.Dot(normalized, sourceForward) +
                    avatarAcross * Vector3.Dot(normalized, sourceAcross) +
                    avatarNormal * Vector3.Dot(normalized, sourceNormal)).normalized;
        }

        private bool ApplyFingerDirection(HumanBodyBones bone, Vector3 direction)
        {
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform == null ||
                !solver.TrySolveFinger(bone, direction, AnatomyLimits.GetMaxSwingDegrees(bone), out var target))
                return false;
            transform.rotation = smoother.Smooth(
                bone, transform.rotation, target, fingerSmoothingSpeed,
                fingerRotationDeadZoneDegrees, Time.deltaTime);
            appliedBones++;
            return true;
        }

        private void FilterHandOrientation(bool left, ref Vector3 direction, ref Vector3 normal)
        {
            var initialized = left ? leftHandOrientationInitialized : rightHandOrientationInitialized;
            var filteredDirection = left ? filteredLeftHandDirection : filteredRightHandDirection;
            var filteredNormal = left ? filteredLeftPalmNormal : filteredRightPalmNormal;
            var reacquireFrames = left ? leftHandOrientationReacquireFrames : rightHandOrientationReacquireFrames;
            if (!initialized)
            {
                filteredDirection = direction;
                filteredNormal = normal;
                initialized = true;
                reacquireFrames = 0;
            }
            else
            {
                var contraryBasis = Vector3.Dot(filteredDirection, direction) < -.5f ||
                                    Vector3.Dot(filteredNormal, normal) < -.5f;
                reacquireFrames = contraryBasis ? reacquireFrames + 1 : 0;
                if (reacquireFrames >= 3)
                {
                    filteredDirection = direction;
                    filteredNormal = normal;
                    reacquireFrames = 0;
                }
                else
                {
                    if (Vector3.Dot(filteredDirection, direction) < 0f)
                    {
                        direction = -direction;
                        normal = -normal;
                    }
                    if (Vector3.Dot(filteredNormal, normal) < 0f)
                        normal = -normal;
                    var t = 1f - Mathf.Exp(-handOrientationSmoothing * Time.deltaTime);
                    filteredDirection = Vector3.Slerp(filteredDirection, direction, t).normalized;
                    filteredNormal = Vector3.Slerp(filteredNormal, normal, t);
                    filteredNormal = Vector3.ProjectOnPlane(filteredNormal, filteredDirection).normalized;
                }
            }
            direction = filteredDirection;
            normal = filteredNormal;
            if (left)
            {
                filteredLeftHandDirection = filteredDirection;
                filteredLeftPalmNormal = filteredNormal;
                leftHandOrientationInitialized = initialized;
                leftHandOrientationReacquireFrames = reacquireFrames;
            }
            else
            {
                filteredRightHandDirection = filteredDirection;
                filteredRightPalmNormal = filteredNormal;
                rightHandOrientationInitialized = initialized;
                rightHandOrientationReacquireFrames = reacquireFrames;
            }
        }

        private void ResetHandOrientationFilter(bool left)
        {
            if (left)
            {
                leftHandOrientationInitialized = false;
                leftHandOrientationReacquireFrames = 0;
            }
            else
            {
                rightHandOrientationInitialized = false;
                rightHandOrientationReacquireFrames = 0;
            }
        }

        private void ReturnFingersToRest(bool left)
        {
            foreach (var chain in FingerChains)
                ReturnFingerChainToRest(left, chain);
        }

        private void ReturnFingerChainToRest(bool left,
            (string start, string middle, string end, string tip,
                HumanBodyBones leftProximal, HumanBodyBones leftIntermediate, HumanBodyBones leftDistal,
                HumanBodyBones rightProximal, HumanBodyBones rightIntermediate, HumanBodyBones rightDistal) chain)
        {
            ReturnFingerToRest(left ? chain.leftProximal : chain.rightProximal);
            ReturnFingerToRest(left ? chain.leftIntermediate : chain.rightIntermediate);
            ReturnFingerToRest(left ? chain.leftDistal : chain.rightDistal);
        }

        private void ReturnFingerToRest(HumanBodyBones bone)
        {
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform == null || !solver.TryGetRestLocalRotation(bone, out var rest)) return;
            transform.localRotation = smoother.Smooth(
                bone, transform.localRotation, rest, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
        }

        private bool TryReadHandEvidence(PosePacket pose, bool left, bool hasPoseWrist, Vector3 poseWristImage, float wristDepthZ,
            bool hasPoseDepth, float shoulderDepthZ, float worldShoulderWidth,
            out Vector3 handWristImage, out float handDepthZ)
        {
            var side = SourceSide(left);
            const float minHandConfidence = .35f;
            var hasDetectedWrist = pose.TryGetImage($"{side}_hand_wrist", minHandConfidence, out var detectedWrist);
            var hasPalm = pose.TryGetImage($"{side}_hand_palm", minHandConfidence, out var detectedPalm);
            // Keep the arm endpoint anchored to the detected wrist.  The palm is used
            // separately by TryGetPalmAlignedWristTarget to compensate for the avatar's
            // hand-bone-to-palm offset.  Using the palm here made that compensation happen
            // twice and made forward/backward hand motion appear to pivot around the fingers.
            handWristImage = detectedWrist;
            var hasLeftShoulder = pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulder);
            var hasRightShoulder = pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulder);
            var hasShoulders = hasLeftShoulder && hasRightShoulder;
            var shoulderWidth = hasShoulders ? Vector2.Distance(leftShoulder, rightShoulder) : .2f;
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
            // The preview draws the same Hand Landmarker wrist/palm packet. Once those blue
            // landmarks exist, the hand is authoritative even when fingers are foreshortened.
            var valid = associated && hasPalm;
            var depthTracker = left ? leftHandDepthTracker : rightHandDepthTracker;
            var projectionScale = 0f;
            var handOpenness = 0f;
            var projectionState = "not_measured";
            var palmProjectionTracker = left ? leftPalmProjectionTracker : rightPalmProjectionTracker;
            var hasProjectionScale = valid &&
                                     palmProjectionTracker.TryMeasure(
                                         pose, side, minHandConfidence, out projectionScale, out handOpenness,
                                         out projectionState);
            var relativeScale = hasProjectionScale
                ? projectionScale / Mathf.Max(shoulderWidth, .001f)
                : 0f;
            if (hasProjectionScale)
            {
                handDepthZ = shoulderDepthZ + depthTracker.Update(
                    relativeScale, worldShoulderWidth, hasPoseDepth, wristDepthZ - shoulderDepthZ,
                    handDepthGain, handNeutralProjectionRatio, maxPoseDepthCorrectionShoulderWidths,
                    maxHandDepthShoulderWidths, handDepthSmoothing,
                    armPointDeadZoneScale, Time.deltaTime, out var depthState);
                handDepthZ += worldShoulderWidth * handForwardOffsetShoulderWidths;
                handDepthZ += handForwardOffsetMeters;
                depthState += $", openness={handOpenness:F2}, gestureScale=[{projectionState}]";
                if (left) leftHandDepthInputState = depthState; else rightHandDepthInputState = depthState;
            }
            else
            {
                if ((left ? leftPalmMissingFrames : rightPalmMissingFrames) >= 5)
                    depthTracker.Reset();
                handDepthZ = (hasPoseDepth ? wristDepthZ : shoulderDepthZ) +
                             worldShoulderWidth * handForwardOffsetShoulderWidths + handForwardOffsetMeters;
                var depthState = $"source={(hasPoseDepth ? "pose" : "plane")}, projectionScale=missing";
                if (left) leftHandDepthInputState = depthState; else rightHandDepthInputState = depthState;
            }
            var state = $"detectorPoints={accepted}/4, association={associationDistance:F3}, maxCluster={maxClusterDistance:F3}, limit={clusterLimit:F3}, valid={valid}";
            if (left) leftHandEvidenceState = state; else rightHandEvidenceState = state;
            return valid;
        }

        private void StabilizeStationaryWristTarget(PosePacket pose, bool left, Vector3 wristImage,
            ref Vector3 wrist)
        {
            var initialized = left ? leftResolvedWristInitialized : rightResolvedWristInitialized;
            var previousImage = left ? lastLeftHandWristImage : lastRightHandWristImage;
            var previousWrist = left ? lastLeftResolvedWrist : lastRightResolvedWrist;
            var imageDeadZone = .002f;
            if (pose.TryGetImage("left_shoulder", wristMinConfidence, out var leftShoulderImage) &&
                pose.TryGetImage("right_shoulder", wristMinConfidence, out var rightShoulderImage))
            {
                imageDeadZone = Mathf.Max(imageDeadZone,
                    Vector2.Distance(leftShoulderImage, rightShoulderImage) * .10f);
            }

            var currentImage = new Vector2(wristImage.x, wristImage.y);
            if (initialized && Vector2.Distance(previousImage, currentImage) <= imageDeadZone)
            {
                wrist = previousWrist;
                if (left) leftWristWithinDeadZone = true;
                else rightWristWithinDeadZone = true;
                return;
            }

            if (left)
            {
                leftWristWithinDeadZone = false;
                lastLeftHandWristImage = currentImage;
                lastLeftResolvedWrist = wrist;
                leftResolvedWristInitialized = true;
            }
            else
            {
                rightWristWithinDeadZone = false;
                lastRightHandWristImage = currentImage;
                lastRightResolvedWrist = wrist;
                rightResolvedWristInitialized = true;
            }
        }

        private bool IsWristWithinDeadZone(bool left)
        {
            return left ? leftWristWithinDeadZone : rightWristWithinDeadZone;
        }

        private bool IsWristOverTorso(PosePacket pose, bool left)
        {
            var side = SourceSide(left);
            if (!PoseInputMapper.TryGet(pose, "left_shoulder", InputCoordinatesNeedMirror, wristMinConfidence, out var leftShoulder) ||
                !PoseInputMapper.TryGet(pose, "right_shoulder", InputCoordinatesNeedMirror, wristMinConfidence, out var rightShoulder) ||
                !PoseInputMapper.TryGet(pose, $"{side}_wrist", InputCoordinatesNeedMirror, wristMinConfidence, out var wrist))
                return false;

            var minShoulderX = Mathf.Min(leftShoulder.x, rightShoulder.x);
            var maxShoulderX = Mathf.Max(leftShoulder.x, rightShoulder.x);
            var meanShoulderY = (leftShoulder.y + rightShoulder.y) * .5f;
            return wrist.x >= minShoulderX && wrist.x <= maxShoulderX && wrist.y <= meanShoulderY;
        }

        private sealed class PalmProjectionTracker
        {
            private readonly float[] referenceWorldLengths = new float[4];
            private int calibrationFrames;
            private bool hasLastGoodScale;
            private float lastGoodScale;

            public bool TryMeasure(PosePacket pose, string side, float minConfidence,
                out float scale, out float openness, out string state)
            {
                var segments = new[]
                {
                    ("wrist", "middle_mcp"),
                    ("index_mcp", "pinky_mcp"),
                    ("wrist", "index_mcp"),
                    ("wrist", "pinky_mcp"),
                };
                var samples = new System.Collections.Generic.List<float>(4);
                var angleRejected = 0;
                for (var index = 0; index < segments.Length; index++)
                {
                    var aName = $"{side}_hand_{segments[index].Item1}";
                    var bName = $"{side}_hand_{segments[index].Item2}";
                    if (!pose.TryGetImage(aName, minConfidence, out var imageA) ||
                        !pose.TryGetImage(bName, minConfidence, out var imageB) ||
                        !pose.TryGet(aName, minConfidence, out var worldA) ||
                        !pose.TryGet(bName, minConfidence, out var worldB)) continue;

                    var imageLength = Vector2.Distance(
                        new Vector2(imageA.x, imageA.y), new Vector2(imageB.x, imageB.y));
                    var worldVector = worldB - worldA;
                    var worldLength = worldVector.magnitude;
                    if (imageLength < .0001f || worldLength < .001f) continue;

                    if (calibrationFrames < 15)
                    {
                        referenceWorldLengths[index] = referenceWorldLengths[index] <= .001f
                            ? worldLength
                            : Mathf.Lerp(referenceWorldLengths[index], worldLength, .15f);
                    }
                    if (referenceWorldLengths[index] <= .001f) continue;

                    // Compensate the fixed physical palm length for its current projection
                    // into the camera XY plane. Current world length itself is never used as
                    // a size cue after calibration; only its direction supplies the angle.
                    var direction = worldVector / worldLength;
                    var projectionFactor = Mathf.Sqrt(
                        direction.x * direction.x + direction.y * direction.y);
                    // Nearly edge-on segments amplify tiny landmark errors into enormous
                    // depth changes, so hold the last trustworthy scale instead.
                    if (projectionFactor < .35f)
                    {
                        angleRejected++;
                        continue;
                    }
                    var projectedReferenceLength = referenceWorldLengths[index] * projectionFactor;
                    if (projectedReferenceLength < .0001f) continue;
                    var sample = imageLength / projectedReferenceLength;
                    if (!float.IsNaN(sample) && !float.IsInfinity(sample) && sample > .0001f)
                        samples.Add(sample);
                }

                if (calibrationFrames < 15 && samples.Count > 0) calibrationFrames++;
                openness = MeasureHandOpenness(pose, side, minConfidence);
                if (samples.Count >= 2)
                {
                    scale = Median(samples);
                    lastGoodScale = scale;
                    hasLastGoodScale = true;
                    state = $"angleCorrected={scale:F2}, samples={samples.Count}, " +
                            $"angleRejected={angleRejected}, calibration={calibrationFrames}/15";
                    return true;
                }

                if (hasLastGoodScale)
                {
                    scale = lastGoodScale;
                    state = $"angleHold={scale:F2}, samples={samples.Count}, angleRejected={angleRejected}";
                    return true;
                }

                scale = 0f;
                state = $"angleMissing, samples={samples.Count}, angleRejected={angleRejected}";
                return false;
            }

            public void Reset()
            {
                calibrationFrames = 0;
                hasLastGoodScale = false;
                lastGoodScale = 0f;
                for (var index = 0; index < referenceWorldLengths.Length; index++)
                    referenceWorldLengths[index] = 0f;
            }
        }

        private static float MeasureHandOpenness(PosePacket pose, string side, float minConfidence)
        {
            var opennessSamples = new System.Collections.Generic.List<float>(5);
            foreach (var finger in new[] { "thumb", "index", "middle", "ring", "pinky" })
            {
                var joints = finger == "thumb"
                    ? new[] { "wrist", "thumb_cmc", "thumb_mcp", "thumb_ip", "thumb" }
                    : new[] { "wrist", $"{finger}_mcp", $"{finger}_pip", $"{finger}_dip", finger };
                var chainLength = 0f;
                var completeChain = true;
                for (var index = 0; index < joints.Length - 1; index++)
                {
                    var from = $"{side}_hand_{joints[index]}";
                    var to = $"{side}_hand_{joints[index + 1]}";
                    if (pose.TryGet(from, minConfidence, out var fromWorld) &&
                        pose.TryGet(to, minConfidence, out var toWorld))
                        chainLength += Vector3.Distance(fromWorld, toWorld);
                    else
                        completeChain = false;
                }
                var wristName = $"{side}_hand_wrist";
                var tipName = $"{side}_hand_{finger}";
                if (completeChain && chainLength > .005f &&
                    pose.TryGet(wristName, minConfidence, out var wristWorld) &&
                    pose.TryGet(tipName, minConfidence, out var tipWorld))
                    opennessSamples.Add(Mathf.Clamp01(Vector3.Distance(wristWorld, tipWorld) / chainLength));
            }
            var rawOpenness = opennessSamples.Count > 0 ? Median(opennessSamples) : .675f;
            return Mathf.InverseLerp(.45f, .9f, rawOpenness);
        }

        private static float Median(System.Collections.Generic.List<float> samples)
        {
            samples.Sort();
            var middle = samples.Count / 2;
            return samples.Count % 2 == 0
                ? (samples[middle - 1] + samples[middle]) * .5f
                : samples[middle];
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
            var upperTransform = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm);
            var lowerTransform = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm);
            var handTransform = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand);
            var leftShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var rightShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            var avatarShoulderWidth = leftShoulder != null && rightShoulder != null
                ? Vector3.Distance(leftShoulder.position, rightShoulder.position)
                : Mathf.Max(body.Lateral.magnitude, .05f);

            var maxArmLength = (upperTransform != null && lowerTransform != null && handTransform != null)
                ? Vector3.Distance(upperTransform.position, lowerTransform.position) + Vector3.Distance(lowerTransform.position, handTransform.position) - .001f
                : avatarShoulderWidth * 1.5f;

            var sourceToAvatarScale = avatarShoulderWidth / Mathf.Max(body.Lateral.magnitude, .05f);
            var rawDepthOffset = (sourceZ - shoulder.z) * sourceToAvatarScale;

            // Compute pure 2D planar offset at shoulder camera depth to isolate X/Y from depth un-projection skew
            var worldTargetAtShoulderDepth = trackingCamera.ViewportToWorldPoint(new Vector3(targetViewport.x, targetViewport.y, shoulderViewport.z));
            var facingOffset = Quaternion.AngleAxis(avatarFacingOffsetDegrees, Vector3.up);
            var localPlanarOffset = Quaternion.Inverse(facingOffset) * (worldTargetAtShoulderDepth - shoulderTransform.position);
            var planarVec = new Vector2(localPlanarOffset.x, localPlanarOffset.y);

            // Prioritize 2D planar position (screen target) and bound 3D Z depth by remaining arm reach
            // Keep only a tiny bend margin so a visibly straight source arm can reach
            // essentially the full avatar arm length without destabilizing the IK pole.
            var maxReach = maxArmLength * .9995f;
            if (planarVec.magnitude > maxReach)
            {
                planarVec = planarVec.normalized * maxReach;
            }
            var planarDistance = planarVec.magnitude;
            var maxDepthForPlanar = Mathf.Sqrt(Mathf.Max(maxArmLength * maxArmLength - planarDistance * planarDistance, 0.001f));
            var depthOffset = Mathf.Clamp(rawDepthOffset, -maxDepthForPlanar, maxDepthForPlanar);

            // Changing Z after unprojecting X/Y at shoulder depth changes the final
            // perspective projection, so a hand constrained near the torso drifted
            // vertically on screen. Intersect the target viewport ray with the selected
            // avatar-depth plane, then take X/Y from that same 3D point.
            var avatarDepthAxis = facingOffset * Vector3.forward;
            var depthPlanePoint = shoulderTransform.position + avatarDepthAxis * depthOffset;
            var targetRay = trackingCamera.ViewportPointToRay(
                new Vector3(targetViewport.x, targetViewport.y, 0f));
            var rayPlaneDenominator = Vector3.Dot(targetRay.direction, avatarDepthAxis);
            if (Mathf.Abs(rayPlaneDenominator) > .0001f)
            {
                var rayDistance = Vector3.Dot(
                    depthPlanePoint - targetRay.origin, avatarDepthAxis) / rayPlaneDenominator;
                if (rayDistance > 0f)
                {
                    var depthAwareOffset = Quaternion.Inverse(facingOffset) *
                                           (targetRay.GetPoint(rayDistance) - shoulderTransform.position);
                    var maxPlanarAtDepth = Mathf.Sqrt(Mathf.Max(
                        maxArmLength * maxArmLength - depthOffset * depthOffset, .001f));
                    planarVec = new Vector2(depthAwareOffset.x, depthAwareOffset.y);
                    if (planarVec.magnitude > maxPlanarAtDepth)
                        planarVec = planarVec.normalized * maxPlanarAtDepth;
                }
            }

            point = shoulder + new Vector3(planarVec.x, planarVec.y, depthOffset);
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
            var sourceShoulderName = SourceSide(left) + "_shoulder";
            if (!pose.TryGetImage(sourceShoulderName, wristMinConfidence, out var sourceShoulderImage))
            {
                targetViewport = default;
                return false;
            }
            var leftShoulderViewport = trackingCamera.WorldToViewportPoint(leftShoulder.position);
            var rightShoulderViewport = trackingCamera.WorldToViewportPoint(rightShoulder.position);
            var avatarShoulderWidth = Vector2.Distance(leftShoulderViewport, rightShoulderViewport);
            var sourceShoulderWidth = Vector2.Distance(leftShoulderImage, rightShoulderImage);
            var sourcePoint = ToPreviewViewport(imagePoint);
            var sourceShoulder = ToPreviewViewport(sourceShoulderImage);
            var viewportScale = avatarShoulderWidth / Mathf.Max(sourceShoulderWidth, .03f);
            // ToPreviewViewport already mirrors camera X. SourceSide handles which physical
            // hand drives the facing avatar, so applying avatarMirror here would invert motion twice.
            var dx = sourcePoint.x - sourceShoulder.x;
            var dy = sourcePoint.y - sourceShoulder.y;
            var offset = new Vector2(dx * handHorizontalGain, dy * armVerticalGain) * viewportScale;
            targetViewport = new Vector3(
                shoulderViewport.x + offset.x,
                shoulderViewport.y + offset.y,
                shoulderViewport.z);
            return shoulderViewport.z > 0f && targetViewport.z > 0f;
        }

        private Vector2 ToPreviewViewport(Vector3 image)
        {
            return new Vector2(1f - image.x, 1f - image.y);
        }

        private static bool IsInsideExtendedArmImage(Vector3 image, float margin)
        {
            return image.x >= -margin && image.x <= 1f + margin && image.y >= -margin && image.y <= 1f + margin;
        }

        private static float GetImageInteriorWeight(Vector3 image, float feather)
        {
            var edgeDistance = Mathf.Min(image.x, 1f - image.x, image.y, 1f - image.y);
            return Mathf.SmoothStep(0f, 1f, Mathf.Clamp01(edgeDistance / Mathf.Max(feather, .001f)));
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
                var shoulderBone = targetAnimator.GetBoneTransform(left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm);
                var spine = targetAnimator.GetBoneTransform(HumanBodyBones.Spine);
                var hasSourceWrist = pose.TryGetImage($"{SourceSide(left)}_hand_wrist", .35f, out var sourceWrist);
                var midpoint = hand != null && forearm != null ? (hand.position + forearm.position) * .5f : Vector3.zero;
                var shoulderViewport = shoulderBone != null ? trackingCamera.WorldToViewportPoint(shoulderBone.position) : Vector3.zero;
                var elbowViewport = forearm != null ? trackingCamera.WorldToViewportPoint(forearm.position) : Vector3.zero;
                var spineViewport = spine != null ? trackingCamera.WorldToViewportPoint(spine.position) : Vector3.zero;
                var wristViewport = hand != null ? trackingCamera.WorldToViewportPoint(hand.position) : Vector3.zero;
                var side = SourceSide(left);
                var hasSourceShoulder = pose.TryGetImage($"{side}_shoulder", wristMinConfidence, out var sourceShoulder);
                var hasSourceElbow = pose.TryGetImage($"{side}_elbow", .35f, out var sourceElbow);
                var sourceUpperDirection = hasSourceShoulder && hasSourceElbow
                    ? ToPreviewViewport(sourceElbow) - ToPreviewViewport(sourceShoulder)
                    : Vector2.zero;
                var actualUpperDirection = new Vector2(
                    elbowViewport.x - shoulderViewport.x, elbowViewport.y - shoulderViewport.y);
                var sourceUpperElevation = Mathf.Atan2(
                    sourceUpperDirection.y, Mathf.Abs(sourceUpperDirection.x)) * Mathf.Rad2Deg;
                var actualUpperElevation = Mathf.Atan2(
                    actualUpperDirection.y, Mathf.Abs(actualUpperDirection.x)) * Mathf.Rad2Deg;
                var sourcePalmDirection = hasSourceWrist
                    ? ToPreviewViewport(source) - ToPreviewViewport(sourceWrist)
                    : Vector2.zero;
                var actualPalmDirection = new Vector2(actual.x - wristViewport.x, actual.y - wristViewport.y);
                var palmDirectionDot = sourcePalmDirection.sqrMagnitude > .000001f && actualPalmDirection.sqrMagnitude > .000001f
                    ? Vector2.Dot(sourcePalmDirection.normalized, actualPalmDirection.normalized)
                    : 0f;
                var elbowDelta = elbowViewport.y - shoulderViewport.y;
                state = $"stage=palm_locked, source={palmName}, target={target:F3}, actual=({actual.x:F3}, {actual.y:F3}), " +
                        $"error={error:F4}, shoulderViewport=({shoulderViewport.x:F3}, {shoulderViewport.y:F3}), " +
                        $"elbowViewport=({elbowViewport.x:F3}, {elbowViewport.y:F3}), elbowViewportDeltaY={elbowDelta:F4}, " +
                        $"elbowBelowShoulder={elbowDelta < -.01f}, spineViewportY={spineViewport.y:F3}, " +
                        $"elbowBelowSpine={spine != null && elbowViewport.y < spineViewport.y}, " +
                        $"targetPalmAboveElbow={target.y > elbowViewport.y}, avatarPalmAboveElbow={actual.y > elbowViewport.y}, " +
                        $"upperElevation=({sourceUpperElevation:F1}->{actualUpperElevation:F1}), " +
                        $"sourcePalmDirection={sourcePalmDirection:F3}, actualPalmDirection={actualPalmDirection:F3}, " +
                        $"palmDirectionDot={palmDirectionDot:F3}, forearmMid={midpoint:F3}";
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
            var leftShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var rightShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            var depthReferenceWidth = leftShoulder != null && rightShoulder != null
                ? Vector3.Distance(leftShoulder.position, rightShoulder.position)
                : worldShoulderWidth;
            var maxDepth = depthReferenceWidth * maxHandDepthShoulderWidths;
            var resolvedWristDepth = Mathf.Clamp(rawDepth, -maxDepth, maxDepth);
            wrist.z = shoulder.z + resolvedWristDepth;
            var resolvedElbowDepth = 0f;
            if (elbowObserved)
            {
                var observedElbowDepth = elbow.z - shoulder.z;
                var chainDepth = resolvedWristDepth * .45f;
                resolvedElbowDepth = Mathf.Clamp(
                    Mathf.Lerp(chainDepth, observedElbowDepth, depthEvidence),
                    -maxDepth * .8f, maxDepth * .8f);
                elbow.z = shoulder.z + resolvedElbowDepth;
            }

            var inputState = left ? leftHandDepthInputState : rightHandDepthInputState;
            var state = $"pathRatio={pathRatio:F2}, evidence={depthEvidence:F2}, wristZ={rawDepth:F3}->{resolvedWristDepth:F3}, " +
                        $"elbowZ={resolvedElbowDepth:F3}, depthLocked=False, input=[{inputState}]";
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

        private static Vector3 InferElbow(Vector3 shoulder, Vector3 wrist, UpperBodyPose body, bool left,
            float upperLength, float lowerLength)
        {
            var chord = wrist - shoulder;
            var distance = Mathf.Clamp(chord.magnitude, Mathf.Abs(upperLength - lowerLength) + .001f, upperLength + lowerLength - .001f);
            var direction = chord / distance;
            if (direction.sqrMagnitude < .000001f) direction = Vector3.down;
            else direction.Normalize();
            var along = (upperLength * upperLength - lowerLength * lowerLength + distance * distance) / (2f * distance);
            var bendHeight = Mathf.Sqrt(Mathf.Max(upperLength * upperLength - along * along, 0f));
            var lateral = body.Lateral.sqrMagnitude > .000001f ? body.Lateral.normalized : Vector3.right;
            var bodyDown = body.Torso.sqrMagnitude > .000001f ? -body.Torso.normalized : Vector3.down;
            var pole = Vector3.ProjectOnPlane(
                lateral * (left ? 1f : -1f) + body.Forward * .2f + bodyDown * .55f, direction);
            if (pole.sqrMagnitude < .0001f)
                pole = Vector3.ProjectOnPlane(body.Forward, direction);
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
            if (!PoseInputMapper.TryGetVisible(pose, "left_elbow", InputCoordinatesNeedMirror, wristMinConfidence, out var leftElbow) ||
                !PoseInputMapper.TryGetVisible(pose, "right_elbow", InputCoordinatesNeedMirror, wristMinConfidence, out var rightElbow) ||
                !PoseInputMapper.TryGetVisible(pose, "left_wrist", InputCoordinatesNeedMirror, wristMinConfidence, out var leftWrist) ||
                !PoseInputMapper.TryGetVisible(pose, "right_wrist", InputCoordinatesNeedMirror, wristMinConfidence, out var rightWrist)) return false;

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
            return PoseInputMapper.TryGet(pose, name, InputCoordinatesNeedMirror, out position);
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
                // The hip anchor is estimated from shoulder width when hips leave the
                // frame. Using it here turns a pure approach into downward motion.
                return body.ShoulderCenter;
            }

            shoulderWidth = body.ShoulderWidth > .001f ? body.ShoulderWidth : hipsInitialized ? sourceShoulderWidthOrigin : .45f;
            var center = body.ShoulderWidth > .001f ? body.ShoulderCenter : body.Anchor;
            if (body.ShoulderWidth <= .001f)
                center.x += body.ShoulderMode < 0 ? shoulderScreenDirection * shoulderWidth * .5f : -shoulderScreenDirection * shoulderWidth * .5f;
            return center;
        }

        private bool TryReadExtendedCameraFrameBody(PosePacket pose, out ScreenBodyPose body)
        {
            if (!pose.TryGetImage("left_shoulder", positionMinConfidence, out var left) ||
                !pose.TryGetImage("right_shoulder", positionMinConfidence, out var right) ||
                left.x < -.2f || left.x > 1.2f || right.x < -.2f || right.x > 1.2f ||
                left.y < -.2f || left.y > 1.4f || right.y < -.2f || right.y > 1.4f)
            {
                body = default;
                return false;
            }
            left.y = -left.y;
            right.y = -right.y;
            var lateral = right - left;
            var width = Mathf.Abs(lateral.x);
            if (width < .05f || width > .95f)
            {
                body = default;
                return false;
            }
            var center = (left + right) * .5f;
            var lean = Mathf.Atan2(lateral.y, lateral.x) * Mathf.Rad2Deg;
            body = new ScreenBodyPose(center, center, width, lean, 0, Mathf.Sign(lateral.x));
            return true;
        }

        private void TryCalibrateCameraFraming(PosePacket pose, ScreenBodyPose body, float shoulderWidth)
        {
            if (!autoFrameCamera || cameraFramingReady || trackingCamera == null || shoulderWidth <= .001f) return;
            var shoulderViewportY = 1f + body.ShoulderCenter.y;
            var hasHeadTop = TryEstimateSourceHeadTopViewportY(pose, out var headTopViewportY);
            if (!hasHeadTop)
                headTopViewportY = shoulderViewportY + Mathf.Max(shoulderWidth * 1.1f, .25f);
            if (cameraCalibrationStarted < 0f)
            {
                cameraCalibrationStarted = Time.unscaledTime;
                cameraCalibrationCenter = body.ShoulderCenter;
                cameraCalibrationWidth = shoulderWidth;
                cameraCalibrationHeadTopY = headTopViewportY;
                cameraFramingState = "calibrating_visible_range";
                return;
            }
            var sampleT = 1f - Mathf.Exp(-5f * Time.deltaTime);
            cameraCalibrationCenter = Vector2.Lerp(cameraCalibrationCenter, body.ShoulderCenter, sampleT);
            cameraCalibrationWidth = Mathf.Lerp(cameraCalibrationWidth, shoulderWidth, sampleT);
            cameraCalibrationHeadTopY = Mathf.Lerp(cameraCalibrationHeadTopY, headTopViewportY, sampleT);
            if (Time.unscaledTime - cameraCalibrationStarted < cameraCalibrationSeconds) return;

            var left = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var right = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (left == null || right == null) return;
            var avatarShoulderCenter = (left.position + right.position) * .5f;
            var avatarShoulderWidth = Vector3.Distance(left.position, right.position);
            var usableWidth = Mathf.Max(cameraCalibrationWidth * (1f - cameraFramingMargin), .03f);
            var verticalTan = Mathf.Tan(trackingCamera.fieldOfView * .5f * Mathf.Deg2Rad);
            var horizontalTan = verticalTan * trackingCamera.aspect;
            var distanceFromWidth = avatarShoulderWidth / (2f * usableWidth * horizontalTan);
            var sourceShoulderY = 1f + cameraCalibrationCenter.y;
            var sourceVerticalSpan = Mathf.Max(cameraCalibrationHeadTopY - sourceShoulderY, .12f);
            var avatarTop = FindAvatarVisualTop(avatarShoulderCenter);
            var avatarVerticalSpan = Mathf.Max(
                Vector3.Dot(avatarTop - avatarShoulderCenter, trackingCamera.transform.up), .05f);
            var usableVerticalSpan = Mathf.Max(sourceVerticalSpan * (1f - cameraFramingMargin), .08f);
            var distanceFromHeight = avatarVerticalSpan / (2f * usableVerticalSpan * verticalTan);
            var distance = Mathf.Max(distanceFromWidth, distanceFromHeight, cameraMinimumDistance);
            var halfHeight = distance * verticalTan;
            var halfWidth = distance * horizontalTan;
            var sourceFrameCenter = new Vector2(
                cameraCalibrationCenter.x, (sourceShoulderY + cameraCalibrationHeadTopY) * .5f);
            var avatarFrameCenter = (avatarShoulderCenter + avatarTop) * .5f;
            var viewportOffset = trackingCamera.transform.right * ((sourceFrameCenter.x - .5f) * 2f * halfWidth) +
                                 trackingCamera.transform.up * ((sourceFrameCenter.y - .5f) * 2f * halfHeight);
            var cameraCenter = avatarFrameCenter - viewportOffset;
            trackingCamera.transform.position = cameraCenter - trackingCamera.transform.forward * distance;
            screenHorizontalRange = halfWidth * 2f;
            screenVerticalRange = halfHeight * 2f;
            cameraFramingReady = true;
            cameraFramingState =
                $"visible=head_to_shoulders, sourceY=({sourceShoulderY:F2}->{cameraCalibrationHeadTopY:F2}), " +
                $"sourceSpan={sourceVerticalSpan:F2}, distance=({distanceFromWidth:F2},{distanceFromHeight:F2})->{distance:F2}";
        }

        private bool TryEstimateSourceHeadTopViewportY(PosePacket pose, out float headTopViewportY)
        {
            var hasLeftEye = pose.TryGetImage("left_eye", .5f, out var leftEye);
            var hasRightEye = pose.TryGetImage("right_eye", .5f, out var rightEye);
            var hasLeftEar = pose.TryGetImage("left_ear", .5f, out var leftEar);
            var hasRightEar = pose.TryGetImage("right_ear", .5f, out var rightEar);
            if (!hasLeftEye && !hasRightEye && !pose.TryGetImage("nose", .5f, out var nose))
            {
                headTopViewportY = 0f;
                return false;
            }
            var minImageY = pose.TryGetImage("nose", .5f, out nose) ? nose.y : 1f;
            if (hasLeftEye) minImageY = Mathf.Min(minImageY, leftEye.y);
            if (hasRightEye) minImageY = Mathf.Min(minImageY, rightEye.y);
            if (hasLeftEar) minImageY = Mathf.Min(minImageY, leftEar.y);
            if (hasRightEar) minImageY = Mathf.Min(minImageY, rightEar.y);
            var faceWidth = hasLeftEar && hasRightEar
                ? Vector2.Distance(leftEar, rightEar)
                : hasLeftEye && hasRightEye
                    ? Vector2.Distance(leftEye, rightEye) * 1.8f
                    : .1f;
            var headTopImageY = minImageY - Mathf.Clamp(faceWidth * .55f, .035f, .18f);
            headTopViewportY = Mathf.Clamp(1f - headTopImageY, -.15f, 1.15f);
            return true;
        }

        private Vector3 FindAvatarVisualTop(Vector3 shoulderCenter)
        {
            var up = trackingCamera.transform.up;
            var topDistance = .05f;
            foreach (var renderer in targetAnimator.GetComponentsInChildren<Renderer>(true))
            {
                if (!renderer.enabled) continue;
                var bounds = renderer.bounds;
                var candidate = bounds.center + up * Vector3.Dot(bounds.extents, Abs(up));
                topDistance = Mathf.Max(topDistance, Vector3.Dot(candidate - shoulderCenter, up));
            }
            return shoulderCenter + up * topDistance;
        }

        private static Vector3 Abs(Vector3 value) =>
            new(Mathf.Abs(value.x), Mathf.Abs(value.y), Mathf.Abs(value.z));

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
            if (mirrorShoulderElevation) targetLean = -targetLean;
            lastBodyShoulderMode = body.ShoulderMode;
            var t = 1f - Mathf.Exp(-bodyLeanSmoothing * Time.deltaTime);
            filteredBodyLean = Mathf.LerpAngle(filteredBodyLean, Mathf.Clamp(targetLean, -maxBodyLean, maxBodyLean), t);
            var delta = Mathf.DeltaAngle(stableBodyLean, filteredBodyLean);
            if (Mathf.Abs(delta) > bodyLeanDeadZone)
                stableBodyLean += Mathf.Sign(delta) * (Mathf.Abs(delta) - bodyLeanDeadZone);
            return Mathf.Clamp(stableBodyLean, -maxBodyLean, maxBodyLean);
        }

        private void ApplyHips(PosePacket pose, Vector2 screenCenter, float sourceShoulderWidth, int shoulderMode)
        {
            var root = targetAnimator.transform;
            if (root == null || trackingCamera == null) return;
            if (!hipsInitialized)
            {
                sourceScreenOrigin = screenCenter;
                filteredScreenCenter = screenCenter;
                stableScreenCenter = screenCenter;
                if (sourceShoulderWidth > .001f)
                {
                    sourceShoulderWidthOrigin = sourceShoulderWidth;
                    filteredShoulderWidth = sourceShoulderWidthOrigin;
                    stableShoulderWidth = sourceShoulderWidthOrigin;
                }
                avatarHipOrigin = root.position;
                sourceCameraDistanceOrigin = trackingCamera != null
                    ? Mathf.Max(Vector3.Dot(avatarHipOrigin - trackingCamera.transform.position, trackingCamera.transform.forward), cameraMinimumDistance)
                    : Mathf.Max(bodyDepthFromShoulderWidth, cameraMinimumDistance);
                hipsInitialized = true;
            }

            var measurementT = 1f - Mathf.Exp(-positionMeasurementSmoothing * Time.deltaTime);
            filteredScreenCenter = Vector2.Lerp(filteredScreenCenter, screenCenter, measurementT);
            stableScreenCenter.x = FollowOutsideDeadZone(stableScreenCenter.x, filteredScreenCenter.x, horizontalPositionDeadZone);
            stableScreenCenter.y = FollowOutsideDeadZone(stableScreenCenter.y, filteredScreenCenter.y, verticalPositionDeadZone);
            if (shoulderMode != 2 && sourceShoulderWidth > .001f)
            {
                filteredShoulderWidth = Mathf.Lerp(filteredShoulderWidth, sourceShoulderWidth, measurementT);
                stableShoulderWidth = FollowOutsideDeadZone(stableShoulderWidth, filteredShoulderWidth, (sourceShoulderWidthOrigin > 0f ? sourceShoulderWidthOrigin : .45f) * depthPositionDeadZone);
            }

            var sourceViewport = SourceImageToViewport(
                new Vector2(stableScreenCenter.x, -stableScreenCenter.y),
                pose.source_width, pose.source_height);
            UpdateHorizontalExitEvidence(sourceViewport);
            sourceViewport.y += avatarViewportVerticalOffset;
            var lockedPlacement = manualController != null && manualController.PlacementLocked;
            var leftAnchor = targetAnimator.GetBoneTransform(
                shoulderMode == 2 ? HumanBodyBones.LeftEye : HumanBodyBones.LeftUpperArm);
            var rightAnchor = targetAnimator.GetBoneTransform(
                shoulderMode == 2 ? HumanBodyBones.RightEye : HumanBodyBones.RightUpperArm);
            if (leftAnchor == null || rightAnchor == null) return;

            var avatarAnchor = (leftAnchor.position + rightAnchor.position) * .5f;
            var depth = Vector3.Dot(
                avatarAnchor - trackingCamera.transform.position,
                trackingCamera.transform.forward);
            if (depth <= .05f) return;

            var desiredAnchor = trackingCamera.ViewportToWorldPoint(
                new Vector3(sourceViewport.x, sourceViewport.y, depth));
            Vector3 correction;
            Vector3 target;
            if (lockedPlacement)
            {
                // Keep the recorded XYZ point as the origin and add only the user's
                // movement relative to the camera frame captured when Ctrl+9 was pressed.
                var originViewport = SourceImageToViewport(
                    new Vector2(sourceScreenOrigin.x, -sourceScreenOrigin.y),
                    pose.source_width, pose.source_height);
                originViewport.y += avatarViewportVerticalOffset;
                var originAnchor = trackingCamera.ViewportToWorldPoint(
                    new Vector3(originViewport.x, originViewport.y, depth));
                correction = desiredAnchor - originAnchor;
                target = avatarHipOrigin + manualController.PlacementOffset +
                         correction * hipsPositionScale;
            }
            else
            {
                correction = desiredAnchor - avatarAnchor;
                target = root.position + correction * hipsPositionScale;
            }
            var cameraRight = trackingCamera.transform.right;
            var cameraUp = trackingCamera.transform.up;
            bodyPositionOffset =
                cameraRight * Vector3.Dot(correction, cameraRight) +
                cameraUp * Vector3.Dot(correction, cameraUp);

            var t = 1f - Mathf.Exp(-positionFollowSpeed * Time.deltaTime);
            var maxStep = maxHipsSpeed > 0f ? maxHipsSpeed * Time.deltaTime : float.PositiveInfinity;
            root.position = Vector3.MoveTowards(root.position, Vector3.Lerp(root.position, target, t), maxStep);
        }

        private Vector2 SourceImageToViewport(Vector2 imagePoint, int sourceWidth, int sourceHeight)
        {
            // Python already removes the square inference letterbox and reports
            // coordinates normalized to the original camera image. Map 0..1 directly
            // to Unity so the camera and game-view edges line up.
            // The native iOS sample buffer and background layer are already mirrored
            // together for the front camera. A second X flip separates the avatar
            // from the person it should cover.
#if UNITY_IOS && !UNITY_EDITOR
            var x = imagePoint.x;
#else
            var x = 1f - imagePoint.x;
#endif
            var y = 1f - imagePoint.y;
            return new Vector2(x, y);
        }

        private void CompleteHorizontalExitIfNeeded()
        {
            if (!finishHorizontalExitOnTrackingLost || targetAnimator == null || trackingCamera == null ||
                horizontalExitCompleted || bottomExitInProgress || bottomExitCompleted ||
                !TryGetAvatarViewportBounds(out var minimumX, out var maximumX, out _, out _, out var depth))
                return;

            if (!horizontalExitInProgress)
            {
                if (pendingHorizontalExitDirection == 0 ||
                    Time.unscaledTime - lastTrackingTime <= horizontalExitLostDelay) return;
                var leftShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
                var rightShoulder = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
                if (leftShoulder == null || rightShoulder == null) return;
                var shoulderViewport = trackingCamera.WorldToViewportPoint((leftShoulder.position + rightShoulder.position) * .5f);
                var crossesExpectedEdge = pendingHorizontalExitDirection > 0
                    ? shoulderViewport.x >= horizontalExitEdgeThreshold && minimumX < 1f && maximumX > 1f
                    : shoulderViewport.x <= 1f - horizontalExitEdgeThreshold && minimumX < 0f && maximumX > 0f;
                if (!crossesExpectedEdge) return;
                horizontalExitDirection = pendingHorizontalExitDirection;
                horizontalExitInProgress = true;
            }

            var remainingShift = horizontalExitDirection > 0
                ? 1f + horizontalExitMargin - minimumX
                : -horizontalExitMargin - maximumX;
            if ((horizontalExitDirection > 0 && remainingShift <= 0f) ||
                (horizontalExitDirection < 0 && remainingShift >= 0f))
            {
                horizontalExitInProgress = false;
                horizontalExitCompleted = true;
                return;
            }
            var maximumStep = horizontalExitViewportSpeed * Time.unscaledDeltaTime;
            var viewportShift = Mathf.Sign(remainingShift) * Mathf.Min(Mathf.Abs(remainingShift), maximumStep);

            var center = trackingCamera.WorldToViewportPoint(targetAnimator.transform.position);
            center.z = depth;
            var shifted = center;
            shifted.x += viewportShift;
            targetAnimator.transform.position +=
                trackingCamera.ViewportToWorldPoint(shifted) - trackingCamera.ViewportToWorldPoint(center);
        }

        private void CompleteBottomExitIfNeeded()
        {
            if (!finishBottomExitOnTrackingLost || targetAnimator == null || trackingCamera == null ||
                bottomExitCompleted || horizontalExitInProgress || horizontalExitCompleted ||
                !TryGetAvatarViewportBounds(out _, out _, out var minimumY, out var maximumY, out var depth))
                return;

            if (!bottomExitInProgress)
            {
                var fallbackToBottom = pendingHorizontalExitDirection == 0;
                if (!pendingBottomExit && !fallbackToBottom) return;
                var requiredDelay = pendingBottomExit ? horizontalExitLostDelay : bottomFallbackLostDelay;
                if (Time.unscaledTime - lastTrackingTime <= requiredDelay) return;
                // With no left/right exit evidence, losing every landmark means the
                // avatar leaves through the bottom. Start from any still-visible pose.
                if (maximumY <= 0f || minimumY >= 1f) return;
                bottomExitInProgress = true;
            }

            var remainingShift = -horizontalExitMargin - maximumY;
            if (remainingShift >= 0f)
            {
                bottomExitInProgress = false;
                bottomExitCompleted = true;
                return;
            }
            var viewportShift = -Mathf.Min(Mathf.Abs(remainingShift), bottomExitViewportSpeed * Time.unscaledDeltaTime);
            var center = trackingCamera.WorldToViewportPoint(targetAnimator.transform.position);
            center.z = depth;
            var shifted = center;
            shifted.y += viewportShift;
            targetAnimator.transform.position +=
                trackingCamera.ViewportToWorldPoint(shifted) - trackingCamera.ViewportToWorldPoint(center);
        }

        private void UpdateHorizontalExitEvidence(Vector2 viewport)
        {
            if (!receivedTrackedPoseFrame) return;
            var now = Time.unscaledTime;
            if (previousFramingViewportTime > float.NegativeInfinity)
            {
                var deltaTime = now - previousFramingViewportTime;
                if (deltaTime > .001f && deltaTime < .5f)
                {
                    var measuredVelocity = (viewport.x - previousFramingViewport.x) / deltaTime;
                    var measuredVerticalVelocity = (viewport.y - previousFramingViewport.y) / deltaTime;
                    var blend = 1f - Mathf.Exp(-12f * deltaTime);
                    horizontalFramingVelocity = Mathf.Lerp(horizontalFramingVelocity, measuredVelocity, blend);
                    verticalFramingVelocity = Mathf.Lerp(verticalFramingVelocity, measuredVerticalVelocity, blend);
                }
                else if (deltaTime >= .5f)
                {
                    horizontalFramingVelocity = 0f;
                    verticalFramingVelocity = 0f;
                }
            }
            previousFramingViewport = viewport;
            previousFramingViewportTime = now;

            pendingHorizontalExitDirection =
                viewport.x >= horizontalExitEdgeThreshold && horizontalFramingVelocity >= horizontalExitMinimumSpeed ? 1 :
                viewport.x <= 1f - horizontalExitEdgeThreshold && horizontalFramingVelocity <= -horizontalExitMinimumSpeed ? -1 : 0;
            pendingBottomExit = viewport.y <= bottomExitEdgeThreshold && verticalFramingVelocity <= -bottomExitMinimumSpeed;
        }

        private bool TryGetAvatarViewportBounds(
            out float minimumX, out float maximumX, out float minimumY, out float maximumY, out float depth)
        {
            minimumX = float.PositiveInfinity;
            maximumX = float.NegativeInfinity;
            minimumY = float.PositiveInfinity;
            maximumY = float.NegativeInfinity;
            depth = 0f;
            var found = false;
            foreach (var renderer in targetAnimator.GetComponentsInChildren<Renderer>(true))
            {
                if (!renderer.enabled) continue;
                var bounds = renderer.bounds;
                for (var x = -1; x <= 1; x += 2)
                for (var y = -1; y <= 1; y += 2)
                for (var z = -1; z <= 1; z += 2)
                {
                    var corner = bounds.center + Vector3.Scale(bounds.extents, new Vector3(x, y, z));
                    var viewport = trackingCamera.WorldToViewportPoint(corner);
                    if (viewport.z <= 0f) continue;
                    minimumX = Mathf.Min(minimumX, viewport.x);
                    maximumX = Mathf.Max(maximumX, viewport.x);
                    minimumY = Mathf.Min(minimumY, viewport.y);
                    maximumY = Mathf.Max(maximumY, viewport.y);
                    depth = Mathf.Max(depth, viewport.z);
                    found = true;
                }
            }
            return found;
        }

        private bool TryReadSourceFace(PosePacket pose, out Vector2 faceCenter, out float faceWidth)
        {
            faceCenter = default;
            faceWidth = 0f;

            if (!pose.TryGetImage("left_eye", 0.55f, out var leftEye) ||
                !pose.TryGetImage("right_eye", 0.55f, out var rightEye))
            {
                return false;
            }

            var left = new Vector2(leftEye.x, 1f - leftEye.y);
            var right = new Vector2(rightEye.x, 1f - rightEye.y);

            faceCenter = (left + right) * 0.5f;
            faceWidth = Vector2.Distance(left, right);

            return faceWidth >= 0.015f;
        }

        private bool TryReadSourceShoulderWidth(PosePacket pose, out float width)
        {
            width = 0f;
            if (!pose.TryGetImage("left_shoulder", .55f, out var left) ||
                !pose.TryGetImage("right_shoulder", .55f, out var right))
                return false;

            // Keep the size calculation used by tracker-video-avatar-overlay: the
            // camera image occupies only part of a wider Unity viewport, so compare
            // shoulder widths in that fitted viewport rather than raw image space.
            var sourceAspect = pose.source_height > 0
                ? (float)pose.source_width / pose.source_height
                : 4f / 3f;
            var viewportScaleX = trackingCamera.aspect > sourceAspect
                ? sourceAspect / trackingCamera.aspect
                : 1f;
            width = Mathf.Abs(right.x - left.x) * viewportScaleX;
            return width >= .03f;
        }

        private bool TryReadAvatarShoulders(out float width, out Vector3 worldCenter)
        {
            width = 0f;
            worldCenter = default;
            var left = targetAnimator.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            var right = targetAnimator.GetBoneTransform(HumanBodyBones.RightUpperArm);
            if (left == null || right == null) return false;

            var leftViewport = trackingCamera.WorldToViewportPoint(left.position);
            var rightViewport = trackingCamera.WorldToViewportPoint(right.position);
            if (leftViewport.z <= 0f || rightViewport.z <= 0f) return false;

            width = Vector2.Distance(leftViewport, rightViewport);
            worldCenter = (left.position + right.position) * .5f;
            return width > .001f;
        }

        private bool TryReadAvatarFace(out Vector2 faceCenter, out float faceWidth, out Vector3 faceWorldCenter)
        {
            faceCenter = default;
            faceWidth = 0f;
            faceWorldCenter = default;

            if (trackingCamera == null || targetAnimator == null)
            {
                return false;
            }

            var leftEye = targetAnimator.GetBoneTransform(HumanBodyBones.LeftEye);
            var rightEye = targetAnimator.GetBoneTransform(HumanBodyBones.RightEye);

            if (leftEye == null || rightEye == null)
                return false;

            Vector3 leftViewport = trackingCamera.WorldToViewportPoint(leftEye.position);
            Vector3 rightViewport = trackingCamera.WorldToViewportPoint(rightEye.position);

            if (leftViewport.z <= 0f || rightViewport.z <= 0f)
            {
                return false;
            }

            faceCenter = ((Vector2)leftViewport + (Vector2)rightViewport) * 0.5f;
            faceWidth = Vector2.Distance(leftViewport, rightViewport);
            faceWorldCenter = (leftEye.position + rightEye.position) * 0.5f;

            return faceWidth > 0.001f;
        }

        private void ApplyFaceZoom(PosePacket pose, float deltaTime)
        {
            if (!enableFaceZoom || trackingCamera == null)
            {
                return;
            }
            if (manualController != null && manualController.PlacementLocked)
                return;

            float sourceWidth;
            float avatarWidth;
            Vector3 avatarWorldCenter;
            if (!pose.TryGetImage("face_top", .55f, out var top) ||
                !pose.TryGetImage("face_chin", .55f, out var chin) ||
                !TryReadAvatarFace(out _, out _, out avatarWorldCenter)) return;
            var topViewport = SourceImageToViewport(new Vector2(top.x, top.y), pose.source_width, pose.source_height);
            var chinViewport = SourceImageToViewport(new Vector2(chin.x, chin.y), pose.source_width, pose.source_height);
            var difference = topViewport - chinViewport;
            // Match the camera background's centred cover fit. Only adjust the
            // head-size measurement; keep the existing body/hand mapping intact.
            if (pose.source_width > 0 && pose.source_height > 0)
            {
                var sourceAspect = (float)pose.source_width / pose.source_height;
                var viewportAspect = trackingCamera.aspect;
                if (sourceAspect < viewportAspect)
                    difference.y *= viewportAspect / sourceAspect;
                else if (sourceAspect > viewportAspect)
                    difference.x *= sourceAspect / viewportAspect;
            }
            difference.x *= trackingCamera.aspect;
            var rawSourceFaceWidth = difference.magnitude;
            if (rawSourceFaceWidth < .02f) return;
            var height = avatarFaceHeightMeters * Mathf.Abs(targetAnimator.transform.lossyScale.y);
            var avatarTop = trackingCamera.WorldToViewportPoint(avatarWorldCenter + trackingCamera.transform.up * height * .5f);
            var avatarBottom = trackingCamera.WorldToViewportPoint(avatarWorldCenter - trackingCamera.transform.up * height * .5f);
            avatarWidth = Mathf.Abs(avatarTop.y - avatarBottom.y);
            {
                if (!faceZoomInitialized)
                {
                    filteredSourceFaceWidth = rawSourceFaceWidth;
                    faceZoomInitialized = true;
                }
                if (receivedNewPoseFrame)
                {
                    var measurementT = 1f - Mathf.Exp(-8f * deltaTime);
                    filteredSourceFaceWidth = Mathf.Lerp(
                        filteredSourceFaceWidth, rawSourceFaceWidth, measurementT);
                }
                sourceWidth = filteredSourceFaceWidth;
            }

            sourceWidth *= avatarSizeMatchScale;

            Vector3 cameraPosition = trackingCamera.transform.position;
            Vector3 cameraForward = trackingCamera.transform.forward;

            float currentDistance = Vector3.Dot(avatarWorldCenter - cameraPosition, cameraForward);

            if (currentDistance <= 0.05f)
                return;

            float sizeRatio = avatarWidth / Mathf.Max(sourceWidth, 0.001f);

            if (Mathf.Abs(sizeRatio - 1f) < faceSizeDeadZoneRatio)
            {
                sizeRatio = 1f;
            }

            float targetDistance = Mathf.Clamp(currentDistance * sizeRatio, minimumFaceCameraDistance, maximumFaceCameraDistance);

            float smoothDistance = Mathf.SmoothDamp(
                    currentDistance,
                    targetDistance,
                    ref cameraDistanceVelocity,
                    faceZoomSmoothTime,
                    5f,
                    deltaTime
                );

            // Zoom only along the existing view axis. Rebuilding the camera position
            // from the face center also changed X/Y, which pulled the camera up to the
            // avatar's eyes and produced an unintended close-up.
            trackingCamera.transform.position =
                cameraPosition + cameraForward * (currentDistance - smoothDistance);
        }

        private void ResetTrackingFiltersOnly()
        {
            hipsInitialized = false;
            faceZoomInitialized = false;
            shoulderZoomInitialized = false;
            cameraDistanceVelocity = 0f;
            leftHandOrientationInitialized = false;
            rightHandOrientationInitialized = false;
            lastLeftFingerTrackingTime = float.NegativeInfinity;
            lastRightFingerTrackingTime = float.NegativeInfinity;

            filteredScreenCenter = Vector2.zero;
            stableScreenCenter = Vector2.zero;
            filteredShoulderWidth = 0f;
            stableShoulderWidth = 0f;
        }

        public void ResumeAfterManualMotion()
        {
            // Keep the last valid tracking/fallback state. Resetting landmark and arm
            // state here makes an occluded body fall back to only the face/fingers.
            // Only discard rotation history from before the animation; with Animator
            // disabled, tracking can blend back without a per-frame writer conflict.
            smoother.Reset();
            leftHandOrientationInitialized = false;
            rightHandOrientationInitialized = false;
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
                if (bone == HumanBodyBones.LeftUpperArm || bone == HumanBodyBones.LeftLowerArm ||
                    bone == HumanBodyBones.LeftHand || bone == HumanBodyBones.RightUpperArm ||
                    bone == HumanBodyBones.RightLowerArm || bone == HumanBodyBones.RightHand) continue;
                var transform = targetAnimator.GetBoneTransform(bone);
                if (transform != null) transform.rotation = smoother.Smooth(bone, transform.rotation, rootRotationDelta * rest, smoothingSpeed, rotationDeadZoneDegrees, Time.deltaTime);
            }
            if (hasLastUpperBody)
            {
                ApplyAvatarRelaxedArm(true);
                ApplyAvatarRelaxedArm(false);
            }
            else
            {
                RelaxArmsToRest();
            }
        }

        private void ApplyAvatarRelaxedArm(bool left)
        {
            var upperBone = left ? HumanBodyBones.LeftUpperArm : HumanBodyBones.RightUpperArm;
            var lowerBone = left ? HumanBodyBones.LeftLowerArm : HumanBodyBones.RightLowerArm;
            var handBone = left ? HumanBodyBones.LeftHand : HumanBodyBones.RightHand;
            var upper = targetAnimator.GetBoneTransform(upperBone);
            var lower = targetAnimator.GetBoneTransform(lowerBone);
            var hand = targetAnimator.GetBoneTransform(handBone);
            if (upper == null || lower == null || hand == null) return;
            var hips = targetAnimator.GetBoneTransform(HumanBodyBones.Hips);
            var center = hips != null ? hips.position : targetAnimator.transform.position;
            var outward = Vector3.ProjectOnPlane(upper.position - center, Vector3.up).normalized;
            if (outward.sqrMagnitude < .000001f) outward = left ? -targetAnimator.transform.right : targetAnimator.transform.right;
            ApplyCurrentBoneDirection(upperBone, upper, lower, (Vector3.down + outward * .22f).normalized);
            ApplyCurrentBoneDirection(lowerBone, lower, hand, (Vector3.down + outward * .08f).normalized);
            ReturnBoneToRest(handBone);
        }

        private float ApplyCurrentBoneDirection(HumanBodyBones bone, Transform boneTransform, Transform endpoint, Vector3 desiredDirection)
        {
            var currentDirection = endpoint.position - boneTransform.position;
            if (currentDirection.sqrMagnitude < .000001f ||
                !solver.TrySolve(bone, desiredDirection, Vector3.zero, rootRotationDelta, false, out var target))
                return 0f;
            var correction = Quaternion.Angle(boneTransform.rotation, target);
            boneTransform.rotation = smoother.Smooth(
                bone, boneTransform.rotation, target, armRotationSmoothingSpeed, 0f, Time.deltaTime);
            appliedBones++;
            return correction;
        }

        private void ResetTrackingCalibration(bool resetRootPosition = false)
        {
            var root = targetAnimator.transform;
            if (resetRootPosition)
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

            lastReliableFaceTime = float.NegativeInfinity;
            filteredHeadRotation = Quaternion.identity;
            filteredHeadRotationInitialized = false;
            lastHeadRotationTime = float.NegativeInfinity;
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
            leftHandDepthTracker.Reset();
            rightHandDepthTracker.Reset();
            leftPalmProjectionTracker.Reset();
            rightPalmProjectionTracker.Reset();
            leftPalmMissingFrames = 0;
            rightPalmMissingFrames = 0;
            leftPalmLastProcessedFrame = long.MinValue;
            rightPalmLastProcessedFrame = long.MinValue;
            leftResolvedWristInitialized = false;
            rightResolvedWristInitialized = false;
            leftWristWithinDeadZone = false;
            rightWristWithinDeadZone = false;
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

        private void ReturnBoneToParentRest(HumanBodyBones bone)
        {
            if (!solver.TryGetRestLocalRotation(bone, out var rest)) return;
            var transform = targetAnimator.GetBoneTransform(bone);
            if (transform != null)
                transform.localRotation = Quaternion.Slerp(
                    transform.localRotation, rest,
                    1f - Mathf.Exp(-smoothingSpeed * Time.deltaTime));
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

        private sealed class HandDepthTracker
        {
            private bool initialized;
            private float filteredDepth;
            private float stableDepth;
            private float lastProjectionScale;

            public float Update(float projectionScale, float shoulderWidth, bool hasPoseDepth, float poseDepth,
                float gain, float neutralProjectionRatio, float maxPoseCorrectionShoulderWidths,
                float maxShoulderWidths, float smoothing, float deadZoneScale, float deltaTime,
                out string state)
            {
                shoulderWidth = Mathf.Max(shoulderWidth, .001f);
                var maxDepth = shoulderWidth * maxShoulderWidths;
                poseDepth = Mathf.Clamp(poseDepth, -maxDepth, maxDepth);
                if (!initialized)
                {
                    initialized = true;
                    filteredDepth = 0f;
                    stableDepth = 0f;
                    lastProjectionScale = projectionScale;
                }

                var rawProjectionScale = projectionScale;
                if (lastProjectionScale > .0001f)
                {
                    projectionScale = Mathf.Clamp(
                        projectionScale, lastProjectionScale * .65f, lastProjectionScale * 1.5f);
                }
                var projectionLimited = Mathf.Abs(projectionScale - rawProjectionScale) > .0001f;
                lastProjectionScale = projectionScale;

                // The 3D palm spread supplies the primary depth estimate. Pose wrist depth
                // may refine it slightly but cannot pull it far from the hand-size estimate.
                var absoluteProjectionRatio = projectionScale * shoulderWidth;
                var scaleRatio = Mathf.Clamp(
                    absoluteProjectionRatio / Mathf.Max(neutralProjectionRatio, .01f), .25f, 8f);
                var scaleDepth = Mathf.Log(scaleRatio) * shoulderWidth * gain;
                var poseCorrectionLimit = shoulderWidth * maxPoseCorrectionShoulderWidths;
                var constrainedPoseDepth = Mathf.Clamp(
                    poseDepth, scaleDepth - poseCorrectionLimit, scaleDepth + poseCorrectionLimit);
                var measuredDepth = hasPoseDepth ? Mathf.Lerp(scaleDepth, constrainedPoseDepth, .7f) : scaleDepth;
                measuredDepth = Mathf.Clamp(measuredDepth, -maxDepth, maxDepth);
                filteredDepth = Mathf.Lerp(
                    filteredDepth, measuredDepth,
                    1f - Mathf.Exp(-smoothing * Mathf.Max(deltaTime, .001f)));
                stableDepth = FollowDepthOutsideDeadZone(
                    stableDepth, filteredDepth, shoulderWidth * deadZoneScale);
                state = $"source={(hasPoseDepth ? "scale3d+bounded_pose" : "scale3d")}, absoluteRatio={absoluteProjectionRatio:F2}, " +
                        $"neutralRatio={neutralProjectionRatio:F2}, scaleRatio={scaleRatio:F2}, pose={poseDepth:F3}->{constrainedPoseDepth:F3}, " +
                        $"projection={rawProjectionScale:F2}->{projectionScale:F2}, limited={projectionLimited}, " +
                        $"measured={measuredDepth:F3}, stable={stableDepth:F3}";
                return stableDepth;
            }

            public void Reset()
            {
                initialized = false;
                filteredDepth = 0f;
                stableDepth = 0f;
                lastProjectionScale = 0f;
            }

            public void Constrain(float maximumMagnitude)
            {
                filteredDepth = Mathf.Clamp(filteredDepth, -maximumMagnitude, maximumMagnitude);
                stableDepth = Mathf.Clamp(stableDepth, -maximumMagnitude, maximumMagnitude);
            }

            private static float FollowDepthOutsideDeadZone(float current, float target, float deadZone)
            {
                var delta = target - current;
                var distance = Mathf.Abs(delta);
                if (distance <= .000001f) return target;
                var smoothFactor = Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(deadZone * .2f, deadZone * 1.8f, distance));
                return current + delta * smoothFactor;
            }
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
            private long lastProcessedFrame = long.MinValue;

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
                lastProcessedFrame = long.MinValue;
                Stage = "LOST";
                RejectReason = "reset";
            }

            public bool TryGetStable(Vector3 candidate, bool hasCandidate, float referenceLength, float maxSpeed,
                float holdTime, int requiredFrames, float deadZoneScale, float smoothingCutoff,
                float motionResponsiveness, long frame, float now, out Vector3 point)
            {
                // LateUpdate can run several times while the receiver still exposes the same
                // tracking packet. Re-filtering that packet made the result depend on Unity's
                // frame rate and reduced dt to a render-frame interval. The next real sample
                // was then interpreted as a velocity spike, causing twitching and skipped
                // motion. Only advance measurement state once per source frame; bone rotation
                // smoothing still runs on every LateUpdate using the held stable point.
                if (frame == lastProcessedFrame)
                {
                    point = hasStable ? stablePoint : pendingPoint;
                    return hasStable;
                }
                lastProcessedFrame = frame;

                if (!hasCandidate)
                {
                    acquiring = false;
                    candidateFrames = 0;
                    RejectReason = "missing_or_anatomy";
                    if (hasStable && now - lastObservedTime <= holdTime)
                    {
                        lastAcceptedTime = now;
                        filteredVelocity = Vector3.Lerp(filteredVelocity, Vector3.zero, .5f);
                        Stage = "HELD";
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
                        // Feed every accepted sample into the low-pass filter. The previous
                        // distance gate accumulated small movements and released them in steps,
                        // which made hands look as if they were updating at a low frame rate.
                        var delta = candidate - stablePoint;
                        var deadZone = referenceLength * Mathf.Max(deadZoneScale, 0f);
                        // Remove input jitter without introducing a jump at the edge of
                        // the dead zone. Only the distance beyond the zone drives the arm.
                        var targetPoint = delta.magnitude <= deadZone
                            ? stablePoint
                            : stablePoint + delta.normalized * (delta.magnitude - deadZone);
                        var measuredVelocity = (targetPoint - stablePoint) / dt;
                        var derivativeAlpha = OneEuroAlpha(1.5f, dt);
                        filteredVelocity = Vector3.Lerp(filteredVelocity, measuredVelocity, derivativeAlpha);
                        var xyCutoff = smoothingCutoff + filteredVelocity.magnitude * motionResponsiveness;
                        var zCutoff = smoothingCutoff * .8f +
                                      Mathf.Abs(filteredVelocity.z) * motionResponsiveness * .7f;
                        var xyT = OneEuroAlpha(xyCutoff, dt);
                        var zT = OneEuroAlpha(zCutoff, dt);
                        stablePoint = new Vector3(
                            Mathf.Lerp(stablePoint.x, targetPoint.x, xyT),
                            Mathf.Lerp(stablePoint.y, targetPoint.y, xyT),
                            Mathf.Lerp(stablePoint.z, targetPoint.z, zT));
                        Stage = "TRACKED";
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

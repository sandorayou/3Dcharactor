# Camera VRM Mocap V2

## Design

- The Python process requests a one-frame camera buffer and runs Pose Landmarker Lite plus the dedicated 21-point Hand Landmarker.
- Every landmark contains world coordinates, image coordinates, and confidence. Unity decides visibility independently for each body part.
- The avatar mirrors the performer. Shoulder depth controls 180-degree body turns, while image-space shoulder-center movement controls translation; the two signals are kept separate.
- Torso lean uses shoulder-to-hip direction when hips are visible and shoulder-to-head direction otherwise. Head orientation is solved separately and blended through the neck so head and torso remain connected.
- A visible palm/wrist is treated as the arm's endpoint tracker. Pose-world elbow data is only a soft hint; when it is occluded at the chest, the elbow is inferred from the shoulder, hand, avatar side, previous solution, and a forward anatomical pole.
- Hand and elbow image coordinates are calibrated into avatar space before IK. Palm projection estimates wrist depth and bounded pose-world Z is used only as a depth correction; the computed depth is not replaced by the raw pose-world wrist.
- Wrist and inferred elbow positions are projected outside a torso safety radius before rotations are applied. This prevents the arm entering the chest.
- The hand endpoint is projected to the avatar's front torso surface even when an observed elbow is used. Its screen-space X/Y is preserved instead of pushing the hand sideways.
- Hand orientation keeps the anatomical wrist-to-finger axis continuous, allows real palm turns, and holds through short landmark dropouts instead of snapping to the rest rotation.
- Tracking state is per part. A missing hand relaxes only that arm and hand; missing head points relax the neck and head; loss of both shoulders relaxes the upper body.
- A scale-relative 10% dead zone is applied before exponential smoothing. Tracking loss transitions to the recorded rest pose instead of freezing.

## Unity setup

Add `UdpTrackingReceiver` and `CameraVrmDriver` to the VRM root, then assign its Humanoid `Animator`. Start `camera-vrm-tracker/tracker.py` with the Lite pose and hand task files in its `models` directory.

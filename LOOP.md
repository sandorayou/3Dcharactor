---
agent: codex
until:
  - done
  - "python -B Tools/verify_avatar_privacy.py"
critic: same
max: 8
max_time: 3h
permissions: default
---
Fix the actual Unity camera avatar alignment and selective privacy mosaic bugs in this repository. User reports avatar repeatedly reverses direction instead of overlapping their camera image exactly; mosaic wrongly affects white pixels despite requesting only skin near tracked bones. Investigate the active scene and full pipeline before changing code. Preserve all pre-existing untracked files (Assets/CameraVrmMocap, Output, preserved directories, model meta files). Do not add them to git. Use existing branch codex/camera-aligned-background. Do not start nested loops. Do not spawn subagents. Inspect applicable AGENTS.md. Use minimal scoped output and tests; commit only files changed for this task before finishing. Do not claim device verification without actual device evidence.

- [x] Trace the active camera/tracker coordinate mapping through image crop, orientation, mirror, bone mapping and avatar framing. Fix contradictory mirrors, unstable facing and other demonstrated causes so character tracks the same displayed landmarks. Verify front-facing, lateral motion, tilt, low-confidence and lost-tracking behavior using executable regression cases.
- [x] Make privacy mosaic affect skin pixels in the vicinity of tracked bones as requested, excluding white/neutral non-skin pixels even inside bone regions; ensure dilation/blur/mask union does not reintroduce white pixels. Verify actual applicable desktop and iOS implementation paths, only changing active relevant code.
- [x] Implement Tools/verify_avatar_privacy.py as a reproducible minimal executable regression verifier covering actual changed behavior, not merely string-presence checks. Reuse existing Unity or native test facilities or compile extracted production helpers if possible. Run relevant syntax/compilation checks. If genuine external limitations prevent execution, explicitly record the blocker and do not mark full completion.
- [x] Inspect available live app/device and log collection paths. Capture real logs if accessible. If not already repeatable, implement a scoped repeatable capture/replay or diagnostic workflow recording alignment coordinates and mosaic behavior; explicitly separate synthetic tests from actual hardware results. Do not fabricate logs or claim full concealment from skeletal alignment alone.
- [x] Review changed files against every acceptance criterion and resolve findings, run the minimal relevant checks, document verified results and any device limitations in a concise task report, and commit only task edits.

The source is primarily Assets/RealtimeBodyTracking/Scripts including HumanoidPoseDriver.cs, PoseInputMapper.cs, ScreenSpaceFramingController.cs, UpperBodyPoseSolver.cs and Assets/Plugins/iOS/NativePoseBridge.mm. Inspect actual scene wiring before assuming paths. Tools currently has no avatar regression verifier. python-tracker currently only has debug and cache directories. Look at git tracked files rather than sweeping generated Builds, Library and Output. Use official sources for any web research. User wants actual corrections, not only advice. End with loop done only when supported by checks; otherwise state precise blockers in the loop letter. A critic must review non-trivial changes. All Python changes require at least py_compile or equivalent syntax check.

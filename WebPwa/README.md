# Realtime Body Tracker PWA

The PWA packages the existing `SampleScene`, VRM avatar, `HumanoidPoseDriver`, and the three existing MediaPipe `.task` models. The browser runs Pose, Hand, and Face Landmarker locally, converts results into the existing version 4 `PosePacket` JSON shape, and sends those packets to Unity through `WebGLPosePacketSource`. The Python/UDP path and the iOS build remain separate.

## Build

Requirements: the same Unity 2022.3.62f3 project version, its WebGL Build Support module, Node.js/npm, and the three model files in `python-tracker/models/`.

From the project root in PowerShell:

```powershell
.
WebPwa\build-pwa.ps1
```

The command exports the `SampleScene` to `Builds/PWA/UnityBuild`, bundles MediaPipe's WASM runtime and the existing models, and writes the deployable site to `WebPwa/dist`.

## Run and install

Serve `WebPwa/dist` over HTTPS (or `localhost` during development). Camera access requires a secure browser context. Open the site, allow camera access, and choose **カメラを開始**. Chromium browsers offer installation from the address bar or browser menu; on iOS, open the HTTPS site in Safari and choose **ホーム画面に追加**.

The first visit downloads the Unity player, MediaPipe runtime, and model files. The service worker caches same-origin files as they are used so a subsequent visit can start offline. Camera frames and inference stay on-device.

Before starting the camera, open **背景とカメラ → 詳細設定** to select another humanoid VRM or toggle **輪郭線を強調**. The setting panel is HTML outside the Unity canvas and is hidden before camera tracking begins, so it is not part of the avatar image.

## Compatibility notes

The avatar scene and body/hand/face solving stay in Unity, but browser inference runs on the main browser thread and can perform differently from the parallel Python tracker. WebGL support, memory, camera permission, and inference speed vary by device. Validate framing, hand-side assignment, face rotation, and sustained frame rate on the target phones before treating the web build as equivalent to the desktop/iOS builds.

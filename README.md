# iPhone Native Body Tracker

現在はiPhone専用です。AVFoundationでカメラを取得し、iOSネイティブMediaPipeで推論した関節座標だけをUnityへ渡します。

## Python tracker

1. `python-tracker` で `python -m pip install -r requirements.txt` を実行します。
2. MediaPipeの **Pose Landmarker Lite**、**Hand Landmarker（片手21点）**、**Face Landmarker** のtaskファイルが `python-tracker/models/` にあることを確認します。
3. `python app.py` を実行します。動画は `python app.py --source C:\\path\\to\\video.mp4`、プレビューなしは `python app.py --no-preview` です。

主なオプションは `--inference-size 256|320`、`--inference-fps 20`、`--host 127.0.0.1`、`--port 39540`、`--tracking-mirror` です。プレビュー反転とトラッキング反転は分離されています。
<img width="642" height="452" alt="image" src="https://github.com/user-attachments/assets/0617cb6b-342b-4e90-b455-50ca8e8b0491" />

## Unity setup

1. VRMをHumanoid Animatorとしてシーンに配置します（UniVRMの導入は任意で、VRMのインポートに必要です）。
2. VRMまたは親オブジェクトに `UdpPoseReceiver` と `HumanoidPoseDriver` を追加します。
3. `HumanoidPoseDriver` の **Target Animator** をVRMのAnimatorに指定し、**UDP Receiver** を同じオブジェクトの `UdpPoseReceiver` に指定します。ReceiverのポートをPythonと一致させます。
4. Play ModeにしてからPython trackerを起動します。

`HumanoidPoseDriver` は Inspector から **Smoothing Speed**、**Avatar Mirror**、**Enable Hips Position**、**Hips Position Scale**、頭・腕・脚の有効化、**Tracking Timeout**、**Return To Rest Pose**、**Debug Logging** を設定できます。Inspectorには最新フレーム番号とTracking状態、`UdpPoseReceiver` には受信フレームと不正・破棄パケット数が表示されます。受信スレッドは最新パケットの置換だけを行い、ボーン更新は `LateUpdate` で行います。

Play Mode中に **Ctrl + テンキー `/`** を押すと、その瞬間の腰の座標と下半身の姿勢を固定します。固定中も肩・頭・手は追従し、腰から上の傾きとして反映されます。もう一度押すと解除し、通常の全身追従へ戻して位置を再基準化します。

`MotionRecorder` はリアルタイム駆動と独立した任意機能です。必要な場合だけ追加し、Hips位置とHumanoidのQuaternionをJSON記録します。FBX変換は録画後の別処理としてください。

# Realtime Body Tracker

Windows向けの、MediaPipe Pose LandmarkerからUnity Humanoid/VRMへ低遅延で全身姿勢を送る初版です。Python側は最新の1フレームだけを保持して古いフレームを破棄し、Unity側も未処理パケットを常に最新のものへ置換します。

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

Play Mode中に **Ctrl + テンキー `/`** を押すと、画面外に出た腰・脚の座標保持を切り替えます。腰が見えている状態で有効にしてから座ったり前傾すると、腰の位置を固定したまま上半身を曲げられます。もう一度押すと解除して位置追従を再基準化します。

`MotionRecorder` はリアルタイム駆動と独立した任意機能です。必要な場合だけ追加し、Hips位置とHumanoidのQuaternionをJSON記録します。FBX変換は録画後の別処理としてください。

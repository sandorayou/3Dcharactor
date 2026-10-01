# 現在のWindows版をiOSへ移植

Windows版 `dc7e1ae` の SampleScene、キャラ、HumanoidPoseDriver、肘・手首の制御を使用します。
iPhoneではPython/UDP/HTTPを起動せず、AVFoundationとMediaPipeのPose・Hand・Faceで検出した
同じPosePacketを共通のキャラ制御へ渡します。3つのモデルはWindows版と同一ファイルです。

実写映像は人物の胴体・頭・四肢・手を16ピクセル単位でモザイクにし、透明なUnity画面の後ろへ
合成します。青背景への置換はありません。前面カメラの映像だけを左右反転し、検出座標は
Windowsと同じ未反転のままです。ネイティブのモザイクはCoreImageを使うため、Windowsの
OpenCVによる縮小・拡大とは境界の画素が完全一致するわけではありません。

## Xcodeプロジェクトを作る

1. Unity 2022.3.62f3とiOS Build Supportでこのプロジェクトを開く。
2. `Build > Export updated iOS project`を実行。
3. 新しい出力は`Builds/iOS-WindowsPort`。古い`Builds/iOS`は使用しない。
4. Macで出力フォルダー内の`pod install`を実行。
5. `Unity-iPhone.xcworkspace`をXcodeで開き、署名チームとBundle Identifierを設定して実機へRun。

コマンドラインではUnityの`-buildTarget iOS -executeMethod RealtimeBodyTracking.Editor.IOSBuildExporter.Export`
で同じエクスポートを実行できます。iOS 15以上、IL2CPP、透明フレームバッファ、カメラ権限説明を
エクスポート時だけ設定し、終了後に元のプロジェクト設定へ戻します。
MediaPipeTasksVisionはAPI互換性のため0.10.21に固定しています。
[公式iOS導入ガイド](https://ai.google.dev/edge/mediapipe/solutions/vision/pose_landmarker/ios)

## 録画と確認

iOSの録画ボタンはReplayKitで合成画面を録画し、停止後の標準プレビューから保存・共有します。
Windowsのffmpegによる実写・透過アバター別ファイル出力はiOSでは提供していません。
Xcodeでのネイティブビルドと実機でのカメラ・表情・指・モザイク・録画確認が必要です。
Windows上のC#コンパイル成功だけでは、iPhoneでの表示・性能を確認したことにはなりません。

GitHubのiOSワークフローを使う場合は、新しい出力を別途リポジトリへ含める必要があります
（Buildsフォルダーは通常Gitの対象外）。ワークフローは古い出力を自動選択しません。

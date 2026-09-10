# WindowsからGitHub ActionsでビルドしてSideStoreへ入れる（My project 5）

本プロジェクトは、`VoiceMemoryPrototype` と同様に、**Windows環境から GitHub Actions（macOS runner）を利用して署名なしの iPhone 向け IPA（`MyProject5-unsigned.ipa`）を作成**し、SideStore を使って iPhone 実機にインストールして動作させることができます。

## 統合配信機能の現在地

Unity側には、VRM画面とiOSネイティブ配信エンジンを接続する契約（`LiveStreamingController`）と、カメラ・マイク権限の設定を追加しています。配信本体は`LiveStreamingBridge.swift`に実装し、HaishinKitのRTMPHaishinKitをXcodeのSwift Packageとして追加して有効化します。生成後のXcodeプロジェクトで、`https://github.com/shogo4405/HaishinKit.swift`を追加し、RTMPHaishinKit productをUnity-iPhone targetへリンクしてください。

### 配信画面と設定画面

配信映像はネイティブ配信エンジンがカメラ＋マイクから直接作るため、UnityのUIは映りません。「イン／アウト」ボタンはUnity UIとして表示し、押下時に配信カメラだけを切り替えます。設定画面で縦（`720 x 1280`、スマホ縦持ち）／横（`1280 x 720`、スマホ横持ち）を配信開始前に選択できます。どちらも30fps・映像3.5Mbps・AAC 128kbpsです。設定画面では各サービスのアカウント、配信URL、配信キーを登録・選択できます。配信キーは現状Unity保存の仮実装なので、公開版ではiOS Keychain保存に置き換えてください。
Windows 上に Mac や Xcode は不要です。

---

## 全体の流れ

1. **Unityで iOS 向けにエクスポート**（Windows上のUnity Editorで実行）
2. **GitHubへプッシュ**
3. **GitHub Actions で自動ビルド（IPA生成）**
4. **SideStore で iPhone へインストール**

---

## ステップ 1: Unityで iOS 向けにプロジェクトを書き出す

1. Unity Editor で本プロジェクト（`My project (5)`）を開きます。
2. メニューバーの **File > Build Settings...** を開きます。
3. Platform から **iOS** を選択し、**Switch Platform** をクリックします。
   （※iOS Build Support が未インストールの場合は Unity Hub から追加してください）
4. **Build** をクリックし、プロジェクトルート直下に `Builds/iOS` などのフォルダを指定して出力します。
   - 例: `c:\Users\81904\Downloads\My project (5)\Builds\iOS`
5. 出力されたフォルダ内に `Unity-iPhone.xcodeproj` が生成されます。

> [!TIP]
> 自動設定スクリプト（`TrackerBuildPostprocessor.cs`）により、iOS ビルド時にカメラ使用許可（`NSCameraUsageDescription`）とローカルネットワーク使用許可（`NSLocalNetworkUsageDescription`）が自動で付与されます。

---

## ステップ 2: GitHub へプッシュ

1. GitHub で新規リポジトリ（Private推奨）を作成します。
2. 本プロジェクト（エクスポートした `Builds/iOS` フォルダおよび `.github/workflows/build-ios.yml` を含む）をリポジトリへ push します。

```bash
git add .
git commit -m "Add iOS build and GitHub Actions workflow"
git push origin main
```

---

## ステップ 3: GitHub Actions で IPA を自動作成

1. GitHub リポジトリの **Actions** タブを開きます。
2. 左側のワークフロー一覧から **Build unsigned iOS IPA** を選択します。
3. **Run workflow** を実行します（push時にも自動実行されます）。
4. ビルド成功後、Artifacts（成果物）に **`MyProject5-unsigned-ipa`** が表示されます。
5. クリックしてダウンロードし、ZIPを展開すると **`MyProject5-unsigned.ipa`** が手に入ります。

---

## ステップ 4: SideStore で iPhone にインストール

1. Windows PC で SideStore の初回セットアップを行います（iLoader を使用）。
2. iPhone で **SideStore** および **LocalDevVPN** を起動し、VPN を「接続」にします。
3. 作成された `MyProject5-unsigned.ipa` を iCloud Drive または AirDrop / Google Drive 経由で iPhone に送信します。
4. iPhone の **SideStore** アプリを開き、左上の「+」ボタンからダウンロードした IPA を選択してインストールします。
5. ホーム画面に追加されたアプリをタップして起動します！

---

## iPhone 実機での使い方（動作モード）

### 1. 単体カメラ表示モード（オフライン / スタンドアロン）
- iPhone 実機でアプリを起動すると、自動的に iPhone のインカメラ映像が背景に表示されます。
- カメラ許可のダイアログが出たら「許可」を選択してください。

### 2. PC連携 VTuberモード（Wi-Fi経由）
- PC（Windows）側で `python-tracker` を起動し、iPhone と PC を同じ Wi-Fi に接続します。
- PC 側トラッカーから iPhone のローカル IP アドレスに向けて UDP ポーズパケット（ポート 39542）を送信することで、PC のカメラトラッキングに合わせて iPhone 上の 3D キャラクターがリアルタイムに連動して動きます。

export async function createUnityHost({ onProgress, onReady }) {
  const canvas = document.querySelector('#unity-canvas');
  const build = await fetch('./unity/build-config.json').then(response => {
    if (!response.ok) throw new Error('Unity WebGLのビルド設定が見つかりません。PWAを再作成してください。');
    return response.json();
  });
  const loader = document.createElement('script');
  loader.src = `./unity/Build/${build.prefix}.loader.js`;
  await new Promise((resolve, reject) => { loader.onload = resolve; loader.onerror = () => reject(new Error('Unity WebGLローダーがありません。UnityのWebGLビルド後にPWAを作成してください。')); document.head.append(loader); });
  const config = {
    dataUrl: `./unity/Build/${build.data}`,
    frameworkUrl: `./unity/Build/${build.framework}`,
    codeUrl: `./unity/Build/${build.code}`,
    streamingAssetsUrl: './unity/StreamingAssets',
    companyName: 'RealtimeBodyTracking',
    productName: 'Realtime Body Tracker',
    productVersion: '0.1.0',
    webglContextAttributes: { alpha: true, premultipliedAlpha: false, preserveDrawingBuffer: false },
  };
  const instance = await globalThis.createUnityInstance(canvas, config, onProgress);
  onReady();
  return {
    sendPose(packet) { instance.SendMessage('WebGLPosePacketSource', 'ReceivePoseJson', JSON.stringify(packet)); },
    setAnimeInternalLinesEnabled(value) {
      instance.SendMessage('WebGLPosePacketSource', 'SetAnimeInternalLinesEnabled', value ? 'true' : 'false');
    },
    async loadAvatar(file) {
      if (file.size <= 0 || file.size > 256 * 1024 * 1024) throw new Error('VRMは256 MB以下のファイルを選択してください。');
      globalThis.__webVrmPickerBytes = new Uint8Array(await file.arrayBuffer());
      globalThis.__webVrmPickerName = file.name;
      instance.SendMessage('WebGLPosePacketSource', 'OnVrmFilePicked', file.name);
    },
  };
}

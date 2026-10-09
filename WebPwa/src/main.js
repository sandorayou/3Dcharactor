import './style.css';
import { createUnityHost } from './unity-host.js';
import { createVisionTracker } from './vision-tracker.js';

const video = document.querySelector('#camera-preview');
const status = document.querySelector('#status');
const progress = document.querySelector('#progress');
const loading = document.querySelector('#loading');
const startButton = document.querySelector('#start-camera');
const toggleButton = document.querySelector('#camera-toggle');
const errorBox = document.querySelector('#error');
const backgroundCameraButton = document.querySelector('#background-camera-button');
const backgroundCameraMenu = document.querySelector('#background-camera-menu');
const detailsButton = document.querySelector('#details-button');
const detailsPanel = document.querySelector('#details-panel');
const vrmFile = document.querySelector('#vrm-file');
const avatarStatus = document.querySelector('#avatar-status');
const outlineToggle = document.querySelector('#outline-toggle');
const savedOutlineSetting = (() => {
  try { return localStorage.getItem('realtime-body-tracker-outline') === 'true'; }
  catch { return false; }
})();
outlineToggle.checked = savedOutlineSetting;
let unity;
let tracker;

if ('serviceWorker' in navigator && import.meta.env.PROD) {
  try {
    await navigator.serviceWorker.register('./service-worker.js');
    await navigator.serviceWorker.ready;
    if (!navigator.serviceWorker.controller) await new Promise(resolve => {
      navigator.serviceWorker.addEventListener('controllerchange', resolve, { once: true });
      setTimeout(resolve, 1500);
    });
  } catch (error) { console.warn('Offline caching is unavailable.', error); }
}

function reportError(error) {
  console.error(error);
  errorBox.textContent = error?.message || String(error);
  errorBox.hidden = false;
  status.textContent = '起動できませんでした';
  startButton.hidden = false;
  startButton.disabled = false;
}

try {
  unity = await createUnityHost({
    onProgress(value) { progress.value = value; },
    onReady() {
      status.textContent = 'カメラを開始してトラッキングを始めます';
      startButton.hidden = false;
      vrmFile.disabled = false;
      outlineToggle.disabled = false;
    },
  });
  unity.setAnimeInternalLinesEnabled(outlineToggle.checked);
} catch (error) {
  reportError(error);
}

backgroundCameraButton.addEventListener('click', () => {
  backgroundCameraMenu.hidden = !backgroundCameraMenu.hidden;
});

detailsButton.addEventListener('click', () => {
  detailsPanel.hidden = !detailsPanel.hidden;
  detailsButton.setAttribute('aria-expanded', String(!detailsPanel.hidden));
});

vrmFile.addEventListener('change', async () => {
  const file = vrmFile.files?.[0];
  if (!file) return;
  avatarStatus.textContent = `${file.name} を読み込んでいます…`;
  try {
    await unity.loadAvatar(file);
  } catch (error) {
    avatarStatus.textContent = error?.message || String(error);
  } finally {
    vrmFile.value = '';
  }
});

outlineToggle.addEventListener('change', () => {
  unity?.setAnimeInternalLinesEnabled(outlineToggle.checked);
  try { localStorage.setItem('realtime-body-tracker-outline', String(outlineToggle.checked)); }
  catch { /* Persistent storage is optional. */ }
});

window.addEventListener('webvrm-status', event => {
  avatarStatus.textContent = event.detail || '';
});

async function startCamera() {
  startButton.disabled = true;
  errorBox.hidden = true;
  try {
    if (!unity) throw new Error('Unity WebGLの読み込みが完了していません。ページを再読み込みしてください。');
    status.textContent = 'カメラへのアクセスを待っています…';
    const stream = await navigator.mediaDevices.getUserMedia({
      audio: false,
      video: { facingMode: 'user', width: { ideal: 640 }, height: { ideal: 480 }, frameRate: { ideal: 30, max: 30 } },
    });
    video.srcObject = stream;
    await video.play();
    // Close the capture-free settings/loading overlay before showing the camera.
    loading.hidden = true;
    tracker = await createVisionTracker({ video, onPacket: packet => unity.sendPose(packet), onStatus: text => { status.textContent = text; } });
    video.style.display = 'block';
    toggleButton.hidden = false;
    toggleButton.textContent = 'カメラ停止';
  } catch (error) {
    if (!tracker) loading.hidden = false;
    video.srcObject?.getTracks().forEach(track => track.stop());
    video.srcObject = null;
    reportError(error);
  } finally {
    startButton.disabled = false;
  }
}

function stopCamera() {
  tracker?.close();
  tracker = null;
  video.srcObject?.getTracks().forEach(track => track.stop());
  video.srcObject = null;
  video.style.display = 'none';
  toggleButton.hidden = true;
  loading.hidden = false;
  startButton.hidden = false;
  status.textContent = 'カメラを停止しました';
  unity?.sendPose({ version: 4, frame: 0, timestamp_ms: Date.now(), source_width: 0, source_height: 0, tracking: false, head_rotation: null, face_blendshapes: [], points: [] });
}

startButton.addEventListener('click', startCamera);
toggleButton.addEventListener('click', stopCamera);
window.addEventListener('beforeunload', stopCamera);

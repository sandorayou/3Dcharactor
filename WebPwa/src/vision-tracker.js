import { FaceLandmarker, FilesetResolver, HandLandmarker, PoseLandmarker } from '@mediapipe/tasks-vision';

const POSE_POINTS = [
  ['nose',0], ['left_eye',2], ['right_eye',5], ['left_ear',7], ['right_ear',8],
  ['left_shoulder',11], ['right_shoulder',12], ['left_elbow',13], ['right_elbow',14],
  ['left_wrist',15], ['right_wrist',16], ['left_pinky',17], ['right_pinky',18],
  ['left_index',19], ['right_index',20], ['left_thumb',21], ['right_thumb',22],
  ['left_hip',23], ['right_hip',24], ['left_knee',25], ['right_knee',26],
  ['left_ankle',27], ['right_ankle',28], ['left_heel',29], ['right_heel',30],
  ['left_foot_index',31], ['right_foot_index',32],
];
const HAND_POINTS = [
  'wrist', 'thumb_cmc', 'thumb_mcp', 'thumb_ip', 'thumb',
  'index_mcp', 'index_pip', 'index_dip', 'index',
  'middle_mcp', 'middle_pip', 'middle_dip', 'middle',
  'ring_mcp', 'ring_pip', 'ring_dip', 'ring',
  'pinky_mcp', 'pinky_pip', 'pinky_dip', 'pinky',
];

const point = (name, world, image, confidence) => ({
  name, x: world.x, y: world.y, z: world.z, confidence,
  image_x: image.x, image_y: image.y, image_z: image.z,
});

function quaternionFromFaceMatrix(matrix) {
  if (!matrix?.data || matrix.data.length < 16) return null;
  const d = matrix.data;
  // MediaPipe's JS matrix is column-major. The axis conversion used by the
  // Unity driver is diag(1,-1,-1), matching the Python producer.
  const signs = [1, -1, -1];
  const r = Array.from({ length: 3 }, (_, row) => Array.from({ length: 3 }, (_, col) => signs[row] * d[col * 4 + row] * signs[col]));
  const trace = r[0][0] + r[1][1] + r[2][2];
  let x, y, z, w;
  if (trace > 0) {
    const s = Math.sqrt(trace + 1) * 2;
    w = .25 * s; x = (r[2][1] - r[1][2]) / s; y = (r[0][2] - r[2][0]) / s; z = (r[1][0] - r[0][1]) / s;
  } else if (r[0][0] > r[1][1] && r[0][0] > r[2][2]) {
    const s = Math.sqrt(1 + r[0][0] - r[1][1] - r[2][2]) * 2;
    w = (r[2][1] - r[1][2]) / s; x = .25 * s; y = (r[0][1] + r[1][0]) / s; z = (r[0][2] + r[2][0]) / s;
  } else if (r[1][1] > r[2][2]) {
    const s = Math.sqrt(1 + r[1][1] - r[0][0] - r[2][2]) * 2;
    w = (r[0][2] - r[2][0]) / s; x = (r[0][1] + r[1][0]) / s; y = .25 * s; z = (r[1][2] + r[2][1]) / s;
  } else {
    const s = Math.sqrt(1 + r[2][2] - r[0][0] - r[1][1]) * 2;
    w = (r[1][0] - r[0][1]) / s; x = (r[0][2] + r[2][0]) / s; y = (r[1][2] + r[2][1]) / s; z = .25 * s;
  }
  const norm = Math.hypot(x, y, z, w) || 1;
  return { x: x / norm, y: y / norm, z: z / norm, w: w / norm };
}

function buildPacket(pose, hands, face, video, frame) {
  const world = pose.poseWorldLandmarks?.[0];
  const image = pose.poseLandmarks?.[0];
  const points = [];
  if (world && image) {
    for (const [name, index] of POSE_POINTS) {
      const w = world[index], i = image[index];
      if (w && i) points.push(point(name, w, i, i.visibility ?? i.presence ?? 1));
    }
    for (const assignment of hands) {
      const handWorld = assignment.world;
      const handImage = assignment.image;
      for (let i = 0; i < HAND_POINTS.length; i++) {
        if (handWorld[i] && handImage[i]) points.push(point(`${assignment.side}_hand_${HAND_POINTS[i]}`, handWorld[i], handImage[i], assignment.score));
      }
      const palmIndexes = [5, 9, 17];
      const average = list => ({
        x: palmIndexes.reduce((sum, i) => sum + list[i].x, 0) / 3,
        y: palmIndexes.reduce((sum, i) => sum + list[i].y, 0) / 3,
        z: palmIndexes.reduce((sum, i) => sum + (list[i].z || 0), 0) / 3,
      });
      points.push(point(`${assignment.side}_hand_palm`, average(handWorld), average(handImage), assignment.score));
    }
  }
  const categories = face.faceBlendshapes?.[0]?.categories || [];
  const selectedShapes = new Set(['eyeBlinkLeft', 'eyeBlinkRight', 'jawOpen', 'mouthSmileLeft', 'mouthSmileRight']);
  const faceBlendshapes = categories.filter(item => selectedShapes.has(item.categoryName)).map(item => ({ name: item.categoryName, score: item.score }));
  return {
    version: 4, frame, timestamp_ms: Math.floor(performance.now()),
    source_width: video.videoWidth, source_height: video.videoHeight,
    tracking: points.length > 0,
    head_rotation: quaternionFromFaceMatrix(face.facialTransformationMatrixes?.[0]),
    face_blendshapes: faceBlendshapes,
    points,
  };
}

function assignHands(result, pose, state, frame) {
  const imageHands = result.landmarks || [];
  const worldHands = result.worldLandmarks || [];
  const candidates = imageHands.map((image, index) => {
    const category = result.handednesses?.[index]?.[0];
    return {
      index, image, world: worldHands[index] || image,
      score: category?.score ?? .5,
      label: (category?.categoryName || '').toLowerCase(),
      x: image[0]?.x ?? .5, y: image[0]?.y ?? .5,
    };
  }).sort((a, b) => b.score - a.score).slice(0, 2);
  const poseLandmarks = pose.poseLandmarks?.[0] || [];
  const poseWrists = {
    left: poseLandmarks[15]?.visibility >= .2 ? poseLandmarks[15] : null,
    right: poseLandmarks[16]?.visibility >= .2 ? poseLandmarks[16] : null,
  };
  const choices = candidates.length < 2 ? [['left'], ['right']] : [['left', 'right'], ['right', 'left']];
  let best = choices[0], bestCost = Infinity;
  for (const sides of choices) {
    let cost = 0;
    candidates.forEach((hand, i) => {
      const side = sides[i];
      const old = state.positions.get(side);
      const age = old ? Math.max(frame - old.frame, 1) : 99;
      if (old && age <= 10) {
        const n = Math.min(age, 3), px = old.x + old.vx * n, py = old.y + old.vy * n;
        cost += 5 * ((hand.x - px) ** 2 + (hand.y - py) ** 2);
      } else cost += .12;
      if (hand.score >= .7 && ['left', 'right'].includes(hand.label) && hand.label !== side) cost += .1 * hand.score;
      const wrist = poseWrists[side];
      if (wrist) cost += .35 * ((hand.x - wrist.x) ** 2 + (hand.y - wrist.y) ** 2);
      const screenSide = hand.x > .5 ? 'right' : 'left';
      if (screenSide !== side) cost += .015;
    });
    if (cost < bestCost) { bestCost = cost; best = sides; }
  }
  return candidates.map((hand, i) => {
    const side = best[i];
    const old = state.positions.get(side);
    const age = old ? Math.max(frame - old.frame, 1) : 99;
    let vx = 0, vy = 0;
    if (old && age <= 10) { vx = old.vx * .45 + ((hand.x - old.x) / age) * .55; vy = old.vy * .45 + ((hand.y - old.y) / age) * .55; }
    state.positions.set(side, { x: hand.x, y: hand.y, vx, vy, frame });
    return { ...hand, side };
  });
}

export async function createVisionTracker({ video, onPacket, onStatus }) {
  const files = await FilesetResolver.forVisionTasks('./mediapipe/wasm');
  onStatus('3つのトラッキングモデルを準備しています…');
  async function createSet(delegate) {
    return Promise.all([
      PoseLandmarker.createFromOptions(files, { baseOptions: { modelAssetPath: './models/pose_landmarker_lite.task', delegate }, runningMode: 'VIDEO', numPoses: 1, outputSegmentationMasks: false }),
      HandLandmarker.createFromOptions(files, { baseOptions: { modelAssetPath: './models/hand_landmarker.task', delegate }, runningMode: 'VIDEO', numHands: 2, minHandDetectionConfidence: .35, minHandPresenceConfidence: .35, minTrackingConfidence: .35 }),
      FaceLandmarker.createFromOptions(files, { baseOptions: { modelAssetPath: './models/face_landmarker.task', delegate }, runningMode: 'VIDEO', numFaces: 1, outputFaceBlendshapes: true, outputFacialTransformationMatrixes: true }),
    ]);
  }
  let tasks;
  try { tasks = await createSet('GPU'); }
  catch (gpuError) {
    console.warn('MediaPipe GPU delegate unavailable; retrying on CPU.', gpuError);
    onStatus('GPUを利用できないためCPUで準備しています…');
    tasks = await createSet('CPU');
  }
  const [pose, hand, face] = tasks;
  const state = { positions: new Map() };
  let frame = 0, lastInference = 0, active = true;
  onStatus('トラッキング中');
  const tick = now => {
    if (!active) return;
    if (video.readyState >= HTMLMediaElement.HAVE_CURRENT_DATA && now - lastInference >= 50) {
      lastInference = now;
      try {
        const poseResult = pose.detectForVideo(video, now);
        const handResult = hand.detectForVideo(video, now);
        const faceResult = face.detectForVideo(video, now);
        const packet = buildPacket(poseResult, assignHands(handResult, poseResult, state, frame), faceResult, video, frame++);
        onPacket(packet);
      } catch (error) {
        console.error('MediaPipe inference failed', error);
        onStatus(`トラッキングエラー: ${error.message}`);
      }
    }
    requestAnimationFrame(tick);
  };
  requestAnimationFrame(tick);
  return { close() { active = false; pose.close(); hand.close(); face.close(); } };
}

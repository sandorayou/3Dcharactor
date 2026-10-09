import { cp, mkdir, readdir, stat, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const root = path.resolve(here, '../..');
const out = process.env.WEB_PWA_PUBLIC_DIR
  ? path.resolve(process.env.WEB_PWA_PUBLIC_DIR)
  : path.join(here, '../public');
const buildsRoot = path.join(root, 'Builds');
const models = path.join(root, 'python-tracker/models');
const visionPackage = path.join(root, 'WebPwa/node_modules/@mediapipe/tasks-vision');

async function requireDirectory(directory, label) {
  try { if (!(await stat(directory)).isDirectory()) throw new Error(); }
  catch { throw new Error(`${label} not found at ${directory}.`); }
}

async function inspectBuild(buildDirectory, outputRoot) {
  let files;
  try { files = await readdir(buildDirectory); }
  catch { return null; }
  const loader = files.find(file => file.endsWith('.loader.js'));
  if (!loader) return null;
  const prefix = loader.slice(0, -'.loader.js'.length);
  const match = suffixes => files.find(file => suffixes.some(suffix => file === `${prefix}${suffix}`));
  const data = match(['.data.unityweb', '.data']);
  const framework = match(['.framework.js.unityweb', '.framework.js']);
  const code = match(['.wasm.unityweb', '.wasm']);
  if (!data || !framework || !code) return null;
  return { buildDirectory, outputRoot, prefix, files: { data, framework, code }, modifiedAt: (await stat(buildDirectory)).mtimeMs };
}

async function locateUnityBuild() {
  let entries;
  try { entries = await readdir(buildsRoot, { withFileTypes: true }); }
  catch { throw new Error(`Unity WebGL output directory not found: ${buildsRoot}`); }
  const candidates = [];
  for (const entry of entries) {
    if (!entry.isDirectory() || !entry.name.startsWith('WebGL')) continue;
    const outputRoot = path.join(buildsRoot, entry.name);
    const direct = await inspectBuild(outputRoot, outputRoot);
    if (direct) candidates.push(direct);
    const nested = await inspectBuild(path.join(outputRoot, 'Build'), outputRoot);
    if (nested) candidates.push(nested);
  }
  candidates.sort((a, b) => b.modifiedAt - a.modifiedAt);
  if (candidates.length === 0) throw new Error('A complete Unity WebGL build was not found. Build/ must contain loader, data, framework, and wasm files.');
  return candidates[0];
}

await requireDirectory(models, 'MediaPipe model directory');
await requireDirectory(path.join(visionPackage, 'wasm'), 'MediaPipe Tasks Vision WASM runtime');
const unity = await locateUnityBuild();
await mkdir(path.join(out, 'unity/Build'), { recursive: true });
await mkdir(path.join(out, 'models'), { recursive: true });
await mkdir(path.join(out, 'mediapipe/wasm'), { recursive: true });
await cp(path.join(here, '../service-worker.js'), path.join(out, 'service-worker.js'), { force: true });
await cp(path.join(here, '../manifest.webmanifest'), path.join(out, 'manifest.webmanifest'), { force: true });
await cp(path.join(here, '../icon.svg'), path.join(out, 'icon.svg'), { force: true });

for (const file of await readdir(unity.buildDirectory))
  await cp(path.join(unity.buildDirectory, file), path.join(out, 'unity/Build', file), { recursive: true, force: true });
for (const entry of await readdir(unity.outputRoot, { withFileTypes: true })) {
  if (entry.name === 'Build') continue;
  const source = path.join(unity.outputRoot, entry.name);
  if (entry.isDirectory()) await cp(source, path.join(out, 'unity', entry.name), { recursive: true, force: true });
  else if (!entry.name.endsWith('.loader.js') && !/\.(data|framework\.js|wasm)(\.unityweb)?$/.test(entry.name))
    await cp(source, path.join(out, 'unity', entry.name), { force: true });
}
await writeFile(path.join(out, 'unity', 'build-config.json'), JSON.stringify({ prefix: unity.prefix, ...unity.files }, null, 2));
for (const file of ['pose_landmarker_lite.task', 'hand_landmarker.task', 'face_landmarker.task'])
  await cp(path.join(models, file), path.join(out, 'models', file), { force: true });
await cp(path.join(visionPackage, 'wasm'), path.join(out, 'mediapipe/wasm'), { recursive: true, force: true });
console.log(`Prepared Unity WebGL player (${unity.prefix}), MediaPipe models, and local WASM runtime.`);

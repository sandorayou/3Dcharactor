param(
  [string]$Unity = 'C:\Users\81904\Documents\Xfer\2022.3.62f3\Editor\Unity.exe'
)
$ErrorActionPreference = 'Stop'
$projectRoot = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$unityLog = Join-Path $projectRoot 'Logs\pwa-webgl-build.log'
$unityArgs = @('-batchmode', '-quit', '-projectPath', $projectRoot, '-buildTarget', 'WebGL', '-executeMethod', 'RealtimeBodyTracking.Editor.WebGLDistributionBuilder.Build', '-logFile', $unityLog)
$quotedArgs = $unityArgs | ForEach-Object { '"' + $_.Replace('"', '\\"') + '"' }
$unityProcess = Start-Process -FilePath $Unity -ArgumentList ($quotedArgs -join ' ') -PassThru -Wait -WindowStyle Hidden
if ($unityProcess.ExitCode -ne 0) { throw "Unity WebGL build failed (exit $($unityProcess.ExitCode)). See $unityLog" }
Push-Location $PSScriptRoot
try {
  npm ci
  if ($LASTEXITCODE -ne 0) { throw "npm ci failed (exit $LASTEXITCODE)." }
  npm run build
  if ($LASTEXITCODE -ne 0) { throw "PWA packaging failed (exit $LASTEXITCODE)." }
} finally { Pop-Location }
Write-Output "PWA output: $(Join-Path $PSScriptRoot 'dist')"

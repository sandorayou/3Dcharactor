param([switch]$SkipExport)
$ErrorActionPreference = 'Stop'
& (Join-Path $PSScriptRoot 'publish_ios_unsigned.ps1') -Branch 'codex/ios-personal-twitch-20261004' -SkipExport:$SkipExport
if ($LASTEXITCODE -ne 0) { throw 'Personal iOS build failed.' }
& python (Join-Path $PSScriptRoot 'personalize_twitch_ipa.py')
if ($LASTEXITCODE -ne 0) { throw 'Local Twitch provisioning failed.' }

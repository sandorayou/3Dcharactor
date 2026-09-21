"""Run the minimal executable regressions for avatar alignment and privacy."""

from pathlib import Path
import os
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]


def run(command):
    subprocess.run(command, cwd=ROOT, check=True)


def find_c_compiler():
    for name in ("tcc", "clang", "gcc"):
        found = shutil.which(name)
        if found:
            return found
    temporary_tcc = Path(os.environ.get("TEMP", "")) / "tcc-0.9.27-win64-bin" / "tcc" / "tcc.exe"
    if temporary_tcc.is_file():
        return str(temporary_tcc)
    raise RuntimeError("C compiler unavailable; run Tools/test_native_privacy.py --cc <compiler>")


def main():
    unity_managed = Path("C:/Users/81904/Documents/Xfer/2022.3.62f3/Editor/Data/Managed")
    if not (unity_managed / "UnityEngine/UnityEngine.CoreModule.dll").is_file():
        raise RuntimeError(f"Unity managed assemblies unavailable: {unity_managed}")
    run([
        "dotnet", "run", "--project", "Tools/TrackingRegression/TrackingRegression.csproj",
        f"--property:UnityManagedPath={unity_managed}", "--nologo", "--verbosity", "quiet",
    ])
    run(["pwsh", "-NoProfile", "-File", "Tools/test_tracking_recorder.ps1"])
    run([sys.executable, "-B", "Tools/test_native_privacy.py", "--cc", find_c_compiler()])
    print("PASS: avatar alignment, bounded replay logging, and selective privacy regressions")


if __name__ == "__main__":
    main()

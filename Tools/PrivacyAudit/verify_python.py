from pathlib import Path
import sys
import cv2
import numpy as np

root = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(root / "python-tracker"))
from privacy_pipeline import AdaptiveSkinMask
cases = Path(__file__).parent / "cases"
for line in (cases / "manifest.txt").read_text().splitlines():
    name, w, h, cb, cr, sc, sr = line.split()
    w, h = int(w), int(h)
    image = np.frombuffer((cases / (name + ".bgra")).read_bytes(), np.uint8).reshape(h, w, 4)
    classifier = AdaptiveSkinMask((float(cb), float(cr)), (float(sc), float(sr)))
    for _ in range(8):
        mask = classifier.classify_small(image[:, :, :3])
    assert mask.tobytes() == (cases / (name + ".mask")).read_bytes(), name
    pixel = cv2.resize(cv2.resize(image, ((w+15)//16, (h+15)//16), interpolation=cv2.INTER_AREA), (w,h), interpolation=cv2.INTER_NEAREST)
    assert pixel.tobytes() == (cases / (name + ".pixel")).read_bytes(), name
print("PASS: Python matches all six frozen native-audit fixtures")

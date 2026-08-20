from math import exp
from pathlib import Path

from PIL import Image


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "Assets/h.Textures/_18.png"
BACK_OUTPUT = ROOT / "Assets/h.Textures/_12.png"
WIDTH, HEIGHT = 512, 1024


def mix(a: float, b: float, amount: float) -> float:
    return a + (b - a) * amount


def main() -> None:
    image = Image.new("RGB", (WIDTH, HEIGHT))
    pixels = image.load()

    for y in range(HEIGHT):
        v = y / (HEIGHT - 1)
        upper_light = exp(-((v - 0.28) / 0.20) ** 2)
        lower_shadow = exp(-((v - 0.82) / 0.25) ** 2)
        for x in range(WIDTH):
            u = x / (WIDTH - 1)
            center_light = exp(-((u - 0.48) / 0.48) ** 2)
            light = 0.34 * upper_light + 0.10 * center_light - 0.18 * lower_shadow
            r = int(max(0, min(255, mix(20, 57, light))))
            g = int(max(0, min(255, mix(66, 147, light))))
            b = int(max(0, min(255, mix(73, 158, light))))
            pixels[x, y] = (r, g, b)

    image.save(OUTPUT, optimize=True)

    back = Image.open(BACK_OUTPUT).convert("RGBA")
    back_pixels = back.load()
    for y in range(back.height):
        v = y / max(1, back.height - 1)
        upper_light = exp(-((v - 0.30) / 0.24) ** 2)
        lower_shadow = exp(-((v - 0.82) / 0.28) ** 2)
        for x in range(back.width):
            _, _, _, alpha = back_pixels[x, y]
            if alpha == 0:
                continue
            u = x / max(1, back.width - 1)
            center_light = exp(-((u - 0.48) / 0.50) ** 2)
            light = 0.30 * upper_light + 0.08 * center_light - 0.16 * lower_shadow
            back_pixels[x, y] = (
                int(max(0, min(255, mix(20, 57, light)))),
                int(max(0, min(255, mix(66, 147, light)))),
                int(max(0, min(255, mix(73, 158, light)))),
                alpha,
            )
    back.save(BACK_OUTPUT, optimize=True)


if __name__ == "__main__":
    main()

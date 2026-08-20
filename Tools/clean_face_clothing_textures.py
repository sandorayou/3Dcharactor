from pathlib import Path

from PIL import Image, ImageFilter


ROOT = Path(__file__).resolve().parents[1]
TEXTURES = ROOT / "Assets/h.Textures"


def clean_clothing(name: str) -> None:
    path = TEXTURES / name
    source = Image.open(path).convert("RGBA")
    red, green, blue, alpha = source.split()
    rgb = Image.merge("RGB", (red, green, blue))

    # Remove the one-pixel fabric weave that aliases into pencil hatching at
    # VTuber framing, while retaining the wide lapel, collar, and seam shapes.
    rgb = rgb.filter(ImageFilter.MedianFilter(7))
    red, green, blue = rgb.split()
    Image.merge("RGBA", (red, green, blue, alpha)).save(path, optimize=True)


def clean_eye_line(name: str, opening_size: int) -> None:
    path = TEXTURES / name
    source = Image.open(path).convert("RGBA")
    alpha = source.getchannel("A")

    # Opening removes isolated one-pixel lash scratches. Thresholding makes
    # the retained lid/lash silhouette a single crisp graphic shape.
    alpha = alpha.filter(ImageFilter.MinFilter(opening_size))
    alpha = alpha.filter(ImageFilter.MaxFilter(opening_size))
    alpha = alpha.point(lambda value: 255 if value >= 96 else 0)

    ink = Image.new("RGBA", source.size, (43, 20, 17, 0))
    ink.putalpha(alpha)
    ink.save(path, optimize=True)


def main() -> None:
    clean_eye_line("_08.png", 3)
    clean_eye_line("_09.png", 3)


if __name__ == "__main__":
    main()

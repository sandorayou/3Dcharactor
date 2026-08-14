from pathlib import Path
import math
import random
import sys

from PIL import Image, ImageChops, ImageDraw, ImageEnhance, ImageFilter


def arg(name: str) -> Path:
    return Path(sys.argv[sys.argv.index(name) + 1]).resolve()


texture_dir = arg("--texture-dir")


def composite_color(image: Image.Image, color, alpha: int) -> Image.Image:
    layer = Image.new("RGBA", image.size, (*color, alpha))
    layer.putalpha(ImageChops.multiply(image.getchannel("A"), layer.getchannel("A")))
    return Image.alpha_composite(image, layer)


def add_hair_detail(path: Path, red: bool = False) -> None:
    original = Image.open(path).convert("RGBA")
    alpha = original.getchannel("A")
    image = ImageEnhance.Contrast(original).enhance(1.08)
    w, h = image.size
    shade = Image.new("RGBA", image.size, (0, 0, 0, 0))
    px = shade.load()
    random.seed(path.name)
    phase = random.random() * math.pi
    for y in range(h):
        vertical = y / max(1, h - 1)
        for x in range(w):
            band = (math.sin((x / w) * math.pi * 13 + phase) + 1) * 0.5
            fine = (math.sin((x / w) * math.pi * 41 + phase * 0.7) + 1) * 0.5
            highlight = max(0.0, 1.0 - abs(vertical - 0.34) / 0.18)
            strength = int(22 * band * highlight + 7 * fine)
            if red:
                px[x, y] = (255, 92, 72, strength)
            else:
                px[x, y] = (83, 201, 218, strength)
    shade.putalpha(ImageChops.multiply(alpha, shade.getchannel("A")))
    image = Image.alpha_composite(image, shade)
    # Deepen roots and undersides for readable clump separation.
    root = Image.new("RGBA", image.size, (6, 25, 34, 0))
    root_alpha = Image.new("L", image.size)
    rpx = root_alpha.load()
    for y in range(h):
        a = int(48 * max(0.0, (y / h - 0.56) / 0.44))
        for x in range(w):
            rpx[x, y] = a
    root.putalpha(ImageChops.multiply(alpha, root_alpha))
    image = Image.alpha_composite(image, root)
    image.putalpha(alpha)
    image.save(path, optimize=True)


def add_fabric_detail(path: Path, white: bool = False) -> None:
    original = Image.open(path).convert("RGBA")
    alpha = original.getchannel("A")
    image = ImageEnhance.Contrast(original).enhance(1.13)
    w, h = image.size
    tint = (205, 215, 230) if white else (22, 31, 52)
    image = composite_color(image, tint, 8 if white else 22)
    weave = Image.new("RGBA", image.size, (0, 0, 0, 0))
    draw = ImageDraw.Draw(weave)
    spacing = max(4, w // 220)
    line_color = (255, 255, 255, 7) if white else (112, 137, 170, 9)
    for offset in range(-h, w, spacing):
        draw.line((offset, 0, offset + h, h), fill=line_color, width=1)
    weave.putalpha(ImageChops.multiply(alpha, weave.getchannel("A")))
    image = Image.alpha_composite(image, weave)
    image.putalpha(alpha)
    image.save(path, optimize=True)


add_hair_detail(texture_dir / "_12.png")
add_hair_detail(texture_dir / "_18.png")
add_hair_detail(texture_dir / "_20.png", red=True)
add_hair_detail(texture_dir / "_22.png", red=True)
add_fabric_detail(texture_dir / "_13.png")
add_fabric_detail(texture_dir / "_14.png", white=True)
add_fabric_detail(texture_dir / "_15.png")
add_fabric_detail(texture_dir / "_16.png")

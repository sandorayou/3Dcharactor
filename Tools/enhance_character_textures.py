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


def add_face_detail(path: Path) -> None:
    image = Image.open(path).convert("RGBA")
    w, h = image.size
    overlay = Image.new("RGBA", image.size, (0, 0, 0, 0))
    draw = ImageDraw.Draw(overlay)
    # Soft blush and eye-socket warmth, positioned on the existing VRoid face UV.
    for cx in (w * 0.355, w * 0.645):
        draw.ellipse((cx - w * 0.105, h * 0.59, cx + w * 0.105, h * 0.745), fill=(240, 103, 116, 29))
        draw.ellipse((cx - w * 0.075, h * 0.535, cx + w * 0.075, h * 0.63), fill=(178, 77, 90, 13))
    # Minimal nose definition that remains subtle in front-facing toon lighting.
    draw.ellipse((w * 0.487, h * 0.625, w * 0.513, h * 0.695), fill=(255, 240, 226, 30))
    draw.arc((w * 0.485, h * 0.65, w * 0.515, h * 0.71), 20, 160, fill=(172, 79, 84, 35), width=max(1, w // 512))
    overlay = overlay.filter(ImageFilter.GaussianBlur(w * 0.018))
    image = Image.alpha_composite(image, overlay)
    image.putalpha(Image.open(path).convert("RGBA").getchannel("A"))
    image.save(path, optimize=True)


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


add_face_detail(texture_dir / "_04.png")
add_hair_detail(texture_dir / "_12.png")
add_hair_detail(texture_dir / "_18.png")
add_hair_detail(texture_dir / "_20.png", red=True)
add_hair_detail(texture_dir / "_22.png", red=True)
add_fabric_detail(texture_dir / "_13.png")
add_fabric_detail(texture_dir / "_14.png", white=True)
add_fabric_detail(texture_dir / "_15.png")
add_fabric_detail(texture_dir / "_16.png")

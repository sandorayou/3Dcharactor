from pathlib import Path
import math
import random
import sys

from PIL import Image, ImageChops, ImageDraw, ImageEnhance, ImageFilter, ImageOps


def arg(name: str) -> Path:
    return Path(sys.argv[sys.argv.index(name) + 1]).resolve()


texture_dir = arg("--texture-dir")
hair_reference = arg("--hair-reference") if "--hair-reference" in sys.argv else None
hair_only = "--hair-only" in sys.argv


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
            strength = int(8 * band * highlight + 2 * fine)
            if red:
                px[x, y] = (255, 92, 72, strength)
            else:
                px[x, y] = (83, 201, 218, strength)
    shade.putalpha(ImageChops.multiply(alpha, shade.getchannel("A")))
    image = Image.alpha_composite(image, shade)
    if hair_reference and not red:
        reference = ImageOps.fit(
            Image.open(hair_reference).convert("RGB"), image.size,
            method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
        reference = ImageEnhance.Color(reference).enhance(0.7)
        reference = ImageEnhance.Brightness(reference).enhance(0.72)
        reference.putalpha(alpha)
        # The generated texture supplies detailed strand structure; retaining most
        # of the original keeps the established teal palette and toon readability.
        image = Image.blend(image, reference, 0.58)
    # Deepen roots and undersides for readable clump separation.
    root = Image.new("RGBA", image.size, (6, 25, 34, 0))
    root_alpha = Image.new("L", image.size)
    rpx = root_alpha.load()
    for y in range(h):
        a = int(30 * max(0.0, (y / h - 0.56) / 0.44))
        for x in range(w):
            rpx[x, y] = a
    root.putalpha(ImageChops.multiply(alpha, root_alpha))
    image = Image.alpha_composite(image, root)
    image.putalpha(alpha)
    image.save(path, optimize=True)


def add_fabric_detail(path: Path, white: bool = False, stitched: bool = False, satin: bool = False) -> None:
    original = Image.open(path).convert("RGBA")
    alpha = original.getchannel("A")
    base = original if white else ImageEnhance.Brightness(original).enhance(0.78)
    image = ImageEnhance.Contrast(base).enhance(1.24 if not white else 1.12)
    w, h = image.size
    tint = (205, 215, 230) if white else (22, 31, 52)
    image = composite_color(image, tint, 8 if white else 22)
    weave = Image.new("RGBA", image.size, (0, 0, 0, 0))
    draw = ImageDraw.Draw(weave)
    spacing = max(4, w // 220)
    line_color = (255, 255, 255, 8) if white else (112, 137, 170, 16)
    for offset in range(-h, w, spacing):
        draw.line((offset, 0, offset + h, h), fill=line_color, width=1)
    weave.putalpha(ImageChops.multiply(alpha, weave.getchannel("A")))
    image = Image.alpha_composite(image, weave)
    if satin:
        gloss = Image.new("RGBA", image.size, (0, 0, 0, 0))
        gdraw = ImageDraw.Draw(gloss)
        for x in range(-w, w * 2, max(12, w // 28)):
            gdraw.line((x, h, x + w // 3, 0), fill=(185, 205, 235, 13), width=max(2, w // 420))
        gloss = gloss.filter(ImageFilter.GaussianBlur(max(1, w // 500)))
        gloss.putalpha(ImageChops.multiply(alpha, gloss.getchannel("A")))
        image = Image.alpha_composite(image, gloss)
    if stitched:
        gray = original.convert("L")
        edges = gray.filter(ImageFilter.FIND_EDGES).filter(ImageFilter.GaussianBlur(0.7))
        edges = edges.point(lambda value: min(150, max(0, (value - 12) * 4)))
        dash = Image.new("L", image.size)
        dpx = dash.load()
        for y in range(h):
            for x in range(w):
                dpx[x, y] = 255 if ((x + y) // max(8, w // 190)) % 2 == 0 else 0
        stitch_mask = ImageChops.multiply(ImageChops.multiply(edges, dash), alpha)
        stitches = Image.new("RGBA", image.size, (142, 22, 32, 0))
        stitches.putalpha(stitch_mask.point(lambda value: min(24, value)))
        image = Image.alpha_composite(image, stitches)
    image.putalpha(alpha)
    image.save(path, optimize=True)


add_hair_detail(texture_dir / "_12.png")
add_hair_detail(texture_dir / "_18.png")
if not hair_only:
    add_hair_detail(texture_dir / "_20.png", red=True)
    add_hair_detail(texture_dir / "_22.png", red=True)
    add_fabric_detail(texture_dir / "_13.png", satin=True)
    add_fabric_detail(texture_dir / "_14.png", white=True)
    add_fabric_detail(texture_dir / "_15.png", stitched=True, satin=True)
    add_fabric_detail(texture_dir / "_16.png", stitched=True)

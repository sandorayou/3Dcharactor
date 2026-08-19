from pathlib import Path
import sys

from PIL import Image, ImageChops, ImageFilter


def value(name: str) -> Path:
    return Path(sys.argv[sys.argv.index(name) + 1]).resolve()


source_path = value("--source")
generated_path = value("--generated")
output_path = value("--output")

source = Image.open(source_path).convert("RGBA")
generated = Image.open(generated_path).convert("RGB")
alpha = source.getchannel("A")

# Bounding boxes are derived from the two UV islands in the original alpha map.
left_half = alpha.crop((0, 0, source.width // 2, source.height))
right_half = alpha.crop((source.width // 2, 0, source.width, source.height))
left_box = left_half.getbbox()
right_local = right_half.getbbox()
if not left_box or not right_local:
    raise RuntimeError("The source eye atlas does not contain both iris UV islands")
right_box = (
    right_local[0] + source.width // 2,
    right_local[1],
    right_local[2] + source.width // 2,
    right_local[3],
)

# Crop the two generated irises. These regions intentionally exclude the black
# atlas background and are fitted back into the exact original UV islands.
gw, gh = generated.size
if gw > gh:
    generated_boxes = (
        (int(gw * 0.152), int(gh * 0.225), int(gw * 0.366), int(gh * 0.744)),
        (int(gw * 0.635), int(gh * 0.225), int(gw * 0.847), int(gh * 0.744)),
    )
else:
    generated_boxes = (
        (int(gw * 0.025), int(gh * 0.265), int(gw * 0.46), int(gh * 0.58)),
        (int(gw * 0.53), int(gh * 0.265), int(gw * 0.965), int(gh * 0.58)),
    )

result = Image.new("RGBA", source.size, (0, 0, 0, 0))
for target_box, generated_box in zip((left_box, right_box), generated_boxes):
    width = target_box[2] - target_box[0]
    height = target_box[3] - target_box[1]
    iris = generated.crop(generated_box).resize((width, height), Image.Resampling.LANCZOS)
    mask = alpha.crop(target_box)
    # Preserve a clean antialiased edge while keeping the original UV silhouette.
    mask = ImageChops.multiply(mask, mask.filter(ImageFilter.GaussianBlur(0.35)))
    iris.putalpha(mask)
    result.alpha_composite(iris, (target_box[0], target_box[1]))

output_path.parent.mkdir(parents=True, exist_ok=True)
result.save(output_path, optimize=True)

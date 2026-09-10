from pathlib import Path

from PIL import Image, ImageDraw


ROOT = Path(__file__).resolve().parents[1]


def reinforce_iris() -> None:
    path = ROOT / "Assets/h.Textures/_02.png"
    image = Image.open(path).convert("RGBA")
    draw = ImageDraw.Draw(image)
    ink = (20, 7, 5, 255)

    # These ellipses follow the two irises in the original VRM atlas.  Drawing
    # them into the atlas makes the outer iris and pupil separation survive
    # Unity lighting, camera scaling, and facial animation.
    for iris, pupil in (
        ((141, 129, 375, 389), (225, 222, 298, 296)),
        ((648, 129, 882, 389), (733, 222, 806, 296)),
    ):
        draw.ellipse(iris, outline=ink, width=12)
        draw.ellipse(pupil, outline=ink, width=9)

    image.save(path, optimize=True)


if __name__ == "__main__":
    reinforce_iris()

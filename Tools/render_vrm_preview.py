import bpy
import math
import sys
from pathlib import Path
from mathutils import Vector


def argv_value(name: str) -> str:
    args = sys.argv[sys.argv.index("--") + 1 :]
    return args[args.index(name) + 1]


source = Path(argv_value("--input")).resolve()
output = Path(argv_value("--output")).resolve()
args = sys.argv[sys.argv.index("--") + 1 :]
eye_texture = Path(argv_value("--eye-texture")).resolve() if "--eye-texture" in args else None
texture_dir = Path(argv_value("--texture-dir")).resolve() if "--texture-dir" in args else None
output.parent.mkdir(parents=True, exist_ok=True)

bpy.ops.wm.read_factory_settings(use_empty=True)
bpy.ops.import_scene.gltf(filepath=str(source), import_shading="NORMALS")

if eye_texture:
    replacement = bpy.data.images.load(str(eye_texture), check_existing=False)
    for material in bpy.data.materials:
        if "EyeIris" not in material.name or not material.use_nodes:
            continue
        for node in material.node_tree.nodes:
            if node.type == "TEX_IMAGE" and node.image:
                node.image = replacement

if texture_dir:
    material_textures = {
        "Face_00_SKIN": "_04.png",
        "HairBack_00_HAIR": "_12.png",
        "Hair_00_HAIR_01": "_18.png",
        "Hair_00_HAIR_02": "_20.png",
        "Hair_00_HAIR_03": "_22.png",
        "Tops_01_CLOTH_01": "_13.png",
        "Tops_01_CLOTH_02": "_14.png",
        "Tops_01_CLOTH_03": "_15.png",
        "Bottoms_01_CLOTH": "_16.png",
    }
    for material in bpy.data.materials:
        match = next((filename for key, filename in material_textures.items() if key in material.name), None)
        if not match or not material.use_nodes:
            continue
        replacement = bpy.data.images.load(str(texture_dir / match), check_existing=False)
        for node in material.node_tree.nodes:
            if node.type == "TEX_IMAGE" and node.image:
                node.image = replacement

meshes = [obj for obj in bpy.context.scene.objects if obj.type == "MESH"]
if not meshes:
    raise RuntimeError("No meshes were imported from the VRM/GLB file")

points = []
for obj in meshes:
    points.extend(obj.matrix_world @ Vector(corner) for corner in obj.bound_box)
minimum = Vector((min(p.x for p in points), min(p.y for p in points), min(p.z for p in points)))
maximum = Vector((max(p.x for p in points), max(p.y for p in points), max(p.z for p in points)))
height = maximum.z - minimum.z
target = Vector(((minimum.x + maximum.x) * 0.5, (minimum.y + maximum.y) * 0.5, minimum.z + height * 0.885))

camera_data = bpy.data.cameras.new("Portrait Camera")
camera = bpy.data.objects.new("Portrait Camera", camera_data)
bpy.context.collection.objects.link(camera)
bpy.context.scene.camera = camera
camera_data.lens = 72
camera.location = target + Vector((0.0, height * 0.28, height * 0.02))


def point_at(obj, destination):
    obj.rotation_euler = (destination - obj.location).to_track_quat("-Z", "Y").to_euler()


point_at(camera, target)

world = bpy.data.worlds.new("Studio World")
bpy.context.scene.world = world
world.use_nodes = True
world.node_tree.nodes["Background"].inputs["Color"].default_value = (0.025, 0.035, 0.05, 1)
world.node_tree.nodes["Background"].inputs["Strength"].default_value = 0.28


def area_light(name, location, energy, size, color):
    data = bpy.data.lights.new(name, "AREA")
    data.energy = energy
    data.shape = "DISK"
    data.size = size
    data.color = color
    obj = bpy.data.objects.new(name, data)
    bpy.context.collection.objects.link(obj)
    obj.location = location
    point_at(obj, target)


area_light("Key", target + Vector((-height * 0.55, height * 0.45, height * 0.45)), 900, height * 0.65, (1.0, 0.82, 0.72))
area_light("Fill", target + Vector((height * 0.55, height * 0.25, height * 0.1)), 500, height * 0.8, (0.62, 0.8, 1.0))
area_light("Rim", target + Vector((0, -height * 0.2, height * 0.55)), 1100, height * 0.5, (0.55, 0.8, 1.0))

scene = bpy.context.scene
scene.render.engine = "BLENDER_EEVEE"
scene.render.resolution_x = 1024
scene.render.resolution_y = 1024
scene.render.resolution_percentage = 100
scene.render.image_settings.file_format = "PNG"
scene.render.filepath = str(output)
scene.render.film_transparent = False
scene.render.image_settings.color_mode = "RGBA"
scene.view_settings.look = "AgX - Medium High Contrast"
scene.render.resolution_percentage = 100
bpy.ops.wm.save_as_mainfile(filepath=str(output.with_suffix(".blend")))
bpy.ops.render.render(write_still=True)

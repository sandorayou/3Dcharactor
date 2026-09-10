"""Add HaishinKit's RTMP product to a generated Unity Xcode project."""
from pathlib import Path
import re
import sys
import uuid

URL = "https://github.com/HaishinKit/HaishinKit.swift"
PRODUCT = "RTMPHaishinKit"


def ident() -> str:
    return uuid.uuid4().hex[:24].upper()


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: add_haishinkit_spm.py path/to/Unity-iPhone.xcodeproj", file=sys.stderr)
        return 2
    pbx = Path(sys.argv[1]) / "project.pbxproj"
    text = pbx.read_text(encoding="utf-8")
    if PRODUCT in text and URL in text:
        return 0

    package_id, product_id = ident(), ident()
    package_block = (
        f"\t\t{package_id} /* XCRemoteSwiftPackageReference \"HaishinKit.swift\" */ = {{\n"
        f"\t\t\tisa = XCRemoteSwiftPackageReference;\n"
        f"\t\t\trepositoryURL = \"{URL}\";\n"
        "\t\t\trequirement = {\n"
        "\t\t\t\tkind = upToNextMajorVersion;\n"
        "\t\t\t\tminimumVersion = 2.0.0;\n"
        "\t\t\t};\n\t\t};\n"
    )
    product_block = (
        f"\t\t{product_id} /* XCSwiftPackageProductDependency {PRODUCT} */ = {{\n"
        "\t\t\tisa = XCSwiftPackageProductDependency;\n"
        f"\t\t\tpackage = {package_id} /* XCRemoteSwiftPackageReference \"HaishinKit.swift\" */;\n"
        f"\t\t\tproductName = {PRODUCT};\n\t\t}};\n"
    )
    text = text.replace("/* End XCRemoteSwiftPackageReference section */", package_block + "\t\t/* End XCRemoteSwiftPackageReference section */")
    text = text.replace("/* End XCSwiftPackageProductDependency section */", product_block + "\t\t/* End XCSwiftPackageProductDependency section */")

    project_match = re.search(r"([A-F0-9]{24}) /\* Project object \*/ = \{", text)
    if not project_match:
        raise SystemExit("PBXProject object not found")
    project_end = text.find("projectDirPath =", project_match.end())
    package_refs = "\n\t\t\tpackageReferences = (\n\t\t\t\t%s /* XCRemoteSwiftPackageReference \\\"HaishinKit.swift\\\" */,\n\t\t\t);" % package_id
    text = text[:project_end] + package_refs + "\n\t\t\t" + text[project_end:]

    # Unity 2022 exports name="Unity-iPhone" but productName="iPhone-target".
    target_match = re.search(r"isa = PBXNativeTarget;[\s\S]*?name = \"Unity-iPhone\";", text)
    if not target_match:
        raise SystemExit("Unity-iPhone PBXNativeTarget not found")
    target_end = text.find("name = \"Unity-iPhone\";", target_match.end())
    dependency = "\n\t\t\tpackageProductDependencies = (\n\t\t\t\t%s /* XCSwiftPackageProductDependency %s */,\n\t\t\t);" % (product_id, PRODUCT)
    text = text[:target_end] + dependency + "\n\t\t\t" + text[target_end:]
    pbx.write_text(text, encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

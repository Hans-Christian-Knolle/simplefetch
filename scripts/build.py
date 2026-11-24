#!/usr/bin/env python3
"""Configure and build simplefetch into build/."""

import subprocess
import sys

from shared import *


def main() -> int:
    try:
        subprocess.run(["cmake", "-S", str(ROOT), "-B", str(BUILD_DIR)], check=True)
        subprocess.run(["cmake", "--build", str(BUILD_DIR), "--parallel"], check=True)
    except subprocess.CalledProcessError as error:
        return error.returncode
    print(f"Built: {BUILD_DIR / 'simplefetch'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

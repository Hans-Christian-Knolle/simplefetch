#!/usr/bin/env python3
"""Create a timestamped archive of src/ in backup/."""

import tarfile
from datetime import datetime
from pathlib import Path

from shared import *


def main() -> Path:
    BACKUP_DIR.mkdir(exist_ok=True)
    stamp = datetime.now().strftime("%d-%m-%Y-%H-%M-%S")
    archive = BACKUP_DIR / f"backup-{stamp}.bak"
    with tarfile.open(archive, "w:gz") as tar:
        tar.add(SRC_DIR, arcname="src")
    return archive


if __name__ == "__main__":
    print(f"Created: {main()}")

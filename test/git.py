import os

import subprocess
process = subprocess.Popen(["git", "pull"], stdout=subprocess.PIPE)
output = process.communicate()[0]
os.walk("d:/rong_plus")
from pathlib import Path

p = Path('d:/rong_plus')
for f in p.iterdir():
     if f.is_dir():
            print(f)
            
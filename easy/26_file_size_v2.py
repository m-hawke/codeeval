import sys
import os

print(os.stat(sys.argv[1]).st_size)

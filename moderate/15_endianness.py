import struct

if struct.pack('@h', 1) == struct.pack('<h', 1):
    print("LittleEndian")
else:
    print("BigEndian")

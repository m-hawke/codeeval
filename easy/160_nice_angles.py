import sys

for n in open(sys.argv[1]):
    degrees = float(n)
    minutes = (degrees % 1) * 60
    seconds = (minutes % 1) * 60
    print('{}.{:02d}\'{:02d}"'.format(int(degrees), int(minutes), int(seconds)))

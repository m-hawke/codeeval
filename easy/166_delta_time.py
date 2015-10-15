import sys

for line in open(sys.argv[1]):
    d1, d2 = line.split()

    h, m, s = [int(x) for x in d1.split(':')]
    d1_seconds = h*3600 + m*60 + s
    h, m, s = [int(x) for x in d2.split(':')]
    d2_seconds = h*3600 + m*60 + s

    hours, _seconds = divmod(abs(d1_seconds - d2_seconds), 3600)
    minutes, seconds = divmod(_seconds, 60)
    print('{:02d}:{:02d}:{:02d}'.format(hours, minutes, seconds))

# using datetime module for this is slow
#from datetime import datetime
#
#for line in open(sys.argv[1]):
#    d1, d2 = sorted(line.split())
#    delta = datetime.strptime(d2, '%H:%M:%S') - datetime.strptime(d1, '%H:%M:%S')
#    hours, _seconds = divmod(delta.seconds, 3600)
#    minutes, seconds = divmod(_seconds, 60)
#    print('{:02d}:{:02d}:{:02d}'.format(hours, minutes, seconds))

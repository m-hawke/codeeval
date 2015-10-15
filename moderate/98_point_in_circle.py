import sys
import string
import math

for line in open(sys.argv[1]):
    # strip out unwanted characters and convert numbers to floats
    data = [float(x) for x in
                line.translate(None, string.ascii_letters + ':(,);\n').split()]
    centre = data[0:2]
    radius = data[2]
    point = data[3:5]

    # calculate distance from the point to the centre
    distance = math.sqrt(((point[0]-centre[0]) ** 2) +
                         ((point[1]-centre[1]) ** 2))

    # point is inside the circle if it is within the radius
    print(str(distance <= radius).lower())

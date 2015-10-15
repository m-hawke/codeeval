import sys
from ast import literal_eval

for line in open(sys.argv[1]):
#    line = line.translate(None, '[]()\r\n')        # remove parens and brackets
    line = line.translate({ord(c):None for c in '[]()\r\n'})
    hole, bricks = line.split('|')

    hole_1, hole_2 = [literal_eval(point) for point in hole.split()]
    hole_width = abs(hole_1[0] - hole_2[0])
    hole_height = abs(hole_1[1] - hole_2[1])

    result = []
    for brick in bricks.split(';'):
        idx, vertex_1, vertex_2 = [literal_eval(s) for s in brick.split()]
        width = abs(vertex_1[0] - vertex_2[0])
        height = abs(vertex_1[1] - vertex_2[1])
        depth = abs(vertex_1[2] - vertex_2[2])
        if ((width <= hole_width and height <= hole_height) or
            (width <= hole_height and height <= hole_width) or
            (width <= hole_width and depth <= hole_height) or
            (width <= hole_height and depth <= hole_width) or
            (depth <= hole_width and height <= hole_height) or
            (depth <= hole_height and height <= hole_width)):
            result.append(idx)
    print(','.join(str(x) for x in sorted(result)) if result else '-')


#import sys
#from ast import literal_eval
#
#for line in open(sys.argv[1]):
#    line = line.translate(None, '[]()\r\n')        # remove parens and brackets
#    hole, bricks = line.split('|')
#
#    hole_1, hole_2 = [literal_eval(point) for point in hole.split()]
#    width = abs(hole_1[0] - hole_2[0])
#    height = abs(hole_1[1] - hole_2[1])
#    hole_dimensions = (width, height) if width < height else (height, width)
#
#    result = []
#    for brick in bricks.split(';'):
#        idx, vertex_1, vertex_2 = [literal_eval(s) for s in brick.split()]
#        width = abs(vertex_1[0] - vertex_2[0])
#        height = abs(vertex_1[1] - vertex_2[1])
#        depth = abs(vertex_1[2] - vertex_2[2])
#        brick_dimensions = sorted((width, height, depth))
#        if ((brick_dimensions[0] <= hole_dimensions[0]) and
#            (brick_dimensions[1] <= hole_dimensions[1])):
#            result.append(idx)
#    print(','.join(str(x) for x in sorted(result)) if result else '-')

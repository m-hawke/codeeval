import sys
#from ast import literal_eval

for line in open(sys.argv[1]):
#    points = literal_eval(line)
    points = eval(line)    # unsafe but faster than literal_eval
    p1 = points[0]

    # don't bother with taking square roots; comparing the squared distances
    # is fine.
    distances = sorted([(p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2
                            for p2 in points[1:]])

    is_square = ((distances[0] == distances[1]) and
                 ((distances[0] + distances[1]) == distances[2]) and
                 (distances[0] > 0))
    print(str(is_square).lower())


## Another method using vector rotation and addition. Runs slightly faster
## locally, but slightly slower and with more memory on codeeval.
#import sys
#
#for line in open(sys.argv[1]):
#    p1, p2, p3, p4 = eval(line)
#
#    # calculate vectors from p1
#    v1 = (p2[0]-p1[0], p2[1]-p1[1]) # p1->p2
#    v2 = (p3[0]-p1[0], p3[1]-p1[1]) # p1->p3
#    v3 = (p3[0]-p2[0], p3[1]-p2[1]) # p2->p3
#
#    is_square = False
#
#    if (0,0) not in (v1, v2, v3):
#        # Check for any orthogonal vectors by vector rotation
#        if ((v1[1], -v1[0]) == v2) or ((-v1[1], v1[0]) == v2):
#            # v1 and v2 are orthogonal
#            is_square = (p2[0]+v2[0], p2[1]+v2[1]) == p4
#        elif ((v1[1], -v1[0]) == v3) or ((-v1[1], v1[0]) == v3):
#            # v1 and v3 are orthogonal
#            is_square = (p4[0]+v1[0], p4[1]+v1[1]) == p3
#        elif ((v2[1], -v2[0]) == v3) or ((-v2[1], v2[0]) == v3):
#            # v2 and v3 are orthogonal
#            is_square = (p4[0]+v3[0], p4[1]+v3[1]) == p1
#
#    print(str(is_square).lower())

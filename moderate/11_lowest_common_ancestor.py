import sys
    
# N.B. depths of ancestor nodes '30', '8', and '20' are deliberately set 1
# level higher because these nodes can be their own lowest ancestor.
tree_depths = {'30':1, '8':2, '52':1, '3':2, '20':3, '10':3, '29':3}
depth_to_ancestor = {-1: '30', 0: '30', 1: '8', 2: '20'}

for line in sys.stdin:
    node1, node2 = line.split()
    print(depth_to_ancestor[min(tree_depths[node1], tree_depths[node2]) - 1])


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024

int get_depth(int node) {
    /* N.B. depths of ancestor nodes '30', '8', and '20' are deliberately set 1
     * level higher because these nodes can be their own lowest ancestor. */
    switch (node) {
        case 30:
            return 1;
        case 8:
            return 2;
        case 52:
            return 1;
        case 3:
            return 2;
        case 20:
            return 3;
        case 10:
            return 3;
        case 29:
            return 3;
        default:
            return -1;
    }
}

int depth_to_ancestor(int depth) {
    switch (depth) {
        case -1:
        case 0:
            return 30;
        case 1:
            return 8;
        case 2:
            return 20;
        default:
            return -1;
    }
}

int min(int i1, int i2) {
    if (i1 > i2)
        return i2;
    return i1;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        int node1, node2;
        sscanf(line, "%d %d", &node1, &node2);

        printf("%d\n", depth_to_ancestor(min(get_depth(node1), get_depth(node2)) - 1));
    }

    return 0;
}

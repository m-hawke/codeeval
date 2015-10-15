#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_SIZE       1024
#define MAX_DIMENSION   3
#define MAX_BRICKS      15

typedef struct point {
    int dimensions;     /* 0, 1, 2, ..., MAX_DIMENSION */
    int values[MAX_DIMENSION];
} POINT;

int parse_point(char *s, POINT *point) {
    /* A point begins with left bracket, contains a series of comma separated
     * numbers and ends with a right bracket */

    char *p = s;

    while (*p && (*p != '['))
        p++;
    if (!*p)
        return 0;  /* no left bracket seen */
    p++;

    point->dimensions = 0;
    while (*p) {
        point->values[point->dimensions++] = atoi(p);
        if (p = strpbrk(p, ",]")) {
            if (*p == ']')
                break;
            p++;
        }
        else
            break;
    }
}

void print_point(POINT point) {
    printf("%dD: (", point.dimensions);
    for (int i=0; i<point.dimensions; i++)
        printf("%s%d", (i==0) ? "": ",", point.values[i]);
    printf(")\n");
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;

    while (fgets(line, LINE_SIZE, file)) {
        char *p = index(line, '|');
        *p = '\0';
        char *hole = line;
        char *bricks = p+1;
//        printf("hole: '%s', bricks: '%s'\n", hole, bricks);

        POINT hole_vertex1, hole_vertex2;
        p = hole;
        parse_point(p, &hole_vertex1);
        p = index(p, ' ');
        parse_point(++p, &hole_vertex2);

//        print_point(hole_vertex1);
//        print_point(hole_vertex2);
        int hole_width = abs(hole_vertex1.values[0] - hole_vertex2.values[0]);
        int hole_height = abs(hole_vertex1.values[1] - hole_vertex2.values[1]);
//        printf("%d X %d\n", hole_width, hole_height);

        int fitting_bricks[MAX_BRICKS+1] = {0};

        for (token=strtok(bricks, "("); token!=NULL; token=strtok(NULL, "(")) {
            int brick_idx = atoi(token);
            POINT vertex1, vertex2;
            token = index(token, ' ');
            parse_point(++token, &vertex1);
            token = index(token, ' ');
            parse_point(++token, &vertex2);

//            print_point(vertex1);
//            print_point(vertex2);
            int width = abs(vertex1.values[0] - vertex2.values[0]);
            int height = abs(vertex1.values[1] - vertex2.values[1]);
            int depth = abs(vertex1.values[2] - vertex2.values[2]);

            if ((width <= hole_width && height <= hole_height) ||
                (width <= hole_height && height <= hole_width) ||
                (width <= hole_width && depth <= hole_height) ||
                (width <= hole_height && depth <= hole_width) ||
                (depth <= hole_width && height <= hole_height) ||
                (depth <= hole_height && height <= hole_width))
                fitting_bricks[brick_idx] = 1;   /* N.B. brick_idx is 1-based */
        }

        int n = 0;
        for (int i=1; i<=MAX_BRICKS; i++) {
            if (fitting_bricks[i])
                n = printf("%s%d", n ? "," : "", i);
        }

        if (n == 0) /* no bricks fit */
            printf("-\n");
        else
            printf("\n");
    }

    return 0;
}

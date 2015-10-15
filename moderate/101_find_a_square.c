#include <stdio.h>
#include <string.h>

#define LINE_SIZE   1024

typedef struct point {
    int x;
    int y;
} POINT;

typedef POINT VECTOR;
#define ZERO_VECTOR (VECTOR){0,0}

int points_equal(POINT p1, POINT p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}
#define vectors_equal   points_equal

int orthogonal(VECTOR v1, VECTOR v2) {
    return (vectors_equal((VECTOR){v1.y, -v1.x}, v2) ||
            vectors_equal((VECTOR){-v1.y, v1.x}, v2));
}

VECTOR add_vectors(VECTOR v1, VECTOR v2) {
    return (VECTOR){v1.x + v2.x, v1.y + v2.y};
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    POINT p1, p2, p3, p4;
    VECTOR v1, v2, v3;       /* vectors p1->p2, p1->p3, p2->p3 */

    while (fgets(line, LINE_SIZE, file)) {
        int is_square = 0;

        sscanf(line, "(%d,%d), (%d,%d), (%d,%d), (%d,%d)",
                    &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);

        v1.x = p2.x - p1.x; v1.y = p2.y - p1.y;     // p1->p2
        v2.x = p3.x - p1.x; v2.y = p3.y - p1.y;     // p1->p3
        v3.x = p3.x - p2.x; v3.y = p3.y - p2.y;     // p2->p3

        if (!vectors_equal(v1, ZERO_VECTOR) &&
            !vectors_equal(v1, ZERO_VECTOR) &&
            !vectors_equal(v1, ZERO_VECTOR)) {
            if (orthogonal(v1, v2))
                is_square = points_equal(add_vectors(p2, v2), p4);
            else if (orthogonal(v1, v3))
                is_square = points_equal(add_vectors(p4, v1), p3);
            else if (orthogonal(v2, v3))
                is_square = points_equal(add_vectors(p4, v3), p1);
        }

        printf(is_square ? "true\n" : "false\n");
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    float centre_x, centre_y, radius, point_x, point_y;

    while (fgets(line, 1024, file)) {
        sscanf(line, "Center: (%f, %f); Radius: %f; Point: (%f, %f)",
                &centre_x, &centre_y, &radius, &point_x, &point_y);

        /* calculate distance from the point to the centre */
        float distance = sqrt(pow(point_x - centre_x, 2) +
                              pow(point_y - centre_y, 2));

        /* point is inside the circle if it is within the radius */
        printf("%s\n", (distance <= radius) ? "true" : "false");
    }

    return 0;
}

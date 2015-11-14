#include <stdio.h>

#define LINE_LEN        1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    /* The magic numbers between 0 and 10,000 inclusive. See
     * 193_magic_numbers.py for how these were generated */
    int magic_numbers[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 15, 17, 19, 31, 35, 37, 39, 51, 53, 57,
        59, 71, 73, 75, 79, 91, 93, 95, 97, 147, 174, 258, 285, 417, 471, 528,
        582, 714, 741, 825, 852, 1263, 1267, 1623, 1627, 2316, 2356, 2396,
        2631, 2635, 2639, 2671, 2675, 2679, 2716, 2756, 2796, 3126, 3162, 3526,
        3562, 3926, 3962, 5263, 5267, 5623, 5627, 6231, 6235, 6239, 6271, 6275,
        6279, 6312, 6352, 6392, 6712, 6752, 6792, 7126, 7162, 7526, 7562, 7926,
        7962, 9263, 9267, 9623, 9627
    };
    int A, B;

    while (fgets(line, LINE_LEN, file)) {
        sscanf(line, "%d %d", &A, &B);
        int print_space = 0;
        for (int i=0; i<sizeof(magic_numbers)/sizeof(int); i++) {
            if ((A <= magic_numbers[i]) && (magic_numbers[i] <= B))
                print_space = printf("%s%d", print_space ? " " : "", magic_numbers[i]);
        }
        if (!print_space)   /* nothing was printed hence no magic numbers */
            printf("-1");
        printf("\n");
    }

    return 0;
}

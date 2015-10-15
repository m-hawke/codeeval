#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char C, N;
    int c, n;
    int delta_c[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int delta_n[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (fgets(line, 1024, file)) {
        sscanf(line, "%c%c", &C, &N);
        int is_first = 1;
        for (int i=0; i<sizeof(delta_c)/sizeof(int); i++) {
            c = C + delta_c[i];
            n = N + delta_n[i];
            if ((c >= 'a' && c <= 'h') && (n >= '1' && n <= '8')) {
                printf("%s%c%c", (is_first) ? "" : " ", c, n);
                is_first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}

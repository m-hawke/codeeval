#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_floats(const void *f1, const void *f2) {
    float l, r;

    l = *(float *)f1;
    r = *(float *)f2;

    if (l < r)
        return -1;
    else if (l > r)
        return 1;
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int i;
    float f;
    float numbers[20];

    while (fgets(line, 1024, file)) {
        for (i=0,token=strtok(line, " "); token!=NULL; i++,token=strtok(NULL, " ")) {
            numbers[i] = atof(token);
//            printf("%d: %.3f\n", i, numbers[i]);
        }

        qsort((void *)numbers, i, sizeof(float), cmp_floats);
        for (int n=0; n<i; n++)
            printf("%.3f%s", numbers[n], (n==(i-1)) ? "" : " ");
        printf("\n");
    }

    return 0;
}

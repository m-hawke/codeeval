#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int length;
    int k;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    /* remove new line */

        length = strlen(line);
        for (k=1; k<=length/2; k++) {
            if ((length % k) == 0) {        /* only try equal length segments */
                int i;
                int equal;

                /* check whether all k-length segments are equal */
                for (i=k, equal=1; (i<length) && equal; i+=k)
                    equal = (strncmp(&line[i], line, k) == 0);
                if (equal) {
                    printf("%d\n", k);
                    break;
                }
            }
        }
        if (k > length/2)
            printf("%d\n", length);
    }

    return 0;
}

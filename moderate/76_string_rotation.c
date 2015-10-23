#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define LINE_LEN    1024

char *_rotate(char *s, int n) {
    int len = strlen(s);

    if (len > 0) {
        char *copy = strdup(s);
        if (n < 0)
            n += len;       /* make negative rotation positive */
        n = n % len;
        strncpy(s, copy+(len-n), n);
        strncpy(s+n, copy, len-n);
        free(copy);
    }

    return s;
}

char *rotate(char *s, int n) {
    int len = strlen(s);

    if (len > 0) {
        char copy[len];         /* N.B. variable-sized array */
        strcpy(copy, s);
        if (n < 0)
            n += len;           /* make negative rotation positive */
        n = n % len;
        strncpy(s, copy+(len-n), n);
        strncpy(s+n, copy, len-n);
    }

    return s;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int is_a_rotation = 0;
        char *b = index(line, ',');
        *b++ = '\0';
        char *a = line;

        char *p = index(b, a[0]);
        if (p) {
            int initial_rotation = (int)(p-b);
            rotate(a, initial_rotation);
            for (int i=0; i<strlen(a)-initial_rotation; i++) {
                if (!strcmp(a, b)) {
                    is_a_rotation = 1;
                    break;
                }
                rotate(a, 1);
            }
        }

        printf(is_a_rotation ? "True\n" : "False\n");
    }

    return 0;
}

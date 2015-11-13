#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char *token;
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        char *p = rindex(line, ';');
        int k = atoi(p+1);
        *p = '\0';

        int item = 0;
        char *items[k];     /* N.B variable-sized array */
        int print_comma = 0;
        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            items[item++] = token;
            /* print these k items in reverse order */
            if (item % k == 0) {
                for (int i=k-1; i>=0; i--)
                    print_comma = printf("%s%s", print_comma ? "," : "",
                                            items[i]);
                item = 0;
            }
        }

        /* print any remaining items without reversing */
        if (item > 0)
            for (int i=0; i<item; i++)
                print_comma = printf("%s%s", print_comma ? "," : "", items[i]);

        printf("\n");
    }

    return 0;
}

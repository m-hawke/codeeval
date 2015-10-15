#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int history[100];
    int history_length;
    int cyclic;
    int n;

    while (fgets(line, 1024, file)) {
        line[strlen(line)-1] = '\0';    /* strip trailing new line */
        n = atoi(line);
        history_length = 0;
        cyclic = 0;
        while (1) {
            if (n == 1) {
                printf("1\n");
                break;
            }

            for (int i=0; i<history_length; i++) {
                if (n == history[i]) {
                    cyclic = 1;
                    break;
                }
            }

            if (cyclic) {
                printf("0\n");
                break;
            }

            history[history_length++] = n;
            n = 0;
            for (int i=0; i<strlen(line); i++) {
                n += ((line[i] - '0') * (line[i] - '0'));
            }
            sprintf(line, "%d", n);

/*
            printf("new n = %d\n", n); 
            for (int i=0; i<history_length; i++)
                printf("history[%d] = %d\n", i, history[i]);
*/
        }
/*
        printf("-------------------------\n");
*/
    }

    return 0;
}

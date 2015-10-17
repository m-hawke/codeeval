#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N_DIGITS    10
#define N_PLAYERS   20

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int counts[N_DIGITS];
    char digits[N_PLAYERS+1];
    int lowest_unique = 0;
    int i;

    while (fgets(line, 1024, file)) {
        bzero(counts, sizeof(counts));

        for (i=0,token=strtok(line, " "); token!=NULL;
                i++,token=strtok(NULL, " ")) {
            counts[token[0] - '0']++;
            digits[i] = token[0];
        }
        digits[i] = '\0';

        for (int i=1; i<N_DIGITS; i++)
            if (counts[i] == 1) {
                lowest_unique = i;
                break;
            }

//        printf("digits: %s, lowest_unique=%d\n", digits, lowest_unique);
        char *p = index(digits, '0' + lowest_unique);
        printf("%d\n", (p != NULL) ? (p-digits)+1 : 0);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <strings.h>

#define LINE_SIZE       1024
#define MAX_WINES       10
#define MAX_WINE_NAME   15
#define MAX_LETTERS     5

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int n_wines;
    char *wines[MAX_WINES];
    int n_results;
    char *results[MAX_WINES];
    char letters[MAX_LETTERS+1];

    while (fgets(line, LINE_SIZE, file)) {
        n_wines = 0;
        sscanf((rindex(line, '|')+2), "%s", letters);
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            if (token[0] == '|')
                break;
            wines[n_wines++] = token;
        }

        n_results = 0;
        for (int i=0; i<n_wines; i++) {
            char *p;
            char wine[MAX_WINE_NAME+1];
            int all_present = 1;        /* are all letters present in wine? */

            strcpy(wine, wines[i]);
            for (char *l=letters; *l; l++) {
                if (p = index(wine, *l)) {
                    *p = ' ';           /* erase so not counted again */
                }
                else {
                    all_present = 0;
                    break;
                }
            }
            if (all_present)
                results[n_results++] = wines[i];
        }

        if (n_results > 0) {
            for (int i=0; i<n_results; i++)
                printf("%s%s", (i==0) ? "" : " ", results[i]);
            printf("\n");
        }
        else {
            printf("False\n");
        }
    }

    return 0;
}

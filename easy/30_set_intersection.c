#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_SIZE       1024
#define MAX_ELEMENTS    20      /* a complete guess */

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int n_elements_s1, n_elements_s2;
    int set1[MAX_ELEMENTS];
    int set2[MAX_ELEMENTS];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        char *p = index(line, ';');
        *p++ = '\0';

        n_elements_s1 = 0;
        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            set1[n_elements_s1++] = atoi(token);
        }

        n_elements_s2 = 0;
        for (token=strtok(p, ","); token!=NULL; token=strtok(NULL, ",")) {
            set2[n_elements_s2++] = atoi(token);
        }

        /* Skip this line if there is no overlap between the two lists */
        if ((set2[0] > set1[n_elements_s1-1]) ||
            (set1[0] > set2[n_elements_s2-1])) {
            /* no intersection */
            printf("\n");
            continue;
        }

        int s1_pos, s2_pos, n;
        s1_pos = s2_pos = n = 0;

        while ((s1_pos < n_elements_s1) && (s2_pos < n_elements_s2)) {
            if (set1[s1_pos] == set2[s2_pos]) {
                n = printf("%s%d", (n>0) ? "," : "", set1[s1_pos]);
                s1_pos++;
                s2_pos++;
            }
            else if (set1[s1_pos] > set2[s2_pos])
                s2_pos++;
            else
                s1_pos++;
        }
        printf("\n");
    }

    return 0;
}

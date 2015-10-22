#include <stdio.h>
#include <string.h>
#include <strings.h>

#define LINE_LEN    10240
#define MAX_LINKS   1000

typedef struct link {
    char *name;
    char *next;
} LINK;

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    LINK chain[MAX_LINKS];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int n_links = 0;
        for (token=strtok(line, ";"); token!=NULL; token=strtok(NULL, ";")) {
            char *p = index(token, '-');
            *p++ = '\0';
            chain[n_links++] = (LINK){token, p};
        }

        int n_remaining = n_links;
        char *current = "BEGIN";
        while (n_remaining > 0) {
            /* search chain for the current link */
            int found = 0;
            for (int i=0; i<n_links; i++) {
                if (!strcmp(chain[i].name, current)) {
                    found = 1;
                    current = chain[i].next;
//                    *chain[i].name = '\0';   /* mark "key" as deleted */
                    n_remaining--;
                    break;
                }
            }

            if (!found)
                break;
        }

        int good = (n_remaining == 0 && (!strcmp(current, "END")));

        printf(good ? "GOOD\n" : "BAD\n");
    }

    return 0;
}

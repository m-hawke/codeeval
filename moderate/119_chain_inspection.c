#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <search.h>

#define LINE_LEN            10240
#define MAX_HASH_ENTRIES    1000

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;

    while (fgets(line, LINE_LEN, file)) {
        ENTRY e, *ep;
        int n_entries = 0;

        hcreate(MAX_HASH_ENTRIES);
        ep = hsearch((ENTRY){"END", "END"}, ENTER);

        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        for (token=strtok(line, ";"); token!=NULL; token=strtok(NULL, ";")) {
            char *p = index(token, '-');
            *p++ = '\0';
            ep = hsearch((ENTRY){token, p}, ENTER);
            if (ep == NULL) {
                fprintf(stderr, "entry failed\n");
                exit(EXIT_FAILURE);
            }
            n_entries++;
        }

        int good = 0;
        char current[] = "BEGIN";
        while (n_entries > 0) {
            e.key = current;
            if ((ep = hsearch(e, FIND)) != NULL) {
                if (*(char *)ep->data) {
                    n_entries--;
                    strcpy(current, (char *)ep->data);
                    if (!strcmp(current, "END"))
                        break;
                    *(char *)ep->data = '\0';    /* mark as "deleted" */
                }
                else {
                    /* entry was already traversed => chain broken */
                    break;
                }
            } else {
                /* entry not found => chain broken */
                break;
            }
        }

        good = (n_entries == 0 && (!strcmp(current, "END")));

        printf(good ? "GOOD\n" : "BAD\n");

        hdestroy();
    }

    return 0;
}

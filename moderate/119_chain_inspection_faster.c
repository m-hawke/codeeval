#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_LEN    10240
#define MAX_LINKS   1000

typedef struct link {
    char *name;
    char *next;
} LINK;

int cmp_links(const void *l1, const void *l2) {
    LINK *link1 = (LINK *)l1;
    LINK *link2 = (LINK *)l2;
    int result;

    if (result = strcmp(link1->name, link2->name))
        return result;

    return strcmp(link1->next, link2->next);
}

int cmp_links_name(const void *l1, const void *l2) {
    LINK *link1 = (LINK *)l1;
    LINK *link2 = (LINK *)l2;

    return strcmp(link1->name, link2->name);
}

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

        qsort((void *)chain, n_links, sizeof(LINK), cmp_links);

        int n_remaining = n_links;
        char *current = "BEGIN";
        while (n_remaining > 0) {
            /* search chain for the current link */
            LINK *link;
            LINK search_link = (LINK){current};
            link = bsearch(&search_link, chain, n_links,
                            sizeof(LINK), cmp_links_name);

            if (link != NULL) {
                current = link->next;
                /* It seems that we can get away without checking for
                 * revisitation of a link. */
//                *chain[i].name = '\0';   /* mark "key" as deleted */
                n_remaining--;
            } else {
                break;
            }
        }

        int good = (n_remaining == 0 && (!strcmp(current, "END")));
        printf(good ? "GOOD\n" : "BAD\n");
    }

    return 0;
}

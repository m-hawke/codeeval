#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 128

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    char *phrases[] = {
        ", yeah!",
        ", this is crazy, I tell ya.",
        ", can U believe this?",
        ", eh?",
        ", aw yea.",
        ", yo.",
        "? No way!",
        ". Awesome!"
    };
    int current_phrase = 0;
    int n_phrases = sizeof(phrases)/sizeof(char *);
    int replace = 0;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';

        int is_first_word = 1;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            char last_char = token[strlen(token)-1];
            if (!is_first_word)
                printf(" ");
            if (index(".!?", last_char)) {
                if (replace) {
                    token[strlen(token)-1] = '\0';
                    printf("%s%s", token, phrases[current_phrase]);
                    current_phrase = ((current_phrase+1) % n_phrases);
                } else {
                    printf(token);
                }
                replace ^= 1;
            } else {
                printf(token);
            }
            is_first_word = 0;
        }
        printf("\n");
    }

    return 0;
}

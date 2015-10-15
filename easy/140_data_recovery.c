#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define LINE_SIZE   1024
#define MAX_WORDS   50

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    char *words, *positions;
    char *reordered_words[MAX_WORDS+1];
    int n_words;

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';

        words = line;
        positions = index(line, ';') + 1;
        *(positions-1) = '\0';

        n_words = 0;
        bzero(reordered_words, sizeof(reordered_words));

        for (token=strtok(words, " "); token!=NULL; token=strtok(NULL, " ")) {
            int position = atoi(positions);
            reordered_words[position-1] = token;
            n_words++;
            if ((positions = index(positions, ' ')) != NULL)
                positions++;
            else
                break;
        }

        /* There is one fewer position than there is words, so one entry in
         * reordered_words will be NULL. We care only about printing the
         * word list so, as we print, find the empty position and fill it in
         * with the remaining word which should be the next token read.
         */
        for (int i=0; i<n_words+1; i++) {
            if (reordered_words[i] == NULL)
                reordered_words[i] = strtok(NULL, " ");
            printf("%s%s", (i==0) ? "" : " ", reordered_words[i]);
        }
        printf("\n");

    }

    return 0;
}

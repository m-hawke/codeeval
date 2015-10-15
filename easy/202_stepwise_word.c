#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 128

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    char longest_word[MAX_WORD_LENGTH+1];
    int longest_length = 0;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';

        longest_length = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            if (strlen(token) > longest_length) {
                strcpy(longest_word, token);
                longest_length = strlen(longest_word);
            }
        }

        for (int i=0; i<longest_length; i++) {
            if (i>0)
                printf(" ");
            for (int j=0; j<i; j++)
                printf("*");
            printf("%c", longest_word[i]);
        }
        printf("\n");
        
    }

    return 0;
}

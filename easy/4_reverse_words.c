#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS   20

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    char *words[MAX_WORDS];
    int i;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        for (i=0,token=strtok(line, " "); token!=NULL;
                i++,token=strtok(NULL, " ")) {
            words[i] = token;
        }

//        printf("read %d words\n", i);
        i--;
        for (; i>=0; i--)
//           printf("words[%d] '%s'\n", i, words[i]);
            printf("%s%s", words[i], (i>0) ? " " : "\n");
    }

    return 0;
}

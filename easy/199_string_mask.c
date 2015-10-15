#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char word[40], mask[40];

    while (fgets(line, 1024, file)) {
        sscanf(line, "%s %s", word, mask);
        for (int i=0; i<strlen(word); i++)
            if (mask[i] == '1')
                word[i] = toupper(word[i]);
        printf("%s\n", word);
    }

    return 0;
}

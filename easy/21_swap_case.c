#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void init_trans_table(char table[256]) {
    for (int c=0; c<256; c++)
        if (isalpha(c))
            if (isupper(c))
                table[c] = tolower(c);
            else
                table[c] = toupper(c);
        else
            table[c] = c;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char trans_table[256];

    init_trans_table(trans_table);

    while (fgets(line, 1024, file)) {
        for (char *p=line; *p; p++)
            *p = trans_table[*p];

        printf("%s", line);
    }

    return 0;
}

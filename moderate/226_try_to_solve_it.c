#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char trans_table[256];

    /* Set up translation table. By default each character maps to itself. */
    for (int i=0; i<256; i++)
        trans_table[i] = i;

    char *a = "abcdefghijklmuvwxyznopqrst";
    char *b = "uvwxyznopqrstabcdefghijklm";
    for (int i=0; i<strlen(a); i++)
        trans_table[a[i]] = b[i];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        for (char *p=line; *p; p++)
            printf("%c", trans_table[*p]);
        printf("\n");
    }

    return 0;
}

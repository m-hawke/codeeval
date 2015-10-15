#include <stdio.h>
#include <string.h>

#define LINE_SIZE   100

int count(const char *s, const char c) {
    int i = 0; 

    for (i=0; s[i]; s[i]==c ? i++ : *s++);

    return i;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int passed = 1;
        for (int i=0; i<strlen(line); i++) {
            if (count(line, i+'0') != line[i]-'0') {
                passed = 0;
                break;
            }
        }

        printf("%d\n", passed);
    }

    return 0;
}

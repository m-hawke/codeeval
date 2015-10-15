#include <stdio.h>

#define LINE_SIZE   1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char codel_to_english[] = "yhesocvxduiglbkrztnwjpfmaq";

    while (fgets(line, LINE_SIZE, file)) {
        for (char *p=line; *p; p++) {
            if ('a' <= *p && *p <= 'z')
                *p = codel_to_english[*p - 'a'];
        }
        printf(line);
    }

    return 0;
}

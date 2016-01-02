#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int sum = 0;
        int even = 1;
        for (int i=0; i<strlen(line); i++) {
            if (isdigit(line[i])) {
                sum += line[i] - '0';
                if (even)
                    sum += line[i] - '0';
                even ^= 1;
            }
        }

        if (sum % 10)
            printf("Fake\n");
        else
            printf("Real\n");
    }

    return 0;
}

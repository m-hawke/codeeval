#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int sum = 0;
        for (int i=0; i<strlen(line)-1; i++)
            sum += line[i] - '0';
        printf("%d\n", sum);
    }
    return 0;
}


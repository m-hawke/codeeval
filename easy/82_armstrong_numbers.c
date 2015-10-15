#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int total;
    int n;

    while (fgets(line, 1024, file)) {
        total = 0;
        n = strlen(line) - 1;
        for (int i=0; i<n; i++)
            total += (int)pow(line[i]-'0', n);
        printf("%s\n", (total == atoi(line)) ? "True" : "False");
    }

    return 0;
}

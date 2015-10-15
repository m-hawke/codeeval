#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int reverse_cmp_length(const void *s1, const void *s2) {
    return (strlen(*(char **)s2) - strlen(*(char **)s1));
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char *lines[100];
    char line[1024];
    int total_lines;
    int n;

    fscanf(file, "%d\n", &n);

    for (total_lines=0; fgets(line, 1024, file); total_lines++)
        lines[total_lines] = strdup(line);

    qsort((void *)lines, total_lines, sizeof(char *), reverse_cmp_length);

    for (int i=0; i<n; i++)
        printf("%s", lines[i]);

    return 0;
}

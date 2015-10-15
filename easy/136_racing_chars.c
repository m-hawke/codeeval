#include <stdio.h>
#include <strings.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *pos;
    char *prev_pos = (char *)NULL;
    char c;

    while (fgets(line, 1024, file)) {
        if ((pos = index(line, 'C')) == NULL)
            pos = index(line, '_');

        if ((prev_pos == pos) || (prev_pos == NULL))
            *pos = '|';
        else if (prev_pos < pos)
            *pos = '\\';
        else
            *pos = '/';

        prev_pos = pos;
        printf(line);
    }

    return 0;
}

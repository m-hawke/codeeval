#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    // get rid of new line

        if (strlen(line) > 55) {
            line[40] = '\0';

            /* rindex() works on my machine, but not codeeval's ??? */
/*
            if ((p = rindex(line, ' ')) != NULL)
                *p = '\0';
*/
            /* rindex() substitute */
            for (char *p=line+39; p>=line; p--)
                if (*p == ' ') {
                    *p = '\0';
                    break;
                }
            strcat(line, "... <Read More>");
        }
        printf("%s\n", line);
    }

    return 0;
}

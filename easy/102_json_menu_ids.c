#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define ID_LEN   2

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    regex_t preg;
    regmatch_t pmatch[3];
    char *cursor;
    char id[ID_LEN+1];

    regcomp(&preg, "\"id\": ([0-9]+)[^}]+\"label\":", REG_EXTENDED);

    while (fgets(line, 1024, file)) {
        cursor = line;
        int sum = 0;
        while (regexec(&preg, cursor, 3, pmatch, 0) != REG_NOMATCH) {
            strncpy(id, cursor + pmatch[1].rm_so,
                        pmatch[1].rm_eo - pmatch[1].rm_so + 1);
            id[ID_LEN] = '\0';
            sum += atoi(id);

            cursor += pmatch[1].rm_eo;
        }
        printf("%d\n", sum);
    }

    return 0;
}

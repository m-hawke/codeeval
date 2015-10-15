#include <stdio.h>
#include <string.h>
#include <regex.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    regex_t preg;

    char *pattern = "^(\"?[a-zA-Z0-9+\\!#$%&'*+-/=? ^_`.{|}~]+\"?|\"[a-zA-Z0-9+@\\!#$%&'*+-/=? ^_`.{|}~]+\"?)@[a-zA-Z0-9+]+(\\.[a-zA-Z0-9+]+)*$";

    regcomp(&preg, pattern, REG_EXTENDED|REG_NOSUB);

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        if (regexec(&preg, line, 0, NULL, 0) != REG_NOMATCH)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}

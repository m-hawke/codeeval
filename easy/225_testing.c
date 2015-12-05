#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

char *bug_count_to_priority(int bug_count) {
    if (bug_count == 0)
        return "Done";
    if (bug_count <= 2)
        return "Low";
    if (bug_count <= 4)
        return "Medium";
    if (bug_count <= 6)
        return "High";
    return "Critical";
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        char *dev_string = line;
        char *p = strstr(line, " | ");
        *p = '\0';
        char *design_string = p + 3;

        int bug_count = 0;
        for (int i=0; i<strlen(dev_string); i++) {
            bug_count += (dev_string[i] != design_string[i]);
        }

        printf("%s\n", bug_count_to_priority(bug_count));
    }

    return 0;
}

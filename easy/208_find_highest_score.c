#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CATEGORIES  20
#define MAX_PEOPLE      10

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int data[MAX_CATEGORIES][MAX_PEOPLE] = {0};

    while (fgets(line, 1024, file)) {
        int category = 0;
        int person = 0;

        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            if (token[0] == '|') {
                category = 0;
                person++;
            }
            else
                data[category++][person] = atoi(token);
        }
        person++;       // EOL terminates the last person's values

        int n_categories = category;
        int n_persons = person;
        int max;

        for (category=0; category < n_categories; category++) {
            for (person=0; person < n_persons; person++) {
                if (person == 0)
                    max = data[category][person];
                else
                    if (data[category][person] > max)
                        max = data[category][person];
            }
            printf("%s%d", (category > 0) ? " " : "", max);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        char *answer;
        int lower = 0;
        int upper = atoi(strtok(line, " "));
        int guess;

        for (answer=strtok(NULL, " "); answer!=NULL; answer=strtok(NULL, " ")) {
            guess = lower + ((upper-lower+1)/2);
            if (!strcmp(answer, "Lower"))
                upper = guess - 1;
            else if (!strcmp(answer, "Higher"))
                lower = guess + 1;
            else
                printf("%d\n", guess);
        }
    }

    return 0;
}

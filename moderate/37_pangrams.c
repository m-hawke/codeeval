#include <stdio.h>
#include <ctype.h>

#define N_CHARS 26

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int counts[N_CHARS] = {0};

        for (char *p=line; *p; p++) {
            char c = tolower(*p);
            if ('a' <= c && c <= 'z')
                counts[c - 'a']++;
        }

        int n = 0;
        for (int i=0; i<N_CHARS; i++)
            if (!counts[i])
                n = printf("%c", i + 'a');
        if (n)
            printf("\n");
        else
            printf("NULL\n");
    }

    return 0;
}

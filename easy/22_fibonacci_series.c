#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int cache[50];
    int cache_size;
    int n, a, b;
    int num_to_generate;

    cache[0] = 0;
    cache[1] = 1;
    cache_size = 2;

    while (fgets(line, 1024, file)) {
        n = atoi(line);

        if (n < cache_size)
            printf("%d\n", cache[n]);
        else {
            a = cache[cache_size-2];
            b = cache[cache_size-1];
            num_to_generate = (n - cache_size + 1);
            for (int i=0; i<num_to_generate; i++) {
                cache[cache_size++] = a + b;
                a = b;
                b = cache[cache_size-1];
            }
            printf("%d\n", cache[cache_size-1]);
        }
    }

    return 0;
}

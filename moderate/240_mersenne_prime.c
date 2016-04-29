#include <stdio.h>
#include <math.h>

#define LINE_SIZE   1024

int is_prime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if ((n%2 == 0) || (n%3 == 0))
        return 0;
    if (n < 25)
        return 1;

    for (int i=3; i < (int)sqrt(n)+1; i+=2) {
        if (n%i == 0)
            return 0;
    }

    return 1;
}

int mersennes[] = {3, 7, 31, 127, 8191};
int n_mersennes = sizeof(mersennes) / sizeof(int);

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    int max;

    while (fgets(line, LINE_SIZE, file)) {
        sscanf(line, "%d", &max);
        int print_sep = 0;
        for (int i=0; i<n_mersennes; i++)
            if (mersennes[i] < max)
                print_sep = printf("%s%d", print_sep ? ", " : "", mersennes[i]);
        printf("\n");
    }

    return 0;
}

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

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    int lower, upper;

    while (fgets(line, LINE_SIZE, file)) {
        sscanf(line, "%d,%d", &lower, &upper);
        int count = 0;
        for (int n=lower; n<=upper; n++) {
            count += is_prime(n);
        }
        printf("%d\n", count);
    }

    return 0;
}

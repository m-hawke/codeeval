#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN    1024

long reverse(long n) {
    int digit;
    long reversed_n = 0;

    while (n) {
        digit = n % 10;
        reversed_n = (reversed_n * 10) + digit;
        n /= 10;
    }

    return reversed_n;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        int i = 0;
        long reversed_n;

        long n = atol(line);
        while ((reversed_n = reverse(n)) != n) {
            n += reversed_n;
            i++;
        }

        printf("%d %ld\n", i, n);
    }

    return 0;
}

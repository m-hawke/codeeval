#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINE_LEN            1024
#define PRIME_CACHE_SIZE    2000        /* cache up to the first 2000 primes */

int primes[PRIME_CACHE_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int n_primes = 9;

void print_primes(int upper) {
    int i;

    if (upper >= 2)
        printf("2");

    /* print from the cache first */
    for (i=1; (i < n_primes) && (primes[i] <= upper); i++) {
        printf(",%d", primes[i]);
    }

    for (int n=primes[n_primes-1]+1; n <= upper; n++) {
        if (n%2 == 0)
            continue;

        int prime = 1;
        for (int i=3; i<((int)sqrt(n))+1; i+=2) {
            if (n%i==0) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            if (n_primes < PRIME_CACHE_SIZE)
                primes[n_primes++] = n;     /* add this prime to the cache */
            printf(",%d", n);
        }
    }

    printf("\n");
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        print_primes(atoi(line)-1);
    }

    return 0;
}

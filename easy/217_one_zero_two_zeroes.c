#include <stdio.h>

#define LINE_SIZE       1024

int count_zeros(int n) {
    int count = 0;
    while (n>0) {
        count += !(n&1);
        n >>= 1;
    }
    return count;
}

int contains_n_zeros(int n, int n_zeros) {
    int count = 0;
    while (n>0 && count<=n_zeros) {
        count += !(n&1);
        n >>= 1;
    }
    return count == n_zeros;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        int n_zeros, n;

        sscanf(line, "%d %d", &n_zeros, &n);

        int count = 0;
        for (int i=1; i<=n; i++)
            count += contains_n_zeros(i, n_zeros);
//            count += (count_zeros(i) == n_zeros);
        printf("%d\n", count);
    }

    return 0;
}

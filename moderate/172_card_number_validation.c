#include <stdio.h>
#include <string.h>

#define LINE_SIZE   1024
#define MAX_PAN     20

int sum_of_digits(int n) {
    int sum= 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int is_luhn_valid(char *pan){
    int checksum = 0;
    int odd = 1;

    for (int i=strlen(pan)-1; i>=0; i--) {
        int digit = pan[i] - '0';
        checksum += odd ? digit : sum_of_digits(digit * 2);
        odd ^= 1;
    }

    return (checksum % 10 == 0);
}


int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char pan[MAX_PAN];

    while (fgets(line, LINE_SIZE, file)) {
        char *p;
        int len_pan = 0;
        for (p=line; *p; p++)
            if ('0' <= *p && *p <= '9')
                pan[len_pan++] = *p;
        pan[len_pan] = '\0';

        printf("%d\n", is_luhn_valid(pan));
    }

    return 0;
}

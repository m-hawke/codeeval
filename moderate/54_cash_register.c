#include <stdio.h>
#include <math.h>

#define LINE_LEN    1024

int AMOUNTS[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
char *AMOUNT_NAMES[] = {"ONE HUNDRED", "FIFTY", "TWENTY", "TEN", "FIVE",
                        "TWO", "ONE", "HALF DOLLAR", "QUARTER", "DIME",
                        "NICKEL", "PENNY"};

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        float price, tendered;
        sscanf(line, "%f;%f", &price, &tendered);
        int change = (int)round(tendered * 100) - (int)round(price * 100);

        if (change < 0)
            printf("ERROR\n");
        else if (change == 0)
            printf("ZERO\n");
        else {
            int print_comma = 0;
            for (int i=0; i<sizeof(AMOUNTS)/sizeof(int); i++) {
                int n = change / AMOUNTS[i];
                change = change % AMOUNTS[i];
                for (; n>0; n--)
                    print_comma = printf("%s%s", print_comma ? "," : "",
                                            AMOUNT_NAMES[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

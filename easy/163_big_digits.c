#include <stdio.h>

#define MAX_SYMBOLS 16
#define FONT_WIDTH  5
#define FONT_HEIGHT 6

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int n_digits;
    int digits[MAX_SYMBOLS];

    char *font[] = {
        "-**----*--***--***---*---****--**--****--**---**--",
        "*--*--**-----*----*-*--*-*----*-------*-*--*-*--*-",
        "*--*---*---**---**--****-***--***----*---**---***-",
        "*--*---*--*-------*----*----*-*--*--*---*--*----*-",
        "-**---***-****-***-----*-***---**---*----**---**--",
        "--------------------------------------------------",
    };

    while (fgets(line, 1024, file)) {
        n_digits = 0;
        for (int i=0; line[i]; i++) {
            if ((line[i] >= '0') && (line[i] <= '9')) {
                digits[n_digits] = line[i] - '0';
                n_digits++;
            }
        }

        if (n_digits > 0) {
            for (int row=0; row<FONT_HEIGHT; row++) {
                for (int i=0; i<n_digits; i++)
                    printf("%.*s", FONT_WIDTH,
                            font[row] + digits[i]*FONT_WIDTH);
                printf("\n");
            }
        }
    }

    return 0;
}

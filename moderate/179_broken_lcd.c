#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define LCD_DIGITS  12

/* LCD segments for each digit with decimal point off */
unsigned char segments[10] = {
    0xFC,  /* 11111100 = '0' */
    0x60,  /* 01100000 = '1' */
    0xDA,  /* 11011010 = '2' */
    0xF2,  /* 11110010 = '3' */
    0x66,  /* 01100110 = '4' */
    0xB6,  /* 10110110 = '5' */
    0xBE,  /* 10111110 = '6' */
    0xE0,  /* 11100000 = '7' */
    0xFE,  /* 11111110 = '8' */
    0xF6,  /* 11110110 = '9' */
};


/* Determine whether the given digit segments can be displayed for the given
 * the LCD segment configuration. */
int can_display_digits(unsigned char digits[], int n_digits,
                       unsigned char lcd_segments[LCD_DIGITS]) {
    for (int i=0; i<n_digits; i++) {
        if ((digits[i] & lcd_segments[i]) != digits[i])
            return 0;
    }

    return 1;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    unsigned char lcd_segments[LCD_DIGITS];

    while (fgets(line, LINE_LEN, file)) {
        char *number = strrchr(line, ';');
        *number++ = '\0';
        if (number[strlen(number)-1] == '\n')
            number[strlen(number)-1] = '\0';

        int i = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) { 
            lcd_segments[i++] = (unsigned char)strtol(token, NULL, 2);
        }

        /* Convert each digit in number to its required LCD segments */
        unsigned char digits[LCD_DIGITS];
        int n_digits = 0;
        for (i=0; i<strlen(number); i++) {
            if (number[i] == '.')
                digits[i-1]++;
            else
                digits[n_digits++] = segments[number[i]-'0'];
        }

        int displayable= 0;
        for (i=0; i<(LCD_DIGITS-n_digits+1); i++) {
            if (displayable = can_display_digits(digits, n_digits, lcd_segments+i))
                break;
        }
        printf("%d\n", displayable);
    }

    return 0;
}

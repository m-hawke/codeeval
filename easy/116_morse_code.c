#include <stdio.h>
#include <string.h>

#define MAX_MORSE_LEN    6

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char morse[MAX_MORSE_LEN+1];
    int i, idx;
    char *p;

    char *morse_strings[] = {" ",  "-",  "--",  "---",  "-----",  "----.",  "---..",  "---...",  "--.",  "--.-",  "--..",  "--..--",  "--...",  "-.",  "-.-",  "-.--",  "-.--.-",  "-.-.",  "-.-.-.",  "-..",  "-..-",  "-..-.",  "-...",  "-....",  "-....-",  ".",  ".-",  ".--",  ".---",  ".----",  ".----.",  ".--.",  ".-.",  ".-.-.-",  ".-..",  "..",  "..-",  "..---",  "..--.-",  "..--..",  "..-.",  "...",  "...-",  "...--",  "....",  "....-",  "....."};
    char morse_values[] = " TMO098:GQZ,7NKY(C;DX/B6-EAWJ1'PR.LIU2_?FSV3H45";

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';
 
        for (p=line, i=0; ; p++) {
            if (*p && (*p != ' '))
                morse[i++] = *p;
            else {
                if (i == 0)     /* empty string... word boundary */
                    printf(" ");
                else {
                    morse[i] = '\0';
                    for (idx=0; strcmp(morse, morse_strings[idx]); idx++) {}
                    printf("%c", morse_values[idx]);
                }
                i = 0;
                if (!*p)    /* handles end of line */
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}

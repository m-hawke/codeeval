#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

char map_paren(char paren) {
    /* map a closing paren to its opening counterpart */
    if (paren == ')') return '(';
    if (paren == '}') return '{';
    if (paren == ']') return '[';
    return '\0';
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int top=-1;
        char stack[strlen(line)];   /* N.B variable-sized array */

        int valid = 1;
        char expected;  /* the top of the stack is expected to be this char */
        for (char *p=line; *p && valid; p++) {
            if (expected = map_paren(*p)) {
                if (valid = ((top != -1) && (stack[top] == expected)))
                    top--;
            } else {
                stack[++top] = *p;
            }
        }

        printf((valid && (top == -1)) ? "True\n" : "False\n");
    }

    return 0;
}

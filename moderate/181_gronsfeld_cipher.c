#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *alphabet = " !\"#$%&'()*+,-./0123456789:<=>?@"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int alphabet_length = strlen(alphabet);
    char ascii_to_alphabet_pos[256];

    for (int i=0; i<alphabet_length; i++)
        ascii_to_alphabet_pos[alphabet[i]] = i;

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        char *key = line;
        char *ciphertext = strchr(line, ';');
        *ciphertext++ = '\0';

        int key_length = strlen(key);
        int ciphertext_length = strlen(ciphertext);
        char plaintext[ciphertext_length];     /* N.B variable-sized array */

        int i;
        for (i=0; i<ciphertext_length; i++) {
            int offset = key[i%key_length] - '0';
            int alphabet_pos = ascii_to_alphabet_pos[ciphertext[i]] - offset;
            if (alphabet_pos < 0)
                alphabet_pos += alphabet_length;
            plaintext[i] = alphabet[alphabet_pos];
        }
        plaintext[i] = '\0';
        printf("%s\n", plaintext);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

struct card {
    char rank[3];
    char suit;
    int face_value;
};

struct card *get_card(char *s, struct card *card) {
    int rank_len = 1;

    if (('2' <= s[0]) && (s[0] <= '9')) {
        card->face_value = s[0] - '0';
    }
    else if (!strncmp(s, "10", 2)) {
        rank_len = 2;
        card->face_value = 10;
    }
    else if (s[0] == 'J')
        card->face_value = 11;
    else if (s[0] == 'Q')
        card->face_value = 12;
    else if (s[0] == 'K')
        card->face_value = 13;
    else if (s[0] == 'A')
        card->face_value = 14;

    strncpy(card->rank, s, rank_len);
    card->rank[rank_len] = '\0';

    card->suit = s[rank_len];

    return card;
}


int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char card1[4];
    char card2[4];
    char trumps;

    while (fgets(line, LINE_LEN, file)) {
        sscanf(line, "%s %s | %c", card1, card2, &trumps);

        struct card c1, c2;
        get_card(card1, &c1);
        get_card(card2, &c2);

        if (c1.suit == c2.suit) {   // same suit, trumps doesn't matter
            printf(c1.face_value >= c2.face_value ? card1 : card2);
            if (c1.face_value == c2.face_value)
                printf(" %s", card2);
        }
        else {
            if (c1.suit == trumps)
                printf(card1);
            else if (c2.suit == trumps)
                printf(card2);
            else {
                printf(c1.face_value >= c2.face_value ? card1 : card2);
                if (c1.face_value == c2.face_value)
                    printf(" %s", card2);
            }
        }

        printf("\n");
    }

    return 0;
}

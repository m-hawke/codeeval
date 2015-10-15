#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_SIZE       1024
#define MAX_DATE_RANGES 50      /* no idea, a complete guess */

typedef struct date_range {
    int start;
    int end;
} DATE_RANGE;

int month_name_to_number(const char *s) {
    if (strncmp(s, "Jan", 3) == 0)
        return 1;
    if (strncmp(s, "Feb", 3) == 0)
        return 2;
    if (strncmp(s, "Mar", 3) == 0)
        return 3;
    if (strncmp(s, "Apr", 3) == 0)
        return 4;
    if (strncmp(s, "May", 3) == 0)
        return 5;
    if (strncmp(s, "Jun", 3) == 0)
        return 6;
    if (strncmp(s, "Jul", 3) == 0)
        return 7;
    if (strncmp(s, "Aug", 3) == 0)
        return 8;
    if (strncmp(s, "Sep", 3) == 0)
        return 9;
    if (strncmp(s, "Oct", 3) == 0)
        return 10;
    if (strncmp(s, "Nov", 3) == 0)
        return 11;
    if (strncmp(s, "Dec", 3) == 0)
        return 12;

    fprintf(stderr, "Invalid month name '%s'\n", s);
    return 0;
}

void parse_date_range(const char *s, DATE_RANGE *date_range) {
    const char *start_date = s;
    const char *end_date = index(s, '-') + 1;

    date_range->start = month_name_to_number(start_date) + (atoi(start_date + 4) * 12);
    date_range->end = month_name_to_number(end_date) + (atoi(end_date + 4) * 12);
}

int cmp_date_range(const void *l, const void *r) {
    DATE_RANGE *dr1 = (DATE_RANGE *)l;
    DATE_RANGE *dr2 = (DATE_RANGE *)r;

    if (dr1->start < dr2->start)
        return -1;
    else if (dr1->start > dr2->start)
        return 1;
    else /* dr1->start == dr2->start so compare end values */
        return dr1->end - dr2->end;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int n_date_ranges;
    DATE_RANGE date_ranges[MAX_DATE_RANGES];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        n_date_ranges = 0;
        for (token=strtok(line, ";"); token!=NULL; token=strtok(NULL, ";")) {
            if (*token == ' ')
                token++;
            parse_date_range(token, &date_ranges[n_date_ranges++]);
        }

        qsort((void *)date_ranges, n_date_ranges, sizeof(DATE_RANGE), cmp_date_range);

        int months = 0;
        int previous_end = 0;
        for (int i=0; i<n_date_ranges; i++) {
            if (date_ranges[i].start > previous_end)
                months += date_ranges[i].end - date_ranges[i].start + 1;
            else if ((date_ranges[i].end > previous_end) ||
                     (date_ranges[i].start == previous_end))
                months += date_ranges[i].end - previous_end;
            else
                continue;

            previous_end = date_ranges[i].end;
        }

        printf("%d\n", months/12);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define DATE_LENGTH 8

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char date1[DATE_LENGTH+1];
    char date2[DATE_LENGTH+1];
    int d1_seconds, d2_seconds, delta;
    int h, m, s;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%s %s", date1, date2);

        sscanf(date1, "%d:%d:%d", &h, &m, &s);
        d1_seconds = h*3600 + m*60 + s;
        sscanf(date2, "%d:%d:%d", &h, &m, &s);
        d2_seconds = h*3600 + m*60 + s;
        delta = abs(d1_seconds - d2_seconds);

        h = delta / 3600;
        s = delta % 3600;
        m = s / 60;
        s = s % 60;

        printf("%02d:%02d:%02d\n", h, m, s);
    }

    return 0;
}

#include <stdio.h>

#define MAX 12

int main(int argc, const char * argv[]) {

    for (int row=1; row<=MAX; row++)
    {
        for (int col=1; col<=MAX; col++)
            printf(col==1 ? "%2d" : "%4d", row*col);

        printf("\n");
    }
    return 0;
}


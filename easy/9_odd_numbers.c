#include <stdio.h>

#define MAX 99

int main(int argc, const char * argv[]) {
    for (int i=1; i<=MAX; i+=2)
        printf("%d\n", i);
    return 0;
}


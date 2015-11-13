#include <stdio.h>

int main(int argc, const char * argv[]) {
    short i = 1;
    char *p = (char *)&i;
    
    if (*p == 0x01)
        printf("LittleEndian\n");
    else
        printf("BigEndian\n");

    return 0;
}

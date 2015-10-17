#include <stdio.h>
#include <sys/stat.h>


int main(int argc, const char * argv[]) {
    struct stat buf;

    stat(argv[1], &buf);
    printf("%d\n", buf.st_size);
    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
    struct stat buf;

    stat(argv[1], &buf);
    printf("%d\n", buf.st_size);
    return 0;
}


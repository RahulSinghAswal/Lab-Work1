#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd1 = open("biodata.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("c1");
        exit(1);
    }
    printf("opened the fd1 = %d\n", fd1);

    //using close system call
    if (close(fd1) < 0) {
        perror("c1");
        _exit(1);
    }
    printf("closed the fd.\n");

    

    return 0;
}
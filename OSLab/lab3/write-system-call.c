#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void main()
{
    int sz;

    int fd = open("biodata.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("r1");
        // exit(1);
        return 1;
    }

    sz = write(fd, "hello world\n", strlen("hello rahul\n"));

    printf("called write(%d, \"hello rahul\\n\", %d)." 
    "It returned %d\n", fd, strlen("hello world\n"),sz);

    close(fd);
}
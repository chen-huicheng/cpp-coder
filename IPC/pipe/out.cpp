#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"
int main()
{
    int fd;
    fd = open("./myfifo", O_RDONLY);
    if (fd < 0)
    {
        printf("open myfifo failure\n");
        return -1;
    }
    printf("open myfifo sucess\n");
    char buf[10];
    const char hi[]="hi";
    read(fd, buf, 3);
    buf[5]='\0';
    printf("%s\n",buf);
    sleep(2);
    // write(fd, hi, 2);
    return 0;
}

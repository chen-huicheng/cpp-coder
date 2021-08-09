#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;
const int BUF_SIZE = 1024;
int main()
{

    // ftok()
    int pid, fd[2];
    if (pipe(fd) < 0) //创建无名管道 fd[0]为管道的读文件描述符 fd[1]为管道的写描述符
    {
        fprintf(stderr, "pipe failed!!\n");
        return -1;
    }
    pid = fork();
    if (pid == 0) //子进程
    {
        char buf[BUF_SIZE];
        sleep(10);
        while (1)
        {
            int rt = read(fd[0], buf, BUF_SIZE);
            //返回读取长度，-1代表错误，0代表EOF
            buf[rt] = '\0';
            if (rt == 0 || rt < 0)
            {
                close(fd[0]);
                close(fd[1]);
                break;
            }
            printf("read:%d %s\n", rt, buf);
        }
    }
    else
    {
        char buf[BUF_SIZE]="hello";
        int size=0;
        while (1)
        {
            // scanf("%s", buf);
            int len = strlen(buf);
            size+=len;
            cout<<size<<endl;
            int rt = write(fd[1], buf, len);
            //返回读取长度，-1代表错误，0代表EOF
            if (rt < 0)
            {
                close(fd[0]);
                close(fd[1]);
                break;
            }
            printf("write:%d\n", len);
        }
    }
    return 0;
}
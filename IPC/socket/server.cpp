#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/epoll.h>
#include <fcntl.h>

int gSetNonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

/* 往epoll描述符添加套接字 */
void gAddfd(int epollfd, int fd, bool oneshoot)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    /* 同一时刻只允许一个线程处理该描述符 */
    if (oneshoot)
    {
        event.events = event.events | EPOLLONESHOT;
    }
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    gSetNonblocking(fd);
}

void gResetOneshot(int epollfd, int conn)
{
    epoll_event event;
    event.data.fd = conn;
    event.events = EPOLLIN | EPOLLONESHOT;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, conn, &event);
}

int main(int argc, char *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        write(STDERR_FILENO, "socket error", 11);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));

    listen(sock, 1024);

    signal(SIGPIPE, SIG_IGN);

    int epollfd;
    epollfd = epoll_create(5);
    gAddfd(epollfd, sock, false);

    int connfd;
    int number;
    epoll_event event[512];
    while (1)
    {

        number = epoll_wait(epollfd, event, 512, -1);
        if (number < 0 && errno != EINTR)
        {
            printf("epoll failure\n");
            break;
        }
        for (int i = 0; i < number; ++i)
        {
            int sockfd = event[i].data.fd;
            if (sockfd == sock && (event[i].events & EPOLLIN))
            {

                struct sockaddr_in cliaddr;
                socklen_t clilen = sizeof(sockaddr_in);
                connfd = accept(sock, (struct sockaddr *)&cliaddr, &clilen);

                if (connfd < 0)
                {
                    printf("errno is -> %d:%s\n", errno, strerror(errno));
                    continue;
                }
                /* 设置连接套接字EPOLLONESHOT */
                gAddfd(epollfd, connfd, false);
                //gResetOneshot(epollfd, sock);
                printf("Client connect\n");
            } /* 来子外界的信号，如在终端输入kill -signal PID给此进程时 */
            else if (sockfd == connfd && (event[i].events & EPOLLIN))
            {
                // printf("Don't process\n");
                // gResetOneshot(epollfd, connfd);
                // continue;
                printf("Start sleep(10) ...\n");
                sleep(10);
                char text[512];

                int ret = recv(connfd, text, 512, 0);
                while (recv > 0)
                {
                    if (ret > 0)

                    {
                        text[ret] = '\0';
                        printf("Recv(%d):%s\n", ret, text);
                    }
                    else if (ret == 0)
                    {
                        printf("Client close socket\n");
                        close(connfd);
                        break;
                    }
                    else if (errno == EWOULDBLOCK)
                    {
                        printf("Wouldblock\n");
                        break;
                    }
                    else if (errno == EPIPE)
                    {
                        printf("Broken pipe\n");
                        break;
                    }
                    ret = recv(connfd, text, 512, 0);
                    epoll_event event;
                    event.data.fd = connfd;
                    event.events = EPOLLOUT;
                    /* 同一时刻只允许一个线程处理该描述符 */
                    event.events = event.events | EPOLLONESHOT;
                    epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &event);
                    gSetNonblocking(connfd);
                }
                //gResetOneshot(epollfd, connfd);
            }
        }
    }

    return 0;
}
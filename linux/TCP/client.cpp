#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sstream>
using namespace std;
 
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage:./exec [ip] [port]\n");
		exit(-1);
	}
	int sock = socket(AF_INET, SOCK_STREAM, 0);
 
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);
 
	connect(sock, (struct sockaddr *)&addr, sizeof(addr));
 
	int old = fcntl(sock, F_GETFL);
	int newoption = old | O_NONBLOCK;
	fcntl(sock, F_SETFL, newoption);
 
	char buf[512];
	memset(buf, 0, sizeof(buf));
	int epollfd = epoll_create(5);
 
	epoll_event event[128];
 
	epoll_event e1,e2;
	e1.data.fd = sock;
	e1.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, sock, &e1); 
	e2.data.fd = STDIN_FILENO;
	e2.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, STDIN_FILENO, &e2); 
 
	int nR;
	int ret;
	while (1)
	{
		int number = epoll_wait(epollfd, event, 128, -1);
		if (number <= 0)
		{
			printf("epoll_wait error\n");
			break;
		}
		for (int i = 0; i < number; ++i)
		{
 
			if (event[i].data.fd == sock && (event[i].events & EPOLLIN))
			{
				memset(buf, 0, sizeof(buf));
				nR = read(sock, buf, 512);
				if (nR == 0)
				{
					close(sock);
					break;
				}
				write(STDOUT_FILENO, buf, nR);
			}
			else if (event[i].data.fd == STDIN_FILENO && (event[i].events & EPOLLIN))
			{
				memset(buf, 0, sizeof(buf));
				nR = read(STDIN_FILENO, buf, 512);
                stringstream sstream;
                sstream<<buf;
                sstream<<1;
                int times;
                sstream>>buf>>times;
                nR=strlen(buf);
				if (nR <= 0)
				{
					printf("errno[%d]:%s\n", errno, strerror(errno));
				}
                ret=0;
                printf("buf:%s times:%d\n",buf,times);
                while(times--){
                    ret = write(sock, buf, nR);
                    if(ret<0)break;
                }
				    
                printf("times %d\n",times);
                continue;
				if (ret == 0 && errno == EINTR)
				{
					printf("write sock error\n");
					exit(-1);
				}
				else if (ret < 0)
				{
					printf("write sock ret < 0\n");
					exit(-1);
				}
				printf("Send [%d]byte\n", ret);
			}
		}
	}
 
	close(sock);
 
	return 0;
}
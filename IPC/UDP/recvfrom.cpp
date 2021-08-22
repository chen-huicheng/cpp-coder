#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>

const int BUF_SIZE=1024;
int main(int argc,char *argv[]){
    if(argc<=1){
        printf("usage:./%s port_number \n",basename(argv[0]));
        return 1;
    }
    int port = atoi(argv[1]);

    // create socket
    int sock = socket(PF_INET,SOCK_DGRAM,0);
    assert(sock>=0);

    // 地址转换
    struct sockaddr_in address,clientaddr;         // 定义ipv4地址  ipv6 为 sockaddr_in6
    bzero(&address,sizeof(address));    // 按字节全部初始化为全0
    address.sin_family = AF_INET;       // 初始化 地址族  与 socket 协议族 相关
    address.sin_addr.s_addr=htonl(INADDR_ANY);    
    address.sin_port = htons(port);          // 初始化端口号  网络字节序

    bind(sock,(sockaddr*)&address,sizeof(address));
    char buffer[BUF_SIZE];
    int k=0;
    socklen_t addrlen=sizeof(clientaddr);
    while(1){
        int ret = recvfrom(sock,buffer,10,0,(sockaddr*)&clientaddr,&addrlen);
        buffer[ret]='\0';
        if(ret<0){
            printf("erron is:%d\n",errno);
        }else{
            printf("server got %d bytes of normal data '%s'\n",ret,buffer);
        }
    }

    close(sock);
    return 0;
}
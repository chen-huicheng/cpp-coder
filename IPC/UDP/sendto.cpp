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
    if(argc<2){
        printf("usage:./%s ip_address port_number \n",basename(argv[0]));
        return 1;
    }
    const char *ip=argv[1];
    int port = atoi(argv[2]);

    // create socket
    int sock = socket(PF_INET,SOCK_DGRAM,0);
    assert(sock>=0);

    // 地址转换
    struct sockaddr_in address;         // 定义ipv4地址  ipv6 为 sockaddr_in6
    bzero(&address,sizeof(address));    // 按字节全部初始化为全0
    address.sin_family = AF_INET;       // 初始化 地址族  与 socket 协议族 相关
    inet_pton(AF_INET,ip,&address.sin_addr); // 将点分十进制字符串地址 转换为 网络字节序整数地址
    address.sin_port = htons(port);          // 初始化端口号  网络字节序

    char buffer[BUF_SIZE];
    socklen_t addrlen=sizeof(address);
    while(1){
        int k;
        // scanf("%d",&k);
        // k=htonl(k);
        memset(buffer,'\0',sizeof(buffer));
        scanf("%s",buffer);
        int ret = sendto(sock,buffer,strlen(buffer),0,(sockaddr*)&address,addrlen);
        if(ret<0){
            printf("erron is:%d\n",errno);
        }else{
            printf("client send %d bytes of normal data '%s'\n",ret,buffer);
        }
    }

    close(sock);
    return 0;
}
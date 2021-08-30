#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main(){
    int pid;
    printf("hel");  //父进程输出  到输出缓冲区
    pid = fork();   //复制进程  输出缓冲区也复制
    if(pid)
        printf("lo\n"); //子进程输出 并刷新输出缓冲区
        //输出 hello
    // 父进程 程序结束 刷新输出缓冲区 hel
    return 0;
}
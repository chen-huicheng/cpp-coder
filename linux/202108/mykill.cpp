#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	if(argc<3){
        printf("Usage: .%s signalno pid [n]",argv[0]);
        return -1;
    }
    int signo=atoi(argv[1]);
    int pid=atoi(argv[2]);
    int n=10;
    if(argc==4){
        n=atoi(argv[3]);
    }
	while(n--){
        kill(pid,signo);
    }
	return 0;
}
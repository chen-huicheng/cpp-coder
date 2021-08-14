#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "fcntl.h"
int main(){
	int fd;
	const char hello[]="hello";
	fd = open("./myfifo",O_WRONLY);
	if(fd<0){
	    printf("open myfifo failure\n");
	    return -1;	
	}
	printf("open myfifo sucess\n");
	
	sleep(5);
	write(fd,hello,5);
    // char buf[5];
    // read(fd,buf,2);
    // buf[2]='\0';
    // printf("%s\n",buf);
	return 0;
}

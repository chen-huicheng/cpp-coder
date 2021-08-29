// #include<signal.h>
// #include<stdio.h>
// #include<unistd.h>
// static int temp = 0;
 
// void fun(int k)
// {
// 	printf("hello world!\n");
// }
 
// int main()
// {
//     struct sigaction sa;
//     sa.sa_handler=fun;
//     sa.sa_flags|=SA_RESTART;
//     sigfillset(&sa.sa_mask);
//     // sigaction(SIGINT,);
// 	sigaction(SIGINT,&sa,NULL);   //处理SIGINT信号为fun
 
// 	while(1)
// 	{
// 		sleep(2);
// 		printf("hello human!\n");   //循环打印
// 	}
// 	return 0;
// }

#include<stdio.h>
#include<signal.h>
int k=0;
void handler2(int no)
{
	static int count=0;
	printf("get signal=%d\ttimes %d\n",no,count++);
}
void handler34(int no)
{
	static int count=0;
	printf("get signal=%d\ttimes %d\n",no,count++);
}
int main()
{
	signal(2,handler2);
	signal(34,handler34);
	while(1);
	return 0;
}
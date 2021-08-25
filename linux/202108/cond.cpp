//创建三个线程顺序打印abc
//利用条件变量加互斥量实现
//
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>//线程相关的头文件
#include<iostream>
using namespace std;
 
int i=0;
int n=0;
//声明互斥量，条件变量
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
 
void* printa(void *)
{
	while(n<10)
	{
		pthread_mutex_lock(&mutex);
		while(i!=1)
			pthread_cond_wait(&cond,&mutex);
		pthread_t tid;
		tid=pthread_self();
		printf("a   tid:%lu\n",tid);
		i++;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return (void *)0;
}
void* printb(void *)
{
	while(n<10){
		pthread_mutex_lock(&mutex);
		while(i!=2)
			pthread_cond_wait(&cond,&mutex);
		pthread_t tid;
		tid=pthread_self();
		printf("b   tid:%lu\n",tid);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return (void *)0;
}
void* printc(void *)
{
	while(n<10)
	{
		pthread_mutex_lock(&mutex);
		while(i!=3)
			pthread_cond_wait(&cond,&mutex);
		pthread_t tid;
		tid=pthread_self();
		printf("c   tid:%lu\n",tid);
		i=1;
        n++;
		sleep(1);
		pthread_mutex_unlock(&mutex);
		printf("\n");
	}
	return (void *)0;
}
 
int main()
{
	pthread_t tid;
	int err;
 
	err=pthread_create(&tid,NULL,printa,NULL);
	if(err!=0)
		printf("pthread_creat erro\n");
 
	err=pthread_create(&tid,NULL,printb,NULL);
	if(err!=0)
		printf("pthread_creat erro\n");
 
	err=pthread_create(&tid,NULL,printc,NULL);
	if(err!=0)
		printf("pthread_creat erro\n");
 
	pthread_mutex_lock(&mutex);
	i++;
	pthread_mutex_unlock(&mutex);
    int j=0;
    clock_t start = clock();
	while(1)
	{
		if(i==1||i==2||i==3){
            // pthread_cond_broadcast(&cond);
            pthread_cond_signal(&cond);
            cout<<"j:"<<j++<<endl;
        }
		if(n==10)
			break;
	}
    cout<<j<<endl;
    cout<<"times "<<1.0*(clock()-start)<<endl;
	exit(0);
}
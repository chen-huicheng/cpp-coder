#include "locker.h"
#include<pthread.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
Locker mutex_1,mutex_2;

void *threadA(void *){
    MutexLockGuard lock1(mutex_1);
    printf("B\n");
    sleep(1);
    MutexLockGuard lock2(mutex_2);
}
void *threadB(void *){
    MutexLockGuard lock1(mutex_2);
    printf("B\n");
    sleep(1);
    MutexLockGuard lock2(mutex_1);
}
int main()
{
    pthread_t ta,tb;
    int rt = pthread_create(&ta,NULL,threadA,NULL);
    if(rt!=0){
        printf("create threadA error, errorno = %d",errno);
        printf("%s",strerror(errno));
    }
    rt = pthread_create(&tb,NULL,threadB,NULL);
    if(rt!=0){
        printf("create threadB error, errorno = %d",errno);
        printf("%s",strerror(errno));
    }
    pthread_join(ta,NULL);
    pthread_join(ta,NULL);

}

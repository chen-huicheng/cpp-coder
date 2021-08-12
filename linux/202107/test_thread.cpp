#include<pthread.h>
#include<vector>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
using namespace std;
void* loop(void *){
    sleep(150);
}
int main(){
    int err=0;
    vector<pthread_t> tids;
    pthread_t tid;
    while((err = pthread_create(&tid,nullptr,loop,nullptr))==0){
        tids.push_back(tid);
    }
    printf("create %d thread\n",tids.size());
    printf("error: %s\n",strerror(err));
    for(auto t:tids){
        pthread_join(t,nullptr);
    }
    printf("exit!\n");
}
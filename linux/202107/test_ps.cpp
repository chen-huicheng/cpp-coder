#include<unistd.h>
#include<iostream>
#include<vector>
#include<sys/wait.h>
using namespace std;
int main(int argv,char *args[]){
    vector<pid_t> pids;
    if(argv!=2){
        cout<<"usage: "<<args[0]<<"  num_process"<<endl;
    }
    int num_process = atoi(args[1]);
    if(num_process <= 0){
        cout<<args[1]<<endl;
    }
    pid_t pid;
    while(num_process--){
        pid = fork();
        if(pid)pids.push_back(pid);
        else{
            cout<<pid<<endl;
            exit(0);
        }
    }
    if(pids.size()>0)
        sleep(16);
    for(pid_t pid:pids){
        int status=0;
        waitpid(pid,&status,0);
    }
    exit(0);
}
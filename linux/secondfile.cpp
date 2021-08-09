#include<fcntl.h>
#include<assert.h>
#include<unistd.h>
#include<sys/sendfile.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string filename="file.txt";
    int fd = open(filename.c_str(),O_WRONLY|O_CREAT);
    if(fd<0){
        cout<<"open file failed!"<<endl;
        assert(0);
    }
    dup2(fd,STDOUT_FILENO);
    string buf;
    while(cin>>buf){
        if(buf=="exit")break;
        cout<<buf<<endl;
    }
    sleep(1000);
    // cout<<"hkkkdk"<<endl;
}
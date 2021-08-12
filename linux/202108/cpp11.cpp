#include<bits/stdc++.h>
using namespace std;
struct A
{
    int a;
    float b;
};
void foo(int *arg){
    cout<<"foo(int*)"<<endl;
}
void foo(int arg){
    cout<<"foo(int)"<<endl;
}


int main(){
    A a{1,1.1};
    cout<<a.a<<a.b<<endl;

    cout<<"nullptr"<<endl;
    int *p=NULL;
    foo(p);
    foo(nullptr);
    return 0;
}
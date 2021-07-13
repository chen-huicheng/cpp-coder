#include<iostream>
using namespace std;
class A{
    public:
    A(){
        cout<<"A()"<<endl;
    }
    ~A(){
        cout<<"~A()"<<endl;
    }
};
A a;
int main(){
    cout<<"main()"<<end;
}
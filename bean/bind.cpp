#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

typedef function<void (int)> Fun_ptr;
typedef function<int (int,int)> Fun_ptr_int;
class A{
public:
    void work(int n){
        cout<<n<<endl;
    }
    int sum(int x,int y){
        return x+y;
    }
    Fun_ptr bind_work(){
        return bind(&A::work,this,_1);
    }
    Fun_ptr_int bind_sum(){
        return bind(&A::sum,this,_1,_2);
    }
};
int main(){
    A a = A();
    Fun_ptr fp = a.bind_work();
    fp(10);
    Fun_ptr_int sum = a.bind_sum();
    cout<<sum(4,5)<<endl;
}
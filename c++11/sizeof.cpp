#include<bits/stdc++.h>
using namespace std;
class A{};
class B:public A{};
class C{
public:
    C(){cout<<"C  "<<this<<endl;};
    virtual ~C(){};
    // int a;
};
class D:public C{};
class E:virtual C{public: E(){cout<<"E  "<<this<<endl;}};
class F:virtual C{public: F(){cout<<"F  "<<this<<endl;}};
class G:public F,public E{public: G(){cout<<"G  "<<this<<endl;}};
int main(){
    cout<<sizeof(A)<<"\t"<<"class A{};"<<endl;
    cout<<sizeof(B)<<"\t"<<"class B:public A{};"<<endl;
    cout<<sizeof(C)<<"\t"<<"class C{public: virtual ~C(){};};"<<endl;
    cout<<sizeof(D)<<"\t"<<"class D:public C{};"<<endl;
    cout<<sizeof(E)<<"\t"<<"class E:virtual C{};"<<endl;
    cout<<sizeof(F)<<"\t"<<"class F:virtual C{};"<<endl;
    cout<<sizeof(G)<<"\t"<<"class G:public E,public F{};"<<endl;
    G g;
}
// 1       class A{};
// 1       class B:public A{};
// 8       class C{public: virtual ~C(){};};
// 8       class D:public C{};
// 8       class E:virtual C{};
// 8       class F:virtual C{};
// 16      class G:public E,public F{}
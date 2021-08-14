#include<bits/stdc++.h>
using namespace std;
class P{
    public:
    P(int a,int b){
        cout<<"P(int,int)"<<endl;
    }
    P(initializer_list<int> initlist){
        cout<<"p(initializer_list<int>)"<<endl;
    }
};

int main(){
    P q(77,5);
    P p{77,5};
    P r{77,5,5};
    P s={33,44};
    return 0;
}
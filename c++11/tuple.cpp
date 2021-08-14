#include <bits/stdc++.h>
using namespace std;
void test_tuple();
void test_pair();
int main()
{
    test_tuple();
    test_pair();
}

void test_tuple(){
    vector<tuple<int,int,string>> t{{1,2,"hhh"},{2,1,"hhh"}};
    for(auto [a,b,c]:t){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
}
void test_pair(){
    vector<pair<int,string>> p{{1,"yao"},{2,"liang"}};
    for(auto [a,b]:p){
        cout<<a<<" "<<b<<endl;
    }
}

/*
output:
1 2 hhh
2 1 hhh
1 yao
2 liang
 */
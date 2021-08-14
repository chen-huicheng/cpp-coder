#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec={12,13,15,24,26,27,35,24};
    auto cmp = [&](const int a,const int b){
        if(a/10==b/10){
            return a%10>b%10;
        }
        return a/10<b/10;
    };
    function<bool(int,int)> f=cmp;
    sort(vec.begin(),vec.end(),f);
    for(auto v:vec)cout<<v<<" ";
    return 0;
}
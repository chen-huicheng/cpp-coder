#include<bits/stdc++.h>
using namespace std;
int work(vector<int> a){
    int min_n=INT_MAX,max_n=INT_MIN;
    for(auto n:a){
        min_n=min(min_n,n);
        max_n=max(max_n,n);
    }
    min_n=min(min_n,0);
    max_n=max(max_n,0);
    return (max_n-min_n)*2;
}
int main(){
    cout<<work({-1,1})<<endl;
    cout<<work({2,1})<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int reverse(int n){
    int res=0;
    while(n){
        res=res*10+n%10;
        n/=10;
    }
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int i=1;i<=k;i++){
        res=max(res,reverse(n*i));
    }
    cout<<res<<endl;
    return 0;
}
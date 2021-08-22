#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long n,m,l,r;
    while(t--){
        cin>>n>>m;
        l=pow(10,n-1);
        r=pow(10,n);
        l=(l-1)/m*m+m;
        if(l<r){
            cout<<l<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
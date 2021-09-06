#include<bits/stdc++.h>
using namespace std;
int main(){
    long long res=0;
    string ac;
    int n;
    cin>>n;
    cin>>ac;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(ac[i]=='c'){
            cnt++;
        }else{
            res+=cnt;
        }
    }
    cout<<res<<endl;
    return 0;
}
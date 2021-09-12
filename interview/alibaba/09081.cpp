#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string kstr;
        while(n){
            kstr.push_back(n%k+'0');
            n/=k;
        }
        // cout<<kstr<<endl;
        long long res=0;
        for(int i=0;i<kstr.size();i++){
            res=res*k+kstr[i]-'0';
        }
        cout<<res<<endl;
    }
    return 0;
}
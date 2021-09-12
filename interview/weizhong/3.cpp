#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y,z,k;
        cin>>k;
        bool flag=false;
        for(x=1;pow(x,5)<k;x++){
            ll sum=pow(x,5);
            for(y=1;pow(y,4)+sum<k;y++){
                sum+=pow(y,4);
                if(pow(pow(k-sum,1.0/3),3)-(k-sum)<=1e-6){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else
        cout<<"NO"<<endl;
    }
    return 0;
}
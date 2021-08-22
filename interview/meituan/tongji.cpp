#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);vector<int> sum(n+1,0),sum2(n+1,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum[i+1]=sum[i]+nums[i];
        sum2[i+1]=sum2[i]+nums[i]*nums[i];
    }
    int m,opt,l,r;
    cin>>m;
    while(m--){
        cin>>opt>>l>>r;
        if(opt==1){
            cout<<sum[r]-sum[l-1]<<endl;
        }else if(opt==2){
            int s=sum[r]-sum[l-1];
            int res=s*s*(r-l+1)+sum2[r]-sum2[l-1]-2*s*(s);
            cout<<res<<endl;
        }else if(opt==3){
            int maxn=-1005;
            for(int i=l;i<=r;i++){
                maxn=max(maxn,nums[i]);
            }
            cout<<maxn<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> nums(n),dp(k+1,LONG_LONG_MIN);
    for(int i=0;i<n;i++)cin>>nums[i];
    dp[0]=dp[1]=0;
    for(int i=0;i<n;i++){
        for(int j=min(i+1,k);j>1;j--){
            // if(j<k&&j==i+1){
            //     dp[j]=dp[j-1]+nums[i]*j;
            //     continue;
            // }
            dp[j]=max(dp[j],dp[j-1])+nums[i]*j;
        }
        dp[1]+=nums[i];
        // for(auto d:dp){
        //     cout<<d<<" ";
        // }
        // cout<<endl;
    }
    cout<<dp[k]<<endl;
    return 0;
}
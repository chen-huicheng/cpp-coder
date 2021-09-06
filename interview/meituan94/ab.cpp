#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    const int mod = 998244353;
    cin>>n;
    if(n<=2){
        cout<<n*2<<endl;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(4,0));
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    for(int i=3;i<=n;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][2])%mod;
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][3];
        dp[i][3]=(dp[i-1][1]+dp[i-1][3])%mod;
    }
    cout<<(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%mod<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> dir={-1,0,1,1,0,-1,-1,1,-1};
int count(int n){
    if(n<=1)return 0;
    vector<vector<int>> dp(n*2+1,vector<int>(n*2+1,0));
    dp[n][n]=-1;
    int x,y;
    for(int i=0;i<8;i++){
        x=n+dir[i];
        y=n+dir[i+1];
        dp[x][y]=-1;
    }
    dp[n*2][0]=1;
    for(int i=n*2;i>=0;i--){
        for(int j=0;j<n*2+1;j++){
            if(dp[i][j]==-1)continue;
            if(j>0&&dp[i][j-1]!=-1){
                dp[i][j]+=dp[i][j-1];
            }
            if(i+1<n*2+1&&dp[i+1][j]!=-1){
                dp[i][j]+=dp[i+1][j];
            }
        }
    }
    return dp[0][n*2];
}
int main(){
    for(int i=1;i<=8;i++){
        cout<<count(i)<<endl;
    }
    return 0;
}
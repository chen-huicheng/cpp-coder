#include<bits/stdc++.h>
using namespace std;
int count(string &str){
    int n=str.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<n;j++){
            if(str[i]==str[j]&&dp[i+1][j-1]!=0){
                dp[i][j]=dp[i][j-1]+dp[i+1][j];
            }
            else {
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    string str;
    cin>>str;
    cout<<count(str)<<endl;
    return 0;
}
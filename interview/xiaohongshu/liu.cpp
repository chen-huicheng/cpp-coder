#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        int n=str.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int l=0,r=0;
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=min(i+1,n/2);j>=i/2+1;j--)
            {
                if(str[i]=='('||str[i]=='?'){
                    dp[j][i+1-j]+=dp[j-1][i+1-j];
                }
                if(str[i]==')'||str[i]=='?')
                    dp[j][i+1-j]+=dp[j][i-j];
                
            }
        }
        cout<<dp[n/2][n/2]<<endl;
    }
    return 0;
}
// ((??))
// ((???((()))((((((()))))(??????
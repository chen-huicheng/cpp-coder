#include<bits/stdc++.h>
using namespace std;
int dis(char a,char b){
    if(a>b){
        swap(a,b);
    }
    return min(b-a,a+26-b);
}
int main(){
    string str;
    int n;
    cin>>str;
    cin>>n;
    if(str.size()<=0){
        cout<<0<<endl;
        return 0;
    }
    int len=str.size();
    vector<int> dp(len,INT_MAX);
    dp[0]=1;
    for(int i=1;i<len;i++){
        dp[i]=dp[i-1]+1+dis(str[i],str[i-1]);
        if(i>=n&&n){
            dp[i]=min(dp[i],dp[i-n]+n*2);
        }
    }
    cout<<dp[len-1]<<endl;
    return 0;
}
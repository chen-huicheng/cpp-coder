#include<bits/stdc++.h>
using namespace std;
bool huiwen(string str){
    int n=str.size();
    if(n==1)return true;
    for(int i=1;i<=n/2;i++){
        if(str.substr(0,i)==str.substr(n-i,i)){
            
            return true;
        }
    }
    return false;
}
int main(){
    string str;
    cin>>str;
    int n=str.size();
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(huiwen(str.substr(j,i-j)))
            {
                dp[i]+=dp[j];
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
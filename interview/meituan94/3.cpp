#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n+1,0);
    int res=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        nums[i]+=nums[i-1];
        if(i>=m&&nums[i]-nums[i-m]>sum){
            sum=nums[i]-nums[i-m];
            res=i-m;
        }
    }
    cout<<res+1<<endl;
    
    return 0;
}
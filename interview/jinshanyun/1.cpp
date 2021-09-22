#include<bits/stdc++.h>
using namespace std;
int res=0;
int n,m;
void dfs(vector<int> &nums,int idx,int k,int sum){
    if(k==0){
        if(sum%m==0){
            res++;
        }
        return;
    }
    for(int i=idx;i+k<=nums.size();i++){
        if(i>idx&&nums[i]==nums[i-1])continue;
        dfs(nums,i+1,k-1,sum+nums[i]);
    }
}
int main(){
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    dfs(nums,0,3,0);
    cout<<res<<endl;
    return 0;
}
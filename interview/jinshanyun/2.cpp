#include<bits/stdc++.h>
using namespace std;
int res=0;
int n;
void dfs(vector<int> &nums,int idx,double sum){
    if(sum-1.0<=1e-6){
        res++;
        return;
    }
    if(sum>1.0){
        return;
    }
    for(int i=idx;i<nums.size();i++){
        dfs(nums,i+1,sum+nums[i]/1.0);
    }
}
int main(){
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    dfs(nums,0,0);
    if(res==0){
        cout<<"No solution!"<<endl;
    }else
    cout<<res<<endl;
    return 0;
}
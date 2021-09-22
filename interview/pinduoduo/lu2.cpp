#include<bits/stdc++.h>
using namespace std;
int res=0;
void dfs(vector<vector<int>>& nums,int i,int j,set<int> &s){
    if(i==nums.size()-1&&j==nums[0].size()-1){
        res++;
        return;
    }
    if(i>=nums.size()||j>=nums[0].size()){
        return;
    }
    if(s.find(nums[i][j])!=s.end()){
        return;
    }
    s.insert(nums[i][j]);
    dfs(nums,i+1,j,s);
    dfs(nums,i,j+1,s);
    s.erase(nums[i][j]);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        if(n+m-1>k){
            cout<<0<<endl;
            continue;
        }
        vector<vector<int>> nums(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>nums[i][j];
            }
        }
        set<int> s;
        res=0;
        dfs(nums,0,0,s);
        cout<<res<<endl;
    }
    return 0;
}
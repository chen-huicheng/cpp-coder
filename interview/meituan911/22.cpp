#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i].first;
        nums[i].second=i;
    }
    sort(nums.begin(),nums.end(),[&](pair<int,int> &a,pair<int,int> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    });
    set<int> idx;
    int m=-1;
    int res=0;
    for(int i=0;i<n;i++){
        // cout<<nums[i].first<<" "<<nums[i].second<<endl;
        idx.insert(nums[i].second);
        m=max(m,nums[i].second);
        if(m+1==idx.size()){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
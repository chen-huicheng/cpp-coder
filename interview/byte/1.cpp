#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i].first>>nums[i].second;
    sort(nums.begin(),nums.end(),[&](pair<int,int> &a,pair<int,int> &b){
        return a.first<b.first;
    });
    size_t res=0;
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<n;i++){
        if(!que.empty()&&que.top()<nums[i].first){
            que.pop();
        }
        que.push(nums[i].first+nums[i].second);
        res=max(res,que.size());
    }
    cout<<res<<endl;
    return 0;
}
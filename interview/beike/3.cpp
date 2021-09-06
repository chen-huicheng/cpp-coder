#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end(),greater<int>());
    int idx=n-1;
    while(idx>=0&&nums[idx]<=m)idx--;
    

    return 0;
}
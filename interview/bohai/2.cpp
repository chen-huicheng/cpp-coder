#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());
    long long res=0;
    for(int i=0;i<n;i++){
        int a=l-nums[i];
        int b=r-nums[i];
        int left=lower_bound(nums.begin()+i+1,nums.end(),a)-nums.begin();
        int right=upper_bound(nums.begin()+i+1,nums.end(),b)-nums.begin();
        res+=right-left;
    }
    cout<<res<<endl;
    return 0;
}
//弹球配对
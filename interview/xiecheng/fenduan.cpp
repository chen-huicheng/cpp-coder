#include<bits/stdc++.h>
using namespace std;
int seg(vector<int> &nums,int m){
    int a=nums[0],b=nums[0];
    int n=nums.size();
    int res=0;
    for(int i=1;i<n;i++){
        a=max(a,nums[i]);
        b=min(b,nums[i]);
        if(a-b>m){
            res++;
            a=b=nums[i];
        }
    }
    return res+1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    int l=0,r=100000;
    while(l<r){
        int mid=(l+r)/2;
        if(seg(nums,mid)>k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}
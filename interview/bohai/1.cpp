#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    int k=sum/n;
    int res=0;
    for(auto num:nums){
        if(num>k)res++;
    }
    cout<<res<<endl;
    return 0;
}

//分糖果
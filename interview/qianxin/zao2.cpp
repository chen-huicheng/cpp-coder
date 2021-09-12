#include<bits/stdc++.h>
using namespace std;
vector<int> findNum(vector<int> nums){
    int sum=0,x=0;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(i>0&&nums[i]==nums[i-1]){
            x=nums[i];
        }
    }
    sum-=x;
    return {x,(1+n)*n/2-sum};
}
int main(){
    auto res=findNum({1,1});
    cout<<res[0]<<" "<<res[1]<<endl;
    res=findNum({1,2,2,4});
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<int> nums(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        nums[i]+=nums[i-1];
    }
    cin>>m;
    int num,idx;
    for(int i=0;i<m;i++){
        cin>>num;
        idx=lower_bound(nums.begin(),nums.end(),num)-nums.begin();
        cout<<idx<<endl;
    }
    return 0;
}
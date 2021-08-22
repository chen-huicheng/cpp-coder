#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<vector<int>> nums(n,vector<int>(2,0));
        for(int i=0;i<n;i++)cin>>nums[i][0]>>nums[i][1];
        sort(nums.begin(),nums.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        int day=1;
        int res=0;
        for(auto num:nums){
            if(num[1]>=day){
                res+=num[0];
                day++;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}

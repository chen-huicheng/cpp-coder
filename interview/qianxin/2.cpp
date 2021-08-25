#include<bits/stdc++.h>
using namespace std;
int func(vector<vector<int>> &nums){
    int ma,mb;
    int n=nums.size();
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        ma=mb=INT_MAX;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            int dis = abs(nums[i][0]-nums[j][0])+abs(nums[i][1]-nums[j][1]);
            if(dis<ma){
                mb=ma;
                ma=dis;
            }else{
                mb=min(mb,dis);
            }
        }
        res=min(res,ma+mb);
    }
    return res;
}
int main(){
    vector<vector<int>> nums{{0,0},{0,2},{1,1},{10,10}};
    cout<<func(nums)<<endl;
    return 0;
}
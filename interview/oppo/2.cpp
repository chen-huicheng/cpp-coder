#include<bits/stdc++.h>
using namespace std;
bool checkReach(vector<int>& nums,int begin){
    queue<int> que;
    que.push(begin);
    int n=nums.size();
    while(!que.empty()){
        int idx=que.front();
        que.pop();
        idx += nums[idx]%n+n;
        idx%=n;
        if(nums[idx]==0){
            return true;
        }
        if(nums[idx]!=-1){
            que.push(idx);
            nums[idx]=-1;
        }
    }
    return false;
}
int main(){
    
    return 0;
}
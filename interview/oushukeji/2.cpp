#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums;
    int num;
    while(cin>>num){
        // if(num==-1)break;
        nums.push_back(num);
    }
    int res=0,idx=0,max_n=0,n=nums.size();
    int i=0;
    while(i<n){
        idx=i;
        while(i<n-1&&nums[i]<=nums[i+1])i++;
        if(i-idx+1>max_n){
            max_n=i-idx+1;
            res=idx;
        }
        i++;
    }
    cout<<res<<endl;
    return 0;
}
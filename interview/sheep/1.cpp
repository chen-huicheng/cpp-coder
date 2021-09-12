#include<bits/stdc++.h>
using namespace std;
int min_n(vector<int> nums,int v){
    vector<int> cap(v+1,0);
    cap[0]=1;
    int res=INT_MAX;
    for(auto num:nums){
        // if(num>v)continue;
        for(int i=v;i>=num;i--){
            if(cap[i-num]){
                cap[i]=1;
                res=min(res,v-i);
            }
        }
    }
    return res;
}
int main(){
    cout<<min_n({8,3,11,7,8,25},24)<<endl;
    return 0;
}
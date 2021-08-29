#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums(10),next(10);
    for(int i=0;i<10;i++)cin>>nums[i];
    int m,key;
    cin>>m;
    map<int,int> ma;
    bool flag=true;
    while(m--){
        next[0]=nums[1]!=nums[9];
        for(int i=1;i<9;i++){
            next[i]=nums[i-1]!=nums[i+1];
        }
        next[9]=nums[8]!=nums[0];
        nums=next;
        if(flag)continue;
        key=0;
        for(int i=0;i<10;i++){
            if(nums[i]==1){
                key+=(1<<i);
            }
        }
        if(ma.find(key)!=ma.end()){
            int step = ma[key]-m;
            m%=step;
            flag=true;
        }
        ma[key]=m;
    }
    for(auto num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
// 1 0 1 1 1 0 1 0 0 1        
// 102451245
// 0 1 0 0 1 1 0 1 1 1 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> pool;
    int a,b,res=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        res+=a*b;
        pool[b]=a;
    }
    int m;
    cin>>m;
    vector<int> nums(m,0);
    for(int i=0;i<m;i++)cin>>nums[i];
    map<int,int> pool2;
    int size;
    sort(nums.begin(),nums.end(),greater<int>());
    for(auto num:nums){
        if(pool2.lower_bound(num)!=pool2.end()){
            size=(*pool2.lower_bound(num)).first;
            pool2[size]--;
            if(pool2[size]==0){
                pool2.erase(size);
            }
            if(size>num)pool2[size-num]++;
        }
        else if(pool.lower_bound(num)!=pool.end()){
            size=(*pool.lower_bound(num)).first;
            res-=size;
            pool[size]--;
            if(pool[size]==0){
                pool.erase(size);
            }
            if(size>num)pool2[size-num]++;
        }
        else{
            res=-1;
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}
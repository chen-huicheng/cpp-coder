#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    map<int,int> nums;
    set<int> se;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)nums[i]=0; 
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(se.find(a*n+b)!=se.end())continue;
        nums[a]+=1;
        nums[b]+=1;
        se.insert(a*n+b);
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        swap(nums[a],nums[b]);
    }
    for(int i=1;i<=n;i++)
        cout<<nums[i]<<" ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int func(int x,int y,int r,vector<tuple<int,int,int>>& nums){
    int i=1,j;
    r=r*r;
    nums.push_back({x,y-r,y+r});
    while((i-x)*(i-x)<r){
        j=sqrt(r-(i-x)*(i-x));
        nums.push_back({x+i,y-j,y+j});
        nums.push_back({x-i,y-j,y+j});
        i++;
    }
}
int main(){
    int n,m,k;
    cin>>n>>m;
    vector<vector<tuple<int,int,int>>> graph(n);
    for(int i=0;i<n;i++){
        graph[i].push_back({1,m,0});
    } 
    int x,y,r;
    vector<tuple<int,int,int>> nums;
    for(int i=1;i<=k;i++){
        cin>>x>>y>>r;
        nums.clear();
        func(x,y,r,nums);
        for(auto [id,l,r]:nums){
            for(int i=0;i<graph[id].size();i++){
                auto [le,ri,kk]=graph[id][i];
                if(kk>k)continue;
                if(ri<l||le>r)continue;
                if(r>le)

            }
        }
    }
    return 0;
}
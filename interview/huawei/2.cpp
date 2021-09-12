#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d,%d",&n,&m);
    vector<vector<int>> nums(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>nums[i][j];
    }
    queue<tuple<int,int>> que;
    que.push({0,0});
    vis[0][0]=1;
    int k=0;
    while(!que.empty()){
        auto [x,y]=que.front();
        if(x==n-1&&y==m-1){
            break;
        }
        que.pop();
        k=nums[x][y];
        for(int i=0;i<=k;i++){
            int a=x+i;
            int b=y+i;
            if(a<n&&nums[a][y]!=0&&vis[a][y]==0){
                vis[a][y]=vis[x][y]+1;
                que.push({a,y});
            }
            if(b<m&&nums[x][b]!=0&&vis[x][b]==0){
                vis[x][b]=vis[x][y]+1;
                que.push({x,b});
            }
        }
    }
    cout<<vis[n-1][m-1]-1<<endl;
    return 0;
}
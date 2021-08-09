#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int> dir = {-1,0,1,0,-1};
bool dfs(vector<vector<int>> &graph,int x,int y,vector<vector<int>> &vis){
    cout<<x<<y<<vis[x][y]<<graph[x][y]<<endl;
    if(x==n-1&&y==m-1){
        return true;
    }
    for(int i=0;i<4;i++){
        int a=x+dir[i];
        int b=y+dir[i+1];
        if(a<0||b<0||a>=n||b>=m)continue;
        if(vis[a][b]!=0&&vis[x][y]>=vis[a][b])continue;
        vis[a][b]=vis[x][y]+1;
        if(vis[a][b]>graph[a][b]+1)continue;
        if(dfs(graph,a,b,vis))return true;
    }
    return false;
}
int main(){
    int t,x,y;
    vector<vector<int>> graph(105,vector<int>(105));
    vector<vector<int>> vis(105,vector<int>(105));
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>graph[i][j];
                vis[i][j]=0;
                if(graph[i][j]==0){
                    x=i;
                    y=j;
                }
            }
        }
        vis[x][y]=1;
        if(dfs(graph,x,y,vis)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

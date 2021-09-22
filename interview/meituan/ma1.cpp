#include<bits/stdc++.h>
using namespace std;
int res=0;
set<string> ss;
void dfs(vector<vector<int>>& graph,vector<int> &vis,int idx,int k){
    if(k==0){
        string str;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==1){
                str+=to_string(i)+",";
            }
        }
        if(ss.find(str)==ss.end()){
            res++;
            ss.insert(str);
        }
        return;
    }
    for(auto next:graph[idx]){
        if(vis[next]==1)continue;
        vis[next]=1;
        dfs(graph,vis,next,k-1);
        vis[next]=0;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(graph,vis,1,4);
        vis[i]=0;
        // cout<<res<<endl;
    }
    cout<<res<<endl;
    return 0;
}


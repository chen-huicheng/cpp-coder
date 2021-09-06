#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> route(m+1,vector<int>());
    vector<vector<int>> site(n+1,vector<int>());
    int k,num;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>num;
            site[i].push_back(num);  // i站点 经过的公交
            route[num].push_back(i); // num 公交能到站点
        }
    }
    vector<set<int>> trans(m+1,set<int>());
    for(int i=1;i<=m;i++){
        for(auto r:route[i]){
            for(auto k:site[r]){
                trans[i].insert(k);
            }
        }
        trans[i].erase(i);
    }
    vector<vector<int>> site(n+1,vector<int>());
    vector<vector<int>> graph(n+1,vector<int>(n+1,INT_MAX));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                graph[i][j]=0;
                continue;
            }
            for(auto s:site[i]){
                if(trans[s].find(j)!=trans[s].end()){
                    graph[i][j]=1;
                    break;
                }
            }
            if(graph[i][j]==1)break;
        }
    }


    return 0;
}
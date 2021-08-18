#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int m,n,x1,y1,x2,y2;
    vector<int> dir={-1,0,1,0,-1};
    vector<int> dir2={-1,0,1,1,0,-1,-1,1,-1};
    while(t--){
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        x2--;
        y2--;
        vector<string> graph(n);
        for(int i=0;i<n;i++)cin>>graph[i];
        queue<tuple<int,int,int>> que;
        int res=-1;
        for(int i=0;i<8;i++){
            int a=x2+dir2[i];
            int b=y2+dir2[i+1];
            if(a<0||b<0||a>=n||b>=m)continue;
            if(graph[a][b]=='.'){
                graph[a][b]='@';
            }
        }
        for(auto g:graph){
            cout<<g<<endl;
        }
        if(graph[x1][y1]=='@'){
            cout<<((x1*x2)^0^(y1*y2))<<endl;
            continue;
        }
        que.push({x1,y1,0});
        graph[x1][y1]='#';
        while(!que.empty()){
            auto [x,y,step]=que.front();
            que.pop();
            for(int i=0;i<4;i++){
                int a=x+dir[i];
                int b=y+dir[i+1];
                if(a<0||b<0||a>=n||b>=m)continue;
                if(graph[a][b]=='#')continue; 
                if(graph[a][b]=='@'){
                    res=step+1;
                    break;
                }
                que.push({a,b,step+1});
                graph[a][b]='#';
            }
            if(res!=-1){
                break;
            }
        }
        if(res==-1){
            cout<<-1<<endl;
        }
        else{
            cout<<((x1*x2)^res^(y1*y2))<<endl;
        }
    }
}
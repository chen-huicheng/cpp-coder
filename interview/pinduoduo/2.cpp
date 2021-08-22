#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int p,q;
        cin>>p>>q;
        if(p==q){
            cout<<0<<endl;
            continue;
        }
        queue<int>que;
        que.push(p);
        vector<int>vis(200005,-1);
        vis[p]=0;
        while(!que.empty()){
            p = que.front();
            que.pop();
            if(p-2>0&&vis[p-2]==-1){
                que.push(p-2);
                vis[p-2]=vis[p]+1;
            }
            if(p-1>0&&vis[p-1]==-1){
                que.push(p-1);
                vis[p-1]=vis[p]+1;
            }
            if(p+1<=200000&&vis[p+1]==-1){
                que.push(p+1);
                vis[p+1]=vis[p]+1;
            }
            if(p*2<=200000&&vis[p*2]==-1){
                que.push(p*2);
                vis[p*2]=vis[p]+1;
            }
            if(vis[q]!=-1){
                break;
            }
        }
        cout<<vis[q]<<endl;
    }
    return 0;
}
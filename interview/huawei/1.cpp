#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &tree,vector<int> &w,int idx){
    if(tree[idx].size()==0){
        return w[idx];
    }
    w[idx]+=dfs(tree,w,tree[idx][0]);
    if(tree[idx].size()>1){
        w[idx]+=dfs(tree,w,tree[idx][1]);
    }
    return w[idx];
}
int main(){
    int n;
    cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    vector<vector<int>> tree(n,vector<int>());
    int f,c;
    for(int i=1;i<n;i++){
        cin>>f>>c;
        tree[f].push_back(c);
    }
    dfs(tree,w,0);
    int res=-1;
    int idx;
    for(int i=1;i<n;i++){
        cout<<w[i]<<endl;
        if(abs(w[0]-w[i]*2)>res){
            idx=i;
            res=abs(w[0]-w[i]*2);
        }
    }
    cout<<idx<<endl;
    return 0;
}

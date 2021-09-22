#include<bits/stdc++.h>
using namespace std;
void dfs(vector<string> &tree,int i,vector<string> &res){
    if(i>=tree.size()){
        return;
    }
    res.push_back(tree[i]);
    dfs(tree,i*2,res);
    dfs(tree,i*2+1,res);
}
int main(){
    vector<string> tree;
    string str;
    tree.push_back("");
    while(cin>>str){
        // if(str=="end")break;
        tree.push_back(str);
    }
    vector<string> res;
    dfs(tree,1,res);
    for(auto r:res){
        cout<<r<<endl;
    }
    return 0;
}
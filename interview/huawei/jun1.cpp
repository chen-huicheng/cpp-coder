#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &opt,int id){
    if(opt[id].size()==2){
        return opt[id][1];
    }
    if(opt[id][0]==1)return opt[id][1];
    int res=0;
    for(int i=2;i<opt[id].size();i++){
        res=max(res,dfs(opt,opt[id][i]));
    }
    opt[id][0]=1;
    opt[id][1]+=res;
    return opt[id][1];
}
int main(){
    int n;
    string str,optname;
    set<int> s;
    getline(cin,str);
    n=stoi(str);
    vector<vector<int>> opt(n);
    for(int i=0;i<n;i++){
        getline(cin,str);
        stringstream in(str);
        in>>optname;
        int tm;
        opt[i].push_back(0);
        in>>tm;
        opt[i].push_back(tm);
        int next;
        while(in>>next){
            opt[i].push_back(next);
            s.insert(next);
        }
    }
    for(int i=0;i<n;i++){
        if(s.find(i)==s.end()){
            cout<<dfs(opt,i)<<endl;
            break;
        }
    }
    return 0;
}
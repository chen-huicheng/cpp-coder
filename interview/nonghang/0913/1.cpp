#include<bits/stdc++.h>
using namespace std;
set<string> sset;
int res=0;
void dfs(string &str,int idx,int n,string &r){
    if(n==0){
        if(sset.find(r)!=sset.end()){
            return;
        }
        do{
            res++;
        }while(next_permutation(r.begin(),r.end()));
        sset.insert(r);
    }
    for(int i=idx;i<str.size();i++){
        r.push_back(str[i]);
        dfs(str,i+1,n-1,r);
        r.pop_back();
        if(str.size()-i-1>=n)
            dfs(str,i+1,n,r);
    }
}
int numPossible(string tiles){
    sort(tiles.begin(),tiles.end());
    int n=tiles.size();
    string r;
    for(int i=1;i<=n;i++){
        dfs(tiles,0,i,r);
    }
    return res;
}
int main(){
    cout<<numPossible("AABBCC")<<endl;
    return 0;
}
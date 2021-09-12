#include<bits/stdc++.h>
using namespace std;
int get(vector<vector<int>> & points){
    map<int,set<int>> po;
    for(auto p:points){
        po[p[0]].insert(p[1]);
    }
    vector<int> key;
    for(auto p:po){
        key.push_back(p.first);
    }
    set<int> inter;
    int res;
    for(int i=0;i<key.size();i++){
        int a=key[i];
        for(int j=i+1;j<key.size();i++){
            int b=key[j];
            inter.clear();
            set_intersection(po[a].begin(), po[a].end(), po[b].begin(), po[b].end(), inserter(inter, inter.begin()));
            int len=inter.size();
            res+=len*(len-1)/2;
        }
    }
	return res;
}
int main(){
    
    return 0;
}
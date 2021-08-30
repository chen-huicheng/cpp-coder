#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> idxs(26,vector<int>());
    string s,a;
    cin>>s>>a;
    int n=s.size();
    int m=a.size();
    for(int i=0;i<n;i++){
        idxs[s[i]-'a'].push_back(i);
    }
    int res=0;
    int preid=-1;
    for(auto c:a){
        if(idxs[c-'a'].size()==0){
            res=-1;
            break;
        }
        auto it=upper_bound(idxs[c-'a'].begin(),idxs[c-'a'].end(),preid);
        if(it==idxs[c-'a'].end()){
            res+=n-preid-1;
            preid=idxs[c-'a'][0];
            res+=preid;
        }else{
            res+=*it-preid-1;
            preid=*it;
        }
    }
    cout<<res<<endl;
    return 0;
}
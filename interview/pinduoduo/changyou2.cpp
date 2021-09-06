#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    sort(strs.begin(),strs.end(),[](string a,string b){
        int na=a.size();
        int nb=b.size();
        
        return false;
    });
    for(auto str:strs){
        cout<<str<<endl;
    }
    return 0;
}
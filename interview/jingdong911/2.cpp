#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<set<int>> a(n+1),b(n+1);
    int k,x,y,m;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>m;
            a[i].insert(m);
            b[m].insert(i);
        }
    }
    set<int> task;
    
    return 0;
}
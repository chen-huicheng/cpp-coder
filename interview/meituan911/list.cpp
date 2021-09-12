#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    map<int,set<int>> li;
    int a,b,c,d;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        li[c].insert(d);
        bool flag=true;
        for(int j=1;j<d;j++){
            if(li[c].find(j)==li[c].end()){
                flag=false;
                break;
            }
        }
        if(flag){
            res+=a;
        }else{
            if(-k<(a-b)){
                res+=(a-b);
            }else{
                li[c].erase(d);
                res-=k;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++){
        res=(3+res)%i;
    }
    cout<<res+1<<endl;
    return 0;
}
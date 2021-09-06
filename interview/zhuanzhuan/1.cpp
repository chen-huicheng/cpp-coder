#include<bits/stdc++.h>
using namespace std;
string maylock(int l,int r,int w){
    if(r>l||w>l)return "YES";
    for(int i=1;i<=r;i++){
        if((w*i)%r+w>l){
            return "YES";
        }
    }
    return "NO";
}
int main(){
    cout<<maylock(9,5,4)<<endl;
    cout<<maylock(9,5,6)<<endl;
    return 0;
}
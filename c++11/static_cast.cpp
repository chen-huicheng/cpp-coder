#include <bits/stdc++.h>
using namespace std;
int padovanSequence(int n){
    if(n<3)return 1;
    return padovanSequence(n-2)+padovanSequence(n-3);
}
int func(int n){
    if(n<3)return 1;
    int a=1,b=1,c=1;
    n-=2;
    int res=0;
    while(n--){
        res=a+b;
        a=b;
        b=c;
        c=res;
    }
    return res;
    
}
int main(){
    for(int i=0;i<15;i++){
        cout<<padovanSequence(i)<<endl;
        cout<<func(i)<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> num1(n),num2(m);
    for(int i=0;i<n;i++)cin>>num1[i];
    for(int i=0;i<m;i++)cin>>num2[i];
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    int len=b-a+1+d-c+1;
    len=(len-1)/2;
    if(len<b-a+1){
        cout<<num1[a+len-1]<<endl;
    }else{
        cout<<num2[c+len-(b-a+1)-1]<<endl;
    }
    return 0;
}
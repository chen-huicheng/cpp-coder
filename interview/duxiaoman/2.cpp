#include<bits/stdc++.h>
using namespace std;
int main(){
    string str,s;
    cin>>str;
    int n,len=str.size();
    cin>>n;
    while(cin>>s){
        bool flag=true;
        for(int i=0;i<len;i++){
            if(str[i]=='X'&&s[i]=='1'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
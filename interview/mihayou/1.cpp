#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        int len=str.size();
        int k=0;
        bool flag=true;
        for(int i=0;i<len;i++){
            if(str[i]=='a')k++;
            if(str[i]=='b')k--;
            if(k<0){
                flag=false;
                break;
            }
        }
        if(flag&&k==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
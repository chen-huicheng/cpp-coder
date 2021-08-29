#include<bits/stdc++.h>
using namespace std;
const string zoom="zoom.us",gov="zoomgov.com";
int main(){
    string url;
    cin>>url;
    long long res=0,k=0;
    if(url.find(zoom)!=url.npos){
        k+=url.find(zoom)+7;
    }
    else if(url.find(gov)!=url.npos){
        k+=url.find(gov)+11;
    }
    if(k==0){
        cout<<0<<endl;
    }else{
        k++;
        if(url[k]=='j'||url[k]=='s'||url[k]=='w'){
            k+=2;
            int i=k;
            cout<<url[i]<<endl;
            while(isdigit(url[i])&&i<url.size()){
                res=res*10+url[i]-'0';
                i++;
            }
            if(i-k>=9&&i-k<=11){
                cout<<res<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }else{
            cout<<0<<endl;
        }
    }
}
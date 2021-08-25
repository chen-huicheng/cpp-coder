#include<bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cin>>in;
    stack<int> sta;
    int res,n=in.size();
    for(int i=0;i<n;i++){
        if(in[i]=='['){
            sta.push(1);
        }else if(in[i]==']'){
            if(i<n&&isdigit(in[i+1])){
                i++;
                int k=in[i]-'0';
                int t =sta.top()*k;
                if(sta.top()!=1)t++;
                sta.pop();
                sta.push(t);
            }
            if(sta.size()>1){
                int a =sta.top();
                sta.pop();
                int b=sta.top();
                sta.pop();
                sta.push(a+b);
            }
            
        }
    }
    while(!sta.empty()){
        res+=sta.top();
        sta.pop();
    }
    cout<< res <<endl;
    
}
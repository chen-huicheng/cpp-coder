#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int k;
    cin>>str;
    cin>>k;
    int n=str.size();
    for(int i=n;i>=0;i--){
        if(str[i]==',')k--;
        if(k==0){
            cout<<str.substr(i+1)<<',';
            cout<<str.substr(0,i)<<endl;
            break;
        }
    }
}





















void trans(string v,vector<int> &res){
    int k=0;
    for(auto c:v){
        if(isdigit(c)){
            k=k*10+c-'0';
        }
        if(c=='.'){
            res.push_back(k);
            k=0;
        }
    }
}
int main(){
    string v1,v2;
    cin>>v1>>v2;
    vector<int> a1,a2;
    trans(v1,a1);
    trans(v2,a2);
    if(a1==a2){
        cout<<0<<endl;
    }
    else if(a1<a2){
        cout<<-1<<endl;
    }
    else{
        cout<<1<<endl;
    }
    
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    const long long mod=1e9+7;
    vector<long long> sta;
    long long k=1;
    for(auto c:str){
        if(c=='('){
            if(k!=1)
                sta.push_back(k);
            sta.push_back(1);
            k=1;
        }else if(c==')'){
            while(!sta.empty()&&sta.back()!=1){
                k=k*sta.back();
                k%=mod;
                sta.pop_back();
            }
            k+=1;
            sta.pop_back();
        }
        for(auto a:sta){
            cout<<a<<" ";
        }
        cout<<"  k:"<<k;
        cout<<endl;
    }
    long long res=k;
    while(!sta.empty()){
        res*=sta.back();
        res%=mod;
        sta.pop_back();
    }
    cout<<res<<endl;
}
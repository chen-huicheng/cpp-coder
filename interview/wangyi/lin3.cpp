#include<bits/stdc++.h>
using namespace std;
int main(){
    long long s;
    cin>>s;
    if(s<=0){
        cout<<-1<<endl;
        return 0;
    }
    string str;
    while(s){
        if(s%2==0)
            str.push_back('0');
        else
            str.push_back('1');
        s/=2;
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    int n=str.size();
    int res=0;
    for(int i=0;i<n;i++){
        if(str[i]=='0')continue;
        int l=i;
        while(l+1<n&&str[l+1]=='1'){
            l++;
        }
        if(l-i>=2){
            res+=2;
            i=l;
        }
        else if(l==i){
            res+=1;
        }
    }
    cout<<res<<endl;
    return 0;
}
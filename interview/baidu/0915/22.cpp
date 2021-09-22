#include<bits/stdc++.h>
using namespace std;
int find(string &str,char c,int &l,int &r){
    for(int i=0;i<str.size();i++){
        if(str[i]==c){
            l=i;
            break;
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]==c){
            r=i;
        }
    }
    return r-l;
}
int main(){
    string str;
    cin>>str;
    int l1=-1,r1=-1,l2=-1,r2=-1;
    find(str,'0',l1,r2);
    int len=r2-l1;
    if(find(str,'0',l1,r1)<find(str,'1',l1,r1)){
        find(str,'1',l1,r2);
        l2=l1+1;
        r1=r2-1;
        cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    }else{
        find(str,'0',l1,r2);
        l2=l1+1;
        r1=r2-1;
        cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    }
    return 0;
}
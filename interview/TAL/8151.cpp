#include<bits/stdc++.h>
using namespace std;
void func(string &str,const string &from,const string &to){
    size_t pos=0;
    while((pos=str.find(from,pos))!=string::npos){
        str.replace(pos,from.length(),to);
        pos+=to.length();
    }
}
int main(){
    string str,from,to;
    cin>>str>>from>>to;
    func(str,from,to);
    cout<<str<<endl;
}
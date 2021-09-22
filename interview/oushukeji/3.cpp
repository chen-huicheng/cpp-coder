#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> li;
    set<string> ss;
    string src,dst,res="";
    while(cin>>src>>dst){
        // if(src=="end")break;
        if(li.find(dst)!=li.end()){
            res="NO";
        }
        li[dst]=src;
        ss.insert(src);
    }
    if(res=="NO"){
        cout<<res<<endl;
        return 0;
    }
    string head;
    for(auto l:li){
        if(ss.find(l.first)==ss.end()){
            head=l.first;
            break;
        }
    }
    vector<string> resli;
    while(li.find(head)!=li.end()){
        resli.push_back(head);
        head=li[head];
        if(resli.size()>li.size()+1){
            break;
        }
    }
    resli.push_back(head);
    // cout<<resli.size()<<li.size();
    if(resli.size()==li.size()+1){
        for(auto r:resli){
            cout<<r<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
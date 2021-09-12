#include<bits/stdc++.h>
using namespace std;
int dfs(map<string,vector<string>> &md,map<string,int> &time,map<string,int> &vis,string &mod){
    
    if(vis[mod]==1||time.find(mod)==time.end()){
        return false;
    }
    if(vis[mod]==2||md[mod].size()==0){
        return time[mod];
    }
    vis[mod]=1;
    int res=0;
    for(auto src:md[mod]){
        int t=dfs(md,time,vis,src);
        if(t<0){
            return t;
        }
        res=max(res,t);
    }
    vis[mod]=2;
    time[mod]+=res;
    return time[mod];
}
int main(){
    map<string,vector<string>> md;
    map<string,int> time,vis;
    string dst,line,str,s;
    cin>>dst;
    while(getline(cin,line)){
        if(line=="end")break;
        int idx=0,len=line.size();
        // cout<<line<<endl;
        while(line[idx]!=','&&idx<len)idx++;
        str=line.substr(0,idx);
        int num=0;
        idx++;
        while(idx<len&&isdigit(line[idx])){
            num=num*10+line[idx++]-'0';
        }
        time[str]=num;
        vis[str]=0;
        // cout<<str<<" "<<num<<endl;
        s.clear();
        for(int i=idx+1;i<len;i++){
            if(line[i]==','){
                md[str].push_back(s);
                s.clear();
            }else
                s.push_back(line[i]);
        }
        md[str].push_back(s);
    }
    int res=time[dst];
    // queue<string> que;
    // map<string,int> vis(time);
    // que.push(dst);
    // vis[dst]=-1;
    // while(!que.empty()){
    //     auto src=que.front();
    //     que.pop();
    //     for(auto mod:md[src]){
    //         if(time.find(mod)==time.end()||vis[mod]==-1){
    //             res=-1;
    //             break;
    //         }
    //         time[mod]+=time[src];
    //         vis[mod]=-1;
    //         res=max(res,time[mod]);
    //         que.push(mod);
    //     }
    //     if(res==-1){
    //         break;
    //     }
    // }
    cout<<dfs(md,time,vis,dst)<<endl;
    return 0;
}
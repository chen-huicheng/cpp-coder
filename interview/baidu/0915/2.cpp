#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PP;
int main(){
    int n,q;
    cin>>n>>q;
    priority_queue<PP,vector<PP>,greater<PP>> que;
    que.push(make_pair(1,n));
    int k,s,e;
    for(int i=1;i<=q;i++){
        cin>>k;
        int res=0;
        int pre=1;
        auto p=que.top();
        que.pop();
        s=p.first;
        e=p.second;
        if(s==1){
            s=2;
            e--;
        }
        que.push(make_pair(s,e));
        if(k==0){
            cout<<res<<" ";
            continue;
        }
        while(k){
            auto p=que.top();
            que.pop();
            s=p.first;
            e=p.second;
            if(e<=k){
                k-=e;
                res+=e*(s-pre);
                pre+=e;
            }else{
                res+=k*(s-pre);
                pre+=k;
                que.push(make_pair(s+k,e-k));
                k=0;
            }
        }
        que.push(make_pair(1,pre-1));
        cout<<res<<endl;
    }
    return 0;
}
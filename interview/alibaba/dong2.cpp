#include<bits/stdc++.h>
using namespace std;
int getMid(vector<int> &nums,int l,int r){
    int n=r-l;
    int le,ri;
    le=0;
    int k=1;
    while(n){
        if(n<=k){
            le+=n;
            break;
        }
        le+=k;
        n-=k;
        if(n<=k)break;
        n-=k;
        k*=2;
    }
    return l+le;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> ans;
        queue<pair<int,int>> que;
        for(int i=0;i<n;i++)cin>>nums[i];
        sort(nums.begin(),nums.end());
        int idx = getMid(nums,0,n-1);
        ans.push_back(nums[idx]);
        que.push(make_pair(0,idx-1));
        que.push(make_pair(idx+1,n-1));
        while(!que.empty()){
            auto f=que.front();
            int a=f.first;
            int b=f.second;
            que.pop();
            if(a>b)break;
            if(a==b){
                ans.push_back(nums[a]);
                continue;
            }
            int idx = getMid(nums,a,b);
            ans.push_back(nums[idx]);
            que.push(make_pair(a,idx-1));
            que.push(make_pair(idx+1,b));
        }
        for(auto a:ans)cout<<a<<" ";
        cout<<endl;
    }
}
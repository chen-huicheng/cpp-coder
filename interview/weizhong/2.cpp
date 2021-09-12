#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll> nums(n),res(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    ll ji=0,ou=0;
    for(int i=1;i<=n;i++){
        if(i%2){
            res[i-1]=nums[i-1]+ou-ji;
            ji+=res[i-1];
        }
        else{
            res[i-1]=ji-nums[i-1]-ou;
            ou+=res[i-1];
        }
    }
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll quick_pow(ll x,ll n){  //x^n % m
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
ll res=0;
void Ck(vector<int> &nums,int k,int idx,vector<int> &vis){
    if(k==0){
        ll tmp=1;
        for(auto v:vis){
            tmp*=v;
            tmp%=mod;
        }
        res+=tmp;
        res%=mod;
        return;
    }
    for(int i=idx;i<26;i++){
        if(nums[i]){
            vis.push_back(nums[i]);
            Ck(nums,k-1,i+1,vis);
            vis.pop_back();
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    vector<int> nums(26,0);
    for(auto c:str){
        nums[c-'a']++;
    }
    for(int i=0;i<26;i++){
        nums[i]=quick_pow(2,nums[i])-1;
    }
    vector<int> vis;
    Ck(nums,k,0,vis);
    cout<<res<<endl;
    return 0;
}
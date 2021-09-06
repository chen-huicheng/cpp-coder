// #include<bits/stdc++.h>
// using namespace std;
// long long mergenprops(vector<int> &a){
//     int n=a.size();
//     vector<vector<long long>> dp1(n,vector<long long>(n));
//     vector<vector<long long>> dp2(n,vector<long long>(n));
//     for(int i=2;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             for(int k=j;k<j+i;k++){
//                 dp1[j][j+i]=dp[j][k]
//             }
//         }
//     }
// }
// int main(){
    
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int f(string s){
    int l=0,r=s.size()-1;
    int res=0;
    while(l<r){
        res+=abs(s[l]-s[r]);
    }
    return res;
}
int main(){
    
    return 0;
}

int f(vector<int> arr,int k){
    if(arr.size()==0)return 0;
    if(arr.size()==1)return abs(k-arr[0]);
    int l=INT_MAX,r=INT_MIN;
    for(auto a:arr){
        l=min(l,a);
        r=max(r,a);
    }
    if(l>k){
        return r-k;
    }else if(r<k){
        return k-l;
    }
    else{
        return min(k-l,r-k)+r-l;
    }
}
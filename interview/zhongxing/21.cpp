#include<bits/stdc++.h>
using namespace std;
int check(vector<int> &a,vector<int> &b){
    int n=a.size();
    int l=0,r=0;
    while(l<n&&r<n){
        while(l<n&&a[l]<=b[r])l++;
        if(l>=n)break;
        r++;
        l++;
    }
    return r;
}
int solve(vector<int> &a,vector<int> &b,vector<int> c,int k){
    int n=a.size();
    if(k>n)return -1;
    sort(c.begin(),c.end());
    int min_c=c[n-1],l=0,r=0;
    for(int i=0;i<n;i++){
        if(a[i]<min_c&&b[i]<=0){
            return -1;
        }
        r=max(r,(min_c-a[i])/b[i]+1);
    }
    vector<int> nums(n);
    while(l<r){
        int mid=(l+r)/2;
        for(int i=0;i<n;i++){
            nums[i]=a[i]+b[i]*mid;
        }
        sort(nums.begin(),nums.end());
        int tmp = check(nums,c);
        if(tmp<k){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}

int main(){
    
    vector<int> a={1,2,3};
    vector<int> b={2,1,2};
    vector<int> c={0,3,4};
    int k=2;
    cout<<solve(a,b,c,k)<<endl;
    return 0;
}
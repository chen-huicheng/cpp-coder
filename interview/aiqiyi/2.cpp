#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    vector<int> nums;
    while(cin>>str){
        int k=0;
        for(auto c:str){
            if(isdigit(c)){
                k=k*10+c-'0';
            }
            else{
                nums.push_back(k);
                k=0;
            }
        }
        nums.push_back(k);
        int minn=nums[0],maxn=nums[0];
        int n=nums.size(),res=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                minn=nums[i];
            }else{
                maxn=nums[i];
            }
            res=max(res,maxn-minn);
        }
        cout<<res<<endl;
        nums.clear();
    }
    return 0;
}

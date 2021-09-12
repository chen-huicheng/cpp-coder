#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PP;
typedef vector<PP> VPP;
int prase(string &str,VPP &res){
    int n=str.size(),idx=0;
    int num=-1;
    vector<int> nums;
    for(int i=0;i<n;i++){
        if(isdigit(str[i])){
            if(num==-1)num=0;
            num=num*10+str[i]-'0';
        }else{
            if(num!=-1)nums.push_back(num);
            num=-1;
        }
    }
    for(int i=0;i<nums.size();i+=2){
        res.push_back(make_pair(nums[i],nums[i+1]));
    }
}
int main(){
    string str;
    getline(cin,str);
    VPP nums;
    prase(str,nums);
    // for(auto n:nums){
    //     cout<<n.first<<" "<<n.second<<endl;
    // }
    sort(nums.begin(),nums.end(),[](PP &a,PP &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    });
    int end=0,res=0;
    for(int i=0;i<nums.size();i++){
        if(i!=0&&nums[i].first<end){
            res++;
            continue;
        }
        end=nums[i].second;
    }
    cout<<res<<endl;
    return 0;
}


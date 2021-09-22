#include<bits/stdc++.h>
using namespace std;
int main(){
    string num1,num2;
    cin>>num1>>num2;
    bool flag=false;
    if(num1[0]=='-'){
        flag=!flag;
    }
    if(num2[0]=='-'){
        flag=!flag;
    }
    vector<int> nums1,nums2;
    for(int i=num1.size()-1;i>=0;i--){
        if(isdigit(num1[i]))
            nums1.push_back(num1[i]-'0');
    }
    for(int i=num2.size()-1;i>=0;i--){
        if(isdigit(num2[i]))
            nums2.push_back(num2[i]-'0');
    }
    vector<int> res(num1.size()+nums2.size(),0);
    for(int i=0;i<nums1.size();i++){
        int k=0;
        for(int j=0;j<nums2.size();j++){
            res[j+i]+=nums1[i]*nums2[j]+k;
            k=res[j+i]/10;
            res[j+i]%=10;
        }
        if(k){
            res[i+nums2.size()]+=k;
        }
    }
    int idx=num1.size()+nums2.size()-1;
    while(res[idx]==0)idx--;
    if(idx<0){
        cout<<0<<endl;
        return 0;
    }
    string ans;
    if(flag){
        ans.push_back('-');
    }
    for(int i=idx;i>=0;i--){
        ans+=to_string(res[i]);
    }
    cout<<ans<<endl;
    return 0;
}
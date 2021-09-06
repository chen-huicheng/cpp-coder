#include<bits/stdc++.h>
using namespace std;
void input(vector<int> &nums){ //读取一行不确定个数的整数
    string str;
    getline(cin,str);
    int num=0;
    for(char c:str)
    {
        if(isdigit(c)){
            num=num*10+c-'0';
           
        }else{
            nums.push_back(num);
            num=0;
        }
    }
    nums.push_back(num);
}
int main(){
    int m,n;
    scanf("m=%d,n=%d\n",&m,&n);
    vector<int> nums1;
    vector<int> nums2;
    input(nums1);
    input(nums2);
    // for(auto n1:nums1)cout<<n1;
    // for(auto n2:nums2)cout<<n2;
    int i=0,j=0;
    while(i<m||j<n){
        if(j==n)cout<<nums1[i++]<<" ";
        else if(i==m)cout<<nums2[j++]<<" ";
        else if(nums1[i]<nums2[j])cout<<nums1[i++]<<" ";
        else cout<<nums2[j++]<<" ";
    }
    cout<<endl;
    return 0;
}
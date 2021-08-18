#include<bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cin>>in;
    int n,k;
    vector<int> nums;
    int tmp=0;
    for(int i=0;i<in.size();i++){
        if(in[i]==','){
            nums.push_back(tmp);
            tmp=0;
        }else if(isdigit(in[i])){
            tmp=tmp*10+in[i]-'0';
        }
    }
    n=nums.size()-1;
    k=tmp;
    nums.pop_back();
    sort(nums.begin(),nums.end());
    cout<<nums[k-1]<<endl;
    return 0;
}
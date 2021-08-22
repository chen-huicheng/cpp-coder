#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str;
    cin>>n;
    cin>>str;
    int zero=0,one=0;
    vector<vector<int>> nums(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            zero++;
        }else{
            one++;
        }
        nums[i][0]=zero;
        nums[i][1]=one;
    }
    vector<int> res(n,1);
    for(int t=1;t<=n/2;t++){
        int o = one=nums[t-1][1];
        int z = zero=nums[t-1][0];
        for(int i=t-1;i<n;i+=t){
            if(nums[i][0]==zero&&nums[i][1]==one){
                zero+=z;
                one+=o;
                res[i]=max(res[i],(i+1)/t);
            }else{
                break;
            }
        }
    }
    for(auto r:res){
        cout<<r<<" ";
    }
}
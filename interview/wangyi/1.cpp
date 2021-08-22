#include<bits/stdc++.h>
using namespace std;
char func(int n,int k){
    vector<int> nums={0};
    int len=0;
    for(int i=0;i<n;i++){
        len=len*2+1;
        nums.push_back(len);
    }
    int cnt=0;
    while(n){
        if(k==nums[n-1]+1){
            break;
        }
        if(k>nums[n-1]){
            k=nums[n]-k+1;
            cnt++;
        }
        n--;
    }
    if(cnt%2==0){
        return 'a'+n-1;
    }
    else{
        return 'a'+26-n;
    }
}

int main(){
    // vector<string> tmp;
    // tmp.push_back("a");
    // for(int i=1;i<26;i++){
    //     string t=tmp[i-1];
    //     t.push_back('a'+i);
    //     for(int j=tmp[i-1].size()-1;j>=0;j--){
    //         t.push_back(26-(tmp[i-1][j]-'a')-1+'a');
    //     }
    //     tmp.push_back(t);
    //     if(i<5)cout<<tmp[i]<<endl;
    // }
    // int k=1;
    // for(int i=0;i<26;i++){
    //     for(int j=0;j<k;j+=1){
    //         if(func(i+1,j+1)!=tmp[i][j]){
    //             cout<<i<<" "<<j<<endl;
    //         }
    //     }
    //     k=k*2+1;
    //     cout<<i<<endl;
    // }
    // for(int i=0;i<15;i++){
    //     cout<<func(1,i+1);
    // }
}
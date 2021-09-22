#include<bits/stdc++.h>
using namespace std;
string solution(vector<int> &arr){
    sort(arr.begin(),arr.end(),greater<int>());
    int sum=0,n=arr.size();
    vector<int> cnt(3,0);
    string res;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        cnt[arr[i]%3]++;
    }
    if(sum%3==2){
        if(cnt[2]!=0){
            cnt[2]--;
        }else{
            cnt[1]-=2;
        }
    }
    else if(sum%3==1){
        cnt[1]--;
    }
    for(int i=0;i<n;i++){
        if(cnt[arr[i]%3]==0) continue;
        cnt[arr[i]%3]--;
        res+=to_string(arr[i]);
    }
    return res;
}
int main(){
    vector<int> arr{3,6,7};
    cout<<solution(arr)<<endl;
    return 0;
}
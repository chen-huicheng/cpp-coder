#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &arr){
    sort(arr.begin(),arr.end());
    int res=0,n=arr.size();
    int sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=arr[i];
        if(sum<=0){
            break;
        }
        res+=sum;
    }
    return res;
}
int main(){
    vector<int> arr{-1,1,4,-8,-9};
    cout<<solution(arr)<<endl;
    return 0;
}
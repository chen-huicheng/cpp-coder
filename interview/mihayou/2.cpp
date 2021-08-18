#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    unordered_map<int,int> m1,m2;
    int max1,max2;
    max1=max2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            m1[nums[i]]++;
            if(m1[nums[i]]>max1){
                max1=m1[nums[i]];
            }
        }
        else{
            m2[nums[i]]++;
            if(m2[nums[i]]>max2){
                max2=m2[nums[i]];
            }
        }
    }
    cout<<n-max1-max2<<endl;
}
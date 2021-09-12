#include<bits/stdc++.h>
using namespace std;
vector<float> getAVG(vector<float> raw_data,int K){
    std::vector<float> res;
    float sum=0;
    int n=raw_data.size();
    for(int i=0;i<n;i++){
        sum+=raw_data[i];
        if(i>=K){
            sum-=raw_data[i-K];
        }
        if(i>=K-1)res.push_back(sum/K);
    }
    return res;
}
int main(){
    vector<float> nums={}
    return 0;
}
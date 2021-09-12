#include<bits/stdc++.h>
using namespace std;
vector<string> scoresort(vector<string> names,vector<string> scores){
    int n=names.size();
    std::vector<int>sums(n,0);
    for(int i=0;i<n;i++){
        int num=0;
        for(int j=0;j<scores[i].size();j++){
            if(isdigit(scores[i][j])){
                num=num*10+scores[i][j]-'0';
            }else{
                sums[i]+=num;
                num=0;
            }
        }
        sums[i]+=num;
        cout<<sums[i]<<endl;
    }
    for(int i=0;i<n;i++){
        int max_n=sums[i];
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(sums[j]>max_n){
                max_n=sums[j];
                idx=j;
            }
        }
        swap(names[i],names[idx]);
        swap(sums[i],sums[idx]);
    }
    return names;
}
int main(){
    auto res=scoresort({"a","b","c"},{{"1,4,4"},{"2,2,4"},{"4,3,5"}});
    for(auto r:res)cout<<r<<" ";
    return 0;
}
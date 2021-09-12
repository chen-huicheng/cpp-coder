#include<bits/stdc++.h>
using namespace std;
bool isContinues(vector<int>& data){
    sort(data.begin(),data.end());
    int k[6]={0},cnt=0,m=65555;
    for(int i=0;i<5;i++){
        if(data[i]==0){
            cnt++;
            continue;
        }
        m=min(m,data[i]);
        if(data[i]-m>=5||k[data[i]-m]==1){
            return false;
        }
        k[data[i]-m]=1;
    }
    return true;
}
int main(){
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool check(string s1,string s2){
    vector<int> num1(300,0),num2(300,0);
    for(auto c:s1){
        num1[c]++;
    }
    int k=s1.size();
    for(int i=0;i<s2.size();i++){
        num2[s2[i]]++;
        if(i>=k){
            num2[s2[i-k]]--;
        }
        if(i>=k-1&&num1==num2){
            return true;
        }
    }
    return false;
}
int main(){
    
    return 0;
}
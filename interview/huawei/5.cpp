#include<bits/stdc++.h>
using namespace std;
bool isaeiou(char c){
    string str="aeiou";
    for(int i=0;i<5;i++){
        if(c==str[i]){
            return true;
        }
    }
    return false;
}
int main(){
    string str;
    cin>>str;
    int l=0,r=str.size()-1;
    while(l<r){
        while(l<r&&!isaeiou(str[l]))l++;
        while(l<r&&!isaeiou(str[r]))r--;
        swap(str[l],str[r]);
        l++,r--;
    }
    cout<<str<<endl;
    return 0;
}
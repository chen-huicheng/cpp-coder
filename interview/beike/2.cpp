#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    int n;
    string str;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str;
        int l=0,r=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                l++;
            }else{
                r++;
                if(r-l>0){
                    res++;
                    r--;
                }  
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
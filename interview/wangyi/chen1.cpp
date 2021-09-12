#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int n;
    cin>>str>>n;
    int len=str.size();
    int l=0;
    int res=0;
    for(int i=0;i<len;i++){
        if(str[i]=='0'&&n==0){
            while(l<=i&&str[l]!='0'){
                l++;
            }
            l++;
            n++;
        }
        if(str[i]=='0'){
            n--;
        }
        res=max(res,i-l+1);
    }
    cout<<res<<endl;
    return 0;
}



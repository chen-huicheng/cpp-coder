#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string n,res;
        cin>>n;
        for(int i=0;i<n.size();i++){
            if(n[i]>'3'){
                while(i<n.size()){
                    res.push_back('3');
                    i++;
                }
                break;
            }else if(n[i]=='0'){
                while(!res.empty()&&res.back()<='1'){
                    res.pop_back();
                }
                if(!res.empty()){
                    char c = res.back();
                    res.pop_back();
                    res.push_back(c-1);
                    while(res.size()<n.size()){
                        res.push_back('3');
                    }
                }else{
                    while(res.size()<n.size()-1){
                        res.push_back('3');
                    }
                }
                break;
            }else{
                res.push_back(n[i]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
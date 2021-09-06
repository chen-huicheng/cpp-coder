#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<4){
            cout<<0<<endl;
            continue;
        }
        long long w=1,h=1;
        n=n-4;
        long long res=1;
        while(n>=3){
            n-=3;
            res++;
            if(h>=w){
                swap(h,w);
            }
            if(n/2>=w-1){
                n-=(w-1)*2;
                res+=w-1;
            }else{
                res+=n/2;
                n=0;
                break;
            }
            h++;
        }
        cout<<res<<endl;
    }
    return 0;
}
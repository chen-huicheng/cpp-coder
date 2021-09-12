#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        long long l=0,r=m,mid,sum;
        long long s=(1+m*n)*m*n/2,res=LONG_LONG_MAX;
        int v=-1,h=-1;
        while(l<r){
            mid=(l+r)/2;
            sum=(1+1+(n-1)*m)*n/2*mid+(n+n*(mid-1))*(mid-1)/2;
            if(res>abs(s-sum*2)){
                res=abs(s-sum*2);
                mid--;
                sum=(1+1+(n-1)*m)*n/2*mid+(n+n*(mid-1))*(mid-1)/2;
                if(res==abs(s-sum*2))
                    v=mid+1;
                else
                    v=mid+2;
            }
            if(sum<s/2){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        l=0,r=n;
        while(l<r){
            mid=(l+r)/2;
            sum=(1+m*mid)*m*mid/2;
            if(res>abs(s-sum*2)){
                res=abs(s-sum*2);
                mid--;
                sum=(1+m*mid)*m*mid/2;
                if(res==abs(s-sum*2))
                    h=mid+1;
                else
                    h=mid+2;
            }
            if(sum<s/2){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        if(h!=-1){
            cout<<"H "<<h<<endl;
        }else{
            cout<<"V "<<v<<endl;
        }
    }
    return 0;
}
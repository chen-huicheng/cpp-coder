#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    int n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<int> a(101,0),b(101,0);
        int id;
        for(int i=0;i<n;i++){
            cin>>id;
            a[id]++;
        }
        for(int i=0;i<m;i++){
            cin>>id;
            b[id]++;
        }
        int res=0;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                if(abs(i-j)<=k){
                    if(b[j]<=a[i]){
                        a[i]-=b[j];
                        res+=b[j];
                        b[j]=0;
                    }
                    else{
                        b[j]-=a[i];
                        res+=a[i];
                        a[i]=0;
                        break;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
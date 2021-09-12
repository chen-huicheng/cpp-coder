#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int t, n, m;
    cin >> t;
    vector<int> prim;
    for(int i=2;i<10000;i++){
        if(isPrime(i))prim.push_back(i);
    }
    while (t--)
    {
        cin>>n>>m;
        int k;
        map<int,int> pm;
        for(int i=0;i<n;i++){
            cin>>k;
            for(auto p:prim){
                while(k%p==0){
                    pm[p]++;
                    k/=p;
                }
                if(k<=1)break;
            }
        }
        for(int i=0;i<m;i++){
            cin>>k;
            for(auto p:prim){
                while(k%p==0){
                    pm[p]--;
                    k/=p;
                }
                if(k<=1)break;
            }
        }
        bool flag=true;
        for(auto p:pm){
            if(p.second<0){
                flag=false;
            }
        }
        if(flag)
            cout<<"yes"<<endl;
        else 
            cout<<"no"<<endl;
    }
    return 0;
}
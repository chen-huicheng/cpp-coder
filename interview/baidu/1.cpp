#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n,vector<int>(n)),b(n*k,vector<int>(n*k));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n*k;i++){
        for(int j=0;j<n*k;j++){
            b[i][j]=a[i/k][j/k];
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    // for(int i=0;i<n*k;i++){
    //     for(int j=0;j<n*k;j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
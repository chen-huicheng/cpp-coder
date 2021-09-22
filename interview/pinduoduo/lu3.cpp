#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir{{},{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<int> opt(n);
        for(int i=0;i<n;i++)cin>>opt[i];
        vector<vector<int>> xx(m,vector<int>(2,0)),yy(m,vector<int>(2,0));
        for(int i=0;i<m;i++){
            cin>>xx[i][0];
            cin>>yy[i][0];
            xx[i][1]=i;
            yy[i][1]=i;
        }
        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());
        int a=1,b=1,da,db;
        for(int i=0;i<n;i++){
            a+=dir[opt[i]][0];
            b+=dir[opt[i]][1];
            if(opt[i]==1){
                for(int j=0;j<m;j++){
                    if(xx[j][0]<a){
                        xx[j][0]=a;
                    }else{
                        break;
                    }
                }
            }else if(opt[i]==2){
                for(int j=0;j<m;j++){
                    if(yy[j][0]<b){
                        yy[j][0]=b;
                    }else{
                        break;
                    }
                }
            }else if(opt[i]==3){
                for(int j=m-1;j>=0;j--){
                    if(xx[j][0]>a+x-1){
                        xx[j][0]=a+x-1;
                    }else{
                        break;
                    }
                }
            }else if(opt[i]==4){
                for(int j=m-1;j>=0;j--){
                    if(yy[j][0]>b+y-1){
                        yy[j][0]=b+y-1;
                    }else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>> res(m,vector<int>(2,0));
        for(int i=0;i<m;i++){
            res[xx[i][1]][0]=xx[i][0];
            res[yy[i][1]][1]=yy[i][0];
        }
        for(int i=0;i<m;i++){
            cout<<res[i][0]-a+1<<" "<<res[i][1]-b+1<<endl;
        }
    }
    return 0;
}
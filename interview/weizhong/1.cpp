#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<int>> nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>nums[i][j];
    }
    int a=0,b=0;
    string str;
    cin>>str;
    int len=str.size();
    int res=0;
    vector<int> dir{-1,0,1,0,-1};
    vector<int> mk(26);
    mk['h'-'a']=0;
    mk['k'-'a']=1;
    mk['j'-'a']=2;
    mk['l'-'a']=3;
    for(int i=0;i<len;i++){
        if(i>0&&str[i]!=str[i-1]){
            res+=x;
        }
        int aa =a+dir[mk[str[i]-'a']];
        int bb =b+dir[mk[str[i]-'a']+1];
        if(a<0||a>=n||b<0||b>=m||nums[a][b]==-1){
            res+=y;
        }else{
            res+=max(nums[a][b],nums[aa][bb]);
            a=aa;
            b=bb;
        }
    }
    cout<<res<<endl;
    return 0;
}
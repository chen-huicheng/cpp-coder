#include<bits/stdc++.h>
using namespace std;
vector<int> dir{-1,1,0,1,1,-1,0,-1,-1};
bool check(vector<string> &air,int i,int j){
    int n=air.size();
    int m=air[i].size();
    for(int k=0;k<8;k++){
        int a=i+dir[k];
        int b=j+dir[k+1];
        if(a<0||a>=n||b<0||b>=m)continue;
        if(air[a][b]=='#'){
            return false;
        }
    }
    return true;
}
int main(){
    int n,c;
    cin>>n>>c;
    vector<string> air(n);
    for(int i=0;i<n;i++)
    {
        cin>>air[i];
    }
    vector<string> res;
    string tmp;
    int begin,end,x,y;
    begin=0;
    end=3;
    for(int i=0;i<n;){
        int cnt=0;
        for(int j=begin;j<end;j+=2){
            if(air[i][j]=='.'&&check(air,i,j)){
                cnt++;
                air[i][j]='#';
                tmp=to_string(i+1);
                tmp.push_back('A'+(j<3?j:j-3));
                res.push_back(tmp);
                x=i,y=j;
            }
        }
        int j=begin+1;
        if(i>0&&cnt<=1&&air[i-1][j]=='.'){
            air[x][y]='.';
            if(!check(air,i-1,j)){
                air[x][y]='#';
                continue;
            }
            air[i-1][j]='#';
            tmp=to_string(i);
            tmp.push_back('A'+(j<3?j:j-3));
            res.pop_back();
            res.push_back(tmp);
        }
        begin+=6;
        end+=6;
        if(begin>6){
            begin=0;
            end=3;
            i++;
        }
    }
    if(c<=res.size()){
        cout<<"SUCCESS"<<endl;
        for(int i=0;i<c;i++){
            cout<<res[i]<<endl;
        }
    }
    else{
        cout<<"FAILED"<<endl;
    }
    return 0;
}




#include<bits/stdc++.h>
using namespace std;
vector<int> dir{-1,1,0,1,1,-1,0,-1,-1};
bool check(vector<string> &air,int i,int j){
    int n=air.size();
    int m=air[i].size();
    for(int k=0;k<8;k++){
        int a=i+dir[k];
        int b=j+dir[k+1];
        if(a<0||a>=n||b<0||b>=m)continue;
        if(air[a][b]=='#'){
            return false;
        }
    }
    return true;
}
int main(){
    int n,c,len;
    cin>>n>>c;
    len=c;
    vector<string> air(n);
    for(int i=0;i<n;i++)
    {
        cin>>air[i];
    }
    vector<string> res;
    string tmp;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<air[i].size();j++){
            if(j%2==0&&j!=4&&air[i][j]=='.'&&check(air,i,j)){
                c--;
                air[i][j]='#';
                tmp=to_string(i+1);
                tmp.push_back('A'+(j<3?j:j-3));
                res.push_back(tmp);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<air[i].size();j++){
            if((j==1||j==7)&&air[i][j]=='.'&&check(air,i,j)){
                c--;
                air[i][j]='#';
                tmp=to_string(i+1);
                tmp.push_back('A'+(j<3?j:j-3));
                res.push_back(tmp);
            }
        }
    }
    if(c<=0){
        cout<<"SUCCESS"<<endl;
        for(int i=0;i<len;i++){
            cout<<res[i]<<endl;
        }
    }
    else{
        cout<<"FAILED"<<endl;
    }
    return 0;
}
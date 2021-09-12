#include<bits/stdc++.h>
using namespace std;
int find(vector<string> Rel_Matrix){
    int n=Rel_Matrix.size();
    std::vector<int> point(n,0);
    for(int i=0;i<n;i++){
        int idx=0;
        for(int j=0;j<Rel_Matrix[i].size();j++){
            if(isdigit(Rel_Matrix[i][j])){
                point[idx++]+=Rel_Matrix[i][j]-'0';
            }
        }
    }
    int max_n=-1,res=-1;
    for(int i=0;i<n;i++){
        if(point[i]>max_n){
            max_n=point[i];
            res=i;
        }
    }
    return res;
}
int main(){
    vector<string> in(5);
    for(int i=0;i<5;i++)cin>>in[i];
    cout<<find(in)<<endl;
    return 0;
}
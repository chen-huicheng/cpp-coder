#include <iostream>
#include<vector>
using namespace std;
vector<int> dir={1,0,-1,0,1};
void check(vector<vector<int>> &matrix,int x,int y,int key,vector<vector<int>> &nums){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<4;i++){
        int a=x+dir[i];
        int b=y+dir[i+1];
        if(a<0||b<0||a>=n||b>=m)continue;
        if(matrix[a][b]!=key)continue;
        vector<int> tmp{a,b};
        nums.push_back(tmp);
        matrix[a][b]=-1;
        check(matrix,a,b,key,nums);
        matrix[a][b]=key;
    }
}
void clean(vector<vector<int>> &matrix){
    int n=matrix.size();
    if(n==0)return;
    int m=matrix[0].size();
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1)continue;
            int key = matrix[i][j];
            matrix[i][j]=-1;
            vector<int> tmp{i,j};// vector<int> tmp{i,i};
            nums.push_back(tmp);
            check(matrix,i,j,key,nums);
            matrix[i][j]=key;
            if(nums.size()>=3){
                cout<<i<<" "<<j<<" "<<key<<endl;
                for(auto num:nums){
                    cout<<num[0]<<" "<<num[1]<<endl;
                    matrix[num[0]][num[1]]=-1;
                }
            }
            nums.clear();
        }
    }
}
int main() {
    vector<vector<int>> matrix = {
   {1, 2, 3, 4, 5, 6},
   {2, 2, 2, 2, 3, 1},
   {1, 2, 3, 1, 1, 6},
   {9, 8, 4, 8, 1, 5},
   {7, 4, 7, 1, 5, 1},
   {3, 3, 7, 1, 3, 3}};
    clean(matrix);
    for(auto line:matrix){
        for(auto it:line){
            cout<<it<<"\t";
        }
        cout<<endl;
    }
}
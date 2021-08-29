#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++){
        cin >> str;
        int k = 0;
        for (auto c : str){
            if (isdigit(c))
                k = k * 10 + c - '0';
            else{
                nums[i].push_back(k);
                k = 0;
            }
        }
        nums[i].push_back(k);
    }

    int a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)continue;
            a=i>0?nums[i-1][j]:INT_MAX;
            b=j>0?nums[i][j-1]:INT_MAX;
            nums[i][j]+=min(a,b);
        }
    }
    cout<<nums[n-1][n-1]<<endl;
    return 0;
}


void input(vector<vector<int>> &nums){
    string str;
    int i=0;
    nums.clear();
    while(cin>>str){
        nums.push_back(vector<int>());
        int k = 0;
        for (auto c : str){
            if (isdigit(c))
                k = k * 10 + c - '0';
            else{
                nums[i].push_back(k);
                k = 0;
            }
        }
        nums[i].push_back(k);
        i++;
    }
}

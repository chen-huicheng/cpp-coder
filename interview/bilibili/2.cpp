#include<bits/stdc++.h>
using namespace std;

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

int main(){
    vector<vector<int>> nums;
    input(nums);
    //处理就行
    return 0;
}
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
void input(vector<int> &nums){ //读取一行不确定个数的整数
    string str;
    getline(cin,str);
    stringstream strin(str);
    int num;
    while(strin>>num) //遇到非法字符 或 结尾 退出
    {
        nums.push_back(num);
    }
}
int main(){
    vector<int> nums;
    input(nums);
    for(auto num:nums){
        cout<<num <<" ";
    }
    input(nums);
    for(auto num:nums){
        cout<<num <<" ";
    }
    return 0;
}
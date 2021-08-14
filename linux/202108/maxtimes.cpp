#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 导弹拦截最大次数
 * 
 * @return int 
 */
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n),dp;
    for(int i=0;i<n;i++)cin>>nums[i];
    dp.push_back(nums[n-1]);
    for(int i=n-1;i>=0;i--){
        int num = nums[i];
        size_t idx=lower_bound(dp.begin(),dp.end(),num)-dp.begin();
        if(idx<dp.size()){
            dp[idx]=num;
        }else{
            dp.emplace_back(num);
        }
    }
    cout<<dp.size()<<endl;
    return 0;
}

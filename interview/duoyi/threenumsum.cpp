#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); //排序 方便去重
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        if (nums[i] > 0) // 当nums[i]>0 时 三数之和必然大于 0
            break;
        if (i != 0 && nums[i - 1] == nums[i]) //有序数组  相同元素只取一次，取第一个，保证之后无重复组合
            continue;
        int l = i + 1, r = len - 1; // 在 i 之后的 取两个数字使之和为 -nums[i]
        while (l < r)               // 将三数之和为0 简化为 在有序数组中找两数之和为 -nums[i]
        {
            if (nums[i] + nums[l] + nums[r] == 0) // 找到一个结果
            {
                ans.push_back({nums[i], nums[l], nums[r]}); //保存结果
                int tmp = nums[l];
                while (tmp == nums[l] && l < r)
                    l++; //调整左右指针 使之不包含重复组合
                tmp = nums[r];
                while (tmp == nums[r] && l < r)
                    r--;
                continue;
            }
            if (nums[l] + nums[r] < -nums[i]) // 当 nums[l] + nums[r] < -nums[i] 时 l++ 也就是使nums[l]变大
                l++;
            else //否则 r--
                r--;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={-1,0,1,2,-1,-4};
    auto ans = threeSum(nums);
    for(auto it:ans){
        for(auto k:it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/* 代码思路
1、首先排序得到有序数组 nums     方便去重 和 查找
2、从小到大遍历有序数组  假设当前遍历值为nums[i]
3、然后在该有序数组后边使用左右指针找到 nums[l]+nums[r]+nums[i]==0 
4、保存结果 并将所有与 nums[l] nums[r] 相同元素过滤掉
*/
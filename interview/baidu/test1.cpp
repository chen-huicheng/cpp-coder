#include <bits/stdc++.h>
using namespace std;

void adjust(vector<int> &nums, int n, int idx)
{
    int k = nums[idx];
    while (idx * 2 + 1 < n)
    {
        int l = idx * 2 + 1;
        if (l + 1 < n && nums[l] > nums[l + 1])
        {
            l++;
        }
        if (nums[l] < k)
        {
            nums[idx] = nums[l];
            idx = l;
        }
        else
        {
            break;
        }
    }
    nums[idx] = k;
}
void heap_sort(vector<int> &nums)
{
    int n = nums.size();
    int k = n / 2;
    for (int i = k; i >= 0; --i)
    {
        adjust(nums, n, i);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        swap(nums[i], nums[0]);
        adjust(nums, i, 0);
    }
}

int findk(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == k)
            return mid;
        if (nums[mid] > nums[r])
        {
            if (nums[mid] > k && k > nums[r])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else if (nums[mid] < nums[r])
        {
            if (nums[mid] < k && k < nums[r])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        else
        {
            if (nums[r] == k)
                return r;
            r--;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums;
    int n = 20;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        nums.push_back(rand() % 100);
    cout << "sort:\t";
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());

    srand((unsigned)time(NULL));
    int k = rand() % n;
    for (int i = 0; i < n; i++)
    {
        nums[(i+k)%n]=temp[i];
    }
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    srand((unsigned)time(NULL));
    int idx = rand() % n;
    int res = findk(nums,nums[idx]);
    cout<<idx<<" "<<res<<endl;

}
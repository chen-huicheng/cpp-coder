#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <unistd.h>
using namespace std;
/**
 * 归并排序
 */
void merge(vector<int> &nums, int l, int mid, int r)
{
    int i = 0, j = mid - l + 1;
    mid = mid - l;
    vector<int> aux(nums.begin() + l, nums.begin() + r + 1);
    int k = l;
    while (k <= r)
    {
        if (i > mid)
            nums[k++] = aux[j++];
        else if (j > r - l)
            nums[k++] = aux[i++];
        else if (aux[i] < aux[j])
            nums[k++] = aux[i++];
        else
            nums[k++] = aux[j++];
    }
}
void merge_sort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}
/**
 * 快速排序
 */
int cnt = 0;
void quick_sort(vector<int> &nums, int l, int r)
{
    // if (l >= r)
    //     return;
    cnt++;
    int hole = nums[l];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && nums[j] > hole)
            j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= hole)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = hole;
    if(i-1-l>0)
    quick_sort(nums, l, i - 1);
    if(r-i-1>0)
    quick_sort(nums, i + 1, r);
}
/**
 * 堆排序
 */
// void adjust(vector<int> &nums, int len, int i)
// {
//     int n = len;
//     int hole = nums[i];
//     int pre = i;
//     while (i * 2 + 1 < n)
//     {
//         i = i * 2 + 1;
//         if (i + 1 < n && nums[i + 1] > nums[i])
//             i++;
//         if (nums[i] > hole)
//         {
//             nums[pre] = nums[i];
//         }
//         else
//         {
//             break;
//         }
//         pre = i;
//     }
//     nums[pre] = hole;
// }
// void heap_sort(vector<int> &nums)
// {
//     int n = nums.size();
//     int k = n / 2;
//     while (k--)
//     {
//         adjust(nums, n, k);
//     }
//     while (n--)
//     {
//         swap(nums[0], nums[n]);
//         adjust(nums, n, 0);
//     }
// }
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
vector<int> topK(vector<int> &nums, int k)
{
    priority_queue<int> que;

    int n = nums.size();
    if (n < k)
        return nums;
    for (int i = 0; i < k; ++i)
        que.push(nums[i]);
    for (int i = k; i < n; ++i)
    {
        if (que.top() > nums[i])
        {
            que.pop();
            que.push(nums[i]);
        }
    }
    vector<int> res(k, 0);
    while (!que.empty() && k)
    {
        res[--k] = que.top();
        que.pop();
    }
    return res;
}
int main()
{
    // vector<int> nums;
    // int n = 10000;
    // srand((unsigned)time(NULL));
    // for (int i = 0; i < n; i++)
    //     nums.push_back(rand()%26253);
    // cout << "sort:\t";
    // vector<int> temp(nums);
    // sort(temp.begin(), temp.end());
    // for (auto n : temp)
    //     cout << n << " ";
    // cout << endl;

    // cout<<"merge_sort:\t";
    // merge_sort(nums, 0, nums.size() - 1);
    // for (auto n : nums)
    //     cout << n << " ";
    // cout << endl;

    int n = 100000;
    vector<int> nums(n);
    int k = 1000;
    cout << "quick_sort:\t";
    int sum = 0;
    for (int i = 0; i < k; ++i)
    {
        srand((unsigned)time(NULL)+rand());
        for (int i = 0; i < n; i++)
            nums[i] = rand();
        // sort(nums.begin(), nums.end(),greater<int>());
        // cout<<"quick_sort:\t";
        quick_sort(nums, 0, nums.size() - 1);
        usleep(100);
        cout << cnt << endl;
        sum += cnt;
        cnt = 0;
    }

    // for (auto n : nums)
    //     cout << n << " ";
    cout << endl;
    cout << sum / 1000 << endl;

    // cout << "heap_sort:\t";
    // heap_sort(nums);
    // for (auto n : nums)
    //     cout << n << " ";
    // cout << endl;

    // cout << "topk:\t";
    // auto res = topK(nums, 10);
    // for (auto n : res)
    //     cout << n << " ";
    // cout << endl;
}
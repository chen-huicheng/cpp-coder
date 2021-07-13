#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <algorithm>
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
void quick_sort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
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
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, j);
}
/**
 * 堆排序
 */
void heap_sort(vector<int> &nums);
int main()
{
    vector<int> nums;
    int n = 30;
    for (int i = 0; i < n; i++)
        nums.push_back(rand()%100);
    cout<<"sort:    \t";
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    for (auto n : temp)
        cout << n << " ";
    cout << endl;

    cout<<"merge_sort:\t";
    merge_sort(nums, 0, nums.size() - 1);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    cout<<"quick_sort:\t";
    quick_sort(nums, 0, nums.size() - 1);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    
}
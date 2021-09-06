#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b)
{
    if (a < b)
    {
        swap(a,b);
    }
    if (a % b == 0)
        return b;
    else
        return GCD(b, a % b);
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    long long a = 0, b = n * (n - 1) / 2;
    int r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (r < n && nums[r] - nums[i] <= k)
            r++;
        a += r - i - 1;
    }
    long long m=GCD(a,b);
    cout<<a/m<<"/"<<b/m<<endl;
    return 0;
}
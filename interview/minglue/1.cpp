#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a = 0, b = 1;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }
    cout << res << endl;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
bool f(long long n, int k)
{
    while (n)
    {
        if (n % 10 == k)
            return false;
        n /= 10;
    }
    return true;
}
int main()
{
    long long n = 100000, k = 0;
    long long m = 1,r=10;
    long long res = 0;
    while (1)
    {
        res++;
        while (!f(res, k))
            res++;
        m++;
        if(m>n){
            break;
        }
        if(res>=r){
            r*=10;cout<<res<<" "<<m<<endl;
        }
            
    }
    // cout << res << endl;
}
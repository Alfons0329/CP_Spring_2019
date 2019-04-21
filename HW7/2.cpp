#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull pow_mod(ull x, ull y, ull p)
{
    ull res = 1;
    x %= p;

    while(y > 0)
    {
        if(y & 1) // last
        {
            res = (res * x) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, a, p;
    cin >> n;
    while(n--)
    {
        cin >> a >> p;
        cout << pow_mod(a, p - 2, p) << '\n';
    }
    return 0;
}

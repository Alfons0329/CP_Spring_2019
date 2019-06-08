#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    if(n <= 2)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << n - 2 << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q, tmp;
    int a[MAX_N] = {0};
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if(i != 1)
        {
            a[i] = a[i - 1] ^ tmp;
        }
        else
        {
            a[i] = tmp;
        }
    }
    
    int l, r;
    while(q--)
    {
        cin >> l >> r;
        l = a[l - 1];
        r = a[r];
        l ^= r;
        cout << l << '\n';
    }
    
    return 0;
}

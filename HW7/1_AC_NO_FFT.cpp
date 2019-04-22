#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX_N 100005
using namespace std;

ull a[MAX_N], b[MAX_N], c[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ull N, n, M, m, Q, tmp;
    cin >> N >> M >> Q;
    a[0] = b[0] = 1;
    m = n = 0;

    while(N--)
    {
        cin >> tmp;
        a[tmp]++;
        n = max(n, tmp);
    }
    while(M--)
    {
        cin >> tmp;
        b[tmp]++;
        m = max(m, tmp);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    while(Q--)
    {
        cin >> tmp;
        if(tmp == 0 ||tmp > 1e5 + 5)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << (ull)(c[tmp]) << '\n';
        }
    }
    return 0;
}

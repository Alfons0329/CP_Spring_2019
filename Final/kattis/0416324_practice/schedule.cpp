#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int q, m, s, l;
    cin >> q >> m >> s >> l;

    int res = 0;
    for(int i = 1; i <= l; i++)
    {
        if(i % m == 0)
        {
            res += q;
        }
    }

    if(l % m)
    {
        res += q;
        cout << "1res " << res << '\n';
    }

    s -= q *(m - l % m);
    res += q;
    cout <<"  s remain  " << s << '\n';

    if(s > 0)
    {
        for(int i = 1; i <= s; i++)
        {
            if(i % m == 0)
            {
                res += 1;
            }
        }
    }
    cout << res;
    return 0;
}

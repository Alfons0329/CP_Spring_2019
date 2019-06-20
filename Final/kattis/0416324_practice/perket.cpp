#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<pair<ll, ll> > in;
    int n;
    ll b, s;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> b >> s;
        in.push_back(make_pair(b, s));
    }

    ll res = LLONG_MAX;
    int n_subset = 1 << n;
    while(n_subset-- > 1)
    {
        int bin = n_subset, cnt = 0;
        b = 1;
        s = 0;
        while(bin)
        {
            if(bin & 1) // has bit 1
            {
                b *= in[cnt].first;
                s += in[cnt].second;
            }
            cnt++;
            bin >>= 1;
        }
        res = min(res, abs(b - s));
    }
    cout << res;
    return 0;
}

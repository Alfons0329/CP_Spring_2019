#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, tmp;
    cin >> n >> m;

    vector<ll>v1, v2; // use ll for AC!
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }

    sort(v1.begin(), v1.end());
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        v2.push_back(tmp);
    }

    ll res = 0;
    for(int i = 0; i < m; i++)
    {
        auto lb = lower_bound(v1.begin(), v1.end(), v2[i]);
        res += (*lb - v2[i]);
    }

    cout << res;
    return 0;
}
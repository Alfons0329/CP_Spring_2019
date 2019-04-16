#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define ll long long
using namespace std;

struct one_h
{
    ll x, h, w;
};

vector<one_h> v;
bool sect = 0;
bool cmp(one_h a, one_h b)
{
    return a.h > b.h;
}

void get_ans(ll& l_most, ll& r_most, vector<ll>& wh_pair)
{
    ll area = 0, len = 0;
    ll n = v.size(), m = wh_pair.size(), cover = 0;
    for(ll i = 0; i < n; i++)
    {
        if(cover >= m)
        {
            break;
        }
        if(v[i].h == 0)
        {
            continue;
        }
        ll spare = 0;
        for(ll j = v[i].x; j < v[i].x + v[i].w; j++)
        {
            if(wh_pair[j - l_most] != 0)
            {
                continue;
            }
            spare++;
            wh_pair[j - l_most] = v[i].h;
            cover++;
        }
        area += spare * v[i].h;
    }

    ll local_start = l_most, local_max = 0;
    int flg = 0;
    for(ll i = l_most; i <= r_most; i++)
    {
        if(wh_pair[i - l_most] == 0)
        {
            if(flg == 1)
            {

                len += (i - local_start) + local_max * 2;
                // printf("len %d i %d whpair i %d local_start %d local_max %d\n", len , i, wh_pair[i - l_most], local_start, local_max);
                local_max = 0;
                local_start = l_most;
                flg = 0;
            }
        }
        else
        {
            if(local_start == l_most && i != local_start)
            {
                local_start = i;
            }
            local_max = max(wh_pair[i - l_most], (ll)local_max);
            flg = 1;
        }
    }

    cout << len + 1  << ' ' << area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x, h, w, l_most = LLONG_MAX, r_most = 0;
    cin >> n;
    while(n--)
    {
        cin >> x >> h >> w;
        one_h tmp;
        tmp.x = x;
        tmp.h = h;
        tmp.w = w;
        v.push_back(tmp);

        l_most = min(x, l_most);
        r_most = max(x + w, r_most);
    }

    vector<ll> wh_pair(r_most - l_most + 1, 0);
    sort(v.begin(), v.end(), cmp);
    get_ans(l_most, r_most, wh_pair);
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define ull unsigned long long
using namespace std;

struct one_h
{
    ull x, h, w;
};

vector<one_h> v;
bool cmp(one_h a, one_h b)
{
    return a.h > b.h;
}

void get_ans(ull& l_most, ull& r_most, vector<ull>& wh)
{
    ull area = 0, len = 0; 
    ull n = v.size(), m = wh.size(), cover = 0;
    map<ull, pair<ull, ull>> wh2; // x -> (h, x + w)
    wh2[v[0].x] = make_pair(v[0].h, v[0].x + v[0].w); 

    for(ull i = 1; i < n; i++)
    {
        ull occupied = 0, xx = v[i].x, hh = v[i].h, xx2 = v[i].x + v[i].w;
        auto it = wh2.begin();
        while(it -> first > xx && it -> second -> second < xx2 || it != wh2.end())
        {
            it++;
            occupied += it -> second -> second - it -> first;
        }
        area += (ww - occupied) * hh;
    }

    ull local_start = l_most, local_max = 0;
    int flg = 0;
    for(ull i = l_most; i <= r_most; i++)
    {
        if(wh[i - l_most] == 0)
        {
            if(flg == 1)
            {

                len += (i - local_start) + local_max * 2;
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
            local_max = max(wh[i - l_most], (ull)local_max);
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
    ull x, h, w, l_most = ULLONG_MAX, r_most = 0;
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

    vector<ull> wh(r_most - l_most + 1, 0);
    sort(v.begin(), v.end(), cmp);
    get_ans(l_most, r_most, wh);
    return 0;
}

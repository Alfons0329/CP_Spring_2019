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

void get_ans(ull& l_most, ull& r_most, map<ull, ull> wh)
{
    ull area = 0, len = 0; 
    ull n = v.size(), m = r_most - l_most, cover = 0;
    wh[v[0].x] = v[0].h;
    wh[v[0].x + v[0].w] = v[0].h;

    for(ull i = 1; i < n; i++)
    {
        ull spare = 0;
        auto l = v[i].x, r = v[i].x + v[i].w, h = v[i].h;
        auto l2 = wh.begin() -> first, r2 = wh.rbegin() -> first; 
        printf("l2 %d r2 %d \n", l2, r2);
        if(l < l2)
        {
             wh[l] = h;
        }

        if(r > r2)
        {
            wh[r] = h;
        }
        printf("update l %llu r %llu to h %llu\n", l, r, h);
    }
    
    auto it1 = wh.begin();
    auto it3 = next(wh.begin());
    while(it1 != wh.end())
    {
        ull w1 = it1 -> first, w2 = it3 -> first, h1 = it1 -> second, h2 = it3 -> second;
        area += (w2 - w1) * (min(h2, h1));

        if(h2 == h1)
        {
            len += h2 * 2 + (w2 - w1);
        }
        else
        {
            len += 2;
        }
        printf("w2 %llu w1 %llu h2 %llu h1 %llu area %llu\n", w2, w1, h2, h1, area);
        it1 = next(it1);
        it3 = next(it3);
    }

    cout << len << ' ' << area;
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

    map<ull, ull> wh;
    sort(v.begin(), v.end(), cmp);
    get_ans(l_most, r_most, wh);
    return 0;
}

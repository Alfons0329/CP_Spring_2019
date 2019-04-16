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
    map<ull, ull>::iterator it1 = wh.begin(); 
    map<ull, ull>::iterator it2 = wh.rbegin(); 
    for(ull i = 0; i < n; i++)
    {
        ull spare = 0;
        ull l = v[i].x, r = v[i].x + v[i].x;
        it1 = wh.begin();
        it2 = wh.rbegin(); 
        if(l > it1 -> first && r < it2 -> first)
        {
            continue;
        }
        wh[l] = wh[r] = v[i].h;
        printf("update l %d r %d to h %d\n", l, r, v[i].h);
    }
    
    it1 = wh.begin();
    it2 = next(wh.begin());
    while(it1 != wh.end())
    {
        ull w1 = it1 -> first, w2 = it2 -> first, h1 = it1 -> second, h2 = it2 -> second;
        area += (w2 - w1) * (min(h2, h1));

        if(h2 == h1)
        {
            len += h2 * 2 + (w2 - w1);
        }
        else
        {
            len += 2;
        }
        // printf("area %d, len %d");
        it1 = next(it1);
        it2 = next(it2);
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

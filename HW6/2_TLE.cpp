#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct one_h
{
    ull x, h, w;
};

vector<one_h> v;
vector<one_h> v2;
bool cmp(one_h a, one_h b)
{
    return a.h > b.h;
}

void get_ans(ull& l_most, ull& r_most)
{
    ull area = 0, len = 0; 
    ull n = v.size(), cover = 0;
    map<ull, pair<ull, ull>> wh; // x -> (h, x + w)
    wh[v[0].x] = make_pair(v[0].h, v[0].x + v[0].w); 
    area += v[0].w * v[0].h;

    auto it = wh.begin();
    for(ull i = 1; i < n; i++)
    {
        ull overlap = 0, xx = v[i].x, hh = v[i].h, xx2 = v[i].x + v[i].w;
        bool flg = 0;
        it = wh.begin();
        // printf("out itf %llu, itss %llu xx %llu xx2 %llu\n", it -> first, it ->second.second, xx, xx2);
        while(it != wh.end())
        {
            // printf("itf %llu, itss %llu xx %llu xx2 %llu\n", it -> first, it ->second.second, xx, xx2);
            if(it -> first < xx && it -> second.second > xx2)
            {
                wh.erase(it);
                flg = 1;
                break;
            }
            if(it -> first < xx2 && it -> second.second > xx)
            {
                overlap = min(xx2 - it -> first, it -> second.second - it -> first); 
            }
            it++;
        }

        if(!flg)
        {
            wh[xx] = make_pair(hh, xx2);
            area += (xx2 - xx - overlap) * hh;
            // printf("xx2 %llu xx %llu overlap %llu hh %llu area %llu\n", xx2, xx, overlap, hh, area);
        }
    }

    ull max_h = 0, xx = v2[0].x;
    one_h tmp;
    tmp.x = r_most + 1;
    tmp.h = 0;
    tmp.w = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(v2[i].h > max_h)
        {
            max_h = v2[i].h;
        }
        else if()
        {
            len += v2[i].x + w - xx;
            xx = 0;
        }
    }
    cout << len  << ' ' << area;
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

    v2 = v;
    sort(v.begin(), v.end(), cmp);
    get_ans(l_most, r_most);
    return 0;
}

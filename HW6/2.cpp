#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct one_h
{
    ull x, h, w;
};

vector<one_h> v;
ull max_h;
bool sect = 0;

void make_wh_pair(ull& l_most, ull& r_most, vector<ull>& wh_pair)
{
    int n = v.size(); 

    for(int i = 0; i < n; i++)
    {
        for(int j = v[i].x; j < v[i].x + v[i].w; j++)
        {
            if(v[i].h > wh_pair[j - l_most])
            {
                wh_pair[j - l_most] = max(wh_pair[j - l_most], v[i].h);
                // printf("w %llu has been updated to h %llu\n", j - l_most, v[i].h);
                sect = 1;
            }
        }
    }
}

void get_ans(ull& l_most, ull& r_most, vector<ull>& wh_pair)
{
    ull area = 0, len = 0;
    for(ull i = l_most; i <= r_most; i++)
    {
        area += wh_pair[i - l_most];
        // printf("wh_pair %d is %d res %d\n", i - l_most, wh_pair[i - l_most], res);
    }

    cout << max_h * 2 + (r_most - l_most + 1) << ' ' << area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ull x, h, w, l_most = ULLONG_MAX, r_most = 0;
    cin >> n;
    max_h = 0;
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
        max_h = max(max_h, h);
    }

    r_most--;
    vector<ull> wh_pair(r_most - l_most, 0);
    make_wh_pair(l_most, r_most, wh_pair);
    get_ans(l_most, r_most, wh_pair);

    return 0;
}

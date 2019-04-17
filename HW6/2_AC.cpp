#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct one_h
{
    ll x, h;
    bool in_type;
};

bool cmp(one_h a, one_h b)
{
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x, h, w; 
    cin >> n;
    vector<one_h> house;

    while(n--)
    {
        cin >> x >> h >> w;
        one_h tmp, tmp2;

        tmp.x = x;
        tmp.h = h;
        tmp.in_type = 1;

        tmp2.x = x + w;
        tmp2.h = h;
        tmp2.in_type = 0;
        
        house.push_back(tmp);
        house.push_back(tmp2);

    }
    
    sort(house.begin(), house.end(), cmp);
    ll h2 = 0, area = 0, len = 0;
    x = h = 0;
    multiset<ll> x_height;
    for(auto i : house)
    {
        if(i.x != x)
        {
            area += h2 * (i.x - x);
            len += abs(h2 - h) + (h2 > 0) * (i.x - x);
            // printf("ix %lld x %lld h2 %lld h %lld area %lld len %lld\n", i.x, x, h2, h, area , len);
            x = i.x;
            h = h2;
        }

        if(i.in_type == 1)
        {
            // printf("insert %lld at %lld\n", i.h, i.x);
            x_height.insert(i.h);
        }
        else
        {
            // printf("erase %lld at %lld\n", i.h, i.x);
            x_height.erase(x_height.find(i.h));
        }
        
        if(x_height.size())
        {
            h2 = *(x_height.rbegin());
        }
        else
        {
            h2 = 0;
        }
    }
    cout << len + abs(h2 - h) << ' ' << area;
    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 1001
#define MAX_M 1001
using namespace std;

int max_r, max_c;
bool mymap[MAX_N][MAX_M];

int solve(const int& r, const int& c)
{
    if(r < max_r && c < max_c)
    {
        return 0;
    }

    int r_1 = r, c_1 = c;
    for(; r_1 > 0; r_1--)
    {
        if(mymap[r_1][c] == true)
        {
            break;
        }
    }

    for(; c_1 > 0; c_1--)
    {
        if(mymap[r][c_1] == true)
        {
            break;
        }
    }
    
    mymap[r][c] = true;
    // cout << "r " << r << "c " << c << "r_1 " << r_1 << "c_1 " << c_1 << '\n';
    return r * c - (r * c_1 + c * r_1 - min(r, r_1) * min(c, c_1));
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m ,q, total, r, c;
    max_r = max_c = 0;
    cin >> n >> m >> q;
    total = n * m;
    int res;

    max_r = max_c = 0;
    // memset(mymap, false, sizeof(bool) * MAX_M * MAX_N);
    while(q--)
    {
        cin >> r >> c;
        res = solve(r, c);
        max_r = max(r, max_r);
        max_c = max(r, max_c);
        if(res)
        {
            cout << res << endl;
        }
        else
        {
            cout << "QAQ" << '\n';
        }
        total -= res;
    }
    cout << total << '\n';

    return 0;
}

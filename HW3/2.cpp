#include <bits/stdc++.h>
using namespace std;
int row_max, col_max;
unordered_map<int, bool> mymap;

int solve(const int& r, const int& c, const int& n, const int& m)
{
    if(mymap[r * m + c])
    {
        return 0;
    }
    int end_r = r;
    int end_c = c;
    while(--end_r >= 1)
    {
        if(mymap[end_r * m + c])
        {
            break;
        }
    }

    while(--end_c >= 1)
    {
        if(mymap[r * m + end_c])
        {
            break;
        }
    }
    
    // cout << "end_r " << end_r << " ,  end_c " << end_c << '\n' ;

    int res = 0;
    for(int i = r; i > end_r; i--)
    {
        for(int j = c; j > end_c; j--)
        {
            res++;
            mymap[i * m + j] = 1;
        }
    }
    return res;
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m ,q, total, r, c;
    row_max = col_max = 0;
    cin >> n >> m >> q;
    total = n * m;
    int res;

    while(q--)
    {
        cin >> r >> c;
        res = solve(r, c, n, m);
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

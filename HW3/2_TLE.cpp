#include <bits/stdc++.h>
#define MAX_N 1001
#define MAX_M 1001
using namespace std;

void solve(const int& r, const int& c, const int& n, const int& m, bool mymap[][MAX_M], int& res)
{
    if(r > n || c > m || r < 1 || c < 1 || mymap[r][c])
    {
        return;
    }
    for(int i = r; i >= 1; i--)
    {
        for(int j = c; j >= 1; j--)
        {
            if(mymap[i][j] == false)
            {
                res++;
                mymap[i][j] = true;
            }
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m ,q, total, r, c;
    bool mymap[MAX_N][MAX_M] = {0};
    cin >> n >> m >> q;
    total = n * m;
    int res;

    while(q--)
    {
        cin >> r >> c;
        res = 0;
        solve(r, c, n, m, mymap, res);
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

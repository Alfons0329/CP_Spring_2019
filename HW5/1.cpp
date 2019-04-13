#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n, m ,q, total, r, c;
    map<ull, ull> col_row;
    cin >> n >> m >> q;
    total = n * m;

    col_row[0] = 0;

    while(q--)
    {
        cin >> r >> c;
        r = min(r, n);
        c = min(c, m);
        ull res = r * c, delta = 0; 
        bool can_eat = 1;
        // printf("r %llu c %llu\n", r, c);

        map<ull, ull>::iterator it = col_row.begin();

        for(; it != col_row.end(); it++)
        {
            if(r <= it -> second && c <= it ->first)
            {
                can_eat = 0;
                res = 0;
                break;
            }
        }

        if(can_eat)
        {
            it = col_row.begin();
            ull last_col = 0;
            for(; it != col_row.end(); it++)
            {
                delta += (min(c, (ull)it -> first) - last_col) * min((ull)it -> second, r);
                // printf("delta %llu itf %llu, last_col %llu its %llu \n", delta, it -> first, last_col, it ->second);
                if(it -> first > c)
                {
                    break;
                }
                last_col = it -> first;
            }

            // update map
            it = col_row.begin();
            for(; it != col_row.end(); it++)
            {
                if(r >= it -> second && c >= it -> first)
                {
                    col_row.erase(it -> first);
                }
            }
            col_row[c] = r;
            
            res -= delta;
        }

        if(res > 0)
        {
            cout << min(m * n, res) << '\n';
            total -= min(m * n, res);
        }
        else
        {
            cout << "QAQ" << '\n';
        }

    }
    cout << total;
    return 0;
}

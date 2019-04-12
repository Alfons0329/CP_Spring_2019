#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n, m ,q, total, r, c;
    map<int, int> col_row;
    cin >> n >> m >> q;
    total = n * m;
    ull res;

    col_row[0] = 0;

    while(q--)
    {
        cin >> r >> c;
        printf("r %d c %d\n", r, c);
        res = r * c;
        col_row[c] = r;
        map<int, int>::iterator it = col_row.begin();

        ull last_col = it -> first, sz = 0;
        it++;
        bool flg = 1;
        for(; it != col_row.end(); it++)
        {

            if(res < (it -> first - last_col) * (it -> second))
            {
                flg = 0;
                break;
            }

            printf("res %llu itf %llu, last_col %llu its %llu \n", res, it -> first, last_col, it ->second);
            res -= (it -> first - last_col) * it -> second;
            last_col = it -> first;
        }

        if(flg)
        {
            it = col_row.begin();
            for(; it != col_row.end(); it++)
            {
                if (it -> first < c && it -> second < r)
                {
                    col_row.erase(it -> first);
                }
            }

            cout << res << '\n';
            total -= res;
        }
        else
        {
            cout << "QAQ" << '\n';
        }
    }
    cout << total << '\n';
    // // printf("---------------\n");
    return 0;
}

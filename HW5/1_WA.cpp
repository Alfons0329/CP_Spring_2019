#include <bits/stdc++.h>
#define ull unsigned long long
#define mp make_pair
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n, m ,q, total, r, c;
    unordered_map<ull, bool> eat;
    cin >> n >> m >> q;
    total = n * m;
    int res;

    while(q--)
    {
        cin >> r >> c;
        if(eat.count(r * m + c) != 0)
        {
            cout << "QAQ" << '\n';
        }
        else
        {
            res = 0;
            bool flg = 0;

            // check up, right have been eaten 
            ull i = r, j = c;
            for(; i <= n; i++)
            {
                // printf("i %llu i * m + c %llu\n", i, i * m + c);
                if(eat.count(i * m + c) != 0)
                {
                    flg = 1;
                    break;
                }
            }

            for(; j <= m; j++)
            {
                // printf("j %llu r * m + j %llu\n", j, r * m + j);
                if(eat.count(r * m + j) != 0)
                {
                    flg = 1;
                    break;
                }
            }

            // check down, left OK to eat 
            if(flg == 0)
            {
                i = r, j = c - 1;
                ull i_cnt = 0, j_cnt = 1;
                for(; i >= 1; i--)
                {
                    // printf("i %llu i * m + c %llu\n", i, i * m + c);
                    if(eat.count(i * m + c) != 0)
                    {
                        break;
                    }
                    eat[i * m + c] = 1;
                    i_cnt++;
                }

                for(; j >= 1; j--)
                {
                    // printf("j %llu r * m + j %llu\n", j, r * m + j);
                    if(eat.count(r * m + j) != 0)
                    {
                        break;
                    }
                    eat[r * m + j] = 1;
                    j_cnt++;
                }
                // printf("down to i %d, j %d | i_cnt %d, j_cnt %d\n", i, j, i_cnt, j_cnt);
                res = i_cnt * j_cnt;

                cout << res << '\n';
                total -= res;
            }
            else
            {
                cout << "QAQ" << '\n';
            }
        }
    }
    cout << total << '\n';
    // // printf("---------------\n");
    return 0;
}

#include <bits/stdc++.h>
#define ull unsigned long long
#define mp make_pair
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m ,q, total, r, c;
    map<ull, bool> eat;
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
            int r_b = r, c_b = c;
            for(; r_b >= 1; r_b--)
            {
                if(eat.count(r_b * m + c) != 0)
                {
                    break;
                }
            }
            for(; c_b >= 1; c_b--)
            {
                if(eat.count(r * m + c_b) != 0)
                {
                    break;
                }
            }

            int i = r, j = c;
            // printf("r_b %d, c_b %d\n", r_b, c_b);
            for(i = r; i > r_b; i--)
            {
                for(j = c; j > c_b; j--)
                {
                    // printf("i %d j %d res %d\n", i, j, res);
                    if(eat.count(i * m + j) != 0)
                    {
                        break;
                    }   
                    res++;
                    eat[i * m + j] = 1;
                }
            }

            cout << res << '\n';
            total -= res;
        }
    }
    cout << total << '\n';
    // // printf("---------------\n");
    return 0;
}

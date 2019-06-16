#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, tmp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int bound = v[i] & 0xFF, bit = 0;
        if (v[i] < 3)
        {
            res.push_back(0);
        }
        else
        {
            while (bound > 0)
            {
                bit++;
                bound >>= 1;
            }

            int flag = 0;
            while (j < (1 << bit) - 1) 
            // wrong answer at this part since 249 ^ 498 and then & 255 is 11, idea of setting bound may not be always right (249 > 2 ^ 4 - 1)
            {
                if (((j ^ (j << 1)) & 0xFF) == v[i])
                {
                    printf("j %d is ans for v[i] %d \n", j, v[i]);
                    res.push_back(j);
                    flag = 1;
                    break;
                }
                j++;
            }
            if(!flag)
            {
                res.push_back(0);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}
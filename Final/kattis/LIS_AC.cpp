#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        vector<int> v(n, 0);
        vector<int> lis;
        vector<int> lis_pos;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        lis.push_back(v[0]);
        lis_pos.push_back(0);
        int max_len = 1, max_pos = 0;
        for(int i = 1; i < n; i++)
        {
            if(v[i] > lis.back())
            {
                lis.push_back(v[i]);
                lis_pos.push_back(max_len);
                max_pos = i;
                max_len++;
            }
            else
            {
                int lb = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[lb] = v[i];
                lis_pos.push_back(lb);
            }
        }

        vector<int> final_res;
        final_res.push_back(max_pos);
        for(int i = max_pos; i >= 0; i--)
        {
            if(lis_pos[i] == lis_pos[max_pos] - 1)
            {
                max_pos = i;
                final_res.push_back(max_pos);
            }
        }

        reverse(final_res.begin(), final_res.end());
        cout << max_len << '\n';
        for(int i = 0; i < max_len; i++)
        {
            cout << final_res[i] << ' ';
        }
        cout << '\n';

    }
    return 0;
}

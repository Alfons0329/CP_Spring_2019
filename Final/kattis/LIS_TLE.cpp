#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(cin >> n)
    {
        vector<int> v(n, 0);
        vector<int> dp(n, 1);
        vector<int> res(n, 0);
        int max_pos = 1, max_len = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)   
            {
                if(v[j] > v[i])
                {
                    if(dp[i] + 1 > dp[j]) // if increment
                    {
                        dp[j] = dp[i] + 1;
                        max_len = dp[j];
                        max_pos = j;
                        res[j] = i;
                    }
                }
            }
        }

        vector<int> final_res(max_len, 0);
        int cnt = 0, max_len_bk = max_len;
        while(max_len_bk--)
        {
            final_res[cnt++] = max_pos;
            max_pos = res[max_pos];
        }

        cout << max_len << '\n';
        reverse(final_res.begin(), final_res.end());
        for(int i = 0; i < max_len; i++)
        {
            cout << final_res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

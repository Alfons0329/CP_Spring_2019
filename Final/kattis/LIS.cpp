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
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        vector<int> res;
        res.push_back(0);
        for(int i = 1; i < n; i++)
        {
            int next_pos = upper_bound(res.begin() + i, res.end(), v[i]) - res.begin();
            if(next_pos >= n)
            {
                break;
            }
            res.push_back(next_pos);
            i = next_pos - 1;
        }

        // cout << "answer ---------------- \n";
        int sz = res.size();
        cout << sz << '\n'; 
        for(int i = 0; i < sz; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
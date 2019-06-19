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
        vector<int> res;
        vector<int> final_res;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        
        res.push_back(v[0]);
        final_res.push_back(0);
        int max_len = 1;
        for(int i = 1; i < n; i++)
        {
            if(v[i] > res.back())
            {
                max_len++;
                res.push_back(v[i]);
                final_res.push_back(i);
            }
            else
            {
                int lb = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
                res[lb] = v[i];
                if(lb == max_len - 1)
                {
                    final_res[lb] = i;
                }
            }
        }

        cout << max_len << '\n'; 
        for(int i = 0; i < max_len; i++)
        {
            cout << final_res[i] << ' ';
        }
        cout << '\n';

        for(int i = 0; i < max_len; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

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
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            pos[v[i]] = i;
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
                if(lb == max_len - 1) // last one, does not mattr
                {
                    res[lb] = v[i];
                    final_res[lb] = i;
                }
                else if(lb == 0 && pos[v[i]] < pos[res[lb + 1]])
                {
                    res[lb] = v[i];
                    final_res[lb] = i;
                }
                else if(pos[v[i]] > pos[res[lb - 1]] && pos[v[i]] < pos[res[lb + 1]]) // in the right order
                {
                    cout << "lb " << lb << " lb front " << pos[res[lb - 1]] << " back " 
                        << pos[res[lb + 1]];
                    res[lb] = v[i];
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
        
        /* 
        for(int i = 0; i < max_len; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        */
    }
    return 0;
}

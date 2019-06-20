#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    set<string> res;
    
    cin >> s;
    int n = s.size();
    string tmp;
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                string s_bk = s;
                reverse(s_bk.begin() + i, s_bk.begin() + j);
                reverse(s_bk.begin() + j, s_bk.begin() + k);
                reverse(s_bk.begin() + k, s_bk.end());
                
                tmp = s_bk;
                res.emplace(tmp);
            }
        }
    }

    cout << *res.begin();
    return 0;
}

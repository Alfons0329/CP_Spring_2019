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
        int j = 0, flag = 0;
        while(j++ <= 255) // just try all the possibilities
        {
            if((j ^ (j << 1) & 0xFF) == v[i])
            {
                res.push_back(j);
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            res.push_back(v[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}
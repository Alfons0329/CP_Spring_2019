#include <bits/stdc++.h>
using namespace std;

int a[6];
map<int, int>m;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int h1, h2;
    for(int i = 0; i < 6; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    vector<int> res1, res2;    
    cin >> h1 >> h2;
    int flag = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 6; j++)
        {
            if(m.count(h1 - a[i] - a[j]) 
            && h1 - a[i] - a[j] != a[i] 
            && h1 - a[i] - a[j] != a[j])
            {
                flag = 1;
                res1.push_back(a[i]);
                res1.push_back(a[j]);
                res1.push_back(h1 - a[i] - a[j]);
                // if 3 height are satisfied, the rest for the other tower since the answer is unique
                m.erase(a[i]);
                m.erase(a[j]);
                m.erase(h1 - a[i] - a[j]);
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }

    flag = 0;

    for(auto it = m.begin(); it != m.end(); it++)
    {
        res2.push_back(it -> first);
    }
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());

    for(int i = 2; i >= 0; i--)
    {
        cout << res1[i] << ' ';
    }

    for(int i = 2; i >= 0; i--)
    {
        cout << res2[i] << ' ';
    }
    return 0;
}
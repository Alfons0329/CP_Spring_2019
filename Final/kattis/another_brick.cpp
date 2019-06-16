#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int h, w, n;
    int tmp;
    
    cin >> h >> w >> n;
    
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int idx = 0, len = 0;
    while(h && idx < n)
    {
        len += v[idx];
        if(len == w)
        {
            len = 0;
            h--;
        }
        idx++;
    }

    if(len == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";   
    }

    return 0;
}

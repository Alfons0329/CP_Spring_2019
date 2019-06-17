#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int s, c, k;
    cin >> s >> c >> k;

    vector<int> v(s, 0);
    for(int i = 0; i < s; i++)
    {
        cin >> v[i];
    }

    long long res = 0;
    sort(v.begin(), v.end());

    for(int i = 0; i < s; i++)
    {
        int j = i, cnt = 0;
        res++;
        while(j < s && cnt < c) // while in the pile of socks and wash machine able to wash
        {
            if(v[j] - v[i] <= k)
            {
                j++;
            }
            else
            {
                break;   
            }
            cnt++; // increment the socks in the washmachine
        }
        i = j - 1;
    }

    cout << res;
    return 0;
}
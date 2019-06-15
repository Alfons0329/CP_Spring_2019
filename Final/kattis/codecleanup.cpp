#include <bits/stdc++.h>
using namespace std;

int a[367];
int main()
{
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    int res = 0, encounter = 0, dirty = 0;
    int i = 0;
    while(i <= 366)
    {
        if(dirty >= 20)
        {
            encounter = 0;
            dirty = 0;
            res++;
            i--; // dont forget to drop back 1
            continue;
        }

        dirty += encounter;

        if(a[i])
        {
            encounter++; // increment the encounter if meet new dirty push
        }

        i++;
    }
    if(dirty > 0)
    {
        res++; // push in the new year's eve
    }
    cout << res << '\n';
    return 0;
}

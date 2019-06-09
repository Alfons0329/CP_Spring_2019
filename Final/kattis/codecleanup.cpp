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
            i--;
            continue;
        }

        dirty += encounter;

        if(a[i])
        {
            encounter++;
        }

        i++;
        // printf("Day %d encounter %d dirty %d res %d\n", i, encounter, dirty, res);
    }
    if(dirty > 0)
    {
        res++;
    }
    cout << res << '\n';
    return 0;
}

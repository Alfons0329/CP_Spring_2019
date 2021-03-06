#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // read # of testcases
    int tc;
    scanf("%d", &tc);
    ll n, l, r;
    ll tmp; // for keep eating the subset

    while(tc--)
    {
        scanf("%lld %lld %lld", &n, &l, &r);

        if(n == 0)
        {
            printf("%lld\n", r);
            continue;
        }
        // map
        bool* m = new bool[n + 1]();
        int array_len = min(n + 1, r - l + 1);
        while(n--)
        { 
            scanf("%lld", &tmp);
            if(tmp - l < array_len)
            {
                m[tmp - l] = true;
            }
        }

        // do ans
        bool has_ans = 0;
        ll shift = 0;
        for(int i = 0; i < array_len; i++)
        {
            if(m[i] == false)
            {
                has_ans = 1;
                shift = i;
                break;
            }
        }

        if(has_ans)
        {
            printf("%lld\n", shift + l);
        }
        else
        {
            printf("^v^\n");
        }
        delete m;
    }

    return 0;
}
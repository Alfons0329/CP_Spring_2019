#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

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
        bool* m = calloc(n + 1, sizeof(bool)); //padding
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
        free(m);
    }

    return 0;
}
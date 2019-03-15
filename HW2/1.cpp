#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffffffffffff
using namespace std;

void fastscan(ll &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register ll c; 

    number = 0; 

    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 

        // extract the next character from the buffer 
        c = getchar(); 
    } 

    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 

    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int main()
{
    // read # of testcases
    int tc;
    scanf("%d", &tc);
    ll n, l, r;
    ll minl_bound = INF, maxr_bound = -INF;
    ll tmp_l = 0, tmp_r = 0;
    ll tmp; // for keep eating the subset
    unordered_map<ll, ll> m;
    ll cnt;
    while(tc--)
    {
        // read n l r
        fastscan(n);
        fastscan(n);
        fastscan(l);
        fastscan(r);

        // test
        // printf("n = %lld l = %lld r = %lld\n", n, l, r);

        // quit if sub len = 0
        if(n == 0)
        {
            printf("%lld\n", r);
            continue;
        }

        if(l == r)
        {
            printf("^v^\n");
            continue;
        }

        // n *= 2;

        tmp_l = l, tmp_r = r;
        ll ans = r;
        cnt = 0;
        while(n--)
        { 
            scanf("%lld", &tmp);
            tmp_l = tmp - 1;

            if(tmp_l < ans && tmp_l > l && m[tmp_l] == 0)
            {
                ans = tmp_l;
            }

            if(m[tmp] == 0)
            {
                m[tmp]++;
                cnt++;
            }
        }
        
        if(cnt == r - l + 1)
        {
            printf("^v^\n");
        }
        else
        {
            printf("%lld\n", ans == r ? r : ans);
        }
        m.clear();
    }

    return 0;

}

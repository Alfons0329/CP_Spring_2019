#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffffffffffff
#define MAX_N 10000000
using namespace std;

void fastscan(ll &number) 
{ 
    bool negative = false; 
    register ll c; 

    number = 0; 

    c = getchar(); 

    if(c == '-') 
    { 
        negative = true; 

        c = getchar(); 
    } 

    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c = getchar()) 
        number = number *10 + c - 48; 

    if (negative) 
        number *= -1; 
} 

int main()
{
    // read # of testcases
    int tc;
    cin >> tc;
    ll n, l, r;
    ll tmp; // for keep eating the subset
    bool m[MAX_N] = { false };

    while(tc--)
    {
        // read n l r
        cout << 1 << endl;
        fastscan(n);
        cout << 1 << endl;
        fastscan(n);
        cout << 1 << endl;
        fastscan(l);
        cout << 1 << endl;
        fastscan(r);

        // test
        printf("n = %lld l = %lld r = %lld\n", n, l, r);

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

        while(n--)
        { 
            fastscan(tmp);
            printf("tmp = %lld\n", tmp);
            m[tmp - l] = true;
        }

        // do ans
        bool has_ans = 0;
        ll shift = 0;
        for(int i = 0; i < MAX_N; i++)
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
    }

    return 0;
}

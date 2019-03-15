#include <bits/stdc++.h>
#define ll long long
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
    ll maxl_bound = 0, maxr_bound = 0;
    ll tmp_l = 0, tmp_r = 0;
    ll tmp; // for keep eating the subset
    while(tc--)
    {
        // read n l r
        fastscan(n);
        fastscan(n);
        fastscan(l);
        fastscan(r);
        
        // test
        printf("n = %lld l = %lld r = %lld\n", n, l, r);
        
        // quit if sub len = 0
        if(n == 0)
        {
            printf("%lld", r);
            continue;
        }

        if(l == r)
        {
            printf("^v^\n");
        }

        // n *= 2;
        unordered_map<ll, ll> mymap;
        while(n--)
        {
            scanf("%lld", &tmp);
            printf("eat %lld\n", tmp);
            
            if(mymap[tmp] == 0)
            {
                mymap[tmp]++;

                if(mymap[tmp - 1] == 0)
                {
                    tmp_l = tmp - 1;
                }
                if(mymap[tmp + 1] == 0)
                {
                    tmp_r = tmp + 1;
                }
            }

        }

        if(maxl_bound < l && maxr_bound > r)
        {
            printf("^v^\n");
        }
        else
        {
            printf("%lld\n", maxr_bound);
        }
    }
    
    return 0;

}

#include<bits/stdc++.h>
#define MAX_N 1000005
using namespace std;
int main()
{
    int testcase;
    scanf("%d", &testcase);
    while(testcase--)
    {
        int n;
        scanf("%d",&n);
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        vector<int> a(n, 0);
        vector<int> dp;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &a[i]);
        }
        
        dp.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {

            if(a[i] > dp.back())
            {
                dp.push_back(a[i]);
            }
            else
            {
                *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
            }
        }
        printf("%lu\n", dp.size());
        dp.clear();
    }
    return 0;
}

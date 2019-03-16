#include<bits/stdc++.h>
#define MAX_N 1000005
using namespace std;

int main()
{
    int testcase;
    // read # of testcases
    scanf("%d", &testcase);
    while(testcase--)
    {
        // read each testcases
        int n;
        scanf("%d",&n);
        static int a[MAX_N];
        int dp[MAX_N] = {0};
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        
        // dynamic programming
        int res = 0;
        for(int l = 0; l < n - 1; l++)
        {
            for(int r = l + 1; r < n; r++)
            {
                if(a[r] > a[l])
                {
                    dp[r] = max(dp[r], dp[l] + 1);
                    res = max(res, dp[r]);
                    // printf("al %d ar %d dpl %d dpr %d res update to %d\n", a[l], a[r], dp[l], dp[r], res);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

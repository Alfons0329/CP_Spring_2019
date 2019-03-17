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
        int res = 0;

        for(int i = 1; i < n; i++)
        {

            if(a[i] > dp.back())
            {
                dp.push_back(a[i]);
            }
            else if(a[i] < dp[0])
            {
                dp.clear();
                dp.push_back(a[i]);
            }
            /*printf("current size %lu\n", dp.size());
            for(int it : dp)
            {
                printf("%d ", it);
            }
            printf("\n");*/
            res = max(res, (int)dp.size());
        }
        printf("%d\n", res);
        dp.clear();
    }
    return 0;
}

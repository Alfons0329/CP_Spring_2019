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

        dp.push_back(INT_MAX); // padding
        
        int res = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            while(dp.back() <= a[i])
            {
                dp.pop_back();
            }
            dp.push_back(a[i]);
            res = max(res, (int)dp.size() - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}

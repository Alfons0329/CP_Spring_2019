#include<bits/stdc++.h>
#define MAX_N 1000005
using namespace std;

int bin_search(int a[], int start, int end, int target)
{
    int mid;
    while(start <= end)
    {
        mid = start + (end - start) / 2; // prevent overflow
        if(a[mid] == target)
        {
            return mid;
        }
        else if(target < a[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
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
        if(n == 0)
        {
            printf("0");
            return 0;
        }
        static int a[MAX_N];
        int dp[MAX_N];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &a[i]);
        }
        
        // dynamic programming
        int res = 0;
        dp[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            if(a[i] < dp[0])
            {
                dp[0] = a[i];
            }
            else if(a[i] >= dp[res])
            {
                dp[++res] = a[i];
            }
            else
            {
                dp[bin_search(dp, 0, res, a[i])] = a[i];
            }
        }
        printf("%d\n", res + 1);
    }
    return 0;
}

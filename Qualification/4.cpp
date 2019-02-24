#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0, tmp = 0;
    cin >> t;
    vector<int>nums;
    while(t--)
    {
        cin >> tmp;
        nums.push_back(tmp); 
    }
    
    int n = nums.size();
    int max_sum = INT_MIN, tmp_sum = 0, max_val = INT_MIN, all_minus = 1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] >= 0)
        {
            all_minus = 0;
        }
        tmp_sum += nums[i];
        max_val = max(max_val, nums[i]); //for testcase 2, if all are the minus
        if(tmp_sum >= 0)
        {
            max_sum = max(tmp_sum, max_sum);
        }
        else
        {
            tmp_sum = 0;
        }
    }
    printf("%d\n", all_minus ? max_val : max_sum);
    return 0;
}

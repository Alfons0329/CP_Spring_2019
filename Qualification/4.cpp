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
    int max_sum = -9999999, tmp_sum = 0;
    for(int i = 0; i < n; i++)
    {
        tmp_sum += nums[i];
        if(tmp_sum < 0)
        {
            tmp_sum = nums[i];
        }
        max_sum = max(tmp_sum, max_sum);
    }
    printf("%d\n", max_sum);
    return 0;
}

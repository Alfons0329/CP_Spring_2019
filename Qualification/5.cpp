#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
vector<pair<int, int>> nums_pos;
void print_seg(vector<int> v)
{
    printf("seg = ");
    for(int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int solve(int L, int R, int k)
{
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums_pos[i].second >= L && nums_pos[i].second <= R)
        {
            k--;
            //printf("Update L %d R %d K %d\n", L, R, k);
            if(k == 0)
            {
                return nums_pos[i].first;
            }
        }
    }
    return INT_MIN; 
}
bool cmp(pair<int, int>p1, pair<int, int>p2)
{
    return p1.first < p2.first;
}
int main()
{
    int n, t, tmp = 0;
    n = t = 0;
    cin >> n >> t;
    while(n--)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int L, R, k;
    for(int i = 0 ; i < nums.size(); i++)
    {
        nums_pos.push_back(make_pair(nums[i], i));
    }
    sort(nums_pos.begin(), nums_pos.end());
    while(t--)
    {
        cin >> L >> R >> k;
        if(L == R)
        {
            cout << nums[--L] << endl;
        }
        else
        {
            cout << solve(L - 1, R - 1, k) << endl;
        }
    }
    return 0;
}

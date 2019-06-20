#include <bits/stdc++.h>
using namespace std;

int main()
{
    int reg[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    int prefix_accumulate[8];
    prefix_accumulate[0] = 1;
    for(int i = 1; i < 8; i++)
    {
        prefix_accumulate[i] = reg[i - 1] * prefix_accumulate[i - 1];
    }

    int tmp, res = 0, lim = prefix_accumulate[7];
    for(int i = 0; i < 8; i++)
    {
        cin >> tmp;
        // res += (tmp) * prefix_accumulate[i];
        res += (reg[i] - tmp - 1) * prefix_accumulate[i];
    }
    cout << res;
    // cout << 9699690 - res - 1;
    return 0;
}

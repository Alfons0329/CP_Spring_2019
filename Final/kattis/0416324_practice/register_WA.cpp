#include <bits/stdc++.h>
using namespace std;

int main()
{
    int reg[8] = {2, 3, 5, 7, 11, 13, 17, 19};

    int tmp, res = 1;
    for(auto i : reg)
    {
        cin >> tmp;
        res *= (tmp - i);
    }

    cout << res - 1;
    return 0;
}

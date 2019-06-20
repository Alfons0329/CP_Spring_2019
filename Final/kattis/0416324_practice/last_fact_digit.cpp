#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T, tmp;
    cin >> T;
    
    int res[13];
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i <= 11; i++)
    {
        res[i] = (i * res[i - 1] % 10) % 10;
    }

    while(T--)
    {
        cin >> tmp;
        cout << res[tmp] << '\n';
    }
    return 0;
}

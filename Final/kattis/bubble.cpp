#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, N, m, tmp;
    cin >> n;
    N = n;
    vector<int> tea, top;

    while(n--)
    {
        cin >> tmp;
        tea.push_back(tmp);
    }

    cin >> m;
    while(m--)
    {
        cin >> tmp;
        top.push_back(tmp);
    }

    int min_cost = INT_MAX, sz;
    for(int i = 0; i < N; i++)
    {
        cin >> sz;
        while(sz--)
        {
            cin >> tmp;
            min_cost = min(min_cost, tea[i] + top[tmp - 1]);
        }
    }
    int money;
    cin >> money;
    int res = money / min_cost - 1; 
    res = res <= 0 ? 0 : res;
    cout << res << '\n';
    return 0;
}

// for visualized solution, see card.jpg
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T, n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        vector<int> order;
        for(int i = 1; i <= n; i++)
        {
            order.push_back(i);
        }

        deque<int> dq;

        int shift = n;
        for(int i = n - 1; i >= 0; i--)
        {
            dq.push_front(order[i]);
            for(int j = 0; j < shift; j++)
            {
                int back = dq.back();
                dq.push_front(back);
                dq.pop_back();
            }
            shift--;
        }

        for(auto it = dq.begin(); it != dq.end(); it++)
        {
            cout << *it << ' ';
        }
        cout << '\n'; 
    }

    return 0;
}
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

    int T, space, g_sz, m_sz;
    cin >> T;
    while(T--)
    {
        cin >> g_sz >> m_sz;
        vector<int> god, mecha;

        int tmp;
        for(int i = 0; i < g_sz; i++)
        {
            cin >> tmp;
            god.push_back(tmp);
        }

        for(int i = 0; i < m_sz; i++)
        {
            cin >> tmp;
            mecha.push_back(tmp);
        }
        
        sort(god.begin(), god.end(), cmp);
        sort(mecha.begin(), mecha.end(), cmp);
        // battle
        
        while(mecha.size() && god.size())
        {
            int m = mecha.back();
            int g = god.back();
            
            if(m > g)
            {
                god.pop_back();
            }
            else if(m <= g)
            {
                mecha.pop_back();
            }
        }

        int m = mecha.size();
        int n = god.size();

        if(m == 0 && n == 0)
        {
            cout << "uncertain" << '\n';
        }
        else if(m == 0 && n)
        {
            cout << "Godzilla" << '\n';
        }
        else if(m && n == 0)
        {
            cout << "MechaGodzilla" << '\n';
        }
        else
        {
            cout << "uncertain" << '\n';
        }
    }
    return 0;
}

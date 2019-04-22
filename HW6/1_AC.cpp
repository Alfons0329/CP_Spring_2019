#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define MIN -100005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, tmp, g_size, cpu_size = 0;
    cin >> n >> q;
    g_size = n;

    vi v;
    v.pb(MIN);
    deque<int> g_order; 
    vb in_cpu(n + 1, 0);
    map<int, vector<int>> cpu; // gid -> process stk

    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }

    int op1, op2;
    while(q--)
    {
        cin >> op1; 
        if(op1 == 1)
        {
            cin >> op2;
            if(in_cpu[op2])
            {
                cout << "Ignore" << '\n';
            }
            else
            {
                if(cpu[v[op2]].size() == 0) // havent such gruop in it
                {
                    g_order.pb(v[op2]);
                }
                cpu[v[op2]].push_back(op2);
                in_cpu[op2] = 1;
                cout << "Successful" << '\n';
            }
        }
        else
        {
            if(g_order.size())
            {
                int g_id = g_order.front();
				op2 = cpu[g_id].back();
				cout << op2 << '\n';
                in_cpu[op2] = 0;
                cpu[g_id].pop_back();

                if(cpu[g_id].size() == 0)
                {
                    if(g_order.size())
                    {
                        g_order.pop_front();
                    }
					cpu.erase(g_id);
                }
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

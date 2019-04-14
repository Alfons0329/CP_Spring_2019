#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define MIN -100005
#define MAX_N 1000001
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

    queue<int> g_order;
    bool* in_cpu = (bool*) calloc(n + 1, sizeof(in_cpu));
    vector<stack<int>> cpu; // gid -> process stk
    cpu.resize(n + 1);
    int order_begin = 0, order_end = 0; 

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
            if(op2 > g_size)
            {
                cout << "Successful" << '\n';
            }
            else if(in_cpu[op2])
            {
                //print_cpu(in_cpu);
                cout << "Ignore" << '\n';
            }
            else
            {
                if(cpu[v[op2]].size() == 0) // havent such gruop in it
                {
                    g_order.push(v[op2]);
                }
                cpu[v[op2]].push(op2);
                in_cpu[op2] = 1;
                cout << "Successful" << '\n';
            }
        }
        else
        {
            if(g_order.size())
            {
                // printf("g_order[begin] %d\n", g_order[order_begin]);

                if(cpu[g_order.front()].size() > 0) // popped out all the element of certain group
                {
                    cout << cpu[g_order.front()].top() << '\n';
                    in_cpu[cpu[g_order.front()].top()] = 0;
                    cpu[g_order.front()].pop();
                    if(cpu[g_order.front()].size() == 0)
                    {
                        g_order.pop();
                    }
                }
            }
            else
            {
                cout << 0 << endl;
            }
        }
        // printf("\n");
    }
    free(in_cpu);
    return 0;
}

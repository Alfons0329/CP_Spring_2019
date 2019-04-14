#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define MIN -100005
using namespace std;
void print_cpu(vi g_order, unordered_map<int, stack<int>> cpu)
{
    printf("CPU: ");
    for(auto i : g_order)
    {
        stack<int> s2(cpu[i]);
        while(s2.size())
        {
            cout << s2.top() << ' ';
            s2.pop();
        }
    }
    printf("\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, tmp, g_size, cpu_size = 0;
    cin >> n >> q;
    g_size = n;

    vi v;
    v.pb(MIN);
    vi g_order;
    int order_begin = 0; 
    vb in_cpu(n + 1, 0);
    unordered_map<int, int> in_cpu_g;
    unordered_map<int, stack<int>> cpu; // gid -> process stk

    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }

    int op1, op2;
    while(q--)
    {
        cin >> op1; 
        // printf("op1 %d order_begin %d", op1, order_begin); 
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
                if(in_cpu_g.count(v[op2]) == 0) // havent such gruop in it
                {
                    g_order.pb(v[op2]);
                    in_cpu_g[v[op2]] = 1;
                }
                cpu[v[op2]].push(op2);
                // print_cpu(g_order, cpu);
                in_cpu[op2] = 1;
                cout << "Successful" << '\n';
            }
        }
        else
        {
            if(in_cpu_g.size())
            {
                cout << cpu[g_order[order_begin]].top() << '\n';
                in_cpu[cpu[g_order[order_begin]].top()] = 0;
                cpu[g_order[order_begin]].pop();

                if(cpu[g_order[order_begin]].size() == 0) // popped out all the element of certain group
                {
                    in_cpu_g.erase(g_order[order_begin]);
                    order_begin++;
                }
            }
            else
            {
                cout << 0 << endl;
            }
        }
        // printf("\n");
    }

    return 0;
}

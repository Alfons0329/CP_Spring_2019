#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
using namespace std;

void print_cpu(vi &v)
{
    cout << "cpu:  ";
    for(auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, tmp;
    vi v;
    v.pb(INT_MAX);
    cin >> n >> q;
    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }
    
    n = v.size();
    vi cpu;
    vb in_queue(n + 1, 0);
    vi gp_front(n + 1, INT_MAX);

    int op1, op2;
    while(q--)
    {
        cin >> op1;
        if(op1 == 1)
        {
            cin >> op2;
            if(in_queue[op2])
            {
                cout << "Ignore" << '\n';
            }
            else
            {
                if(gp_front[v[op2]] == INT_MAX)// first to be in the group
                {
                    cpu.pb(op2);
                    printf("op1 %d group new element %d\n",op1 ,op2);
                    print_cpu(v);
                    gp_front[v[op2]] = cpu.size();
                }
                else // in the group
                {
                    cpu.insert(cpu.begin() + gp_front[v[op2]], op2);
                    printf("old element %d group %d front %d\n", op2, v[op2], gp_front[v[op2]]);
                    print_cpu(v);
                    gp_front[v[op2]]--;
                }
                cout << "Successful" << '\n';
                in_queue[op2] = 1;
            }
        }
        else
        {
            if(v.size())
            {
                cout << cpu.front() + 1 << '\n';
                cpu.erase(cpu.begin());
                in_queue[op2] = 0;
            }
        }
    }

    return 0;
}

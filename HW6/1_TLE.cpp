#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define MIN -100005
using namespace std;

    template<class T>
void print_cpu(vector<T> &v)
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

    int n, q, tmp, g_size;
    vi v;
    v.pb(MIN);
    cin >> n >> q;
    g_size = n;

    vi cpu;
    vb in_cpu(n + 1, false);
    unordered_map<int, int>gp_front;
    unordered_map<int, int>::iterator it;
    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }


    int op1, op2;
    while(q--)
    {
        cin >> op1; 
        // printf("op1 %d", op1); 
        if(op1 == 1)
        {
            cin >> op2;
            // printf("op2 %d", op2);
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
                if(gp_front.count(v[op2]) == 0)// first to be in the group
                {
                    // printf("new element %d group %d new element %d\n", op2, v[op2] ,op2);
                    cpu.pb(op2);
                    //print_cpu(cpu);
                    gp_front[v[op2]] = cpu.size() - 1;
                }
                else // in the group
                {
                    // printf("old element %d group %d front %d\n", op2, v[op2], gp_front[v[op2]]);
                    cpu.insert(cpu.begin() + gp_front[v[op2]], op2);
                    //print_cpu(cpu);
                    gp_front[v[op2]] = gp_front[v[op2]] == 0 ? 0 : gp_front[v[op2]] - 1;
                    it = gp_front.begin();
                    for(; it != gp_front.end(); it++)
                    {
                        if(it -> first != v[op2] && it -> second > gp_front[v[op2]])
                        {
                            // printf("group %d front %d++\n", it -> first, it -> second);
                            it -> second ++;
                        }
                    }
                }
                cout << "Successful" << '\n';
                in_cpu[op2] = true;
            }
        }
        else
        {
            // printf("queue size %d\n", cpu.size());
            if(cpu.size())
            {
                cout << cpu.front() << '\n';
                in_cpu[cpu.front()] = false;
                it = gp_front.begin();
                for(; it != gp_front.end(); it++)
                {
                    if(it -> second > 0)
                    {
                        // printf("group %d front %d--\n", it -> first, it -> second);
                        it -> second --;
                    }
                }
                cpu.erase(cpu.begin());
                //print_cpu(in_cpu);
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        // printf("\n");
    }

    return 0;
}

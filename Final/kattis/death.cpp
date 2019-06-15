#include <bits/stdc++.h>
using namespace std;

int main()
{
    string op;
    int on1, on2;
    float total = 0.0f, avg = 0;
    int shares = 0;
    while(cin >> op)
    {
        if(op == "buy")
        {
            cin >> on1 >> on2;
            shares += on1;
            total += on1 * on2;
            avg = total / (float) shares; 
        }
        else if(op == "sell")
        {
            cin >> on1 >> on2;
            shares -= on1;
        }
        else if(op == "split")
        {
            cin >> on1;
            shares *= on1;
        }
        else if(op == "merge")
        {
            cin >> on1;
            avg *= on1;
            shares /= on1; 
        }
        else if(op == "die")
        {
            cin >> on1;
            float profit = on1 - avg; 
            float final_ans = shares * (max(0.0f, on1 - profit * 0.3f));
            printf("%.6f\n", final_ans);
        }

        printf("op %s on1 %d on2 %d, shares now %f, avg %f \n", op.c_str(), on1, on2, shares, avg);    
    }
    return 0;
}

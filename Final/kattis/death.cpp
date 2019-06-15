#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string op;
    int on1, on2;
    double total = 0.0f, avg = 0;
    int shares = 0;
    while(cin >> op)
    {
        if(op == "buy")
        {
            cin >> on1 >> on2;
            total = shares * avg + (double)(on1 * on2);
            shares += on1;
            avg = total / (double) shares; 
            //printf("shares in buy %d total %f avg %f\n", shares, total, avg);
        }
        else if(op == "sell")
        {
            cin >> on1 >> on2;
            shares -= on1;
            //printf("shares in sell %d total %f avg %f\n", shares, total, avg);
        }
        else if(op == "split")
        {
            cin >> on1;
            shares *= on1;
            avg /= on1;
            //printf("shares in split %d total %f avg %f\n", shares, total, avg);
        }
        else if(op == "merge")
        {
            cin >> on1;
            shares /= on1; 
            avg *= on1;
            //printf("shares in merge %d total %f avg %f\n", shares, total, avg);
        }
        else if(op == "die")
        {
            cin >> on1;
            double profit = ((double)on1 - (double)avg) < 0.0f ? 0 : ((double)on1 - (double)avg); 
            double final_ans = shares * (max(0.0, on1 - profit * 0.3));
            printf("%.5lf\n", final_ans);
        }
    }
    return 0;
}
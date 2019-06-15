#include <bits/stdc++.h>
using namespace std;

int main()
{
    string op;
    int on1, on2;
    float total = 0.0f, avg;
    int shares;
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
        
        }
        else if(op == "split")
        {
        
        }
        else if(op == "merge")
        {
        
        }
        else if(op == "die")
        {
        
        }
    
    }
    return 0;
}

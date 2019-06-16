#include <bits/stdc++.h>
using namespace std;

int a[11];
int main()
{
    int sum = 0;

    for(int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int d = sum - 100, flag = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(a[i] + a[j] == d)
            {
                a[i] = -1;
                a[j] = -1;
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    
    for(int i = 0; i < 9; i++)
    {
        if(a[i] != -1)
        {
            cout << a[i] << '\n';
        }
    }
    return 0;
}
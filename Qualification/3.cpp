#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int one = 0, zero = 0;
    cin >> str;
    int n = str.size();
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    printf("%d %d\n", zero, one);
    return 0;
}

#include <bits/stdc++.h>
const int MAX_N = 2e7;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int D, Q;
    scanf("%d" ,&D);
    int m[MAX_N] = {0};
    string s;
    
    int T = D;
    int n = 0;
    while(T--)
    {
        cin >> s;
        n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                m[i * 2]++;
            }
            else
            {
                m[i * 2 + 1]++;
            }
        }
    }
    
    scanf("%d", &Q);
    while(Q--)
    {
        cin >> s;
        n = s.size();
        if(s[n - 1] == '0')
        {
            printf("%d\n", m[2 * (n - 1)]);
        }
        else
        {
            printf("%d\n", m[2 * (n - 1) + 1]);
        }
    }
    
    return 0;
}

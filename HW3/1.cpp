#include <bits/stdc++.h>
const int MAX_N = 2e2;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int D, Q;
    cin >> D;

    unordered_map<string, int> m;
    string s, tmp;
    
    int T = D;
    int n = 0;
    while(T--)
    {
        cin >> s;
        n = s.size();
        tmp = "";
        for(int i = 0; i < n; i++)
        {
            tmp += s[i];
            m[tmp]++;
        }
    }
    
    cin >> Q;
    while(Q--)
    {
        cin >> s;
        cout << m[s] << '\n';
    }
    
    return 0;
}

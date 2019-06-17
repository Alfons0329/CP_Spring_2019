// for visualized solution, see text_message.jpg
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T, k, p, l, cas = 0;
    cin >> T;
    while(T--)
    {
        cin >> p >> k >> l;
        vector<long long> letter(l, 0);
        // vector<vector<long long> > greedy(k, vector<int>(p, 0));
        for(int i = 0; i < l; i++)
        {
            cin >> letter[i];
        }
        
        sort(letter.begin(), letter.end(), cmp);
        int cnt = 0;
        long long res = 0;
        for(int i = 1; i <= p; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(cnt >= l)
                {
                    break;
                }
                res += letter[cnt++] * i;
                // printf("cnt %d res %lld i %d j %d", cnt, res, i, j);
                // greedy[i][j] = letter[k];   
            }
            if(cnt >= l)
            {
                break;
            }
        }
        cout << "Case #" << ++cas << ": " << res << '\n';
    }
    return 0;
}
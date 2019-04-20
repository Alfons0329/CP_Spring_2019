#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX_N 50001
using namespace std;

ull fft(vector<ull>& sw, vector<ull>& sh, ull q)
{
    ull res = 0;
    if(q > 1e5)
    {
        return 0;
    }
    else
    {
        ull end = q;

        for(int i = end; i >= 0; --i)
        {
            // printf("i %d end - i %d\n", i, end - i);
            res += sw[end - i] * sh[i];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tmp, cnt = 0;
    ull q;
    cin >> n >> m >> q;

    vector<ull> sw(MAX_N, 0);
    vector<ull> sh(MAX_N, 0);
    sw[0] = sh[0] = 1;
    while(n--)
    {
        cin >> tmp;
        sw[tmp]++;
    }
    while(m--)
    {
        cin >> tmp;
        sh[tmp]++;
    }

    while(q--)
    {
        cin >> tmp;
        cout << fft(sw, sh, tmp) << '\n';
    }

    return 0;
}

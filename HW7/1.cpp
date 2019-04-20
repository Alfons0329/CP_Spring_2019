#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX_N 65536
#define MAX_HP 100005
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

ull bit_rev(ull x, int log2n)
{
    ull n = 0;
    for(int i = 0; i < log2n; ++i)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

void fft(vector<cd>& a, vector<cd>& A, int log2n)
{
    ull n = MAX_N;
    for(ull i = 0; i < n; ++i)
    {
        ull rev = bit_rev(i, log2n);
        A[i] = a[rev];
    }

    const cd J(0, 1);
    for (int s = 1; s <= log2n; ++s) 
    {
        int m = 1 << s; // 2 power s
        int m2 = m >> 1; // m2 = m/2 -1
        cd w(1, 0);

        cd wm = exp(J * (PI / m2));
        for (int j = 0; j < m2; ++j)
        {
            for (int k = j; k < n; k += m) 
            {
                cd t = w * A[k + m2];
                cd u = A[k];
                A[k] = u + t;
                A[k + m2] = u - t;
            }
            w *= wm;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tmp, cnt = 0, max_sw = 0, max_sh = 0;
    ull q;
    cin >> n >> m >> q;
    vector<cd> sw(MAX_N, 0);
    vector<cd> sw_cp(MAX_N, 0);
    vector<cd> sh(MAX_N, 0);
    vector<cd> sh_cp(MAX_N, 0);
    vector<cd> res(MAX_N, 0);

    sw[0] = sh[0] = 1;
    while(n--)
    {
        cin >> tmp;
        cout << "tmp " << tmp << '\n';
        max_sw = max(max_sw, tmp);
        sw[tmp] += 1;
    }
    while(m--)
    {
        cin >> tmp;
        cout << "tmp " << tmp << '\n';
        max_sh = max(max_sh, tmp);
        sh[tmp] += 1;
    }

    fft(sw, sw_cp, log2(max_sw));
    fft(sh, sh_cp, log2(max_sh));
    for(int i = 0; i < max_sh + max_sw; i++)
    {
        sw_cp[i] *= sh_cp[i];
    }
    fft(sw_cp, res, log2(max_sh + max_sw));

    cout << "------\n";
    for(int i = 0; i < 5; i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}

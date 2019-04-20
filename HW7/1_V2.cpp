#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
const int MAX_N = 4e5 + 10;
int r[MAX_N];
struct Complex{
    double r, i;
    Complex(){}
    Complex(double _r, double _i){ r = _r, i = _i; }
    Complex operator +(const Complex &y) { return Complex(r+y.r, i+y.i); }
    Complex operator -(const Complex &y) { return Complex(r-y.r, i-y.i); }
    Complex operator *(const Complex &y) { return Complex(r*y.r - i*y.i, r*y.i+i*y.r); }
    Complex operator *=(const Complex &y) { double t = r; r = r*y.r - i*y.i, i = t*y.i + i*y.r; }
}a[MAX_N], b[MAX_N], c[MAX_N];
void fft(Complex *a, int len, int op)
{
    Complex tt;
    for (int i = 0; i < len; i++)
    {
        if (i < r[i])
        {
            tt = a[i], a[i] = a[r[i]], a[r[i]] = tt;
        }
    }
    for (int i = 1; i < len; i <<= 1)
    {
        Complex wn(cos(PI / i), sin(PI * op / i));
        for (int k = 0, t = (i << 1); k < len; k += t)
        {
            Complex w(1, 0);
            for (int j = 0; j < i; j++, w *= wn)
            {
                Complex t = w * a[k + j + i];
                Complex u = a[k + j];
                a[k + j] = u + t;
                a[k + j + i] = u - t;
            }
        }
    }
    if (op == -1)
    {
        for (int i = 0; i < len; i++)
        {
            a[i].r /= len;
            a[i].i /= len;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, n, M, m, Q, tmp;
    cin >> N >> M >> Q;
    a[0].r = b[0].r = 1;
    m = n = 0;
    while(N--)
    {
        cin >> tmp;
        a[tmp].r++;
        n = max(n, tmp);
    }
    while(M--)
    {
        cin >> tmp;
        b[tmp].r++;
        m = max(m, tmp);
    }

    m += n;
    // printf("n %d m %d\n", n, m);
    int L, i, x;
    for(n = 1, L = 0; n <= m; n <<= 1)
    {
        L++;
    }
    for (i = 0, x = L - 1; i < n; i++)
    {
        r[i] = (r[i >> 1] >>1) | ((i & 1) << x);
    } 

    // printf("n %d m %d\n", n, m);
    fft(a, n, 1);
    // printf("OK\n");
    fft(b, n, 1);
    // printf("OK2\n");
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
        // printf("i %d ci %d ai %d bi %d\n", i, c[i], a[i], a[i]);
    }
    // printf("OK3\n");
    fft (c, max(n, m), -1);
    // printf("OK4\n");
    
    while(Q--)
    {
        cin >> tmp;
        if(tmp > 1e5 + 5)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << int(c[tmp].r + 0.5) << '\n';
        }
    }
    return 0;
}

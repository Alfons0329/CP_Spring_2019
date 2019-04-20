#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
const int MAXN = 4*1e5+10;
int r[MAXN];
struct Complex{
    double r, i;
    Complex(){}
    Complex(double _r, double _i){ r = _r, i = _i; }
    Complex operator +(const Complex &y) { return Complex(r+y.r, i+y.i); }
    Complex operator -(const Complex &y) { return Complex(r-y.r, i-y.i); }
    Complex operator *(const Complex &y) { return Complex(r*y.r - i*y.i, r*y.i+i*y.r); }
    Complex operator *=(const Complex &y) { double t = r; r = r*y.r - i*y.i, i = t*y.i + i*y.r; }
}a[MAXN], b[MAXN];
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
        Complex wn(cos(PI/i), sin(PI*op/i));
        for (int k=0, t=(i<<1); k < len; k += t)
        {
            Complex w(1, 0);
            for (int j = 0; j < i; j++, w *= wn)
            {
                Complex t = w*a[k+j+i];
                Complex u = a[k+j];
                a[k+j] = u + t;
                a[k+j+i] = u - t;
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
    int L, i, x;
    for(int i = 0; i <= 4; i++)
    {
        cout << a[i].r << '|' << b[i].r << '\n';
    }
    for(n = 1, L = 0; n <= m; n <<= 1)
    {
        L++;
    }
    for (i = 0, x = L - 1; i < n; i++)
    {
        r[i] = (r[i>>1]>>1) | ((i&1)<<x);
    } 

    fft(a, n, 1);
    fft(b, n, 1);
    for (int i = 0; i < n; i++)
    {
        a[i] *= b[i];
    }
    fft (a, n, -1);
    
    printf("res -----\n");
    while(Q--)
    {
        cin >> tmp;
        cout << int(a[tmp].r + 0.5) << '\n';
    }
    return 0;
}

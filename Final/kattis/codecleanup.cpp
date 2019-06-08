#include <bits/stdc++.h>
using namespace std;

int a[366];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = a[n - 1]; // padding 
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i;
        res++;
        while(j < n && a[j] - a[i] < 20)
        {
            j++;
        }
        i = j - 1;
    }
    
    cout << res << '\n';
    return 0;
}

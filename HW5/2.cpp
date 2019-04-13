#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

bool compare(int& a, int& b)
{
    return a < b;
}

pii find_need(vi& v)
{
    int r_most = -1, cei = -1, n = v.size();
    for(int i = 0; i < n - 1; i++)
    {
        if(v[i] < v[i + 1])
        {
            r_most = i;
        }
    }

    if(r_most >= 0)
    {
        int cei_value = INT_MAX;
        for(int i = r_most + 1; i < n; i++)
        {
            if(v[i] < cei_value && v[i] > v[r_most])
            {
                cei_value = v[i];
                cei = i;
            }
        }
        // printf("r_most val %d cei val %d\n", v[r_most], v[cei]);
    }

    return make_pair(r_most, cei);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, tmp;
    vi v;
    cin >> n >> k;
    while(n--)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int has_next = 0;
    while(k--) 
    {
        pii p = find_need(v);
        int r_most = p.first, cei = p.second;

        if(r_most < 0) 
        {
            break;
        }
        has_next = 1;
        swap(v[r_most], v[cei]);
        sort(v.begin() + r_most + 1, v.end());
        
        for(auto i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    if(has_next == 0)
    {
        cout << "hello world!" << '\n';
    }

    return 0;
}

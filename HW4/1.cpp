#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
vector<string> order;
void collect(string& str)
{
    string::iterator it = str.begin();
    string pu;
    while(it != str.end())
    {
        if(isalpha(*it))
        {
            pu += tolower(*it);
        }
        ++it;
    }
    if(m.count(pu) == 0 && isalpha(pu[0]))
    {
        order.push_back(pu);
    }
    m[pu]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(cin >> str)
    {
        collect(str);
    }

    for(auto i : order)
    {
        cout << i << ' ' << m[i] << '\n';
    }

    return 0;
}

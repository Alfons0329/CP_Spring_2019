#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
vector<string> order;
void collect(const string& str)
{
    string w_split;
    stringstream ss(str);
    while(ss >> w_split)
    {
        string::iterator it = w_split.begin();
        string pu;
        cout << "wsplit[" << w_split << "]\n"; 
        while(it != w_split.end())
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

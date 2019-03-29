#include <bits/stdc++.h>
using namespace std;
void solve(const string& str)
{
    string w_split;
    stringstream ss(str);
    unordered_map<string, int> m;
    vector<string> order;
    while(ss >> w_split)
    {
        string::iterator it = w_split.begin();
        string pu;
        while(it != w_split.end())
        {
            if(!isalpha(*it))
            {
                break;
            }
            pu += tolower(*it);
            ++it;
        }

        if(m.count(pu) == 0)
        {
            order.push_back(pu);
        }
        m[pu]++;
    }

    for(auto i : order)
    {
        cout << i << ' ' << m[i] << endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(getline(cin, str))
    {
        solve(str);
    }
    return 0;
}

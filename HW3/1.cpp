#include <bits/stdc++.h>

using namespace std;
bool mycompare(const string& s1, const string& s2)
{
    return s1.size() > s2.size();
}
bool prefix_match(const string& s1, const string& s2)
{
    int n = s1.size() == s2.size() ? s1.size() : min(s1.size(), s2.size());
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }
    // cout << s1 << " , " << s2 << " prefix prefix_match \n";
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int D, Q;
    scanf("%d" ,&D);
    unordered_map<string, int>m;
    string str;
    
    while(D--)
    {
        cin >> str;
        m[str]++;
    }

    // process the dictionary
    
    for(unordered_map<string, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        
        for(unordered_map<string, int>::iterator j = m.begin(); j != m.end(); j++)
        {
            if(i -> first.size() < j -> first.size() && i -> first != j -> first && prefix_match(i -> first, j -> first))
            {
                m[i -> first]++;
                // cout << i -> first << " increment to  " << i -> second << " \n";  
            }
        }
    }
    scanf("%d", &Q);
    while(Q--)
    {
        cin >> str;
        printf("%d\n", m[str]);
    }
    
    return 0;
}

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;


int main()
{
    string str, tmp;
    
    while(getline(cin, str))
    {
        vector<string> stk;
        int n = str.size(), cnt = 0;
        ull res = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] <= '9' && str[i] >= '0')
            {
                cnt = i;
                while(str[cnt] >= '0' )
                {
                    cnt++;
                }
                //cout << "pb " << str.substr(i, cnt - i);
                stk.push_back(str.substr(i, cnt - i));
                i = cnt - 1;
            }
            else
            {
                tmp = "";
                tmp += str[i];
                stk.push_back(tmp);
            }
            //printf("stk size %ld \n", stk.size());
            if(stk.size() == 3) //do operation
            {
                //cout << stk[0] << "," <<stk[1] << "," << stk[2] << '\n';

                if(stk[1] == "*")
                {
                    res = stoi(stk[0]) * stoi(stk[2]);
                }
                else
                {
                    res = stoi(stk[0]) + stoi(stk[2]);
                }
                stk.clear();
                stk.push_back(to_string(res));
                // printf("res pb %lld, total %lld\n", res, stoi(stk.back()));
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}


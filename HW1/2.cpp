#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

vector<int> str_2_big(string s)
{
    vector<int> v;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        v.push_back(s[i] - '0');
    }
    return v;
}

string big_2_str(vector<int> v)
{
    string s;
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        if(v[i] > 0)
        {
            s += to_string(v[i]);
        }
    }
    return s;
}

string big_num_add(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    if(m > n)
    {
        swap(s1, s2);
    }

    vector<int>res(n + 2, 0);
    n += 2;

    vector<int> num_1 = str_2_big(s1);
    vector<int> num_2 = str_2_big(s2);

    for(int i = 0; i < n; i++)
    {
        if(i >= m)
        {
            res[i] = num_1[i];
        }
        else
        {
            res[i] = num_1[i] + num_2[i];
        }
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    string str = big_2_str(res);
    cout << "addres " << str << endl;
    return str;
}

string big_num_mul(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    if(m > n)
    {
        swap(s1, s2);
    }

    vector<int>res(n + m - 1, 0);
    int total_len = n + m - 1;

    vector<int> num_1 = str_2_big(s1);
    vector<int> num_2 = str_2_big(s2);
    
    int k = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            res[total_len - k] += num_1[i] * num_2[j];
            k++;
        }
        k = 0;
    }

    for(int i = total_len; i >= 0; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    string str = big_2_str(res);
    cout << "mulres " << str << endl;
    return str;
}


int main()
{
    string str, tmp;
    
    while(getline(cin, str))
    {
        vector<string> stk;
        int n = str.size(), cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] <= '9' && str[i] >= '0') // pb the operands
            {
                cnt = i;
                while(str[cnt] >= '0' )
                {
                    cnt++;
                }
                stk.push_back(str.substr(i, cnt - i));
                i = cnt - 1;
            }
            else // pb the operator
            {
                tmp = "";
                tmp += str[i];
                stk.push_back(tmp);
            }

            if(stk.size() == 3) // do operation
            {
                if(stk[1] == "+")
                {
                    tmp = big_num_add(stk[0], stk[2]);
                }
                else if(stk[1] == "*")
                {
                    tmp = big_num_mul(stk[0], stk[2]);
                }
                stk.clear();
                stk.push_back(tmp);
            }
            cout << "Stktop " << stk.back() << endl;
        }
        cout << stk.back() << '\n';
    }
    return 0;
}


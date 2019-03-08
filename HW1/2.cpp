#include <bits/stdc++.h>
#define MAX_N 201
#define MAX_NN 402
using namespace std;

void str_2_big(string s, int* v)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        v[MAX_N - i - 1] = s[n - i - 1] - '0';
    }
}

string big_2_str(int* v, int len)
{
    string s;
    int non_zero_flg = 0;
    for(int i = 0; i < len; i++)
    {
        if(v[i] > 0)
        {
            non_zero_flg = 1;
        }
        if(non_zero_flg)
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

    int res[MAX_N] = {0};
    int num_1[MAX_N] = {0}; 
    int num_2[MAX_N] = {0};
    str_2_big(s1, num_1);
    str_2_big(s2, num_2);

    for(int i = MAX_N - 1; i >= 0; i--)
    {
        // printf("i %d , %d + %d\n", i, num_1[i], num_2[i]);
        if(num_1[i] == 0 && num_2[i] == 0)
        {
            break;
        }
        res[i] = num_1[i] + num_2[i];
    }
    
    for(int i = MAX_N - 1; i >= 0; i--)
    {
        // printf("i %d res %d\n", i, res[i]);
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
        else if(res[i] == 0)
        {
            break;
        }
    }
    return big_2_str(res, MAX_N);
}

string big_num_mul(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    int res[MAX_NN] = {0};
    int num_1[MAX_N] = {0}; 
    int num_2[MAX_N] = {0};
    str_2_big(s1, num_1);
    str_2_big(s2, num_2);
    int k = 0;

    for(int i = MAX_N - 1, l = MAX_NN - 1; i >= 0; i--, l--)
    {
        for(int j = MAX_N - 1; j >= 0; j--)
        {
            res[l - k] += num_1[i] * num_2[j];
            k++;
        }
        k = 0;
    }

    for(int i = MAX_NN - 1; i >= 0; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    return big_2_str(res, MAX_NN);
}


int main()
{
    string str, tmp;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vector<string> stk;
    while(getline(cin, str))
    {
        int n = str.size(), cnt = 0;
        stk.clear();
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
                    if(stk[0] != "0" && stk[2] != "0")
                    {
                        tmp = big_num_add(stk[0], stk[2]);
                    }

                }
                else if(stk[1] == "*")
                {
                    if(stk[0] != "0" && stk[2] != "0")
                    {
                        tmp = big_num_mul(stk[0], stk[2]);
                    }
                }
                stk.clear();
                stk.push_back(tmp);
            }
            // cout << "Stktop " << stk.back() << endl;
        }
        cout << stk.back() << '\n';
    }
    return 0;
}


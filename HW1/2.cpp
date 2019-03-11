#include <bits/stdc++.h>
#define MAX_N 402
using namespace std;

int res[MAX_N];
int num[MAX_N];

void str_2_big(string s, int in[MAX_N], int str_len)
{
    for(int i = 0; i < MAX_N; i++)
    {
        in[MAX_N - i - 1] = s[str_len - i - 1] - '0';
    }
}

void big_num_add()
{
    for(int i = MAX_N - 1; i >= 0; i--)
    {
        res[i] += num[i];
    }

    for(int i = MAX_N - 1; i >= 0; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
}

void big_num_mul()
{
    int k = 0;

    for(int i = MAX_N - 1, l = MAX_N - 1; i >= 0; i--, l--)
    {
        for(int j = MAX_N - 1; j >= 0; j--)
        {
            res[l - k] *= num[i];
            k++;
        }
        k = 0;
    }

    for(int i = MAX_N - 1; i >= 0; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
}

void print_res()
{
    int start_pos = 0;
    for(int i = 0; i < MAX_N; i++)
    {
        if(res[i] != 0)
        {
            start_pos = i;
        }
    }

    for(int i = start_pos; i < MAX_N; i++)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    return;
}
int main()
{
    string str, tmp;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, cnt, str_len, flag;
    char last_oper, this_oper;

    while(getline(cin, str))
    {
        n = str.size();
        cnt = 0;
        flag = 0;
        
        memset(res, 0, sizeof(res));
        memset(num, 0, sizeof(num));
        
        for(int i = 0; i < n; i++)
        {
            str_len = 0;
            if(str[i] <= '9' && str[i] >= '0') // collect the operands
            {
                cnt = i;
                
                while(str[cnt] >= '0')
                {
                    cnt++;
                    str_len++;
                    if(cnt == n)
                    {
                        break;
                    }
                }
                
                tmp = str.substr(i, cnt - i);
                i = cnt - 1;
            }

            if(flag == 0) // 1st number to do
            {
                str_2_big(tmp, res, str_len);
                last_oper = str[i];
                cout << "1st " << tmp << " last_oper" << last_oper << endl;
                flag = 1;
            }
            else
            {
                str_2_big(tmp, res, str_len);
                last_oper = this_oper;
                this_oper = str[i];
                cout << "to oper " << tmp << " last_oper" << last_oper << endl;
            }

            if(last_oper == '+')
            {
                big_num_add();
            }
            else if(last_oper == '*')
            {
                big_num_mul();
            }
        }
        print_res();
       }
    return 0;
}

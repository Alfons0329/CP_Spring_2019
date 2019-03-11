#include <bits/stdc++.h>
#define MAX_NN 402
#define MAX_N 201
using namespace std;

int res[MAX_NN];
int num[MAX_NN];
int buf[MAX_NN];

void print_num(int in[MAX_NN])
{
    int start_pos = 0;
    // printf("res now ");
    for(int i = 0; i < MAX_NN; i++)
    {
        if(res[i] > 0)
        {
            start_pos = i;
            break;
        }
    }

    for(int i = start_pos; i < MAX_NN; i++)
    {
        printf("%d", in[i]);
    }
    printf("\n");
    return;
}

void str_2_big(string s, int in[MAX_NN], int str_len)
{
    memset(in, 0, sizeof(int) * MAX_NN);
    for(int i = 0; i < str_len; i++)
    {
        in[MAX_NN - i - 1] = s[str_len - i - 1] - '0';
    }
    // printf("from str2_big str_len %d", str_len);
    // print_num(in);
}

void big_num_add()
{
    for(int i = MAX_NN - 1; i >= MAX_N; i--)
    {
        res[i] += num[i];
    }

    for(int i = MAX_NN - 1; i >= MAX_N; i--)
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

    memcpy(buf, res, sizeof(res));
    memset(res, 0, sizeof(res));
    for(int i = MAX_NN - 1; i >= MAX_N; i--) // outer layer num
    {
        for(int j = MAX_NN - 1; j >= MAX_N; j--) // inner layer res
        {
            if(num[i] == 0)
            {
                break;
            }
            res[i + j + 1 - MAX_NN] += buf[j] * num[i];
            // printf("buf %d = %d, num %d = %d res %d = %d\n", j, buf[j], i, num[i], i + j +1 -MAX_NN, res[i + j + 1 - MAX_NN]);
        }
    }

    for(int i = MAX_NN - 1; i >= 1; i--)
    {
        if(res[i] >= 10)
        {
            res[i - 1] += res[i] / 10;
            // printf("res %d = %d inc %d to %d\n", i, res[i], res[i] / 10, res[i - 1]);
            res[i] %= 10;
        }
    }
}


int main()
{
    string str, tmp;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, cnt, flag;
    char last_oper, this_oper;

    while(getline(cin, str))
    {
        n = str.size();
        cnt = 0;
        flag = 0;

        memset(res, 0, sizeof(res));
        memset(num, 0, sizeof(num));
        memset(buf, 0, sizeof(buf));

        for(int i = 0; i < n; i++)
        {
            if(str[i] <= '9' && str[i] >= '0') // collect the operands
            {
                cnt = i;

                while(str[cnt] >= '0')
                {
                    cnt++;
                    if(cnt == n)
                    {
                        break;
                    
                    }
                }

                tmp = str.substr(i, cnt - i);
                i = cnt;
            }

            if(flag == 0) // 1st number to do
            {
                str_2_big(tmp, res, tmp.length());
                this_oper = str[i];
                // cout << "1st " << tmp << " last_oper" << this_oper << endl;
                flag = 1;
            }
            else
            {
                str_2_big(tmp, num, tmp.length());
                last_oper = this_oper;
                this_oper = str[i];
                // cout << "to oper " << tmp << " last_oper" << last_oper << endl;

                if(last_oper == '+')
                {
                    big_num_add();
                }
                else if(last_oper == '*')
                {
                    big_num_mul();
                }
            }
        }
        print_num(res);
    }
    return 0;
}

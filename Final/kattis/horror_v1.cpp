#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // data IO
    int n, m, tmp, last_day = 1, first_day = INT_MAX;
    bool like1[1000000] = {false};
    bool like2[1000000] = {false};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        like1[tmp] = true;
        last_day = max(tmp, last_day);
        first_day = min(tmp, first_day);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        like2[tmp] = true;
        last_day = max(tmp, last_day);
        first_day = min(tmp, first_day);
    }

    // check interval, dislike is the "mark of previous deslike"
    int dislike1 = 0, dislike2 = 0, days = 0, res = 0;
    for(int i = first_day; i <= last_day; i++)
    {
        if(like1[i] && like2[i]) // if both like, watch movie on such day
        {
            days++;
            dislike1 = dislike2 = 0;
        }
        else if(dislike1 == 0 && like2[i]) // if only person 2 likes, and previously person 1 DOES NOT DISLIKE, OK TO WATCH MOVIE
        {
            days++;
            dislike1 = 1;
            dislike2 = 0;
        }
        else if(like1[i] && dislike2 == 0) // if only person 1 likes, and previously person 2 DOES NOT DISLIKE, OK TO WATCH MOVIE
        {
            days++;
            dislike1 = 0;
            dislike2 = 1;
        }
    }

    cout << days; 
    return 0;
}


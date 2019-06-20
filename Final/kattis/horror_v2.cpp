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

    // check interval, dislike is the "continuous single dislike (either by person1 or person2)"
    int dislike1 = 0, dislike2 = 0, days = 0, res = 0;
    for(int i = 0; i < 1e6; i++)
    {
        if(like1[i] && like2[i])
        {
            days++;
            dislike1 = dislike2 = 0; // dislike should be set to zero ONLY IF both like the movie, thus cut the continuity of dislikeness
        }
        else if(!like1[i] && like2[i])
        {
            dislike1++;
            dislike2 = 0;
            if(dislike1 >= 2)
            {
                // dislike1 = 0; // WA
                dislike1 = 1; // NOT 0! 0 will cause WA since once reach dislike by someone, there is at least 1 dislike counter for him
            }
            else 
            {
                days++;
            }
        }
        else if(like1[i] && !like2[i])
        {
            dislike2++;
            dislike1 = 0;
            if(dislike2 >= 2)
            {
                // dislike2 = 0; // WA
                dislike2 = 1; // NOT 0! 0 will cause WA since once reach dislike by someone, there is at least 1 dislike counter for him
            }
            else
            {
                days++;
            }
        }
    }

    cout << days; 
    return 0;
}


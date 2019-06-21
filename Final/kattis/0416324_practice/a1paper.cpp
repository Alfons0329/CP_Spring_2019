#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    pair<double, double > scale[31];
    scale[2].first = pow(2.0, -3.0 / 4.0); // size of a1 paper, first long side, second short side
    scale[2].second = pow(2.0, -5.0 / 4.0);
    // calculate all the scale
    for(int i = 3; i <= 30; i++) //from A2 to A 30
    {
        scale[i].first = scale[i - 1].second;
        scale[i].second = scale[i - 1].first / 2.0;
    }

    int n;
    cin >> n;
    vector<int>paper(31);
    n--;
    for(int i = 2; i < n + 2; i++)
    {
        cin >> paper[i];
    }

    // sum up from the largest paper (greedy) 
    int can = 0, need = 1; 
    double res = 0;
    for(int i = 2; i < n + 2; i++)
    {
        res += scale[i].first * (double)need;
        need *= 2; // need 2 paper to form a bigger one
        need -= paper[i]; // use the paper, decrease the requirement

        if(need <= 0) // need satisfied ! 
        {
            can = 1;
            break;
        }
    }
    
    if(can)
    {
        cout << fixed;
        cout.precision(9);
        cout << res;
    }
    else
    {
        cout << "impossible";
    }
    return 0;
}

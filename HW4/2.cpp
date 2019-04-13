#include <bits/stdc++.h>
using namespace std;

void triangle(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
{ 
    double a1=2*(x2-x1);
    double b1=2*(y2-y1);
    double c1=x2*x2+y2*y2-x1*x1-y1*y1;

    double a2=2*(x3-x2);
    double b2=2*(y3-y2);
    double c2=x3*x3+y3*y3-x2*x2-y2*y2;

    double x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
    double y=(a1*c2-a2*c1)/(a1*b2-a2*b1);

    cout << x << ' ' << y << ' ' << sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) << '\n'; 
}

void line(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
{
    set<pair<int, int>> spi;
    spi.insert(make_pair(x1, y1));
    spi.insert(make_pair(x2, y2));
    spi.insert(make_pair(x3, y3));
    int n = spi.size();
    double x = 0.0f, y = 0.0f;
    
    for(auto i : spi)
    {
        x += i.first;
        y += i.second;
    }
    x /= (double)n;
    y /= (double)n;
    cout << x << ' ' << y << ' ' << sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) << '\n'; 
}

double len(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double x1, x2, x3, y1, y2, y3, x4, y4;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
    {
        vector<double> l(3, 0.0f);
        l[0] = len(x1, y1, x2, y2); 
        l[1] = len(x1, y1, x3, y3); 
        l[2] = len(x3, y3, x2, y2);
        sort(l.begin(), l.end());

        if(l[0] + l[1] > l[2]) // is triangle
        {
            triangle(x1, y1, x2, y2, x3, y3);
        }
        else
        {
            line(x1, y1, x2, y2, x3, y3);
        }
    } 
    return 0;
}

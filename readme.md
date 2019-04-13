# Competitive Programming
* Spring 2019
* Lecturer: Min-Zheng Hsieh
* Time: 5IJK @ ED117
* Note: Please use your Google or E3 account to use OAuth for login

###### tags: `NCTU CS` `Blog` `OJ` 

## 20190308, HW1
### [Big Integer](https://oj.nctu.me/problems/819/)
* Thought: Lazy... just use python
```python
from sys import stdin
lines = stdin.read().splitlines()
for each_line in lines:
    res = 0
    for i in each_line.split(  ):
        res += int(i)

    print(res)
```
### [Expression](https://oj.nctu.me/problems/820/)
* Thought: Use `re` module to split input with regular expression (split the operators) and `()` symbol to keep operator and operand in the same container.

```python
from sys import stdin
import re
import collections as col

while True: # keep reading till eof
    try:
        each_line = input() # read each line
    except EOFError: # break when EOF encounters
        break

    splitted = re.split(r'(\*|\+)', each_line) # split line with regular expression
    res = int(splitted[0]) # pb the first
    for i in range(1, len(splitted), 2):
        if splitted[i] == '*':
            res *= int(splitted[i + 1])
        else:
            res += int(splitted[i + 1])

    print(res)
```

## 20190315, HW2
### [Mex](https://oj.nctu.me/problems/822/) 
* Thought 1(MLE): Store each of the input number in the hash map, and traverse from 0 to len_map - 1, seeing which number is the first that haven't been put to the slot before
* Analysis: 
    * Time complexity: $O(N) 
    * Space complexity $O(r-l)$ but the `bool* m = new bool[r - l + 1]();` part due to r, l may be up to $10^{18}$, and the input length is at most $10^7$, it is quite sparse and waste lots of memory space thus causing MLE.  

```cpp
#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffffffffffff
#define MAX_N 10000000
using namespace std;
int main()
{
    // read # of testcases
    int tc;
    scanf("%d", &tc);
    ll n, l, r;
    ll tmp; // for keep eating the subset

    while(tc--)
    {
        // read n l r
        scanf("%d %d %d", &n, &l, &r);
        
        if(n == 0) //special case
        {
            printf("%lld\n", r);
            continue;
        }

        if(l == r) // no subset
        {
            printf("^v^\n");
            continue;
        }

        // hash map
        bool* m = new bool[r - l + 1]();

        while(n--)
        { 
            scanf("%lld", &tmp);
            m[tmp - l] = true;
        }

        // do ans
        bool has_ans = 0;
        ll shift = 0;
        for(int i = 0; i < MAX_N; i++)
        {
            if(m[i] == false)
            {
                has_ans = 1;
                shift = i;
                break;
            }
        }

        if(has_ans)
        {
            printf("%lld\n", shift + l);
        }
        else
        {
            printf("^v^\n");
        }
        delete m;
    }

    return 0;
}
```
* Thought2(AC): Still use the hashmap, but only store the first n numbers where $len\_map = n + 1$ is the size of subset. And traverse up to $min(n + 1, l - r + 1)$ Please try the gieven example and you'll understand how it works :smile_cat: 
* Analysis:
    * Time complexity $O(N), N = len(subset)$
    * Space complexity $O(N), N = len(subset)$ 
```
Example:

Original set =         {1 2 3 4 5 6 7 8}
Subset                 {2 5 7 8}   
Bool map (len 5) =     {0 0 0 0 0} (Store only the occupancy of 1 - 5)

After hashing
Original set =         {1 2 3 4 5 6 7 8}
Subset                 {2 5 7 8}   
Bool map (len 5) =     {0 1 0 0 1} (Store only the occupancy of 1 - 5)

Traverse to min(8, 5) - 1, the first non-occupied slot is 0 --> a[0] = 1
-----------------------------------------------------
More examples
Original set =         {1 2 3 4 5}
Subset                 {1 2 3}
Bool map (len 3) =     {1 1 1 0} traverse to min(5, 4) - 1, the first non-occupied slot is 3 a[3] = 4

Original set =         {1 2 3 4 5}
Subset                 {1 2 3 4 5}
Bool map (len 5) =     {1 1 1 1 1 0} traverse to min(5, 6) - 1, hence all the slot are occupied and the result is ^v^

```
* Analysis: Time complexity: $O(N)$, Space complexity $O(N)$ where $N = len(subset)$

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int main()
{
    // read # of testcases
    int tc;
    scanf("%d", &tc);
    ll n, l, r;
    ll tmp; // for keep eating the subset

    while(tc--)
    {
        // read n l r
        scanf("%lld %lld %lld", &n, &l, &r);

        if(n == 0) // special case
        {
            printf("%lld\n", r);
            continue;
        }

        // map
        bool* m = calloc(n + 1, sizeof(bool)); //padding
        int array_len = min(n + 1, r - l + 1);
        
        while(n--)
        { 
            scanf("%lld", &tmp);
            if(tmp - l < array_len)
            {
                m[tmp - l] = true;
            }
        }

        // do ans
        bool has_ans = 0;
        ll shift = 0;
        for(int i = 0; i < array_len; i++)
        {
            if(m[i] == false)
            {
                has_ans = 1;
                shift = i;
                break;
            }
        }

        if(has_ans)
        {
            printf("%lld\n", shift + l);
        }
        else
        {
            printf("^v^\n");
        }
        free(m);
    }

    return 0;
}
```

### [Time Limit Exceeded(Optimize the given code)](https://oj.nctu.me/problems/823/)

* Statement: This problem **IS NOT Longest Increasing Subsequence**, it uses **Greedy algorithm** to find the local optimal solution rather then **DP** for the global optimal solution

```
Example:
5 9 6 7 10 
With DP (nlgn) binary search algorithm --> [here](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)
5
5 9
5 6
5 6 7
5 6 7 10

With Greedy
5 9 10 
9 10
6 7 10
7 10
```

* Thought: Traverse [n - 1, 0] where n is len of the given sequence, maintain a stack that is increasing from top(newest) to bottom(oldest). Once the higher elements encounterd, pop the stack until the top of stack is higher, and update the size of current stack as the final answer(see code).
    * Why it works? 
        * From [n - 1, 0] maintains the increasing stack makes result correct.
        * Use the number as large as possible to implementation the greedy algorithm (See the following example)
* Question: Why cant we traverse [0, n - 1] (See the following example)

* Analysis:
    * Time complexity $O(N), N = len(seq)$, each insert takes $O(1)$ and pop takes $O(1)$ since each one element enters the stack and leaves the stack at most once
    * Space complexity $O(N), N = len(seq)$
```
Example
                <---------
                5  9  6  7  10
stack down      10 10 10 10 10
                9  9  7  7
                5     6   
top

final answer -> max size 3 (not 5 6 7 10)

From
                --------->
                5  9  6  7  10
stack down      5  9  9  9  10
                      6  7
top

final answer -> max size 2 (wrong)
```

```cpp
#include<bits/stdc++.h>
#define MAX_N 1000005
using namespace std;
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        vector<int> a(n, 0);
        stack<int> dp;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &a[i]);
        }

        dp.push(INT_MAX); // padding for no size checking
        
        int res = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            while(dp.top() <= a[i])
            {
                dp.pop();
            }
            dp.push(a[i]);
            res = max(res, (int)dp.size() - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}
```

## 20190322, HW3
### [Binary String](https://oj.nctu.me/problems/825/)

* Thought: By using the dedicated data structure "trie" to accomplish string prefix matching in O(N) time, for more idea, see the comments.
* Analysis:
    * Time complexity: $O(N)$
    * Space complexity: $O(N)$
    
```cpp
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int f;
    bool is_end;
    node* child[2];

};

node* create_node()
{
    node* new_node = new node;
    new_node -> f = 0; // init the freq to 0 up to the prefix node
    new_node -> is_end = 0; // is the end of string
    new_node -> child[0] = new_node -> child[1] = NULL; // next left and right

    return new_node;
}

void insert(node* cur_node, const string& s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(cur_node -> child[s[i] - '0'] == NULL)
        {
            cur_node -> child[s[i] - '0'] = create_node();
        } // create the node if that path of prefix matching does not exist
        cur_node = cur_node -> child[s[i] - '0']; // move to the next node
        cur_node -> f++; // increase the freq of path
    }

    cur_node -> is_end = 1; // finish inserting
}

void search(node* cur_node, const string& s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(cur_node -> child[s[i] - '0'] == NULL) // no such string
        {
            cout << 1 << '\n';
            return;
        }
        cur_node = cur_node -> child[s[i] - '0'];
    }
    cout << cur_node -> f << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, Q;
    string s;
    cin >> T;
    
    node* root = new node; // trie root
    root -> f = 0;
    root -> child[0] = root -> child[1] = NULL;

    while(T--)
    {
        cin >> s;
        insert(root, s);
    }
    
    cin >> Q;
    while(Q--)
    {
        cin >> s;
        search(root, s);
    }
    
    return 0;
}
```

### [Chocolate! Chocolate!!](https://oj.nctu.me/problems/825/)
* Thought: DFS the map, and mark the eaten grid so the infinite recusrion will not happen.
* Analysis:
    * Time complexity: $O(m * n)$ eventully up to m * n grid of chocolate will be eaten
    * Space complexity: $O(m * n)$ by using the map to trace grids that have been eaten
```cpp
#include <bits/stdc++.h>
#define MAX_N 1001
#define MAX_M 1001
using namespace std;

int res; 
bool mymap[MAX_N][MAX_M];

void solve(int r, int c, const int& n, const int& m)
{
    if(r > n || c > m || r < 1 || c < 1 || mymap[r][c])
    {
        return;
    }
    mymap[r][c] = true;
    res++;
    // cout << "visit: " << r << " , " << c << " res now " << res << '\n';
    solve(r - 1, c - 1, n, m);
    solve(r - 1, c, n, m);
    solve(r, c - 1, n, m);
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m ,q, total, r, c;
    cin >> n >> m >> q;
    total = n * m;

    while(q--)
    {
        cin >> r >> c;
        res = 0;
        solve(r, c, n, m);
        if(res)
        {
            cout << res << endl;
        }
        else
        {
            cout << "QAQ" << '\n';
        }
        total -= res;
    }
    cout << total << '\n';

    return 0;
}
```
## 20190329, HW4
### [Novelist](https://oj.nctu.me/problems/829/)
* Thought: By using `getline + stringstream` to remove blank b/w each string or directly use `cin >>` to avoid while space. After that, just concatenate the alphabetical letters togethers and store them into the map to count occurances;
* Analysis:
    * Time complexity: $O(N)$ by iterating from the begin of input to the end
    * Space complexity: $O(N)$ where N is the total length of input, and we use the unordered_map to store different string in it.
```cpp
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
vector<string> order;
void collect(string& str)
{
    string::iterator it = str.begin();
    string pu;
    while(it != str.end())
    {
        if(isalpha(*it))
        {
            pu += tolower(*it);
        }
        ++it;
    }
    if(m.count(pu) == 0 && isalpha(pu[0]))
    {
        order.push_back(pu);
    }
    m[pu]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(cin >> str)
    {
        collect(str);
    }

    for(auto i : order)
    {
        cout << i << ' ' << m[i] << '\n';
    }

    return 0;
}
```

### [Base Station](https://oj.nctu.me/problems/830/)
* Thought: 
    * Step 1. There are two kinds of the situation, one is by using the 2 of 3 points, the middle point of 2 forms the centre of circle, the other one is using the **Circumscribed circle** of 3 points iff they does not lie on the same line. 
    * Step 2. Comparing the radius, print the least one and corresponding center.

* Analysis:
    * Time complexity: $O(1)$ but lies on the floating point computation
    * Space complexity: $O(1)$.
```cpp
#include <bits/stdc++.h>
#include <cfloat>
#define pb push_back
#define mp make_pair
#define spdd set<pair<double, double>>
#define vpdd vector<pair<double, double>>
#define pdd pair<double, double>
using namespace std;

struct p_r
{
    pdd c;
    double r;
};

double len(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool same_line(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return ((y2 - y1) * (x3 - x2)) == ((y3 - y2) * (x2 - x1));
}

p_r triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{ 
    double a1=2.0f*(x2-x1);
    double b1=2.0f*(y2-y1);
    double c1=x2*x2+y2*y2-x1*x1-y1*y1;

    double a2=2.0f*(x3-x2);
    double b2=2.0f*(y3-y2);
    double c2=x3*x3+y3*y3-x2*x2-y2*y2;

    double x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
    double y=(a1*c2-a2*c1)/(a1*b2-a2*b1);

    p_r tmp;
    tmp.r = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    tmp.c = make_pair(x, y);
    return tmp;
}

p_r two_one(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
{
    double r = len(x1, y1, x2, y2) / 2.0f;
    double x = (x1 + x2) / 2.0f;
    double y = (y1 + y2) / 2.0f;
    
    p_r tmp;
    if(len(x, y, x3, y3) <= r) //can be covered
    {
        
        tmp.r = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        tmp.c = make_pair(x, y);
        return tmp;
    }
    else
    {
        p_r tmp;
        tmp.r = FLT_MAX;
        tmp.c = make_pair(x, y);
        return tmp;
    }
}

bool cmp(p_r p1, p_r p2)
{
    return p1.r < p2.r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double x1, x2, x3, y1, y2, y3;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
    {
        vector<p_r> vpr;
        vpr.resize(3);
        vpr[0] = two_one(x1, y1, x2, y2, x3, y3);
        vpr[1] = two_one(x1, y1, x3, y3, x2, y2);
        vpr[2] = two_one(x2, y2, x3, y3, x1, y1);

        
        if(!same_line(x1, y1, x2, y2, x3, y3))
        {
            vpr.pb(triangle(x1, y1, x2, y2, x3, y3));
        }
        sort(vpr.begin(), vpr.end(), cmp);
        cout << fixed << setprecision(6) << vpr[0].c.first << ' ' << vpr[0].c.second << ' ' << vpr[0].r<< '\n';
    } 
    return 0;
}
`

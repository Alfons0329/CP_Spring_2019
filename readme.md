# $Competitive Programming$
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
```
 ## 20190405, HW5
 ### [Extra Chocolate! ](https://oj.nctu.me/problems/843/) (Only AC 17/53 but cross validate with AC friend's tricky testcase, they are identical QQ)

* Thought:
    * Step 1. Define a map to store the col -> row correspondence **if successfully eat a chocolate** 
    * Step 2. If such row, col (prepare-to-eat) <= one of the bite's position eaten before, then this location must been eaten before, hence Hank cannot eat this time, print QAQ
    * Step 3. Sum each vertical xxx up (eaten before) from left to right
to form the delta value (sum all the vertical bar of x till the position of ready-to-eat's column) this process bears a resemblance to that of **Reimann Integral**
    * For more detail, see the following demo and comment part of code since it is bit hard to explain thoroughly of the algorithm with plain words
```
xoooov ---> position want to eat
xxoooo
xxxooo
xxxooo
xxxxoo
xxxxxx

from the aforementioned step, the delta will sum up to 
and total chocolate to eat this time will be row_pos of v * col_pos of v - delta(sum of x) being 36 - (6 + 5 + 4 + 2 + 1 + 1)
```
    
* Analysis:
    * Time complexity: $O(m)$, with m being the # of columns of chocolate since each time we move horizontally to manipulate the data.
    * Space complexity: $O(m)$, and the reason is similar above, we store the data of correspondence of mapping eat_col -> eat_row

```cpp
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n, m ,q, total, r, c;
    map<ull, ull> col_row; // Step 1.
    cin >> n >> m >> q;
    total = n * m;

    col_row[0] = 0;

    while(q--)
    {
        cin >> r >> c;
        r = min(r, n); // prevent out-of-bound like error
        c = min(c, m); // prevent out-of-bound like error
        ull res = r * c, delta = 0; 
        bool can_eat = 1;
        // printf("r %llu c %llu\n", r, c);

        map<ull, ull>::iterator it = col_row.begin();

        for(; it != col_row.end(); it++) // Step 2.
        {
            if(r <= it -> second && c <= it ->first)
            {
                can_eat = 0;
                res = 0;
                break;
            }
        }

        if(can_eat)
        {
            // integrate from left, where min... - last_col down there represents the width of rectangle and min(ull it ->....r) represents the height
            it = col_row.begin();
            ull last_col = 0; // integral from left
            for(; it != col_row.end(); it++) // step 3
            {
                delta += (min(c, (ull)it -> first) - last_col) * min((ull)it -> second, r); // the height limit is the row number of ready-to-eat part and the column part should iterate up to the col number of ready-to-eat, to form an integral
                if(it -> first > c)
                {
                    break;
                }
                last_col = it -> first; // change to the column data of this rectangel and it++ to find the next border
            }

            // update map if current eating part is bigger than all the position that haven been eaten before, then use the right-up most to represent the eaten area will be enough
            it = col_row.begin();
            for(; it != col_row.end(); it++)
            {
                if(r >= it -> second && c >= it -> first)
                {
                    col_row.erase(it -> first);
                }
            }
            col_row[c] = r;
            
            res -= delta;
        }

        if(res > 0)
        {
            cout << min(m * n, res) << '\n';
            total -= min(m * n, res);
        }
        else
        {
            cout << "QAQ" << '\n';
        }

    }
    cout << total;
    return 0;
}
```

### [K next permutations](https://oj.nctu.me/problems/844/)
* Thought: 
    * Step 1. Take the previously printed permutation and find the rightmost character in it, which is smaller than its next character. Let us call this character as ‘r_most’.
    * Step 2. Now find the ceiling of the ‘r_most’. Ceiling is the smallest character on right of ‘r_most’, which is greater than ‘r_most’. Let us call the ceil character as ‘cei’.
    * Step 3. Swap the two characters found in above 2 steps.
    * Step 4. Sort the substring (in non-decreasing order) after the original index of ‘r_most’.
    * Note: Initialize the r_most position to -1, and if nothing can satisfy the rule in step 1 and step 2, `ex: [5,4,3,2,1], [2,2,2,2,2], [7], since there are no position to satisfy v[i] < v[i + 1]`, r_most will remain -1 and output should be either `hello world` if next permutation has not been generated before or break from the while loop directly.
* Analysis:
    * Time complexity: $O(2 ^ n * n !)$, with n being the length of given integer vector. If we generated all the permutations without any interruption, time complexity will be this 
    * Space complexity: $O(n)$, just store the input vector (array) 
```cpp
/*The variables' name are same with that in as above steps*/
#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

pii find_need(vi& v)
{
    int r_most = -1, cei = -1, n = v.size();
    for(int i = 0; i < n - 1; i++)
    {
        if(v[i] < v[i + 1])
        {
            r_most = i;
        }
    }

    if(r_most >= 0)
    {
        int cei_value = INT_MAX;
        for(int i = r_most + 1; i < n; i++)
        {
            if(v[i] < cei_value && v[i] > v[r_most])
            {
                cei_value = v[i];
                cei = i;
            }
        }
    }

    return make_pair(r_most, cei);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, tmp;
    vi v;
    cin >> n >> k;
    while(n--)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int has_next = 0;
    while(k--) 
    {
        pii p = find_need(v);
        int r_most = p.first, cei = p.second;

        if(r_most < 0) 
        {
            break;
        }
        has_next = 1;
        swap(v[r_most], v[cei]);
        sort(v.begin() + r_most + 1, v.end());
        
        for(auto i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    if(has_next == 0)
    {
        cout << "hello world!" << '\n';
    }

    return 0;
}
```

## 20190412, HW6
### [CPU Scheduling](https://oj.nctu.me/problems/847/)

* Thought : (See the comment part in code for more information) 
    * Step 1. From the description of problem, tasks with the same group should be **inserted at the front** of its group, and remove at first, hence the "stack" STL satisfies this problem.
    * Step 2. Aside from the insertion, we should also maintain the order of all groups, since tasks with the same group are clustered togerher like segments (Visualization)--> |G1|G3|G5|G2| and so on.
    * Step 3. Here we have 2 situations for insertion.
        * Step 3-1. First, if this task is the newly inserted one, namely such group has not been inserted before` (cpu[v[op2]].size() == 0)` --> in-group order stack has no size, then this task will be the fist of its group to be inserted in.
        * Step 3-2. Otherwise, just push to its group correspondingly.
    * Stp 4. Here we have 2 situations for deletion.
        * Step 4-1. To pop a work from CPU, we should check which group is in the "frontmost" and get its gid.
        * Step 4-2. After the gid is secured, we may query the top element of the stack of such gid, due to the property of stack, LIFO will satisfying the requirement of this problem.
        * Step 4-3. If all of the tasks of such group have been popped out, pop "front" of the g_order deque (deque makes pop_front possible) and **erase such group from map to prevent MLE or RE**.
        * Step 4-4. If there is no more task in the CPU, just print 0 and let CPU take rest.

* Memory Limit Exceeded Notice: To maintain the order in group (order of tasks of the same gid) vector should replace stack since it does support pop_back and stack usually implemented with deque by default. Please feel free to check [this link](https://stackoverflow.com/questions/16252183/why-is-deque-using-so-much-more-ram-than-vector-in-c) for understanding.    
* Analysis:
    * Time complexity: $O(NlogN)$, where N is the # of total tasks since each tasks will be inserted and remove from the cpu queue certain times, but operations of insertion/erase to the map will cost up to $logN$ (map). Other operations such as pop_front/push_back the g_order from the front, and pop_back/push_back the in-group vector all costs $O(1)$ 
    * Space complexity: $O(N)$, where N is the # of total tasks.

```cpp
#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define MIN -100005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, tmp, g_size, cpu_size = 0;
    cin >> n >> q;
    g_size = n;

    vi v;
    v.pb(MIN);
    deque<int> g_order; // Step 2
    vb in_cpu(n + 1, 0);
    map<int, vector<int>> cpu; // gid -> process stk **MLE IF USE stack<int instead>** Step 1

    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }

    int op1, op2;
    while(q--)
    {
        cin >> op1; 
        if(op1 == 1)
        {
            cin >> op2;
            if(in_cpu[op2])
            {
                cout << "Ignore" << '\n';
            }
            else
            {
                if(cpu[v[op2]].size() == 0) // Step 3-1 havent such gruop in it
                {
                    g_order.pb(v[op2]);
                }
                cpu[v[op2]].push_back(op2); // Step 3-2 
                in_cpu[op2] = 1;
                cout << "Successful" << '\n';
            }
        }
        else
        {
            if(g_order.size()) // Step 4
            {
                int g_id = g_order.front();
				op2 = cpu[g_id].back(); // Step 4-1
				cout << op2 << '\n';
                in_cpu[op2] = 0;
                cpu[g_id].pop_back(); // Step 4-2

                if(cpu[g_id].size() == 0)
                {
                    if(g_order.size())
                    {
                        g_order.pop_front();
                    }
					cpu.erase(g_id); // Step 4-3
                }
            }
            else
            {
                cout << 0 << endl; // Step 4-4
            }
        }
    }

    return 0;
}
```

### [City Skyline](https://oj.nctu.me/problems/848/)
* Thought: 
    * Use **multiset** to maintain the height of current position while remain the order of highest on the top due to the property of multiset.
    * Step 1. Classify the wall of house into 2 type, in (left) and out(right), once the house is encountered, push_back to the multiset, while leave erase it.
    * Step 2. $h_{2}$ is the height of current position and $h$ being the last height, while the same is true for $i.x$ and $x$.
        * Step 2-1. Add the total area by $h_{2} * \Delta x, \Delta x = (i.x - x)$
        * Step 2-2. Add the total outline length by $|x-y| + \Delta x$ if current height is not zero (the ㄏ part) and add by $|x-y|$ (the | part at the end of each house cluster)
    * After all the house hav been iterated, add the rightmost wall to the total outline length.
* Visualization: Please toggle the comment part (printf) to understanding the height change and current area and outline length.
![](https://i.imgur.com/kR22YoQ.jpg)
![](https://i.imgur.com/x5iriNG.jpg)

* Analysis:
    * Time complexity: $O(N)$ where N is # of building since we iterate all the buildings left wall and right wall to "climb the outline" of this overlapped structure
    * Space complexity: $O(N)$
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct one_h
{
    ll x, h;
    bool in_type;
};

bool cmp(one_h a, one_h b)
{
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x, h, w; 
    cin >> n;
    vector<one_h> house;

    while(n--)
    {
        cin >> x >> h >> w;
        one_h tmp, tmp2;

        tmp.x = x;
        tmp.h = h;
        tmp.in_type = 1;

        tmp2.x = x + w;
        tmp2.h = h;
        tmp2.in_type = 0;
        
        house.push_back(tmp);
        house.push_back(tmp2);

    }
    
    sort(house.begin(), house.end(), cmp);
    ll h2 = 0, area = 0, len = 0;
    x = h = 0;
    multiset<ll> x_height;
    for(auto i : house)
    {
        if(i.x != x)
        {
            area += h2 * (i.x - x);
            len += abs(h2 - h) + (h2 > 0) * (i.x - x);
            // printf("ix %lld x %lld h2 %lld h %lld area %lld len %lld\n", i.x, x, h2, h, area , len);
            x = i.x;
            h = h2;
        }

        if(i.in_type == 1)
        {
            // printf("insert %lld at %lld\n", i.h, i.x);
            x_height.insert(i.h);
        }
        else
        {
            // printf("erase %lld at %lld\n", i.h, i.x);
            x_height.erase(x_height.find(i.h));
        }
        
        if(x_height.size())
        {
            h2 = *(x_height.rbegin());
        }
        else
        {
            h2 = 0;
        }
    }
    cout << len + abs(h2 - h) << ' ' << area;
    return 0;
}
```

## 20190419 HW7 + 8 (Till 15th HW that teacher required)
### [Dragon Raider](https://oj.nctu.me/problems/853/)
* Thought: Use the index as power of shiled and sword, and the value being objects in such power. Represent them in 2 arrays, hence the total combination of certain power $p$ will be the value in the corresponding position $arr[p]$
* Analysis:
    * Time complexity: $O(N^2)$
    * Space complexity: $O(N)$
```cpp
#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX_N 100005
using namespace std;

ull a[MAX_N], b[MAX_N], c[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ull N, n, M, m, Q, tmp;
    cin >> N >> M >> Q;
    a[0] = b[0] = 1;
    m = n = 0;

    while(N--)
    {
        cin >> tmp;
        a[tmp]++;
        n = max(n, tmp);
    }
    while(M--)
    {
        cin >> tmp;
        b[tmp]++;
        m = max(m, tmp);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    while(Q--)
    {
        cin >> tmp;
        if(tmp == 0 ||tmp > 1e5 + 5)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << (ull)(c[tmp]) << '\n';
        }
    }
    return 0;
}
```
* おまけ: FFT
* [FFT reference](https://medium.com/@aiswaryamathur/understanding-fast-fourier-transform-from-scratch-to-solve-polynomial-multiplication-8018d511162f)
* Analysis:
    * Time complexity: $O(NlogN)$
    * Space complexity: $O(N)$
```cpp
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

double PI = acos(-1);
const int MAX_N = 4e5 + 10;
int r[MAX_N];
struct Complex
{
    double r, i;
    Complex(){}
    Complex(double _r, double _i){ r = _r, i = _i; }
    Complex operator +(const Complex &y) { return Complex(r + y.r, i + y.i); }
    Complex operator -(const Complex &y) { return Complex(r - y.r, i - y.i); }
    Complex operator *(const Complex &y) { return Complex(r * y.r - i * y.i, r * y.i + i * y.r); }
    Complex operator *=(const Complex &y) { double t = r; r = r * y.r - i * y.i, i = t * y.i + i * y.r; }
} a[MAX_N], b[MAX_N], c[MAX_N];

void fft(Complex *a, int len/* Deg of polynomial */, int op /* Inverse or normal FFT */) 
{
    Complex tt;
    for (ull i = 0; i < len; i++)
    {
        if (i < r[i])
        {
            tt = a[i], a[i] = a[r[i]], a[r[i]] = tt;
        }
    }

    for (ull i = 1; i < len; i <<= 1)
    {
        Complex wn(cos(PI / i), sin(PI * op / i));
        for (ull k = 0, t = (i << 1); k < len; k += t)
        {
            Complex w(1, 0);
            for (ull j = 0; j < i; j++, w *= wn)
            {
                Complex t = w * a[k + j + i];
                Complex u = a[k + j];
                a[k + j] = u + t;
                a[k + j + i] = u - t;
            }
        }
    }

    if (op == -1)
    {
        for (ull i = 0; i < len; i++)
        {
            a[i].r /= len;
            a[i].i /= len;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ull N, n, M, m, Q, tmp;
    cin >> N >> M >> Q;
    a[0].r = b[0].r = 1;
    m = n = 0;

    while(N--)
    {
        cin >> tmp;
        a[tmp].r++;
        n = max(n, tmp);
    }
    while(M--)
    {
        cin >> tmp;
        b[tmp].r++;
        m = max(m, tmp);
    }

    m += n;
    ull L, i, x;
    for(n = 1, L = 0; n <= m; n <<= 1)
    {
        L++;
    }
    for (i = 0, x = L - 1; i < n; i++)
    {
        r[i] = (r[i >> 1] >>1) | ((i & 1) << x);
    } 

    fft(a, n, 1);
    fft(b, n, 1);
    for (ull i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
    }
    fft (c, n, -1); // inverse fft
    
    while(Q--)
    {
        cin >> tmp;
        if(tmp == 0 ||tmp > 1e5 + 5)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << (ull)(c[tmp].r + 0.5) << '\n';
        }
    }
    return 0;
}
```
### [Mod inverse (Prime version)](https://oj.nctu.me/problems/854/)
* Thought: $Fermat's little\ Theorem$
* Analysis:
    * Time complexity: $O(a^p)??$ **Not sure** with a being the base and p being power.
    * Space complexity: $O(1)$
```cpp
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull pow_mod(ull x, ull y, ull p)
{
    ull res = 1;
    x %= p;

    while(y > 0)
    {
        if(y & 1) // last
        {
            res = (res * x) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, a, p;
    cin >> n;
    while(n--)
    {
        cin >> a >> p;
        cout << pow_mod(a, p - 2, p) << '\n';
    }
    return 0;
}
```
### [XOR](https://oj.nctu.me/problems/857/)
* Thought: Just like interval sum, now we query the interval XOR or the array. 
    * Step 1. Each time we XOR with the latest input value and store the corrresponding interval XOR value(from 1 to i, 1-base in this problem) in array $a[MAX\_N]$
    * Step 2. For the query value, the interval XOR value between $l,\ r$ will be $a[l\ -\ 1]\ XOR\ a[r]$
* Analysis:
    * Time complexity: $O(N)$
    * Space complexity: $O(N)$
```cpp
#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q, tmp;
    int a[MAX_N] = {0};
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if(i != 1)
        {
            a[i] = a[i - 1] ^ tmp;
        }
        else
        {
            a[i] = tmp;
        }
    }
    
    int l, r;
    while(q--)
    {
        cin >> l >> r;
        l = a[l - 1];
        r = a[r];
        l ^= r;
        cout << l << '\n';
    }
    
    return 0;
}
`

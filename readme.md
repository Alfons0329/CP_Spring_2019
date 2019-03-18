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
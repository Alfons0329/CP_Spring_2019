#include <bits/stdc++.h>
using namespace std;

int res;

void dfs(vector<vector <bool> >& adj, vector<bool>& visited, int cur_node, int vis_nodes, int target)
{
    visited[cur_node] = true;
    vis_nodes++;
    
    if(adj[cur_node][1] && vis_nodes == target) // return to start, forms a cycle
    {
        res++;
    }

    for(int i = 1; i <= target ; i++)
    {
        if(adj[cur_node][i] && visited[i] == false) // adjacent matrix
        {
            dfs(adj, visited, i, vis_nodes, target);
        }
    }

    // back tracking
    visited[cur_node] = false;
    vis_nodes--;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    int case_cnt = 0;
    while(T--)
    {
        int n, k;
        cin >> n >> k;

        res = 0;

        // build the adjacent list
        vector<vector <bool> > adj(n + 1, vector<bool>(n + 1, false));
        vector< pair<int, int>> forbid;
        int a, b;
        for(int i = 0; i < k; i++)
        {
            cin >> a >> b;
            forbid.push_back(make_pair(a, b));
        }
        int ok_edge = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j)
                {
                    ok_edge = 1;
                    for(int _k = 0; _k < k; _k++)
                    {
                        a = forbid[_k].first;
                        b = forbid[_k].second;
                        if((a == i && b == j) || (a == j && b == i))
                        {
                            ok_edge = 0;
                            break;
                        }
                    }
                    if(ok_edge)
                    {
                        adj[i][j] = true;
                        adj[j][i] = true;
                    }
                }
            }
        }

        // do dfs, no need for(0..n) and dfs since 1 2 3 4 5, 2 3 4 5 1 is the same cycle
        vector<bool> visited(n + 1, false);
        dfs(adj, visited, 1, 0, n);
        cout << "Case #" << ++case_cnt << ": " << (res / 2) % 9901 << '\n';
    }

    return 0;
}

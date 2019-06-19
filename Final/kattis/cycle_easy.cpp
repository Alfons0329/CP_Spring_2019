#include <bits/stdc++.h>
using namespace std;

int res;

void dfs(vector<vector <int> >& adj, vector<bool>& visited, int cur_node, int vis_nodes, int start_node, int target)
{
    visited[cur_node] = true;
    vis_nodes++;

    cout << "cur_node " << cur_node << " vis_nodes " << vis_nodes << '\n';
    int n_edges = adj[cur_node].size();
    if(vis_nodes == target && cur_node == start_node);
    {
        res++;
        return;
    }

    for(int i = 0; i < n_edges; i++)
    {
        if(visited[adj[cur_node][i]] == false)
        {
            cout << "start from " << adj[cur_node][i] << '\n';
            dfs(adj, visited, adj[cur_node][i], vis_nodes, adj[cur_node][i], target);
        }
    }

    // clear the node
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
        vector<vector <int> > adj(n + 1, vector<int>());
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
                            // cout << "fail with " << i << " and " << j << " a " << a << " b " << b << '\n';
                            ok_edge = 0;
                            break;
                        }
                    }
                    if(ok_edge)
                    {
                        // cout << " i " << i << "  pb " << j << '\n';
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        // do dfs
        vector<bool> visited(n, false);
        for(int i = 1; i <= n; i++)
        {
            cout << "start from " << i << '\n';
            dfs(adj, visited, i, 0, i, n);
        }
        /*
        cout << "adjlist \n";
        for(int i = 1; i <= n; i++)
        {
            cout << i << " --> ";
            for(int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        cout << "Case #" << ++case_cnt << ": " << res % 9901 << '\n';
    }

    return 0;
}

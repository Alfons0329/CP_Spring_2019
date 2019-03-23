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
    new_node -> f = 0;
    new_node -> is_end = 0;
    new_node -> child[0] = new_node -> child[1] = NULL;

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
        }
        cur_node = cur_node -> child[s[i] - '0'];
        cur_node -> f++;
    }

    cur_node -> is_end = 1; // finish inserting
}

void search(node* cur_node, const string& s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(cur_node -> child[s[i] - '0'] == NULL) // no such string, new one
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
    cin >> T;

    unordered_map<string, int> m;
    string s, tmp;
    
    int n = 0;
    node* root = new node; // trie root
    root -> f = 0;
    root -> child[0] = root -> child[1] = NULL;

    while(T--)
    {
        cin >> s;
        n = s.size();
        tmp = "";
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

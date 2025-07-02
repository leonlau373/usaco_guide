/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int>& v)
{
    for (int i = 0; i < v.size(); i = i + 1)
    {
        cout << v[i] << ' ';
    }
}

void inputvec(vector<int>& v, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

int main()
{
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<int> tree_row(n);
        for(int i = 0; i < n ; i++)
        {
            if(s[i] == '*')
            {
                tree_row[i] = 1;
            }
            else
            {
                tree_row[i] = 0;
            }
        }

        tree.push_back(tree_row);
    }

    vector<vector<int>> prefix_tree(n + 1);
    vector<int> prefix_row(n+1,0);

    for(int i = 0 ; i <= n ; i++)
    {
        prefix_tree[i] = prefix_row;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            prefix_tree[i][j] = tree[i - 1][j - 1] + prefix_tree[i][j - 1] + (prefix_tree[i - 1][j] - prefix_tree[i - 1][j - 1]);
        }
    }

    for(int i = 0 ; i < q ; i++)
    {
        int y1;
        int x1;
        int y2;
        int x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << prefix_tree[y2][x2] - prefix_tree[y2][x1 - 1] - prefix_tree[y1 - 1][x2] + prefix_tree[y1 - 1][x1 - 1];
        cout << endl;
    }

    return 0;
}

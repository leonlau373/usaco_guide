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
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> adj[N];

    int m;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for(int i = 0; i < N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> color(N);
    color[0] = 1;

    for(int i = 1; i < N; i++)
    {
        int coloring = 1;
        set<int> s = {};
        for(int j = 0; j < i && j < adj[i].size() ; j++)
        {
            s.insert( color[ adj[i][j] ] );
        }

        //Checking whether coloring is in the set or not.
        while( s.find(coloring) != s.end() )
        {
            coloring++;
        }

        color[i] = coloring;
    }

    for(int i = 0; i < N; i++)
    {
        cout << color[i];
    }



    return 0;
}

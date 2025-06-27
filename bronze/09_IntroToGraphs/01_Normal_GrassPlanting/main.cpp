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
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> adj[N];

    for(int i = 0; i < N - 1; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int color = 1;

    for(int i = 0; i < N; i++)
    {
        int c = adj[i].size() + 1;
        color = max(color, c);
    }

    cout << color;

    return 0;
}

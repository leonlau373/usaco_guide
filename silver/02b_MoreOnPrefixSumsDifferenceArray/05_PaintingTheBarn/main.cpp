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

using ll = long long;

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> row(1002, 0);
    vector<vector<int>> barn(1001, row);

    int x1;
    int y1;
    int x2;
    int y2;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1 ; j < y2 ; j = j + 1)
        {
            barn[j][x1]++;
            barn[j][x2]--;
        }
    }

    for(int i = 1 ; i <= 1000 ; i++)
    {
        for(int j = 1; j <= 1001; j++)
        {
            barn[i][j] = barn[i][j] + barn[i][j-1];
        }
    }

    int ans = 0;

    for(int i = 1 ; i <= 1000 ; i++)
    {
        for(int j = 1 ; j <= 1001 ; j++)
        {
            if(barn[i][j] == k)
            {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}

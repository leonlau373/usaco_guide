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
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int a1, b1, a2, b2;
    int c1, d1, c2, d2;
    cin >> a1 >> b1 >> a2 >> b2 >> c1 >> d1 >> c2 >> d2;

    int min_x = min({a1, a2, c1, c2});
    int max_x = max({a1, a2, c1, c2});

    int min_y = min({b1, b2, d1, d2});
    int max_y = max({b1, b2, d1, d2});

    int sides = max(max_x - min_x, max_y - min_y);

    cout << pow(sides, 2);

    return 0;
}

/*
Name: Leon Lau
User name: nya10
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
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;

    int intersection;

    intersection = max(min(x2, x4) - max(x1, x3) , 0);

    int total = x4 - x3 + x2 - x1 - intersection;

    cout << total;

    return 0;
}

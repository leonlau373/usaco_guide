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
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);

    int n, x;
    cin >> n >> x;

    vector<vector<int>> num;

    for(int i = 1 ; i <= n ; i++)
    {
        int a;
        cin >> a;
        num.push_back({a, i});
    }

    sort(num.begin(),num.end());

    int left = 0;
    int right = 2;

    bool possible = false;

    if(n <= 2)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        while(right < n)
        {

        }
    }

    return 0;
}

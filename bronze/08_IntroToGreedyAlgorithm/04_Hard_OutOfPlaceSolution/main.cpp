/*
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
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    int cow[n];
    int sorted[n];

    for(int i = 0; i < n; i++)
    {
        cin >> cow[i];
        sorted[i] = cow[i];
    }

    sort(sorted, sorted + n);

    int differences = 0;

    for(int i = 0; i < n; i++)
    {
        if(cow[i] != sorted[i])
        {
            differences++;
        }
    }

    cout << differences - 1;

    return 0;
}

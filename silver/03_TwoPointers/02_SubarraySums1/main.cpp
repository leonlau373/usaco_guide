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

    int possible = 0;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;

    int sum = a[0];
    while(left < n && right < n)
    {
        if(sum < x)
        {
            right = right + 1;
            if(right != n)
            {
                sum = sum + a[right];
            }
        }

        else if(sum >= x)
        {
            if(sum == x)
            {
                possible++;

            }
            sum = sum - a[left];
            left = left + 1;
        }

    }

    cout << possible;

    return 0;
}

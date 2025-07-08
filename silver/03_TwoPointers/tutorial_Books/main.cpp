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

    ll n, t;
    cin >> n >> t;

    vector<ll> book(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> book[i];
    }

    ll left = 0;
    ll right = 0;

    ll max_length = 0;

    ll sum = book[0];

    while(right < n)
    {
        if(sum < t)
        {
            max_length = max(max_length, right - left + 1);
            right = right + 1;
            if(right != n)
            {
                sum = sum + book[right];
            }
        }
        else if(sum >= t)
        {
            if(sum == t)
            {
                max_length = max(max_length, right - left + 1);
            }
            if(left < right)
            {
                sum = sum - book[left];
                left = left + 1;

            }
            else
            {
                left = left + 1;
                right = right + 1;
                sum = book[right];
            }
        }

    }

    cout << max_length;


    return 0;
}

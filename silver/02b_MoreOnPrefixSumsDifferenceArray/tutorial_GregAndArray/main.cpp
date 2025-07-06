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
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1);
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }


    vector<ll> op_diff(n + 2, 0);
    vector<vector<ll>> prefix_diff(m + 1, op_diff);
    prefix_diff[0] = op_diff;

    ll l;
    ll r;
    ll d;
    for(ll i = 1 ; i <= m ; i++)
    {
        cin >> l >> r >> d;

        op_diff[l] += d;
        op_diff[r+1] -= d;

        for(ll j = 0 ; j <= n ; j++ )
        {
            prefix_diff[i][j] += op_diff[j];
        }
    }

    int add = 0;
    ll left;
    ll right;

    for(ll i = 0 ; i < k; i++)
    {
        cin >> left >> right;

        add = 0;

        for(int j = 0 ; j <= n ; j++)
        {
            add = add + prefix_diff[right][j] - prefix_diff[left-1][j];
            a[j] = a[j] + add;
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}

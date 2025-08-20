/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<ll>> cows;

    ll x,y;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y;
        cows.push_back({y, x});
    }

    sort(cows.begin(),cows.end());

    ll sum = cows[0][0] + cows[n - 1][0];

    ll left = 0;
    ll right = n - 1;

    while(left < right)
    {
        sum = max(cows[left][0] + cows[right][0], sum);
        if(cows[left][1] < cows[right][1])
        {
            cows[right][1] = cows[right][1] - cows[left][1];
            left++;
        }
        else if(cows[left][1] > cows[right][1])
        {
            cows[left][1] = cows[left][1] - cows[right][1];
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }

    cout << sum;

    return 0;
}

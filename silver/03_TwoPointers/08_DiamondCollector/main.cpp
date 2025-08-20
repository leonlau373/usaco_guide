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
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> diamonds;

    ll diamond;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> diamond;
        diamonds.push_back({diamond,0});
    }

    sort(diamonds.begin(), diamonds.end());

    ll maximum = 0;

    /*
    Idea:

    Do this algorithm twice:
        - Scan from left to right
        - Find the maximum diamonds we can put in a case
    */

    ll j = 0;
    ll max_i = 0;
    ll max_j = 0;
    for(int i = 0 ; i < n ; i++)
    {
        j = i;
        while(j < n && diamonds[j][0] <= diamonds[i][0] + k )
        {
            j++;
        }

        maximum = max(maximum , j - i);
        if(maximum == j - i)
        {
            max_i = i;
            max_j = j;
        }
    }

    for(int i = max_i; i < max_j ; i++)
    {
        diamonds[i][1] = 1;
    }

    ll total = maximum;

    maximum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        j = i;
        while(j < n && diamonds[i][0] + k >= diamonds[j][0] &&
              (diamonds[i][1] == 0 && diamonds[j][1] == 0))
        {
            j++;
        }
        maximum = max(maximum, j - i);

    }

    total = total + maximum;

    cout << total;


    return 0;
}

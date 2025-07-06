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

    ll n, q;
    cin >> n >> q;

    vector<ll> num(n, 0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> num[i];
    }

    sort(num.rbegin(), num.rend());

    vector<ll> freq(n+2,0);
    ll left;
    ll right;
    for(int i = 0 ; i < q; i++)
    {
        cin >> left >> right;
        freq[left]++;
        freq[right+1]--;
    }

    for(int i = 1; i <= n; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }

    sort(freq.rbegin(), freq.rend());

    ll sum = 0;
    for(int i = 0; i < num.size() ; i++)
    {
        sum = sum + num[i]*freq[i];
    }

    cout << sum;


    return 0;
}


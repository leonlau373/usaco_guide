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
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    long long n, target;
    cin >> n >> target;

    vector<long long> a(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    long long prefix_sum = 0;
    long long ans = 0;
    map<long long, int> sums;
    sums[0] = 1;

    for(long long x : a)
    {
        prefix_sum = prefix_sum + x;

        ans = ans + sums[prefix_sum - target];
        sums[prefix_sum]++;
    }

    cout << ans << endl;

    return 0;
}

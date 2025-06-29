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

    int n;
    cin >> n ;

    vector<int> a(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    map<int, long long int> sums;
    sums[0] = 1;
    int prefix = 0;

    long long int ans = 0;

    for(int x : a)
    {
        prefix = (prefix + x) % n;
        if(prefix < 0)
        {
            prefix = prefix + n;
        }
        sums[prefix]++;
    }

    cout << endl;

    for(int i = 0 ; i < n ; i++)
    {
        ans = ans + sums[i]*(sums[i] - 1)/2;
    }


    cout << ans;

    return 0;
}

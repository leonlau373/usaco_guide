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
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    vector<int> gcd_left(n);
    gcd_left[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        gcd_left[i] = gcd(gcd_left[i - 1], a[i]);
    }

    vector<int> gcd_right(n);
    gcd_right[n - 1] = a[n-1];
    for(int i = n - 2; i >= 0; i--)
    {
        gcd_right[i] = gcd(gcd_right[i + 1], a[i]);
    }

    int answer = max(gcd_right[1], gcd_left[n-2]);

    for(int i = 1; i < n - 1; i++)
    {
        int ans = gcd(gcd_left[i - 1], gcd_right[i + 1]);

        answer = max(ans, answer);
    }

    cout << answer;




    return 0;
}

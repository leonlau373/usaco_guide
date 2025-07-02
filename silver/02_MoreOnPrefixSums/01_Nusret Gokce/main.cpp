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

    long long n, diff;
    cin >> n >> diff;
    vector<long long> s(n);

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for(int i = 1 ; i < n ; i++)
    {
        if(s[i] < s[i - 1] - diff)
        {
            s[i] = s[i - 1] - diff;
        }
    }

    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(s[i] < s[i + 1] - diff)
        {
            s[i] = s[i + 1] - diff;
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << s[i] << ' ';
    }

    cout << endl;

    return 0;
}

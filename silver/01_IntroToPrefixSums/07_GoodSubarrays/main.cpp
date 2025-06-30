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

    int t;
    cin >> t;
    for(int test = 0; test < t; test++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> num(n);
        for(int i = 0; i < n; i++)
        {
            num[i] = s[i] - '0';
        }

        int prefix = 0;
        long long int answer = 0;

        map<long long int, long long int> prefix_minus_index;
        prefix_minus_index[0] = 1;

        for(int i = 0; i < n; i++)
        {
            prefix = prefix + num[i];

            int difference = prefix - (i + 1);

            prefix_minus_index[difference]++;
        }

        for(const auto &[a, f]: prefix_minus_index)
        {
            answer = answer + f * (f - 1) / 2;

        }

        cout << answer << endl;
    }

    return 0;
}

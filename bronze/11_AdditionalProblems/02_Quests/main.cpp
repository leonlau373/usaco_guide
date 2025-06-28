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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> a;
        vector<long long> b;

        for(int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            a.push_back(x);
        }

        for(int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            b.push_back(x);
        }

        long long max_score = 0;
        long long main_quest = 0;
        long long repeat_quest = 0;
        for(int j = 1; j <= min(n,k); j++)
        {
            long long score = 0;
            main_quest += a[j - 1];
            repeat_quest = max(repeat_quest, b[j - 1]);

            score = main_quest + (k - j)*repeat_quest;

            max_score = max(score, max_score);
        }

        cout << max_score << endl;
    }
    return 0;
}

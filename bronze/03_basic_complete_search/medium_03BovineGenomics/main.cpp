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
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n;
    int gen;
    cin >> n >> gen;

    vector<string> spotty;
    vector<string> plain;

    for(int i = 0; i < n; i = i + 1)
    {
        string cow;
        cin >> cow;
        spotty.push_back(cow);
    }

    for(int i = 0; i < n; i = i + 1)
    {
        string cow;
        cin >> cow;
        plain.push_back(cow);
    }

    int position = 0;
    for(int pos = 0; pos < gen; pos = pos + 1)
    {
        bool possible = true;
        for(int s = 0; s < n; s = s + 1)
        {
            for(int p = 0; p < n; p = p + 1)
            {
                if(s == p)
                {
                    continue;
                }
                else
                {
                    if(spotty[s][pos] == plain[p][pos])
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if(possible)
        {
            position = position + 1;
        }
    }

    cout << position;

    return 0;
}

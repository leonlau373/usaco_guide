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

int find_cow(vector<string> cows, string cow)
{
    int idx = -1;
    for(int i = 0; i < cows.size(); i++)
    {
        if(cow == cows[i])
        {
            idx = i;
        }
    }

    return idx;
}

int main()
{
    //Input Method
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    vector<vector<int>> milk;

    for(int i = 0; i < 7; i++)
    {
        milk.push_back({0, i});
    }

    int query;
    cin >> query;
    for(int i = 0; i < query; i++)
    {
        string s;
        int production;

        cin >> s >> production;

        milk[find_cow(cows,s)][0] += production;
    }

    sort(milk.begin(),milk.end());

    bool possible = false;
    int min_production = milk[0][0];
    int idx = 0;
    for(int i = 0; i < 7; i++)
    {
        if(min_production < milk[i][0])
        {
            min_production = milk[i][0];
            idx = i;
            break;
        }
    }

    if(idx + 1 < 7 && min_production < milk[idx + 1][0])
    {
        possible = true;
    }
    else if(idx == 6)
    {
        possible = true;
    }

    if(possible)
    {
        cout << cows[milk[idx][1]];
    }
    else
    {
        cout << "Tie";
    }



    return 0;
}


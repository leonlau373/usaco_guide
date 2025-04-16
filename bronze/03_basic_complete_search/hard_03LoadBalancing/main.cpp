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

int max_quadrant_count(vector<pair<int,int>> v, int x, int y)
{
    vector<int> quadrant{0,0,0,0};
    for(int i = 0; i < v.size() ; i = i + 1)
    {
        if(v[i].first > x && v[i].second > y)
        {
            quadrant[0] = quadrant[0] + 1;
        }
        else if(v[i].first < x && v[i].second > y)
        {
            quadrant[1] = quadrant[1] + 1;
        }
        else if(v[i].first < x && v[i].second < y)
        {
            quadrant[2] = quadrant[2] + 1;
        }
        else if(v[i].first > x && v[i].second < y)
        {
            quadrant[3] = quadrant[3] + 1;
        }
    }
    sort(quadrant.begin(),quadrant.end());
    return quadrant[3];
}

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    //input method
    vector<pair<int,int>> cows;
    int n;
    int b;

    cin >> n >> b;
    for(int i = 0 ; i < n ; i = i + 1)
    {
        int p;
        int q;
        cin >> p >> q;
        pair<int,int> cow;
        cow.first = p;
        cow.second = q;

        cows.push_back(cow);
    }

    //Solution

    /*
    Solution idea:
    Iterating each point 4 times, making a fence on:
    x + 1 , y + 1

    storing each x and y in cows

    Counting the number of cows in each quadrant

    Then seeing what is the minimum of the desired problem
    */
    vector<int> x_pos;
    vector<int> y_pos;
    for(int i = 0; i < n ; i = i + 1)
    {
        int x = cows[i].first;
        int y = cows[i].second;

        x_pos.push_back(x);
        y_pos.push_back(y);
    }

    int minimum = 10000;
    for(int i = 0; i < n ; i = i + 1)
    {
        int x = x_pos[i];
        for(int j = 0 ; j < n ; j = j + 1)
        {
            int y = y_pos[j];
            int quadrant_count = max_quadrant_count(cows, x+1, y+1);
            minimum = min(minimum, quadrant_count);
        }

    }

    cout << minimum;

    return 0;
}

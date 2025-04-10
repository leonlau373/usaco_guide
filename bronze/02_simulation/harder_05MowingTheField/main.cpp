/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        cout << v[i] << ' ';
    }
}

void inputvec(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    vector<vector<int>> pos;
    int n;
    int x = 0;
    int y = 0;
    pos.push_back({0,0});

    cin >> n;
    for(int i = 0; i < n; i = i + 1)
    {
        char direction;
        int step;

        cin >> direction >> step;
        for(int j = 0; j < step; j = j + 1)
        {
            if(direction == 'N')
            {
                y = y + 1;
                pos.push_back({x,y});
            }
            else if(direction == 'S')
            {
                y = y - 1;
                pos.push_back({x,y});
            }
            else if(direction == 'W')
            {
                x = x - 1;
                pos.push_back({x,y});
            }
            else if(direction == 'E')
            {
                x = x + 1;
                pos.push_back({x,y});
            }
        }
    }
    int time = 2147483647;
    for(int i = 0; i < pos.size() - 1; i = i + 1)
    {
        for(int j = i + 1; j < pos.size(); j = j + 1)
        {
            if(pos[i][0] == pos[j][0] && pos[i][1] == pos[j][1])
            {
                time = min(time, j - i);
            }
        }
    }
    if(time == 2147483647)
    {
        cout << -1;
    }
    else
    {
        cout << time;
    }


    return 0;
}


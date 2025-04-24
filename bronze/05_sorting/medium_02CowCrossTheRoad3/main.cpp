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
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> arrival;
    for(int i = 0; i < n; i = i + 1)
    {
        int a;
        int b;
        cin >> a >> b;
        arrival.push_back({a,b});
    }

    /*
    Solution:

    Sort the cow based on arrival, then simulate.
    */

    sort(arrival.begin(), arrival.end());

    int time = arrival[0][0];

    int cow = 0;

    while(cow < n)
    {
        if(time <= arrival[cow][0])
        {
            time = arrival[cow][0];
            time = time + arrival[cow][1];
            cow = cow + 1;
        }
        else
        {
            time = time + arrival[cow][1];
            cow = cow + 1;
        }
    }

    cout << time;
    return 0;
}

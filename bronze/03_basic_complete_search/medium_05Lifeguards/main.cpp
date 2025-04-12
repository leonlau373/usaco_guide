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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;


    vector<vector<int>> start_end;

    for(int i = 0; i < n; i = i + 1)
    {
        vector<int> start_end_cow;
        int start;
        int ended;
        cin >> start >> ended;
        start_end_cow.push_back(start);
        start_end_cow.push_back(ended);
        start_end.push_back(start_end_cow);
    }

    int max_time = 0;

    for(int fired = 0; fired < n; fired = fired + 1)
    {
        //time from t = 0 to t = 1000 is set to false
        vector<bool> time(1001);
        for(int i = 0 ; i < 1001 ; i = i + 1)
        {
            time[i] = false;
        }

        for(int cow = 0; cow < n; cow = cow + 1)
        {
            if(cow == fired)
            {
                continue;
            }
            else
            {
                int start = start_end[cow][0];
                int ended = start_end[cow][1];
                for(int i = start; i < ended ; i = i + 1)
                {
                    time[i] = true;
                }
            }
        }
        int time_count = 0;
        for(int i = 1; i < 1001; i = i + 1)
        {
            time_count = time_count + time[i];
        }
        max_time = max(max_time, time_count);
    }

    cout << max_time;


    return 0;
}

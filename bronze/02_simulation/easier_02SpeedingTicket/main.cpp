#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    vector<int> speed_limit;
    vector<int> speed;

    int n;
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i = i + 1)
    {
        int segment;
        int s;
        cin >> segment >> s;
        for(int j = 0; j < segment; j = j + 1)
        {
            speed_limit.push_back(s);
        }
    }

    for(int i = 0; i < m; i = i + 1)
    {
        int segment;
        int s;
        cin >> segment >> s;
        for(int j = 0; j < segment; j = j + 1)
        {
            speed.push_back(s);
        }
    }

    int max_value = 0;
    for(int i = 0; i < speed.size(); i = i + 1)
    {
        if(speed[i] - speed_limit[i] > max_value)
        {
            max_value = speed[i] - speed_limit[i];
        }
    }
    freopen("speeding.out", "w", stdout);
    cout << max_value;

    return 0;
}

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

vector<bool> ac_iterator(int combination, int m)
{
    int bitwise = combination;
    vector<bool> result;
    for(int i = m - 1; i >= 0 ; i = i - 1)
    {
        if(bitwise - pow(2, i) >= 0)
        {
            result.push_back(true);
            bitwise = bitwise - pow(2,i);
        }
        else
        {
            result.push_back(false);
        }
    }

    return result;
}

bool possible(vector<vector<int>> cow, vector<vector<int>> ac, vector<bool> ac_use)
{
    vector<int> shelf_temperature(101);
    for(int i = 0; i < ac.size(); i = i + 1)
    {
        if(ac_use[i])
        {
            for(int start = ac[i][0]; start <= ac[i][1]; start = start + 1)
            {
                shelf_temperature[start] = shelf_temperature[start] + ac[i][2];
            }
        }
    }

    vector<int> temperature_need(101);
    for(int i = 0; i < cow.size(); i = i + 1)
    {
        for(int j = cow[i][0]; j <= cow[i][1]; j = j + 1)
        {
            temperature_need[j] = max(temperature_need[j], cow[i][2]);
        }
    }

    bool flag = true;
    for(int i = 1; i < 101; i = i + 1)
    {
        if(temperature_need[i] > shelf_temperature[i])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);

    //input method
    int n, m;
    cin >> n >> m;

    /*
    s = start
    t = end
    c = temperature needed to cool down
    */
    vector<vector<int>> cow;

    /*
    a = start
    b = end
    p = temperature reduced by the AC
    m = AC price
    */
    vector<vector<int>> ac;

    for(int i = 0; i < n; i = i + 1)
    {
        int si;
        int ti;
        int ci;
        cin >> si >> ti >> ci;
        cow.push_back({si, ti, ci});
    }

    for(int i = 0; i < m; i = i + 1)
    {
        int ai;
        int bi;
        int pi;
        int mi;
        cin >> ai >> bi >> pi >> mi;
        ac.push_back({ai, bi, pi, mi});
    }

    /*
    Solution outline:
    Generate all possibilities of vector<bool> use from 0 to 2^m - 1.

    Each "switched on" use variable will calculate the AC usage, and
    looking AC usage compared to the cow needs.
    */
    vector<bool> ac_use;

    int min_cost = 2147483647;

    for(int i = 0; i < pow(2,m); i = i + 1)
    {
        ac_use = ac_iterator(i, m);

        bool plausible = possible(cow, ac, ac_use);

        int cost = 0;
        if(plausible)
        {
            for(int j = 0; j < m ; j = j + 1)
            {
                if(ac_use[j])
                {
                    cost = cost + ac[j][3];
                }
            }
            min_cost = min(cost, min_cost);
        }
    }

    cout << min_cost;
    return 0;
}

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
    long long int n;
    cin >> n;
    vector<long long int> cost;
    for(long long int i = 0 ; i < n ; i = i + 1)
    {
        long long int c;
        cin >> c;
        cost.push_back(c);
    }

    long long int tuition = 0;
    long long int max_profit = 0;

    sort(cost.rbegin(), cost.rend());

    for(long long int i = 0; i < n ; i = i + 1)
    {
        long long int profit;
        profit = (i + 1)*cost[i];

        if(profit >= max_profit)
        {
            max_profit = profit;
            tuition = cost[i];
        }
    }

    cout << max_profit << ' ' << tuition << endl;

    return 0;
}

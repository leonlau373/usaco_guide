/*
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
    long long int k;
    cin >> n >> k;
    vector<long long int> watch;

    for(int i = 0; i < n; i++)
    {
        long long int d;
        cin >> d;
        watch.push_back(d);
    }

    /*
    Solution idea:

    See if we can take k consecutive days or not.
        If we can take k consecutive days, take it.
        Otherwise, use single day subscription as it is cheaper.
    */

    long long int start = 0;
    long long int ending = 1;
    long long int cost = 0;

    while(ending < n)
    {
        //cout << "Start: " << start << '\n';
        //cout << "Ending: " << ending << '\n';
        if(watch[ending] - watch[ending - 1] <= k)
        {
            ending++;
        }
        else
        {
            cost = cost + 1 + k + watch[ending - 1] - watch[start];
            start = ending;
            ending++;
        }


        //cout << "Cost: " << cost << '\n';
        //cout << endl;
    }

    cost = cost + 1 + k + watch[n - 1] - watch[start];

    //cout << "Start: " << start << '\n';
    //cout << "Ending: " << ending << '\n';
    //cout << "Cost: " << cost << '\n';
    cout << cost << endl;
    return 0;
}

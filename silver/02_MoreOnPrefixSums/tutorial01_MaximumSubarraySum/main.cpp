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
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    int n;
    cin >> n;
    vector<long long> x;
    for(int i = 0; i < n; i++)
    {
        long long xi;
        cin >> xi;
        x.push_back(xi);
    }

    vector<long long> prefix;
    long long sum = 0;
    prefix.push_back(sum);

    for(int i = 0; i < n ; i++)
    {
        sum += x[i];
        prefix.push_back(sum);
    }

    long long max_subarray_sum = prefix[1];
    long long min_prefix_sum = prefix[0];
    for(int i = 1; i <= n ; i++)
    {
        max_subarray_sum = max(max_subarray_sum, prefix[i] - min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum, prefix[i]);
    }
    cout << max_subarray_sum;





    return 0;
}

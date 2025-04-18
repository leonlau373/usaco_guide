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

long long int minimum_difference(vector<long long int> apples, int n, int index, long long int left, long long int right)
{
    if(index == n)
    {
        return abs(left - right);
    }
    else
    {
        return min(minimum_difference(apples, n, index + 1, left + apples[index], right),
                   minimum_difference(apples, n, index + 1, left, right + apples[index]));
    }
}

int main()
{
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);

    //input method
    int n;
    cin >> n;
    vector<long long int> apples;
    for(int i = 0; i < n; i = i + 1)
    {
        long long int weight;
        cin >> weight;
        apples.push_back(weight);
    }

    long long int x = minimum_difference(apples,n,0,0,0);
    cout << x;

    return 0;
}

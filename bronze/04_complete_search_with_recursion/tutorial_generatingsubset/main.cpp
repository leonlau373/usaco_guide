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

void inputvec(vector<long long int>& v, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

vector<vector<int>> subsetRecursion(int n, int k)
{
    /*
    n = number of members in 1,2,3,...,n
    k = current number to be included in subset.
    */
    vector<vector<int>> subsetTotal;
    vector<int> subset;

    if(n == k)
    {
        subsetTotal.push_back(subset);
    }
    else
    {
        subset.push_back(k);
        subsetRecursion(n,k+1);
        subset.pop_back();
        subsetRecursion(n,k+1);
    }

    return subsetTotal;
}

int main()
{
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);

    //input method
    vector<vector<int>> a = subsetRecursion(4,1);

    for(int i = 0; i < a.size(); i = i + 1)
    {
        for(int j = 0; j < a[i].size(); j = j + 1)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

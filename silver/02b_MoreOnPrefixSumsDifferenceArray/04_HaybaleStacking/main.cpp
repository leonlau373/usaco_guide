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

using ll = long long;

int main()
{
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> haystack(n+2,0);

    int left;
    int right;
    for(int i = 0 ; i < k ; i++)
    {
        cin >> left >> right;
        haystack[left]++;
        haystack[right+1]--;
    }

    for(int i = 1 ; i <= n+1 ; i++)
    {
        haystack[i] = haystack[i] + haystack[i - 1];
    }

    sort(haystack.begin()+1,haystack.end()-1);

    vector<int> result(n);
    for(int i = 1 ; i <= n ; i++)
    {
        result[i - 1] = haystack[i];
    }


    cout << result[n/2];

    return 0;
}

/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        cout << v[i] << ' ';
    }
}

void inputvec(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<int> diamond;

    inputvec(diamond, n);

    sort(diamond.begin(),diamond.end());

    int maximum = 0;
    for(int i = 0; i < n - 1; i = i + 1)
    {
        int bgn = diamond[i];
        int j = i + 1;
        int ending = diamond[j];
        while(ending - bgn <= k && j < n)
        {
            j = j + 1;
            ending = diamond[j];
        }
        maximum = max(maximum, j - i);
    }

    cout << maximum;
    return 0;
}

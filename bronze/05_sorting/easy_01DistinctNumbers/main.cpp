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
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);

    //input method
    int n;
    vector<int> num;

    cin >> n;
    inputvec(num,n);

    sort(num.begin(),num.end());
    int distinct = 1;
    for(int i = 0; i < n - 1; i = i + 1)
    {
        if(num[i] != num[i + 1])
        {
            distinct++;
        }
    }
    cout << distinct;

    return 0;
}

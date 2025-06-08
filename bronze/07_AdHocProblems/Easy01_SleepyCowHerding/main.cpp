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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    vector<int> pos = {a,b,c};

    sort(pos.begin(),pos.end());

    int minimum;

    if(pos[1] - pos[0] == 1 && pos[2] - pos[1] == 1)
    {
        minimum = 0;
    }
    else if(pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2)
    {
        minimum = 1;
    }
    else
    {
        minimum = 2;
    }

    int maximum = 0;

    maximum = max(pos[1] - pos[0] , pos[2] - pos[1]) - 1;

    cout << minimum << endl;
    cout << maximum << endl;

    return 0;
}


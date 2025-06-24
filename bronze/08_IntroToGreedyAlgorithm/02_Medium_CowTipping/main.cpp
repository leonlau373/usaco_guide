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
    //freopen("cowtip.in", "r", stdin);
    //freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        s.push_back(s1);
    }


    return 0;
}

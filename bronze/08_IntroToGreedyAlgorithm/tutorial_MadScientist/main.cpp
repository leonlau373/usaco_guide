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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    string s1;
    string s2;
    cin >> n >> s1 >> s2;

    int op = 0;

    for(int i = 0; i < n - 1; i++)
    {
        if(s1[i] != s2[i] && s1[i+1] == s2[i+1])
        {
            op++;
        }
    }

    cout << op << endl;

    return 0;
}

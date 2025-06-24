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
    vector<int> id;
    inputvec(id, n);

    int odd = 0;
    int even = 0;

    for(int i = 0; i < n; i++)
    {
        if(id[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    int group = 0;
    while(odd > even)
    {
        odd = odd - 2;
        even = even + 1;
    }

    group = odd*2 + 1;

    cout << group;


    return 0;
}

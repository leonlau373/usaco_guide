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

vector<vector<int>> cow_track(vector<int>& cow)
{
    int a = 0;
    int b = 0;
    int c = 0;

    vector<vector<int>> track;
    track.push_back({a,b,c});

    for(int i = 0; i < cow.size(); i++)
    {
        if(cow[i] == 1)
        {
            a++;
        }
        else if(cow[i] == 2)
        {
            b++;
        }
        else if(cow[i] == 3)
        {
            c++;
        }
        track.push_back({a,b,c});
    }

    return track;
}

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n;
    int q;

    cin >> n >> q;

    vector<int> cow;
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        cow.push_back(c);
    }

    vector<vector<int>> cow_prefix = cow_track(cow);

    for(int i = 0; i < q; i++)
    {
        int l;
        int r;
        cin >> l >> r;

        int a = cow_prefix[r][0] - cow_prefix[l - 1][0];
        int b = cow_prefix[r][1] - cow_prefix[l - 1][1];
        int c = cow_prefix[r][2] - cow_prefix[l - 1][2];

        cout << a << ' ' << b << ' ' << c << endl;
    }




    return 0;
}

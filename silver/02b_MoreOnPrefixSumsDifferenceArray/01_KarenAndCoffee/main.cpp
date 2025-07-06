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
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> difference(200002, 0);

    int l = 0;
    int r = 0;
    for(int recipe = 0 ; recipe < n ; recipe++)
    {
        cin >> l >> r;
        difference[l]++;
        difference[r+1]--;
    }

    for(int i = 1 ; i < 200002 ; i++)
    {
        difference[i] += difference[i - 1];
    }

    for(int i = 0 ; i < 200002 ; i++)
    {
        if(difference[i] >= k)
        {
            difference[i] = 1;
        }
        else
        {
            difference[i] = 0;
        }
    }

    for(int i = 1 ; i < 200002 ; i++)
    {
        difference[i] += difference[i - 1];
    }

    for(int i = 0; i < q ; i++)
    {
        cin >> l >> r;
        int answer = difference[r] - difference[l - 1];

        cout << answer << endl;
    }


    return 0;
}

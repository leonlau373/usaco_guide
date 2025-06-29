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
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    vector<int> sum_prefix;
    int n;
    cin >> n;

    vector<int> id;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        id.push_back(x);
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = (sum + id[i]) % 7;
        sum_prefix.push_back(sum);
    }

    int max_group = 0;
    for(int num = 0 ; num < 7 ; num++)
    {
        int left = n - 1;
        int right = 0;
        int group = 0;

        for(int l = 0; l < n; l++)
        {
            if(sum_prefix[l] % 7 == num)
            {
                left = l;
                break;
            }
        }

        for(int r = n - 1; r >= 0; r--)
        {
            if(sum_prefix[r] % 7 == num)
            {
                right = r;
                break;
            }
        }

        group = right - left;
        max_group = max(max_group, group);
    }

    cout << max_group;

    return 0;
}


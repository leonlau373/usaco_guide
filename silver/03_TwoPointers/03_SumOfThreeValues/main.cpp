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
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);

    ll n, x;
    cin >> n >> x;

    vector<vector<ll>> num;

    for(ll i = 1 ; i <= n ; i++)
    {
        ll a;
        cin >> a;
        num.push_back({a, i});
    }

    sort(num.begin(),num.end());

    int left = 0;
    int right = n - 1;

    bool possible = false;

    if(n <= 2)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        ll sum = 0;
        bool possible = false;

        for(int i = 0 ; i < n - 2 ; i++)
        {
            sum = num[i][0];

            int left = i + 1;
            int right = n - 1;

            while(left != right)
            {
                if(sum + num[left][0] + num[right][0] < x)
                {
                    left++;
                }
                else if(sum + num[left][0] + num[right][0] > x)
                {
                    right--;
                }
                else
                {
                    possible = true;
                    cout << num[i][1] << ' ' << num[left][1] << ' ' << num[right][1];
                    break;
                }
            }

            if(possible)
            {
                break;
            }
        }
        if(!possible)
        {
            cout << "IMPOSSIBLE";
        }
    }

    return 0;
}

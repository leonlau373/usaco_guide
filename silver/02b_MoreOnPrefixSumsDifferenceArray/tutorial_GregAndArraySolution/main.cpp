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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++) {cin >> a[i];}

    vector<array<int,3>> ops(m);
    for(int i = 0 ; i < m ; i++)
    {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }

    vector<long long> s(m + 2);
    for(int i = 0 ; i < k ; i++)
    {
        int x,y;
        cin >> x >> y;
        s[x]++;
        s[y + 1]--;
    }

    vector<long long> add(n+2,0);

    vector<long long> op_amount(m+2,0);
    long long amount = 0;
    for(int i = 1 ; i <= m ;i++)
    {
        amount = amount + s[i];
        op_amount[i] = amount;

        add[ ops[i - 1][0] ] += op_amount[i] * ops[i - 1][2];
        add[ ops[i - 1][1] + 1 ] -= op_amount[i] * ops[i - 1][2];
    }

    for(int i = 1 ; i <= n ; i++)
    {
        add[i] = add[i] + add[i - 1];
        cout << a[i] + add[i] << ' ';
    }




    return 0;
}

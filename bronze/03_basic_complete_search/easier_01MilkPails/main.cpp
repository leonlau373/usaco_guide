/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        cout << v[i] << ' ';
    }
}

void inputvec(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x,y,m;
    cin >> x >> y >> m;

    int x_amount;
    int y_amount;

    x_amount = m / x;

    int maximum_milk = 0;

    for(int i = 0; i <= x_amount ; i = i + 1)
    {
        int y_amount = (m - x * i)/y;
        int milk = x * i + y_amount * y;
        maximum_milk = max(maximum_milk, milk);
    }

    cout << maximum_milk << endl;


    return 0;
}

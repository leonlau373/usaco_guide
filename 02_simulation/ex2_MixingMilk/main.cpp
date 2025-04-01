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
    freopen("mixmilk.in", "r", stdin);
    vector<int> capacity{};
    vector<int> milk{};

    int pour;

    for(int i = 0; i <= 2; i = i + 1)
    {
        int c;
        int m;
        cin >> c >> m;
        capacity.push_back(c);
        milk.push_back(m);
    }

    for(int i = 1; i <= 100; i = i + 1)
    {
        if(i%3 == 1)
        {
            milk[1] = milk[1] + milk[0];
            if(milk[1] <= capacity[1])
            {
                milk[0] = 0;
            }
            else
            {
                milk[0] = milk[1] - capacity[1];
                milk[1] = capacity[1];
            }
        }
        else if(i%3 == 2)
        {
            milk[2] = milk[2] + milk[1];
            if(milk[2] <= capacity[2])
            {
                milk[1] = 0;
            }
            else
            {
                milk[1] = milk[2] - capacity[2];
                milk[2] = capacity[2];
            }
        }
        else if(i%3 == 0)
        {
            milk[0] = milk[0] + milk[2];
            if(milk[0] <= capacity[0])
            {
                milk[2] = 0;
            }
            else
            {
                milk[2] = milk[0] - capacity[0];
                milk[0] = capacity[0];
            }
        }
    }
    freopen("mixmilk.out", "w", stdout);
    cout << milk[0] << '\n' << milk[1] << '\n' << milk[2];
    return 0;
}

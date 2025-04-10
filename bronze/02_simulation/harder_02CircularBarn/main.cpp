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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> r;

    for(int i = 0; i < n; i = i + 1)
    {
        int r_i;
        cin >> r_i;
        r.push_back(r_i);
    }

    int minimum = 2147483646;

    for(int choose = 0; choose < n; choose = choose + 1)
    {
        int total_step = 0;
        int cow = choose;
        int room_distance = 1;
        if(choose == n - 1)
        {
            cow = 0;
        }
        else
        {
            cow = cow + 1;
        }
        while(cow != choose)
        {
            total_step = total_step + r[cow]*room_distance;
            if(cow == n - 1)
            {
                cow = 0;
            }
            else
            {
                cow = cow + 1;
            }
            room_distance = room_distance + 1;

        }

        if(total_step < minimum)
        {
            minimum = total_step;
        }

    }
    cout << minimum;

    return 0;
}

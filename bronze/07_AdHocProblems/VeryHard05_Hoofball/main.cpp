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
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> pos;
    inputvec(pos,n);

    sort(pos.begin(),pos.end());

    /*
    Example:
    10
    2 5 7 9 13 18 21 25 30 32
    R R L L L  R  L  L  R  L

    Code each cow where to pass. If it passes to left --> L
                                       passes to right --> R

    Then for each R..RL..L sequence, it will come as two balls needed to pass. (if R and L both more than one)
                                        Otherwise, we only need one ball for RL...L or R..RL or RL
    */

    vector<char> cow_pass(n);
    cow_pass[0] = 'R';
    cow_pass[n-1] = 'L';

    for(int i = 1; i <= n - 2; i++)
    {
        if(pos[i] - pos[i - 1] <= pos[i + 1] - pos[i])
        {
            cow_pass[i] = 'L';
        }
        else
        {
            cow_pass[i] = 'R';
        }
    }



    int balls = 0;
    int count_l = 0;
    int count_r = 0;

    for(int i = 0; i < n; i = i + 1)
    {

        if(cow_pass[i - 1] == 'L' && cow_pass[i] == 'R' )
        {
            if(count_l > 1 && count_r > 1)
            {
                balls = balls + 2;
            }
            else if(count_l == 1 && count_r > 1)
            {
                balls = balls + 1;
            }
            else if(count_l > 1 && count_r == 1)
            {
                balls = balls + 1;
            }
            else if(count_l == 1 && count_r == 1)
            {
                balls = balls + 1;
            }
            count_l = 0;
            count_r = 1;
        }
        else if(cow_pass[i] == 'L')
        {
            count_l++;
        }
        else if(cow_pass[i] == 'R')
        {
            count_r++;
        }
    }

    if(count_l > 1 && count_r > 1)
    {
        balls = balls + 2;
    }
    else if(count_l == 1 && count_r > 1)
    {
        balls = balls + 1;
    }
    else if(count_l > 1 && count_r == 1)
    {
        balls = balls + 1;
    }
    else
    {
        balls = balls + 1;
    }

    cout << balls << endl;
    return 0;
}

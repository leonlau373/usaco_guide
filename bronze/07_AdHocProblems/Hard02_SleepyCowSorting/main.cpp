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
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cow;
    inputvec(cow, n);

    /*
    Key idea:
    If the last k cows are sorted in increasing order, then we just
    need to sort n - k cows left.
    */
    int consecutive = 1;
    for(int i = n - 1; i >= 1 ; i--)
    {
        if(cow[i] > cow[i - 1])
        {
            consecutive++;
        }
        else
        {
            break;
        }
    }

    cout << n - consecutive;


    return 0;
}

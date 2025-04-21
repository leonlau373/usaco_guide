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
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);

    //input method


    /*
    Solution idea:

    Take each column as a vector, then sort them one by one.

    The total difference can be counted using this pseudocode:

        sum = sum of cards in column i
        difference = 0

        for(i = 0 ; i < n ; i = i + 1)
        {
            sum = sum - ( (n - i)*(a[i] -  a[i - 1]) )
            difference = difference + sum
        }

        Illustration:
        Array = 1 3 5 6 8
        Sum = 23

        Loop 1:
        Array = 0 2 4 5 7
        Sum = 23 - 5 * (1-0)
        Difference = 18

        Loop 2:
        Array = 0 0 2 3 5
        Sum = 18 - 4 * (3 - 1)
        Difference = 18 + 10 = 28

        And so on...

        Do this over all columns.
    */

    return 0;
}

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
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> records;
    inputvec(records, n);
    /*
    Seems like I'm missing test cases.

    But the solution outline is as follows:
        Count how many consecutive -1, then see the next entry after -1
        If -1 count < record[i]:
            No breakout
        Else:
            At least one breakout in the position k before the record
            At most n - k + 1 breakout
    */
    int minimum = 1;
    int maximum = 1;

    int count_missing = 0;

    for(int i = 1; i < n ; i++)
    {
        if(records[i] == -1)
        {
            count_missing++;
        }
        else if(records[i] == -1 && i == n - 1)
        {
            count_missing++;
            maximum = maximum + count_missing;
        }
        else
        {
            if(count_missing - records[i] < 0)
            {
                count_missing = 0;
            }
            else
            {
                maximum = maximum + count_missing - records[i] + 1;
                minimum = minimum + 1;
                count_missing = 0;
            }
        }
    }

    cout << minimum << ' ' << maximum;
    return 0;
}

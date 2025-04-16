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

void inputvec(vector<long long int>& v, int n)
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
    int testcase;
    cin >> testcase;
    for(int t = 0; t < testcase; t = t + 1)
    {
        int n;
        cin >> n;
        vector<long long int> ai;
        inputvec(ai, n);

        //Solution

        /*
        Solution outline:
        Find all numbers that is divisible by total, and for each of them
        see if the operation is feasible or not by looking at the sum of first
        few terms.

        Example:
        1 2 3 1 1 1

        Total = 9
        Divisible by : 1 , 3 , 9

        If divisible by 1, it means that must be 9 groups of 1, not attainable

        If divisible by 3, it means there must be 3 groups of 3
        This can be attained by grouping, linear grouping from L to R:
        (1 2) (3) (1 1 1)

        Then from 6 to 3 --> we need 6 - 3 operations.
        */
        long long int total = 0;
        for(int j = 0; j < n ; j = j + 1)
        {
            total = total + ai[j];
        }

        if(total == 0)
        {
            cout << 0 << endl;
            continue;
        }

        long long int current_total = 0;

        int i = 0;
        long long int min_operation = 1000000;
        while(i < n)
        {
            bool feasible = true;
            current_total = current_total + ai[i];
            if(current_total != 0 && total % current_total == 0)
            {
                long long int running_total = 0;
                int j = i + 1;
                while(running_total <= current_total && j < n)
                {
                    running_total = running_total + ai[j];
                    if(running_total == current_total)
                    {
                        running_total = 0;
                    }
                    else if(running_total > current_total)
                    {
                        feasible = false;
                    }
                    j = j + 1;
                }

                if(feasible)
                {
                    min_operation = min(min_operation, n - total/current_total);
                }

            }

            i = i + 1;
        }

        cout << min_operation << endl;

    }
    return 0;
}


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
    int testcase;
    cin >> testcase;
    for(int test = 0; test < testcase; test = test + 1)
    {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<long long int>> cards;
        for(int i = 0; i < n; i = i + 1)
        {
            vector<long long int> player_card;
            for(int j = 0; j < m; j = j + 1)
            {
                long long int card;
                cin >> card;
                player_card.push_back(card);
            }
            cards.push_back(player_card);
        }

        long long int winnings = 0;
        for(int j = 0; j < m; j = j + 1)
        {
            vector<long long int> sequence;
            for(int i = 0; i < n; i = i + 1)
            {
                sequence.push_back(cards[i][j]);
            }

            sort(sequence.begin(), sequence.end());

            long long int sum = 0;
            for(int i = 0; i < n; i = i + 1)
            {
                sum = sum + sequence[i];
            }

            long long int difference = 0;
            for(int i = 0; i < n; i = i + 1)
            {
                if(i == 0)
                {
                    sum = sum - (n - i)*(sequence[0]);
                    difference = difference + sum;
                }
                else
                {
                    sum = sum - (n - i)*(sequence[i] - sequence[i-1]);
                    difference = difference + sum;
                }
            }

            winnings = winnings + difference;
        }

        cout << winnings << endl;
    }

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

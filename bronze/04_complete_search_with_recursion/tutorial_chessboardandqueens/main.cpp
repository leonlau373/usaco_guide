#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int DIM = 8;

int main()
{
    vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
    for(int r = 0; r < DIM ; r++)
    {
        string row;
        cin >> row;
        for(int c = 0 ; c < DIM ; c++)
        {
            if(row[c] == '*')
            {
                blocked[r][c] = true;
            }
            else
            {
                blocked[r][c] = false;
            }
        }
    }

    vector<int> queens(DIM);

    //set initial values from 0 to 7
    iota(queens.begin(), queens.end(), 0);
    int possible = 0;

    do
    {
        bool works = true;

        for(int c = 0; c < DIM ; c++)
        {
            if(blocked[queens[c]][c])
            {
                works = false;
                break;
            }
        }

        //Check diagonals from top right to bottom left
        for(int i = 0; i < DIM - 1; i = i + 1)
        {
            for(int j = i + 1 ; j < DIM; j = j + 1)
            {
                if(i + queens[i] == j + queens[j])
                {
                    works = false;
                    break;
                }
             }
             if(works == false)
             {
                 break;
             }
        }

        //Check diagonals from top right to bottom left
        for(int i = 0; i < DIM - 1; i = i + 1)
        {
            for(int j = i + 1 ; j < DIM; j = j + 1)
            {
                if(i - queens[i] == j - queens[j])
                {
                    works = false;
                    break;
                }
            }

            if(works == false)
            {
                break;
            }
        }

        if(works)
        {
            possible++;
        }

    }
    while (next_permutation(queens.begin(),queens.end()));

    cout << possible;
    return 0;
}

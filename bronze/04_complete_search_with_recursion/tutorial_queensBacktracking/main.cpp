#include <bits/stdc++.h>
using namespace std;

const int DIM = 14;

int valid_num = 0;
vector<int> queens(DIM);

void search_queens(int c = 0)
{
    if(c == DIM)
    {
        valid_num++;
        return;
    }

    for(int r = 0; r < DIM ; r++)
    {
        queens[c] = r;
        bool possible = true;
        for(int s = 0; s < c; s = s + 1)
        {
            if(queens[s] == queens[c])
            {
                possible = false;
                break;
            }
            if(queens[s] + s == queens[c] + c)
            {
                possible = false;
                break;
            }
            if(queens[s] - s == queens[c] - c)
            {
                possible = false;
                break;
            }
        }

        if(possible)
        {
            search_queens(c + 1);
        }
    }
}

int main()
{
    search_queens();
    cout << valid_num;
    return 0;
}

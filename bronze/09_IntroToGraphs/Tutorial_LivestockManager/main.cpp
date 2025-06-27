/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

const vector<string> COWS = []()
{
    vector<string> cow_name = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                               "Bella", "Blue", "Betsy", "Sue" };
    sort(cow_name.begin(),cow_name.end());

    return cow_name;
}();


int main()
{
    //freopen("lineup.in", "r", stdin);
    //freopen("lineup.out", "w", stdout);
    map<string,int> cow_indices;
    for(int i = 0; i < COWS.size(); i++)
    {
        cow_indices[COWS[i]] = i;
    }

    int n;
    cin >> n;

    vector<vector<int>> neighbors(COWS.size());
    for(int r = 0; r < n ; r++)
    {
        string cow1;
        string cow2;
        string trash;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

        int c1 = cow_indices[cow1];
        int c2 = cow_indices[cow2];
        neighbors[c1].push_back(c2);
        neighbors[c2].push_back(c1);
    }

    vector<int> order;
    vector<bool> added(COWS.size());

    for(int c = 0; c < COWS.size(); c++)
    {
        if(!added[c] && neighbors[c].size() <= 1)
        {
            added[c] = true;
            order.push_back(c);

            if(neighbors[c].size() == 1)
            {
                int prev = c;
                int att = neighbors[c][0];
                while(neighbors[att].size() == 2)
                {
                    added[att] = true;
                    order.push_back(att);

                    int a = neighbors[att][0];
                    int b = neighbors[att][1];
                    int temp_att = a == prev ? b : a;

                    prev = att;
                    att = temp_att;
                }

                added[att] = true;
                order.push_back(att);
            }
        }
    }

    for(int c : order)
    {
        cout << COWS[c] << endl;
    }


    return 0;
}

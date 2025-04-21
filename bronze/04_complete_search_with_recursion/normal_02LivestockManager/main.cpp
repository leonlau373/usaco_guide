/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    //input method
    vector<string> cow_name = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                               "Bella", "Blue", "Betsy", "Sue" };
    sort(cow_name.begin(),cow_name.end());

    int n;
    cin >> n;
    vector<vector<string>> sides;

    for(int i = 0; i < n; i = i + 1)
    {
        string start_name;
        string must;
        string be;
        string milked;
        string beside;
        string end_name;

        cin >> start_name >> must >> be >> milked >> beside >> end_name;
        sides.push_back({start_name, end_name});
    }

    /*
    Just do naive checking whether start_name is beside end_name or not
    for every query.
    */

    do
    {
        bool flag = true;

        for(int i = 0; i < n; i = i + 1)
        {
            int index_start = -1;
            int index_end = -1;
            for(int name = 0; name < cow_name.size(); name = name + 1)
            {
                if(sides[i][0] == cow_name[name])
                {
                    index_start = name;
                }

                if(sides[i][1] == cow_name[name])
                {
                    index_end = name;
                }
            }

            if(!(index_start == index_end + 1 || index_start == index_end - 1))
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            for(int i = 0; i < cow_name.size(); i = i + 1)
            {
                cout << cow_name[i] << endl;
            }
            break;
        }
    }
    while(next_permutation(cow_name.begin(), cow_name.end()));
    return 0;
}

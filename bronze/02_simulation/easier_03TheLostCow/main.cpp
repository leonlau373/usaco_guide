#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int start;
    int finish;
    int total_distance = 0;

    cin >> start >> finish;
    int position = start;

    int i = 0;
    if(finish > start)
    {
        while(start + pow(-2,i) < finish)
        {
            total_distance = total_distance + abs(position - start);
            position = start + pow(-2,i);
            total_distance = total_distance + abs(position - start);

            i++;
        }
    }
    else if(finish < start)
    {
        while(start + pow(-2,i) > finish)
        {
            total_distance = total_distance + abs(position - start);
            position = start + pow(-2,i);
            total_distance = total_distance + abs(position - start);

            i++;
        }
    }
    else
    {
        total_distance = 0;
    }


    total_distance = total_distance + abs(position - finish);
    cout << total_distance;

    return 0;
}


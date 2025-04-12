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
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> coordinates;
    for(int i = 0; i < n ; i = i + 1)
    {
        pair<int,int> coordinate;
        cin >> coordinate.first >> coordinate.second;
        coordinates.push_back(coordinate);
    }
    //Idea: Finding pivot point, then complete search other points if it has the same x as pivot , and same y as that pivot as well.
    int maxarea = 0;
    for(int pivot = 0; pivot < n; pivot = pivot + 1)
    {
        pair<int,int> pivot_point = coordinates[pivot];
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i = i + 1)
        {
            if(pivot_point.first == coordinates[i].first)
            {
                y = abs(coordinates[i].second - pivot_point.second);
            }
            else
            {
                continue;
            }
            for(int j = 0; j < n; j = j + 1)
            {
                if(pivot_point.second == coordinates[j].second)
                {
                    x = abs(coordinates[j].first - pivot_point.first);
                }
                maxarea = max(maxarea, x*y);
            }
        }



    }

    cout << maxarea;


    return 0;
}


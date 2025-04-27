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
    int n;
    int t;
    cin >> n >> t;

    vector<vector<int>> arr;
    for(int i = 0; i < n; i = i + 1)
    {
        int x;
        cin >> x;
        vector<int> a = {x, i + 1};
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while(left != right)
    {
        if(arr[left][0] + arr[right][0] > t)
        {
            right = right - 1;
        }
        else if(arr[left][0] + arr[right][0] < t)
        {
            left = left + 1;
        }
        else
        {
            cout << arr[left][1] << ' ' << arr[right][1];
            break;
        }
    }

    if(left == right)
    {
        cout << "IMPOSSIBLE";
    }



    return 0;
}


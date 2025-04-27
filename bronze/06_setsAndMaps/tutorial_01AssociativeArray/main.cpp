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
    int query;
    cin >> query;

    map<long long int, long long int> m;
    for(int i = 0 ; i < query ; i = i + 1)
    {
        int choice;
        cin >> choice;
        if(choice == 0)
        {
            long long int k;
            long long int v;
            cin >> k >> v;
            m[k] = v;
        }
        else if(choice == 1)
        {
            long long int k;
            cin >> k;
            cout << m[k] << endl;
        }
    }

    return 0;
}


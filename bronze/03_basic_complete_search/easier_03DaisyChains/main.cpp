/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        cout << v[i] << ' ';
    }
}

void inputvec(vector<int>& v, int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
}

int main()
{
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> petals;

    inputvec(petals,n);

    int valid_photo = 0;
    for(int i = 0; i < n; i = i + 1)
    {
        int total = 0;
        for(int j = i; j < n; j = j + 1)
        {
            total = total + petals[j];
            int average = -1;
            if(total % (j-i+1) == 0)
            {
                average = total / (j - i + 1);
            }

            for(int k = i; k <= j; k = k + 1)
            {
                if(petals[k] == average)
                {
                    valid_photo = valid_photo + 1;
                    break;
                }
            }
        }
    }

    cout << valid_photo;
    return 0;
}


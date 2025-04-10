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

bool cow_consistency(vector<vector<int>> v, int a, int b, int n)
{
    int k = v.size();
    bool flag = true;
    for(int i = 0; i < k; i = i + 1)
    {
        int a_position;
        int b_position;
        for(int a_pos = 0; a_pos < n; a_pos = a_pos + 1)
        {
            if (v[i][a_pos] == a)
            {
                a_position = a_pos;
            }
        }

        for(int b_pos = 0; b_pos < n; b_pos = b_pos + 1)
        {
            if (v[i][b_pos] == b)
            {
                b_position = b_pos;
            }
        }

        if(a_position < b_position)
        {
            flag = false;
            break;
        }

    }

    return flag;
}

int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    /*
    n = number of cows, k = number of practice sessions
    */
    int k,n;
    cin >> k >> n;
    vector<vector<int>> practice_ranking;

    for(int i = 0; i < k; i = i + 1)
    {
        vector<int> ranking;
        for(int j = 0; j < n; j = j + 1)
        {
            int num;
            cin >> num;
            ranking.push_back(num);
        }
        practice_ranking.push_back(ranking);
    }

    int counting = 0;
    for(int a = 1; a <= n; a = a + 1)
    {
        for(int b = 1; b <= n; b = b + 1)
        {
            if(a == b)
            {
                continue;
            }
            else
            {
                if(cow_consistency(practice_ranking,a,b,n))
                {
                    counting++;
                }
            }
        }
    }

    cout << counting;

    return 0;
}

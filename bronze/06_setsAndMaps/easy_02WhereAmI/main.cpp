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
    //Input Method
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    /*
    Solution outline:

    Just brute force from len = 1 to len = n - 1
    If one of the string is same, then iterate to next len.
    Otherwise, set min_length = len, output.

    Another solution, using set, if set.size() < number of total run, then return false.
    */

    int min_length = n + 1;

    for(int len = 1; len < n ; len = len + 1)
    {
        bool flag = false;

        for(int i = 0; i <= n - len ; i = i + 1)
        {
            for(int j = i + 1; j <= n - len; j = j + 1)
            {
                string s1 = s.substr(i, len);
                string s2 = s.substr(j, len);

                if(s1 == s2)
                {
                    flag = true;
                }
            }
        }

        if(!flag)
        {
            min_length = len;
            break;
        }
    }

    cout << min_length;

    return 0;
}


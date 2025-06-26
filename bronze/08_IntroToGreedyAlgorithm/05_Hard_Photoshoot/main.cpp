/*
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
    //freopen("outofplace.in", "r", stdin);
    //freopen("outofplace.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    vector<char> r;

    for(int i = 0; i < n; i = i + 2)
    {
        if(s[i] == 'G' && s[i + 1] == 'H')
        {
            r.push_back('F');
        }
        else if(s[i] == 'H' && s[i + 1] == 'G')
        {
            r.push_back('T');
        }
    }

    /*
    Solution idea:
    Since John can only reverse the prefix in even length, then we
    have the bijection as follows for every 2 letters:

    GG or HH = ignored
    GH = False (F)
    HG = True (T)

    False and True is evaluated based on the position of Guernseys.

    For example:
    GGGHGHHGHHHGHG is coded as:
     . F F T . T T
     --> FFTTT

     Then observe that: Every operation will reverse the FT sequence
     and flip the FT sequence.

     Example:
     HGGHGH --> TFF
     Swapping all of them make it become:
     HGHGGH --> TTF

     An obvious greedy algorithm is to: Swap every T until it meets F,
     Then swap all F from index 1 to the end.

     Example:

     TTFFTTTTFTF
     FFFFTTTTFTF
     TTTTTTTTFTF
     FFFFFFFFFTF
     TTTTTTTTTTF
     FFFFFFFFFFF
     TTTTTTTTTTT
    */

    int m = r.size();

    int swaps = 0;

    int right = 1;

    if(m == 0)
    {
        cout << swaps;
    }
    else if(m == 1)
    {
        if(r[0] == 'F')
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            if(r[i] == 'F')
            {
                swaps = swaps + 2;
            }
            while( r[i] == 'F')
            {
                i++;
            }
        }

        if(r[0] == 'F')
        {
            swaps--;
        }

        cout << swaps;
    }


    return 0;
}

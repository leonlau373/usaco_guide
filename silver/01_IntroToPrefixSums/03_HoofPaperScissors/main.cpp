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
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;
    cin >> n;
    vector<char> fj;

    for(int i = 0 ; i < n ; i++)
    {
        char f;
        cin >> f;
        fj.push_back(f);
    }

    /*
    We will observe using a prefix array from:
    hoof 0 games || paper n games
    hoof 1 games || paper n - 1 games
    and so on
    */

    //1st case: paper --> hoof
    vector<int> wins;

    int win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'H')
        {
            win++;
        }
    }

    wins.push_back(win);

    //Changing move i from P to H
    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'H')
        {
            win = win - 1;
        }
        else if(fj[i] == 'S')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    //2nd case: paper --> scissors
    win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'H')
        {
            win++;
        }
    }

    wins.push_back(win);

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'H')
        {
            win = win - 1;
        }
        else if(fj[i] == 'P')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    //3rd case: scissors --> hoof
    win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'P')
        {
            win++;
        }
    }

    wins.push_back(win);

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'P')
        {
            win = win - 1;
        }
        else if(fj[i] == 'S')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    //4th case: scissors --> paper
    win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'P')
        {
            win++;
        }
    }

    wins.push_back(win);

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'P')
        {
            win = win - 1;
        }
        else if(fj[i] == 'H')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    //5th case: hoof --> paper
    win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'S')
        {
            win++;
        }
    }

    wins.push_back(win);

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'S')
        {
            win = win - 1;
        }
        else if(fj[i] == 'H')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    //6th case: hoof --> scissors
    win = 0;

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'S')
        {
            win++;
        }
    }

    wins.push_back(win);

    for(int i = 0; i < n; i++)
    {
        if(fj[i] == 'S')
        {
            win = win - 1;
        }
        else if(fj[i] == 'P')
        {
            win = win + 1;
        }
        wins.push_back(win);
    }

    int max_win = *max_element(wins.begin(),wins.end());

    cout << max_win;

    return 0;
}

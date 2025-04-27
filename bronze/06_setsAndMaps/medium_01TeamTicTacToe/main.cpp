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

set<char> checkWin(char a, char b, char c)
{
    set<char> set_c;
    if(a == b && b == c)
    {
        set_c.insert(a);
    }
    else if(a == b)
    {
        set_c.insert(a);
        set_c.insert(c);
    }
    else if(a == c)
    {
        set_c.insert(b);
        set_c.insert(c);
    }
    else if(b == c)
    {
        set_c.insert(a);
        set_c.insert(b);
    }

    return set_c;
}

int main()
{
    //Input Method
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    vector<string> ttt;
    for(int i = 0; i < 3; i = i + 1)
    {
        string s;
        cin >> s;
        ttt.push_back(s);
    }

    /*
    Solution outline:
    8 sets, count the size each of them.
        If size == 1:
            output row_1 + 1
        If size == 2:
            output row_2 + 1
    */
    set<char> r0 = checkWin(ttt[0][0], ttt[0][1], ttt[0][2]);
    set<char> r1 = checkWin(ttt[1][0], ttt[1][1], ttt[1][2]);
    set<char> r2 = checkWin(ttt[2][0], ttt[2][1], ttt[2][2]);
    set<char> c0 = checkWin(ttt[0][0], ttt[1][0], ttt[2][0]);
    set<char> c1 = checkWin(ttt[0][1], ttt[1][1], ttt[2][1]);
    set<char> c2 = checkWin(ttt[0][2], ttt[1][2], ttt[2][2]);
    set<char> d0 = checkWin(ttt[0][0], ttt[1][1], ttt[2][2]);
    set<char> d1 = checkWin(ttt[0][2], ttt[1][1], ttt[2][0]);

    set<set<char>> win;
    win.insert(r0);
    win.insert(r1);
    win.insert(r2);
    win.insert(c0);
    win.insert(c1);
    win.insert(c2);
    win.insert(d0);
    win.insert(d1);

    int win1 = 0;
    int win2 = 0;

    for(set<char> element : win)
    {
        if(element.size() == 1)
        {
            win1++;
        }
        else if(element.size() == 2)
        {
            win2++;
        }
    }

    cout << win1 << endl << win2;




    return 0;
}


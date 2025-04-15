/*
Name: Leon Lau
username: nya10
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=893
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

int codeValue(char a, char b, char c)
{
    int val_a;
    int val_b;
    int val_c;

    if(a == 'A')
    {
        val_a = 0;
    }
    else if(a == 'C')
    {
        val_a = 1;
    }
    else if(a == 'G')
    {
        val_a = 2;
    }
    else
    {
        val_a = 3;
    }

    if(b == 'A')
    {
        val_b = 0;
    }
    else if(b == 'C')
    {
        val_b = 1;
    }
    else if(b == 'G')
    {
        val_b = 2;
    }
    else
    {
        val_b = 3;
    }

    if(c == 'A')
    {
        val_c = 0;
    }
    else if(c == 'C')
    {
        val_c = 1;
    }
    else if(c == 'G')
    {
        val_c = 2;
    }
    else
    {
        val_c = 3;
    }

    return 16*val_a + 4*val_b + val_c;
}

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    //Input method
    int n;
    int m;
    cin >> n >> m;
    vector<string> spotty;
    vector<string> plain;

    for(int i = 0; i < n ; i = i + 1)
    {
        string s;
        cin >> s;
        spotty.push_back(s);
    }

    for(int i = 0; i < n ; i = i + 1)
    {
        string s;
        cin >> s;
        plain.push_back(s);
    }

    //Solution start

    //Iterating a , b , c over DNA choice
    int possible = 0;

    for(int a = 0; a < m - 2; a = a + 1)
    {
        for(int b = a + 1; b < m - 1; b = b + 1)
        {
            for(int c = b + 1; c < m ; c = c + 1)
            {
                vector<int> s;
                vector<int> p;
                //For each a,b,c position of genetics:
                for(int i = 0; i < n; i = i + 1)
                {
                    int val = codeValue(spotty[i][a],spotty[i][b],spotty[i][c]);
                    s.push_back(val);
                }

                for(int i = 0; i < n; i = i + 1)
                {
                    int val = codeValue(plain[i][a],plain[i][b],plain[i][c]);
                    p.push_back(val);
                }

                //Checking whether s_i = p_j for some i,j
                bool same = true;
                for(int i = 0; i < n; i = i + 1)
                {
                    for(int j = 0; j < n; j = j + 1)
                    {
                        if(s[i] == p[j])
                        {
                            same = false;
                            break;
                        }
                    }
                }

                if(same)
                {
                    possible = possible + 1;
                }

            }
        }
    }

    cout<<possible;

    return 0;
}

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

/*
bool possible(int pos, vector<int> order, vector<int> hierarchy)
{
    bool flag = true;

    for(int i = 0 ; i < hierarchy.size(); i++)
    {
        if(order[hierarchy[i]] != 0)
        {

        }
    }
}
*/

int main()
{
    //Input Method
    //freopen("notlast.in", "r", stdin);
    //freopen("notlast.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> hierarchy;
    inputvec(hierarchy, m);
    /*
    vector<int> order(n + 1);
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        order[a] = b;
    }
    */

    /*
    Idea:
    Brute force position from cow 1 = 1 to cow 1 = n
    */



    return 0;
}

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
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n;
    vector<int> G;
    vector<int> L;

    cin >> n;

    for(int i = 0; i < n; i = i + 1)
    {
        char c;
        int pi;
        cin >> c >> pi;

        if(c == 'G')
        {
            G.push_back(pi);
        }
        else if(c == 'L')
        {
            L.push_back(pi);
        }
    }

    sort(G.begin(),G.end());
    sort(L.begin(),L.end());

    int lie = 1000000;

    for(int i = 0; i < L.size(); i = i + 1)
    {
        int count_lie = i;
        for(int j = G.size()-1; j >= 0; j = j - 1)
        {
            if(L[i] < G[j])
            {
                count_lie = count_lie + 1;
            }
        }
        lie = min(count_lie, lie);

    }

    cout << lie;

    return 0;
}

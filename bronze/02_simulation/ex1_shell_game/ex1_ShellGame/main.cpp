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
    freopen("shell.in", "r", stdin);

    int n;
    cin >> n;

    vector<int> shell {0, 1, 2, 3};
    vector<int> guess_num;
    int max_score;

    for(int i = 0; i < n; i = i + 1)
    {
        int a;
        int b;
        int guess;
        cin >> a >> b >> guess;

        swap(shell[a], shell[b]);
        guess_num.push_back(shell[guess]);
    }

    vector<int> score {0, 0, 0, 0};
    for(int i = 0; i < n; i = i + 1)
    {
        for(int j = 1; j <= 3; j = j + 1)
        {
            if(guess_num[i] == j)
            {
                score[j] = score[j] + 1;
            }
        }
    }

    max_score = *max_element(score.begin(), score.end());
    freopen("shell.out", "w", stdout);

    cout << max_score;
    return 0;
}

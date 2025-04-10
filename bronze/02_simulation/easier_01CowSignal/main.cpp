#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("cowsignal.txt", "r", stdin);
    int row;
    int col;

    int large;

    cin >> row >> col >> large;

    vector<string> code;
    for(int i = 1; i <= row; i = i + 1)
    {
        string str;
        cin >> str;
        code.push_back(str);
    }

    freopen("cowsignalout.txt", "w", stdout);

    for(int i = 0; i < row; i = i + 1)
    {
        for(int k = 1; k <= large; k = k + 1)
        {
            for(int j = 0; j < col; j = j + 1)
            {
                for(int k2 = 1; k2 <= large; k2 = k2 + 1)
                {
                    cout << code[i][j];
                }

            }
            cout << '\n';
        }
    }


    return 0;
}

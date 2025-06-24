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
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    int cow[n];

    for(int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }

    //Check where Bessie is.
    int bessie = -1;
    string type;

    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(cow[i] > cow[i + 1] && cow[i] > cow[i - 1])
        {
            bessie = i;
            type = "right";
            break;
        }
        else if(cow[i] < cow[i + 1] && cow[i] < cow[i - 1])
        {
            bessie = i;
            type = "left";
            break;
        }
    }

    if(cow[0] > cow[1])
    {
        bessie = 0;
        type = "right";
    }
    else if(cow[n - 1] < cow[n - 2])
    {
        bessie = n - 1;
        type = "left";
    }
    /*
    cout << "Bessie: " << bessie << endl;
    cout << "Type: " << type << endl << endl << endl;
    */

    //Then count how many swaps
    int swaps = 0;
    if(type == "left")
    {
        int cow_swap = bessie - 1;
        while(cow_swap > 0 && cow[cow_swap] > cow[bessie])
        {
            /*
            cout << "cow_swap: " << cow_swap << endl;
            cout << "bessie: " << bessie << endl;
            cout << "swaps: " << swaps << endl;
            cout << endl;
            */
            if(cow_swap > 0 && cow[cow_swap - 1] == cow[cow_swap])
            {
                cow_swap--;
            }
            else
            {
                swaps++;
                cow_swap--;
            }
            /*
            cout << "cow_swap: " << cow_swap << endl;
            cout << "bessie: " << bessie << endl;
            cout << "swaps: " << swaps << endl;
            cout << endl;
            cout << endl;
            */
        }
    }
    else if(type == "right")
    {
        int cow_swap = bessie + 1;
        while(cow_swap < n && cow[cow_swap] < cow[bessie])
        {
            /*
            cout << "cow_swap: " << cow_swap << endl;
            cout << "bessie: " << bessie << endl;
            cout << "swaps: " << swaps << endl;
            cout << endl;
            */
            if(cow_swap < n - 1 && cow[cow_swap] == cow[cow_swap + 1])
            {
                cow_swap++;
            }
            else
            {

                swaps++;
                cow_swap++;
            }
            /*
            cout << "cow_swap: " << cow_swap << endl;
            cout << "bessie: " << bessie << endl;
            cout << "swaps: " << swaps << endl;
            cout << endl;
            cout << endl;
            */
        }
    }
    else
    {
        swaps = 0;
    }

    cout << swaps;

    return 0;
}

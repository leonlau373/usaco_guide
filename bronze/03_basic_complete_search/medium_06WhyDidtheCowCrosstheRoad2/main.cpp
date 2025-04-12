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
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    //Insert alphabet A to Z
    vector<char> alphabet;
    for(int i = 0; i < 26; i = i + 1)
    {
        char c = 65 + i;
        alphabet.push_back(c);
    }

    //Input method
    string circlecross;
    cin >> circlecross;

    int cross = 0;
    for(char c1 : alphabet)
    {
        int find_c1 = circlecross.find(c1);
        int find2_c1 = circlecross.find(c1, find_c1 + 1);

        for(char c2 : alphabet)
        {
            if(c1 >= c2)
            {
                continue;
            }
            else
            {
                int find_c2 = circlecross.find(c2);
                int find2_c2 = circlecross.find(c2, find_c2 + 1);
                if( (find_c2 > find_c1 && find_c2 < find2_c1) && (find2_c2 > find_c1 && find2_c2 < find2_c1) )
                {

                }
                else if( (find_c1 > find_c2 && find_c1 < find2_c2 ) && (find2_c1 > find_c2 && find2_c1 < find2_c2 ) )
                {

                }
                else if( (find_c2 > find2_c1) || (find2_c2 < find_c1) )
                {

                }
                else
                {
                    cross = cross + 1;
                }
            }
        }
    }

    cout << cross;




    return 0;
}

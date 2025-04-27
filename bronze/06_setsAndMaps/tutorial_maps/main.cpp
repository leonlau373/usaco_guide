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
    //UNORDERED MAP
    /*
        m[key] = value, assigns a value to a key, and place them into a map

        Both of count and erase works similarly in unordered sets
        count(key)
        erase(key) , erase(it) for iterator
    */
    unordered_map<int,int> m;

    m[1] = 5;
    m[4] = 14;
    m[2] = 7;

    m.erase(2);

    cout << m[1] << endl;
    cout << m.count(7) << endl;
    cout << m.count(1) << endl;

    //ORDERED MAPS
    /*
        Also supports lower_bound and upper_bound
    */

    map<int, int> n;
    n[3] = 5;
    n[11] = 4;
    n[10] = 23;

    cout << n[3] << endl;

    cout << n.lower_bound(10)->first << " " << n.lower_bound(10)->second << endl;
    cout << n.upper_bound(10)->first << " " << n.upper_bound(10)->second << endl;

    n[15] = 432;

    cout << endl << "INITIAL: " << endl;
    for(auto element : n)
    {
        cout << element.first << " " << element.second;
        cout << endl;
    }

    n.erase(11);

    cout << endl <<  "END: " << endl;
    for(auto element : n)
    {
        cout << element.first << " " << element.second;
        cout << endl;
    }
    cout << endl;

    if(n.upper_bound(10) == n.end())
    {
        cout << "END" << endl;
    }

    return 0;
}

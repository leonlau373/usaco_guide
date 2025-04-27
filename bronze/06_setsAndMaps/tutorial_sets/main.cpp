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
    //UNORDERED SETS
    /*
        Works by Hashing, allows insertions, deletions, and searches in O(1) time (with high constant factors).
        Elements are ordered arbitrarily.

        OP:
        insert: adds an element if it's not prsenet
        erase: deletes an element if it exists
        count: return 1 if the set contain element, 0 if not
    */
    cout << "UNORDERED SETS" << endl;

    unordered_set<int> s;
    s.insert(1); // [1]
    s.insert(4); // [1,4] in arbitrary order
    s.insert(2); // [1,4,2] in arbitrary order

    cout << "Is 1 exist? " << s.count(1) << endl;
    cout << "Is 3 exist? " << s.count(3) << endl;

    s.erase(1); // [2,4] in arbitrary order

    cout << "Is 1 exist? " << s.count(1) << endl;

    s.erase(0); // Nothing happens

    for(int e: s)
    {
        cout << e << ' ';
    }
    cout << endl;
    cout << endl;

    //ORDERED SETS
    /*
        Insertion, deletions, and searches on the ordered sets require O(log n) time

        Additional operator:
        begin(), returns an iterator from the lowest element in set
        end(), iterator to highest element in set
        lower_bound(), returns an iterator to the least element >= k
        upper_bound(), returns an iterator to the least element > k
    */
    cout << "ORDERED SETS" << endl;

    set<int> t;
    t.insert(1);
    t.insert(14);
    t.insert(9);
    t.insert(2);

    cout << "Upper bound for 7 is: " << *t.upper_bound(7) << endl;
    cout << "Upper bound for 9 is: " << *t.upper_bound(9) << endl;
    cout << "Lower bound for 5 is: " << *t.lower_bound(5) << endl;
    cout << "Lower bound for 9 is: " << *t.lower_bound(9) << endl;

    //To extract the last element
    auto it = t.end();
    cout << *(--it) << endl;

    t.erase(t.upper_bound(6));

    for(int e: t)
    {
        cout << e << ' ';
    }
    cout << endl << endl;

    return 0;
}

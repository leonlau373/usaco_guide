#include <bits/stdc++.h>

using namespace std;

int main()
{
    //PART 4: Pairs
        //pair<type1, type2> p: Creates a pair p with two elements with the first one being of type1 and the second one being of type2
        //make_pair(a, b): Returns a pair with values a, b.
        //{a, b}: With C++11 and above, this can be used as to create a pair, which is easier to write than make_pair(a, b).
        pair<string, int> pair1 = make_pair("Testing", 123);
        cout << pair1.first << " " << pair1.second << endl;

        pair1.first = "It is possible to edit pairs after declaring them";
        cout << pair1.first << " " << pair1.second << endl;

        pair<string, string> pair2{"Testing", "curly braces"};
        cout << pair2.first << " " << pair2.second << endl;

    //PART 5: Tuples
        /*
        tuple<type1, type2, ..., typeN> t: Creates a tuple with N elements, i'th one being of typei.

        make_tuple(a, b, c, ..., d): Returns a tuple with values written in the brackets.

        get<i>(t): Returns the i'th element of the tuple t. Can also be used to change the element of a tuple.
                   i must be a constant, can't be stored in a variable.

        */
        int a = 3, b = 4, c = 5;
        tuple<int, int, int> t = tie(a, b, c);
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
        get<0>(t) = 7;
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

        tuple<string, string, int> tp2 = make_tuple("Hello", "world", 100);
        string s1, s2;
        int x;
        tie(s1, s2, x) = tp2;
        cout << s1 << " " << s2 << " " << x << endl;




    return 0;
}

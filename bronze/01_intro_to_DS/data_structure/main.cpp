#include <bits/stdc++.h>

using namespace std;

int main()
{
    //PART 1: Array

        //initializing array
        array<int, 25> arr;
        int arr2[5];

    //PART 2: Dynamic Array (Vector)

        //Initializing array
        //Then add numbers from 1 to 10
        vector<int> v;
        for(int i = 1; i <= 10; i++)
        {
            v.push_back(i);
        }

        //Initializing vector with size n
        int n;
        cin >> n;
        vector<int> v2;
        v2.resize(n);

        //Iterating vector
        vector<int> v3{1, 7, 4, 5, 2};
        for(int i = 0; i < v3.size() ; i++)
        {
            cout << v3[i] << ' ';
        }
        cout << endl;

        for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

        for(auto it = begin(v); it != end(v); it = next(it))
        {
            cout << *it << " ";
        }
        cout << endl;

        for(int element : v3)
        {
            cout << element << " ";
        }
        cout << endl;

        //Inserting and Erasing
        vector<int> v4;

        v4.push_back(2);          // [2]
        v4.push_back(3);          // [2, 3]
        v4.push_back(7);          // [2, 3, 7]
        v4.push_back(5);          // [2, 3, 7, 5]
        v4[1] = 4;                // sets element at index 1 to 4 -> [2, 4, 7, 5]
        v4.erase(v4.begin() + 1);  // removes element at index 1 -> [2, 7, 5]
        // this remove method is O(n); to be avoided
        v4.push_back(8);        // [2, 7, 5, 8]
        v4.erase(v4.end() - 1);  // [2, 7, 5]
        // here, we remove the element from the end of the list; this is O(1).
        v4.push_back(4);                     // [2, 7, 5, 4]
        v4.push_back(4);                     // [2, 7, 5, 4, 4]
        v4.push_back(9);                     // [2, 7, 5, 4, 4, 9]
        cout << v4[2] << endl;                       // 5
        v4.erase(v4.begin(), v4.begin() + 3);  // [4, 4, 9]
        v4.pop_back(); // [4, 4]
        // this erases the first three elements; O(n)

    //PART 3: Strings
        //Using getline to ignore blank space
        cout << "Enter your full name: ";
        string name{};
        getline(cin >> ws, name);

        cout << "Your name is " << name << endl;
        //Get amount of characters
        cout << name << " has " << name.length() << " characters" << endl;

        //String Method
        std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

        std::string str2 = str.substr (3,5);     // "think"

        std::size_t pos = str.find("live");      // position of "live" in str

        std::string str3 = str.substr (pos);     // get from "live" to the end

        std::cout << str2 << ' ' << str3 << '\n';

    return 0;
}

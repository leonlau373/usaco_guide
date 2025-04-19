/*
Name: Leon Lau
username: nya10
Problem link:
*/
#include <bits/stdc++.h>

using namespace std;

string s;
vector<string> perms;
int char_count[26];

void search(const string &curr = "")
{
    if(curr.size() == s.size())
    {
        perms.push_back(curr);
    }
    else
    {
        for(int i = 0 ; i < 26 ; i = i + 1)
        {
            if(char_count[i] > 0)
            {
                char_count[i] = char_count[i] - 1;
                char c = 'a' + i;
                string s = curr + c;
                search(s);
                char_count[i] = char_count[i] + 1;
            }
        }
    }
}

int main()
{
    cin >> s;
    for(int i = 0; i < s.size() ; i = i + 1)
    {
        char_count[s[i] - 'a']++;
    }

    search();

    cout << perms.size() << endl;
    for(int i = 0; i < perms.size(); i = i + 1)
    {
        cout << perms[i] << endl;
    }

    return 0;
}

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

vector<int> alphabet_count(string s)
{
    vector<int> alphabet(26);
    for(int i = 0; i < s.length(); i = i + 1)
    {
        alphabet[s[i] - 97] += 1;
    }

    return alphabet;
}

int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    vector<int> alphabet_total(26);

    int n;
    cin >> n;

    vector<pair<string,string>> word(n);
    for(int i = 0; i < n; i = i + 1)
    {
        string str1;
        string str2;

        cin >> str1 >> str2;

        word[i].first = str1;
        word[i].second = str2;
    }

    for(int i = 0; i < n; i = i + 1)
    {
        vector<int> alphabet_first(26);
        vector<int> alphabet_second(26);
        alphabet_first = alphabet_count(word[i].first);
        alphabet_second = alphabet_count(word[i].second);

        for(int j = 0; j < 26; j = j + 1)
        {
            alphabet_total[j] += max(alphabet_first[j], alphabet_second[j]);
        }

    }

    for(int i = 0; i < 26; i = i + 1)
    {
        cout << alphabet_total[i] << endl;
    }

    return 0;
}

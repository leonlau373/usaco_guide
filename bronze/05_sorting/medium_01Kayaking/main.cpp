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

int main() {
	int N;
	cin >> N;
	N = N * 2;

	vector<int> people;
	for(int i = 0; i < N ; i = i + 1)
    {
        int p;
        cin >> p;
        people.push_back(p);
    }
	sort(people.begin(), people.end());

	int min_instability = 2147483647;

	for(int i = 0; i < N - 1 ; i = i + 1)
    {
        for(int j = i + 1 ; j < N ; j = j + 1)
        {
            vector<int> couple;
            for(int k = 0 ; k < N ; k = k + 1)
            {
                if(k != i && k != j)
                {
                    couple.push_back(people[k]);
                }
            }


            int instability = 0;
            for(int k = 0 ; k < N - 2 ; k = k + 2)
            {
                instability = instability + couple[k + 1] - couple[k];
            }

            min_instability = min(instability, min_instability);
        }
    }

	cout << min_instability << endl;
}

/*
Name: Leon Lau
username: nya10
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=893
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
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    //Input method
    /*
    animals = list of animals and its characteristics
    */
    int n;
    cin >> n;
    vector<vector<string>> animals;

    for(int i = 0; i < n; i = i + 1)
    {
        vector<string> a;
        string animal;
        cin >> animal;
        a.push_back(animal);

        int characteristics;
        cin >> characteristics;
        for(int j = 0; j < characteristics; j = j + 1)
        {
            string characters;
            cin >> characters;
            a.push_back(characters);
        }

        animals.push_back(a);
    }

    //Start solution
    /*
    Idea: Check how much in common that animal has characteristics
          with other specific animal

          In the testcase, cow has max 2 same characteristics with goat
          That's why they need to ask 3 max questions
    */
    int yes_answer = 0;
    for(int animal_1 = 0; animal_1 < n - 1; animal_1 = animal_1 + 1)
    {
        for(int animal_2 = animal_1 + 1; animal_2 < n; animal_2 = animal_2 + 1)
        {
            // Checking how many characteristics are the same for each pair
            // of animals
            int same_characters = 0;
            for(int i = 1; i < animals[animal_1].size() ; i = i + 1)
            {
                for(int j = 1; j < animals[animal_2].size() ; j = j + 1)
                {
                    if(animals[animal_1][i] == animals[animal_2][j])
                    {
                        same_characters = same_characters + 1;
                    }
                }
            }

            yes_answer = max(yes_answer, same_characters + 1);
        }

    }

    cout << yes_answer;




    return 0;
}


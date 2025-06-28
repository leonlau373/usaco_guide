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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        double n, d, h;
        cin >> n >> d >> h;

        vector<double> triangle;

        for(int i = 0; i < n; i++)
        {
            double x;
            cin >> x;
            triangle.push_back(x);
        }

        double area = d*h/2;

        for(int i = 1; i < n; i++)
        {
            double diff = triangle[i] - triangle[i - 1];

            if(diff >= h)
            {
                area = area + d*h/2;
            }
            else
            {
                area = area + d*h/2 - d*h/2 * pow( (h - diff)/h ,2);
            }

            //cout << "Area: " << area << endl;
        }

        cout << setprecision(20) << area << endl;
    }



    return 0;
}

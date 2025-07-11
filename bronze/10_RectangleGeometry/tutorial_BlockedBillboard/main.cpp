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

struct Rect
{
    int x1, y1, x2, y2;
    int area()
    {
        return (y2 - y1)*(x2 - x1);
    }
};

int intersect(Rect p, Rect q)
{
    int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));

    return xOverlap * yOverlap;
}

int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect a, b, t;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    cout << a.area() + b.area() - intersect(a,t) - intersect(b,t);

    return 0;
}

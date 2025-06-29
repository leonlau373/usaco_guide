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

vector<long long> p_sum(vector<long long>& a)
{
    long long sum = 0;
    vector<long long> psum;
    psum.push_back(0);

    for(int i = 1; i <= a.size(); i++)
    {
        sum = sum + a[i - 1];
        psum.push_back(sum);
    }

    return psum;
}

int main()
{
    long long n;
    long long q;
    vector<long long> a;

    cin >> n >> q;

    for(int i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;
        a.push_back(ai);
    }

    vector<long long> psum = p_sum(a);

    for(int q_i = 0; q_i < q; q_i++)
    {
        long long l;
        long long r;
        cin >> l >> r;
        cout << psum[r] - psum[l] << endl;
    }



    return 0;
}

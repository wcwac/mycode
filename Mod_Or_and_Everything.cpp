#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long m;
        cin >> m;
        long long t = 2;
        while (t < m)
            t <<= 1;
        cout << (t >> 1) - 1 << endl;
    }
}
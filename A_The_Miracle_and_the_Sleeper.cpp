#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a, b;
        cin >> a >> b;
        cout << b - max(a, b / 2 + 1) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a;
        cin >> a;
        cout << a * 12 << " " << 4 << "\n"
             << a << " " << a * 2 << " " << a * 3 << " " << a * 6 << "\n";
    }
}
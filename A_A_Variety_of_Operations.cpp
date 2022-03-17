#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int c, d;
        cin >> c >> d;
        if (c == d && c == 0)
            puts("0");
        else if (c == d && c != 0)
            puts("1");
        else if (abs(c - d) & 1)
            puts("-1");
        else
            puts("2");
    }

    return 0;
}
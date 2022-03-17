#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans = 1e9 + 7;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c - a > 0)
        {
            ans = min(ans, b);
        }
    }
    if (ans == 1e9 + 7)
    {
        puts("-1");
    }
    else
        cout << ans << endl;

    return 0;
}
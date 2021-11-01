#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T != -1)
    {
        long long ans = 0;
        int now = 0;
        while (T--)
        {
            int a, b;
            cin >> a >> b;
            ans += a * (b - now);
            now = b;
        }
        cout << ans << " miles\n";
        cin >> T;
    }
}
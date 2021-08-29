#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long
int a[N];
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int xm = a[1], ym = a[2], xr = 1, yr = 1, ans = n * xm + n * ym, sum = a[1] + a[2];
        for (int i = 3; i <= n; ++i)
        {
            if (i & 1)
            {
                xm = min(xm, a[i]);
                ans = min(ans, (n - xr) * xm + (n - yr) * ym + sum);
                ++xr;
            }
            else
            {
                ym = min(ym, a[i]);
                ans = min(ans, (n - xr) * xm + (n - yr) * ym + sum);
                ++yr;
            }
            sum += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}
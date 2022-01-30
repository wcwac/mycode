#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, a, t = 0;
    // cin >> n >> m >> a;
    for (n = 2; n <= 10; ++n)
    {
        for (m = 2; m <= 10; ++m)
        {
            for (a = 0; a <= n * m / 2; ++a)
            {

                t = 0;
                int ans = 0;
                for (int i = 0; i < n * m; ++i)
                {
                    t = (t + n) % (n * m);
                    if (t >= i)
                    {
                        if (t - i <= a || i + n * m - t <= a)
                        {
                            ++ans;
                        }
                    }
                    else
                    {
                        if (i - t <= a || t + n * m - i <= a)
                        {
                            ++ans;
                        }
                    }
                }
                cout << n << "," << m << "," << a << "\t" << ans << endl;
                break;
            }
        }
    }
    return 0;
}
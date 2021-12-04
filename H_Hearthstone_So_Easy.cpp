#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        if (n > 1 && n - k <= 1)
        {
            cout << "pllj" << endl;
        }
        else
        {
            cout << "freesin" << endl;
        }
        continue;

        double t = (-2 * k - 1 + sqrt(1.0l * (2 * k + 1) * (2 * k + 1) + 8.0l * n)) / 2.0l;

        long long tt = max((long long)(t - 20), 0ll);
        int nn = n - tt * k - (1 + tt) * tt / 2;
        int a = nn, b = nn;

        for (int now = tt + 1; a > 0 && b > 0; ++now)
        {
            a -= now;
            if (a <= 0)
            {
                cout << "freesin" << endl;
                break;
            }
            b -= k;
            b -= now;
            if (b <= 0)
            {
                cout << "pllj" << endl;
                break;
            }
            a -= k;
        }
    }
}
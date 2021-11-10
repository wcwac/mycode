#include <bits/stdc++.h>
using namespace std;

int mygcd(int x, int y)
{
    return !x ? y : mygcd(y % x, x);
}

int main()
{
    int T;
    scanf("%d", &T);
    // cin >> T;
    while (T--)
    {
        int n;
        long long sum = 0;
        // cin >> n;
        scanf("%d", &n);
        int now;
        // cin >> now;
        scanf("%d", &now);
        sum += now;
        for (int i = 2; i <= n; ++i)
        {
            int x;
            // cin >> x;
            scanf("%d", &x);
            now = mygcd(now, x);
            sum += x;
        }
        cout << sum << " " << now << endl;
    }

    return 0;
}
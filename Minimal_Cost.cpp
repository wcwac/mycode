#include <bits/stdc++.h>
using namespace std;
int a[20010];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, v, u;
        cin >> n >> u >> v;
        int flag = 1, flag1 = 1;
        map<int, int> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ++q[i + a[i]];
            if (i > 1 && a[i] != a[i - 1])
                flag = 0;
            if (i > 1 && abs(a[i] - a[i - 1]) >= 2)
                flag1 = 0;
        }
        if (flag)
        {
            cout << min(v + v, v + u) << endl;
        }
        else
        {
            if (flag1)
            {
                cout << min(u, v) << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            // else
            // {
            //     int ans = 0;
            //     for (auto i : q)
            //     {
            //         if (i.second == i.first + 1 || i.second + i.first == 1000000 + n + 2)
            //         {
            //             ans += min(u, v);
            //         }
            //     }
            //     cout << ans << endl;
            // }
        }
    }

    return 0;
}
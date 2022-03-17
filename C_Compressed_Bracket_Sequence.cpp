#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    ll now = 0, ans = 0, last = 0;

    for (int i = 0; i < n; i += 2)
    {
        for (int j = i + 3; j < n; j += 2)
        {
            ll now = 0, high, mm = 0;
            int flag = 1;
            for (int k = i; k < j; ++k)
            {
                mm = max(mm, now);
                if (k & 1)
                {
                    now -= v[k];
                }
                else
                {
                    now += v[k];
                }
            }
            if (mm > now)
                continue;
            now -= min(now, v[j]);
            if (now)
                continue;
            // if (flag)
            // {
            //     printf("%d,%d\n", i, j);
            // }
            ans += flag;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            ans += min(v[i], now);
            now = now - v[i];
            if (now < 0)
            {
                last = 0;
                now = 0;
            }
        }
        else
        {
            now += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}
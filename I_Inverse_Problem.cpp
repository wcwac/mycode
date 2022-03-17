#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
const int p = 998244353;
int s[N], vis[N];
int inv[N], invfac[N];
signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    inv[1] = invfac[1] = invfac[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = 1ll * (p - (p / i)) * inv[p % i] % p;
        invfac[i] = 1ll * invfac[i - 1] * inv[i] % p;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> s[i];
        vis[s[i]] = 1;
    }
    if (!vis[1])
    {
        puts("0");
        return 0;
    }
    s[m + 1] = n;
    int now = 0, cnt = 0, ans = 1;
    for (int i = 1; i <= m + 1; ++i)
    {
        if (s[i] < now)
        {
            int tnow = 0;
            while (now < n)
            {
                ++now;
                if (!vis[now])
                {
                    ans = 1ll * ans * cnt % p;
                    ++cnt;
                    ++tnow;
                }
                else
                {
                    ++cnt;
                }
            }
            // ans = 1ll * ans * invfac[tnow] % p;
            break;
        }

        int tnow = 0;
        while (now < s[i])
        {
            ++now;
            if (!vis[now])
            {
                ans = 1ll * ans * cnt % p;
                ++cnt;
                ++tnow;
            }
            else
            {
                ++cnt;
            }
        }
        // ans = 1ll * ans * invfac[tnow] % p;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const ll maxn = 1e6 + 10;
ll read()
{
    ll x;
    scanf("%lld", &x);
    return x;
}
int _[maxn];
vector<ll> o[60];
void init()
{
    for (ll i = 1; i < maxn; ++i)
    {
        _[i] = _[i / 10] + i % 10;
        o[_[i]].push_back(i);
    }
}
signed main()
{
    // ll maxx = 1;
    init();
    for (int t = read(); t; t--)
    {
        ll A, B, C, D, N, ans = -1;
        A = read();
        B = read();
        C = read();
        D = read();
        N = read();
        {
            int x = 1;
            int i = 1;
            ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
        }
        for (int i = 1; i <= 54; i++)
        {
            ll a, b, d, x, line;
            a = A * i * i + B;
            b = C * i * i + D * i;
            if (a >= 0)
            {
                if (!a)
                {
                    line = b > 0 ? N + 1 : -1;
                }
                else if (a > 0)
                {
                    line = -b / 2 / a;
                }
                // cout << d << endl;
                int pos = lower_bound(o[i].begin(), o[i].end(), d) - o[i].begin();
                for (int j = max(0ll, pos - 10); j < min((int)o[i].size(), pos + 10); ++j)
                {
                    x = o[i][j];
                    if (x <= N && x >= 1)
                        ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
                }
            }
            else
            {
                x = o[i][0];
                if (x <= N && x >= 1)
                    ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
                int pos = lower_bound(o[i].begin(), o[i].end(), N) - o[i].begin();
                for (int j = max(0ll, pos - 10); j < min((int)o[i].size(), pos + 10); ++j)
                {
                    x = o[i][j];
                    if (x <= N && x >= 1)
                        ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
                }
            }
        }
        for (int x = 1; x <= 10 && x <= N; ++x)
        {
            int i = _[x];
            ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
        }
        for (int x = N; x >= N - 10 && x >= 1; --x)
        {
            int i = _[x];
            ans = min(ans, A * x * x * i + B * x * x + C * x * i * i + D * x * i);
        }
        printf("%lld\n", ans);
    }
}
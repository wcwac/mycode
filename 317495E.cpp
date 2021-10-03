#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int N = 1000 * 1010;
typedef long long ll;
struct NODE
{
    ll x, y, c;
} s[N];
ll XX[N], X[N], YY[N], Y[N];
ll f[N], F[N];
ll inv[N];
bool cmp(NODE a, NODE b)
{
    return a.c < b.c;
}
int n, m, e, a, b;
int main()
{

    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ++e;
            s[e].x = i;
            s[e].y = j;
            cin >> s[e].c;
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= e; ++i)
    {
        inv[i] = (long long)(P - P / i) * inv[P % i] % P;
    }
    cin >> a >> b;
    sort(s + 1, s + 1 + e, cmp);
    int last = 0;
    for (int i = 1; i <= e; ++i)
    {

        XX[i] = (XX[i - 1] + s[i].x * s[i].x) % P;
        X[i] = (X[i - 1] + s[i].x) % P;

        YY[i] = (YY[i - 1] + s[i].y * s[i].y) % P;
        Y[i] = (Y[i - 1] + s[i].y) % P;
        if (i > 1)
        {
            if (s[i].c == s[i - 1].c)
            {
                f[i] = ((F[last - 1] + XX[last - 1] - 2 * s[i].x * X[last - 1] % P + (last - 1) * s[i].x % P * s[i].x % P + YY[last - 1] - 2 * s[i].y * Y[last - 1] % P + (last - 1) * s[i].y % P * s[i].y % P) % P + P) % P * inv[last - 1] % P;
                F[i] = F[i - 1] + f[i];
            }
            else
            {
                f[i] = ((F[i - 1] + XX[i - 1] - 2 * s[i].x * X[i - 1] % P + (i - 1) * s[i].x % P * s[i].x % P + YY[i - 1] - 2 * s[i].y * Y[i - 1] % P + (i - 1) * s[i].y % P * s[i].y % P) % P + P) % P * inv[i - 1] % P;
                F[i] = (F[i - 1] + f[i]) % P;
                last = i;
            }
        }
        // printf("%lld %lld %lld %lld %lld %lld\n", XX[i], X[i], YY[i], Y[i], f[i], F[i]);

        if (s[i].x == a && s[i].y == b)
        {
            cout << f[i] << endl;
            return 0;
        }
    }
    return 0;
}
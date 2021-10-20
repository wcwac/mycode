#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500001;
int n, m;
ll c[maxn], a[maxn], b[maxn];
#define ans(x) t[x].ans
map<int, int> q[maxn << 2];
inline ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}
inline void build(int p, int l, int r)
{
    if (l == r)
    {
        int t = b[l];
        for (int i = 2; i * i <= t; ++i)
        {
            int cnt = 0;
            while (t % i == 0)
            {
                t /= i;
                ++cnt;
            }
            if (cnt)
                q[p][i] = cnt;
        }
        if (t)
            q[p][t] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    if (q[p << 1].size() < q[p << 1 | 1].size())
    {
        for (auto i : q[p << 1])
        {
            int t = min(i.second, q[p << 1 | 1][i.first]);
            if (t)
                q[p][i.first] = t;
        }
    }
    else
    {
        for (auto i : q[p << 1 | 1])
        {
            int t = min(i.second, q[p << 1][i.first]);
            if (t)
                q[p][i.first] = t;
        }
    }
}

inline void update(int p, int l, int r, int x, int t)
{
    if (l == r)
    {
        for (int i = 2; i * i <= t; ++i)
        {
            int cnt = 0;
            while (t % i == 0)
            {
                t /= i;
                ++cnt;
            }
            if (cnt)
                q[p][i] += cnt;
        }
        if (t)
            ++q[p][t];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(p << 1, l, mid, x, t);
    else
        update(p << 1 | 1, mid + 1, r, x, t);
    if (q[p << 1].size() < q[p << 1 | 1].size())
    {
        for (auto i : q[p << 1])
        {
            int t = min(i.second, q[p << 1 | 1][i.first]);
            if (t)
                q[p][i.first] = t;
        }
    }
    else
    {
        for (auto i : q[p << 1 | 1])
        {
            int t = min(i.second, q[p << 1][i.first]);
            if (t)
                q[p][i.first] = t;
        }
    }
}
const int P = 1e9 + 7;
int fpow(int x, int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = 1ll * ret * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        update(1, 1, n, x, y);
        int ans = 1;
        for (auto i : q[1])
        {
            ans = 1ll * ans * fpow(i.first, i.second);
        }
        printf("%d\n", ans);
    }
    return 0;
}
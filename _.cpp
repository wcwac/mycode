#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> piii;
map<piii, int> q;

ll gcd(ll a, ll b)
{
    return !a ? b : gcd(b % a, a);
}

bool dfs(pii a, pii b, int dep = 0)
{
    if (dep == 10)
        return 0;
    printf("%lld/%lld %lld/%lld\n", a.first, a.second, b.first, b.second);
    int &u = q[piii(a, b)];
    if (u != 0)
        return u == 1;
    if (a.first == a.second || b.first == b.second)
        return u = 1;
    u = -1;
    ll t1 = (ll)a.first * b.second + (ll)a.second * b.first;
    ll t2 = 2ll * a.second * b.second;
    ll t12 = gcd(t1, t2);
    ll t3 = 2ll * a.first * b.first;
    ll t13 = gcd(t1, t3);
    if (dfs(pii(t1 / t12, t2 / t12), pii(t3 / t13, t1 / t13), dep + 1))
        return u = 1;
    return 0;
}

int popcount(int x)
{
    int t = 0;
    while (x)
    {
        x -= (x & -x);
        ++t;
    }
    return x;
}

int main()
{
    // freopen("1.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        // if (a > b)
        //     swap(a, b);
        // if (dfs(pii(a, b), pii(b, a)))
        ll t = a + b;
        if (__builtin_popcount(t) == 1)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
}
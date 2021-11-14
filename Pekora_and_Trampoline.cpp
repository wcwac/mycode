#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010];
ll b[5010];
ll t[5010];
ll T, n, cnt;
ll lowbit(ll x) { return x & -x; }
void add(ll x, ll q)
{
    while (x <= n)
    {
        t[x] += q;
        x += lowbit(x);
    }
}
ll query(ll x)
{
    ll tot = 0;
    while (x >= 1)
    {
        tot += t[x];
        x -= lowbit(x);
    }
    return tot;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int flag = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            t[i] = 0;
            if (a[i] != 1)
                flag = 0;
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll tmp = query(i);
            cnt += max(0ll, a[i] - 1 - tmp);
            ll xx = max(0ll, tmp - a[i] + 1);
            if (xx > 0)
            {
                add(i + 1, xx);
                add(i + 2, -xx);
            }
            add(i + 2, 1);
            add(i + a[i] + 1, -1);
            // cout << query(i) << " ";
        }
        cout << cnt << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 998244353;
inline ll fpow(ll n, ll k)
{
    ll res = 1;
    n %= p;
    while (k)
    {
        if (k & 1)
            res = res * n % p;
        n = n * n % p;
        k >>= 1;
    }
    return res;
}

ll bsgs(ll a, ll b)
{
    unordered_map<int, int> Hash;
    a %= p;
    b %= p;
    if (b == 1)
        return 0;
    int k = sqrt(p) + 1;
    for (int i = 0, j = b % p; i < k; i++)
    {
        Hash[j] = i;
        j = (ll)j * a % p;
    }
    int ak = fpow(a, k);
    for (int x = 1, num = ak; x <= k; x++)
    {
        if (Hash.count(num))
            return x * k - Hash[num];
        num = (ll)num * ak % p;
    }
    return -1;
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    // freopen("1.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, x;
        cin >> n >> x;
        if (x == 1)
            cout << "0"
                 << "\n";
        else if (x == 0)
            cout << "1"
                 << "\n";
        else
        {
            ll ans1 = bsgs(n - 1, (n * x + n - 1) % p);
            ll ans2 = bsgs(n - 1, (n * x - n + 1) % p);
            if (ans1 != -1 && ans1 % 2 == 1)
            {
                if (ans2 != -1 && ans2 % 2 == 0)
                {
                    cout << min(ans1, ans2) << "\n";
                }
                else
                {
                    cout << ans1 << "\n";
                }
            }
            else
            {
                if (ans2 != -1 && ans2 % 2 == 0)
                {
                    cout << ans2 << "\n";
                }
                else
                {
                    cout << -1 << "\n";
                }
            }
        }
    }
    return 0;
}
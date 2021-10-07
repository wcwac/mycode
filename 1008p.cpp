#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll fac[1000004];
ll qk(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    ll ans = fac[n - m + 1] * fac[m] % mod;

    
    cout<<ans<<endl;
    //(n-i)!-1
    for (int i = 1; i < m; i++)
        ans = (ans + (fac[m] * qk(fac[m - i], mod - 2) % mod) % mod * (fac[n - m] - 1)) % mod;
    cout << ans;
}
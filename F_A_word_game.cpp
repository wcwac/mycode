#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 200005;
int prime[1100000], primesize;
bool isprime[11000000];
ll f[N], invf[N];
ll inv[N];
void getlist(int listsize)
{
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= listsize; i++)
    {
        if (isprime[i])
            prime[++primesize] = i;
        for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void extend_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extend_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
void ni(int n)
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
    }
}
ll fpow(ll a, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % mod;
        k >>= 1;
        a = a * a % mod;
        //cout<<1<<endl;
    }
    return res;
}
void init(int n)
{
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] * i % mod;
    }
    invf[n] = fpow(f[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }
}
ll C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * invf[k] % mod * invf[n - k] % mod;
}
ll sg[45];
int vis[45];
ll sgg()
{
    for (int i = 1; i <= 41; i++)
    {
        vis[0] = 1;
        if (i - 1 >= 0)
        {
            vis[sg[i - 1]] = 1;
        }
        if (i - 2 >= 0)
        {
            vis[sg[i - 2]] = 1;
        }
        for (int j = 0; j <= 41; j++)
        {
            if (!vis[j])
            {
                sg[i] = j;
                memset(vis, 0, sizeof(vis));
                break;
            }
        }
    }
}
ll cas[27];
void solve()
{
    string x;
    cin >> x;
    sgg();
    for (auto i : x)
    {
        //	cout<<i<<endl;
        cas[i - 'A']++;
    }
    ll ans = 0;
    for (int i = 0; i <= 26; i++)
    {
        if (cas[i])
        {
            //	cout<<sg[cas[i]]<<endl;
            ans ^= sg[cas[i]];
        }
    }
    if (!ans)
    {
        cout << "Bob" << endl;
    }
    else
    {
        cout << "Alice" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //	getlist(1e7);
    int t = 1;
    //	cin>>t;
    while (t--)
    {
        solve();
    }
}
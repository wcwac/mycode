#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
ll sd[N], sp[N], vis[N], prime[N], e;
ll G[N];
void init()
{
    sd[1] = 1;
    G[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime[++e] = i;
            sd[i] = sp[i] = i + 1;
        }
        for (int j = 1; j <= e && i < N / prime[j]; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                sp[i * prime[j]] = sp[i] * prime[j] + 1;
                sd[i * prime[j]] = sd[i] / sp[i] * sp[i * prime[j]];
                break;
            }
            sd[i * prime[j]] = sd[i] * sd[prime[j]];
            sp[i * prime[j]] = 1 + prime[j];
        }
        G[i] = G[i - 1] + sd[i];
    }
}

ll calcG(ll n)
{
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += 1ll * (l + r) * (r - l + 1) / 2 * (n / l);
    }
    return ans;
}

int main()
{
    // init();
    // ll ans = 0;
    //for (int i=1;i<=40;++i)
    //cout <<i<<":"<< G[i]<<"  "<<sd[i]<<"\n";
    // cout<<calcG(5)<<" "<<calcG(calcG(5));
    // cout << G[G[5]];
    int n;
    cin >> n;
    cout << calcG(calcG(n));
    return 0;
}
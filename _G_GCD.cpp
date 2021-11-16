#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
ll sd[N], sp[N], vis[N], prime[N], e;
void init()
{
    sd[1] = 1;
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
    }
}

ll ans;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; ++i)
    {
        int t = i / b;
        if (t < 1)
            continue;
        if (t == 1)
        {
            ans += b;
        }
        if (t > 1)
        {
            int l = b;
            int r = t * b;
            ans += 1ll * (l + r) * t / 2;
        }
        // cout<<ans<<endl;
    }
    cout << ans << endl;
    return 0;
}
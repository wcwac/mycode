#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, P = 998244353;
vector<int> eg[N];
int fa[N];
typedef long long ll;
int f[N];

ll fpow(ll base, ll power)
{
    ll result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = result * base % P;
        }
        power >>= 1;
        base = (base * base) % P;
    }
    return result;
}

// int dfs(int x)
// {
//     if (eg[x].empty())
//         return f[x] = 1;
//     f[x] = 1e9;
//     for (auto i : eg[x])
//         f[x] = min(f[x], dfs(i) + 1);
//     return f[x];
// }

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        fa[i] = x;
        eg[x].push_back(i);
    }
    // dfs(1);
    //bfs
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (eg[i].empty())
        {
            q.push(i);
            f[i] = 1;
        }
        else
        {
            f[i] = 1e9;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u != 1 && f[fa[u]] > f[u] + 1)
        {
            f[fa[u]] = f[u] + 1;
            q.push(fa[u]);
        }
        for (auto i : eg[u])
        {
            if (f[i] > f[u] + 1)
            {
                f[i] = f[u] + 1;
                q.push(i);
            }
        }
    }
    long long ans = 0, ansb = n;
    for (int i = 1; i <= n; ++i)
    {
        // printf("%d %d\n", i, f[i]);
        ans += f[i];
    }
    // cout << ans << " " << ansb << endl;
    long long c = __gcd(ans, ansb);
    ans /= c;
    ansb /= c;
    ans = ans * fpow(ansb, P - 2) % P;
    cout << ans;
    return 0;
}
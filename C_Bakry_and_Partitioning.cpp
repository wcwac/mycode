#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> eg[N];
int val[N], sum[N];

void dfs(int u, int fa)
{
    sum[u] = val[u];
    // cout << "dfs" << u << endl;
    for (auto v : eg[u])
    {
        if (v != fa)
        {
            dfs(v, u);
            sum[u] ^= sum[v];
        }
    }
}

int dfs1(int u, int fa)
{
    int cnt = 0;
    for (auto v : eg[u])
    {
        if (v != fa)
        {
            cnt += dfs1(v, u);
        }
        if (cnt >= 2 || (cnt == 1 && sum[u] == 0))
            return 100;
    }
    if (sum[u] == sum[1])
        cnt = 1;
    return cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            eg[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            cin >> val[i];
        }
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            eg[u].push_back(v);
            eg[v].push_back(u);
        }
        dfs(1, 0);
        // cout << sum[1] << " " << dfs1(1, 0) << endl;
        if (sum[1] == 0 || k > 2 && dfs1(1, 0) >= 2)
        {
            cout << "YES" << endl;
            ;
        }
        else
        {
            cout << "NO" << endl;
            ;
        }
    }
}
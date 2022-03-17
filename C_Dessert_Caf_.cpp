#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> eg[N];
int ret[N], flag[N];
unordered_set<int> q;
int dfs(int x, int fa)
{
    if (flag[x])
        ret[x] = 1;
    for (auto i : eg[x])
    {
        if (i.first != fa)
        {
            if (dfs(i.first, x))
            {
                ret[x] = 1;
            }
        }
    }
    return ret[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        eg[u].push_back(pii(v, d));
        eg[v].push_back(pii(u, d));
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        flag[x] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (flag[i])
        {
            dfs(i, 0);
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += ret[i];
    }
    cout << ans << endl;
}
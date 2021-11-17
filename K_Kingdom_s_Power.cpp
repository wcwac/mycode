#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int fa[N], val[N];
typedef long long ll;
vector<int> eg[N];
int nowdep = 0;
ll ans = 0;

int dfs1(int x)
{
    val[x] = 1;
    for (auto i : eg[x])
    {
        val[x] = max(val[x], dfs1(i) + 1);
    }
    return val[x];
}

bool cmp(int x, int y)
{
    return val[x] < val[y];
}

void dfs(int x, int dep)
{
    ans += dep - nowdep;
    nowdep = dep;
    sort(eg[x].begin(), eg[x].end(), cmp);
    for (auto i : eg[x])
    {
        ans += min(nowdep - dep, dep);
        nowdep = dep;
        dfs(i, dep + 1);
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            eg[i].clear();
        for (int i = 2; i <= n; ++i)
        {
            cin >> fa[i];
            eg[fa[i]].push_back(i);
        }
        dfs1(1);
        // for (int i = 1; i <= n; ++i)
        //     printf("%d:%d\n", i, val[i]);
        nowdep = ans = 0;
        dfs(1, 0);
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
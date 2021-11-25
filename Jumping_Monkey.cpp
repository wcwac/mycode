#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int fa[N], fa1[N], ans[N], a[N];
int ask(int x)
{
    return fa1[x] == x ? x : fa1[x] = ask(fa1[x]);
}

// int ask1(int x)
// {
//     return fa[x] == x ? x : fa[]ask()
// }

int n;
vector<int> eg[N], eg1[N];
typedef pair<int, int> pii;

void dfs(int x, int fa, int dep)
{
    ans[x] = dep;
    for (auto i : eg1[x])
    {
        if (i != fa)
        {
            dfs(i, x, dep + 1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            eg1[i].clear();
            eg[i].clear();
        }
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        vector<pii> v;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            fa[i] = fa1[i] = i;
            v.push_back(pii(a[i], i));
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < n; ++j)
        {
            int now = v[j].second;
            for (auto i : eg[now])
            {
                if (a[i] < a[now])
                {
                    int x = ask(i);
                    fa1[x] = now;
                    fa[x] = now;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (fa[i] != i)
                eg1[fa[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (fa[i] == i)
            {
                dfs(i, 0, 1);
                break;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << ans[i] << "\n";
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int age[N], fa[N][20];
vector<int> ch[N];
vector<int> p[N];
int depth[N], ans[N];
int n, m;
void dfs1(int x)
{
    for (auto i : ch[x])
    {
        if (i == fa[x][0])
            continue;
        depth[i] = depth[x] + 1;
        dfs1(i);
    }
}

int c[N];

void add(int x, int k)
{
    for (; x < N; x += -x & x)
        c[x] += k;
}

int ask(int x)
{
    int ans = 0;
    for (; x; x -= -x & x)
        ans += c[x];
    return ans;
}

void dfs2(int x)
{
    for (auto i : p[x])
        add(i, 1);
    ans[x] = ask(age[x]);
    for (auto i : ch[x])
        if (i != fa[x][0])
            dfs2(i);
    for (auto i : p[x])
        add(i, -1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> age[i] >> fa[i][0];
        ch[fa[i][0]].push_back(i);
    }
    depth[1] = 1;
    dfs1(1);
    for (int i = 1; i < 20; ++i)
    {
        for (int j = 0; j <= n; ++j)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    }

    for (int i = 1; i <= m; ++i)
    {
        int o, l, r;
        cin >> o >> l >> r;
        --ans[o];
        for (int j = 19; j >= 0; --j)
        {
            if (age[fa[o][j]] <= r)
                o = fa[o][j];
        }
        p[o].push_back(l);
    }
    dfs2(1);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << (i == n ? "\n" : " ");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 420, M = 20000, S = 411, T = 412;
int hd[N], to[M], nt[M], le[M], e = 1;

inline void add(int u, int v, int l)
{
    to[++e] = v, le[e] = l, nt[e] = hd[u], hd[u] = e;
    to[++e] = u, le[e] = 0, nt[e] = hd[v], hd[v] = e;
}

int ans;

int n, m;
int dep[N], cur[N];

bool bfs()
{
    queue<int> q;
    while (!q.empty())
        q.pop();
    memset(dep, 0, sizeof dep);
    dep[S] = 1;
    q.push(S);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = hd[u]; i; i = nt[i])
        {
            int v = to[i];

            if (!dep[v] && le[i])
            {
                dep[v] = dep[u] + 1;

                if (v == T)
                    return 1;
                else
                    q.push(v);
            }
        }
    }

    return 0;
}

int dfs(int x, int f)
{
    if (x == T)
        return f;

    if (dep[x] >= dep[T])
        return 0;

    int used = 0;

    for (int &i = cur[x]; i; i = nt[i])
    {
        if (!le[i] || dep[to[i]] != dep[x] + 1)
            continue;

        int w = dfs(to[i], min(f - used, le[i]));
        used += w, le[i] -= w, le[i ^ 1] += w;

        if (f == used)
            return used;
    }

    return used;
}

void dfs2(int x, int ignore)
{
    for (int i = hd[x]; i; i = nt[i])
    {
        if ((i & 1) == 1 && le[i] == 1)
        {
            if (to[i] != S)
                dfs2(to[i] - n, 0);
            if (ignore)
                puts("");
            else
                printf("%d ", x);
        }
    }
}

typedef pair<int, int> pii;

int main()
{
    scanf("%d", &n);
    vector<pii> v(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i].first == 0)
            add(S, i, 1);
        add(i, n + i, 1);
        for (int j = 1; j <= n; ++j)
        {
            if (v[i].second < v[j].second && v[i].second >= v[j].first)
            {
                add(n + i, j, 1);
            }
        }
    }
    scanf("%d", &m);
    for (int i = n + n + 1; i <= n + n + m; ++i)
    {
        int h;
        scanf("%d", &h);
        add(i, T, 1);
        for (int j = 1; j <= n; ++j)
        {
            if (v[j].second >= h)
                add(n + j, i, 1);
        }
    }

    while (bfs())
    {
        for (int i = 1; i <= n + n + m; ++i)
            cur[i] = hd[i];

        cur[S] = hd[S];
        cur[T] = hd[T];

        while (int d = dfs(S, 1e9))
            ans += d;
    }

    if (ans != m)
    {
        puts("impossible");
        return 0;
    }

    for (int i = n + n + 1; i <= n + n + m; ++i)
    {
        dfs2(i, 1);
    }
    return 0;
}

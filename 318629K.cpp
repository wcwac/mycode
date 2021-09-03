#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, x, a, y, b, cnt, hd[N], to[N << 1], nxt[N << 1], tot, c[N], top, s[N], num, dfn[N], low[N];
void add(int x, int y)
{
    to[++cnt] = y, nxt[cnt] = hd[x], hd[x] = cnt;
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++num, s[++top] = x;
    for (int i = hd[x]; i; i = nxt[i])
    {
        int y = to[i];
        if (!dfn[y])
            tarjan(y), low[x] = min(low[x], low[y]);
        else if (!c[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x])
    {
        c[x] = ++tot;
        while (s[top] != x)
            c[s[top--]] = tot;
        --top;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int id[3][2];
        for (int j = 0; j < 3; ++j)
        {
            int y;
            string x;
            cin >> y >> x;
            if (x == "R")
                id[j][0] = y, id[j][1] = y + n;
            else
                id[j][1] = y, id[j][0] = y + n;
        }
        add(id[0][0], id[1][1]);
        add(id[0][0], id[2][1]);
        add(id[1][0], id[0][1]);
        add(id[1][0], id[2][1]);
        add(id[2][0], id[0][1]);
        add(id[2][0], id[1][1]);
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (c[i] == c[i + n])
            return puts("-1"), 0;
    for (int i = 1; i <= n; i++)
        printf("%c", (c[i] < c[i + n]) ? 'B' : 'R');
}
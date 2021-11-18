#include <bits/stdc++.h>
using namespace std;
int n, tx, ty, tv, a[5][200010], sum[5];
int head[200010], tot;
int vis[200010];
long double c[5][200010];
struct edge
{
    long double y, v, next;
} e[400010];
void add(int x, int y, int v)
{
    tot++;
    e[tot].y = y;
    e[tot].v = v;
    e[tot].next = head[x];
    head[x] = tot;
}
double ans;
void dfs(ll x)
{
    vis[x] = 1;
    for (ll i = head[x]; i; i = e[i].next)
    {
        if (vis[e[i].y])
            continue;
        ll y = e[i].y;
        dfs(y);

        c[1][x] += c[1][e[i].y];
        c[2][x] += c[2][e[i].y];
        c[3][x] += c[3][e[i].y];
        ans += e[i].v * 1ll * (c[1][y] * (sum[3] * (sum[2] - c[2][y]) + sum[2] * (sum[3] - c[3][y])) + c[2][y] * (sum[3] * (sum[1] - c[1][y]) + sum[1] * (sum[3] - c[3][y])) + c[3][y] * (sum[2] * (sum[1] - c[1][y]) + sum[1] * (sum[2] - c[2][y])));
    }
}

int main()
{
    // n = read();
    cin>>n;
    for (ll i = 1; i < n; i++)
    {
        cin>>tx>>ty>>tv;
        // tx = read();
        // ty = read();
        // tv = read();
        add(tx, ty, tv);
        add(ty, tx, tv);
    }
    for (int i = 1; i <= 3; i++)
    {
        cin>>sum[i];
        // sum[i] = read();
        for (int j = 1; j <= sum[i]; j++)
        {
            a[i][j] = read();
            c[i][a[i][j]]++;
        }
    }

    dfs(1);
    printf("%.16f", ans / 2.0 / sum[1] / sum[2] / sum[3]);
}
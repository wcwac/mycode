#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
struct E
{
    int u, v, w;
} e[5 * N];
bool cmp(E a, E b)
{
    return a.w < b.w;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    // freopen("1.in", "r", stdin);
    int _;
    scanf("%d", &_);
    while (_--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }
        if (n == k)
        {
            printf("0\n");
            continue;
        }
        sort(e, e + m, cmp);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        int now = n, ans = 1e9;
        for (int i = 0; i < m;)
        {
            do
            {
                ans = e[i].w;
                if (find(e[i].u) != find(e[i].v))
                {
                    fa[find(e[i].u)] = find(e[i].v);
                    --now;
                }
            } while (++i < m && e[i].w == ans);
            if (now <= k)
            {
                break;
            }
        }
        printf("%d\n", (now == k) ? ans : -1);
    }

    return 0;
}
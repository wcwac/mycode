#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
struct Q
{
    int id, l, r, u, d;
} q[N];

int cnt[N], sum[330];
const int k = 313;
void init()
{
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
}
void insert(int x)
{
    if (++cnt[x] == 1)
        ++sum[x / k];
}
void remove(int x)
{
    if (--cnt[x] == 0)
        --sum[x / k];
}

int calc(int u)
{
    int ret = 0, i;
    for (i = 0; (i + 1) * k - 1 < u; ++i)
        ret += sum[i];
    for (i = i * k; i <= u; ++i)
        ret += (cnt[i] > 0);
    return ret;
}

int ans[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        int block = sqrt(n);
        for (int i = 0; i < m; ++i)
        {
            q[i].id = i;
            scanf("%d%d%d%d", &q[i].l, &q[i].d, &q[i].r, &q[i].u);
        }
        sort(q, q + n,
             [block](Q a, Q b)
             {
                 if (a.l / block == b.l / block)
                 {
                     return (bool)(((a.l / block) & 1) ^ (a.r > b.r));
                 }
                 else
                 {
                     return a.l < b.l;
                 }
             });
        init();
        int l = 1, r = 0;
        for (int i = 0; i < m; ++i)
        {
            while (r < q[i].r)
                insert(a[++r]);
            while (l > q[i].l)
                insert(a[--l]);
            while (r > q[i].r)
                remove(a[r--]);
            while (l < q[i].l)
                remove(a[l++]);
            ans[q[i].id] = calc(q[i].u) - calc(q[i].d - 1);
        }
        for (int i = 0; i < m; ++i)
            printf("%d\n", ans[i]);
    }

    return 0;
}
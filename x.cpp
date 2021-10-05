#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N << 2];
void build(int x, int l, int r)
{
    if (l == r)
    {
        cin >> a[l];
        s[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) | 1, mid + 1, r);
    s[x] = max(s[x << 1], s[(x << 1) | 1]);
}
int query(int x, int l, int r, int ll, int rr)
{
    if (ll <= l && rr >= r)
        return s[x];
    int mid = (l + r) >> 1, ret = -1;
    if (ll <= mid)
        ret = max(ret, query(x << 1, l, mid, ll, rr));
    if (rr > mid)
        ret = max(ret, query((x << 1) | 1, mid + 1, r, ll, rr));
    return ret;
}
void update(int x, int l, int r, int p, int k)
{
    if (l == r)
    {
        s[x] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
        update(x << 1, l, mid, p, k);
    else
        update((x << 1) | 1, mid + 1, r, p, k);
    s[x] = max(s[x << 1], s[(x << 1) | 1]);
}
int n, m;
int main()
{
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (!op)
        {
            long long l, r, k;
            cin >> l >> r >> k;
            int u = query(1, 1, n, l, r);
            if (u < k)
                puts("-1");
            else
                printf("%d\n", min(u - k, 100000ll));
        }
        else
        {
            int p, k;
            cin >> p >> k;
            update(1, 1, n, p, k);
        }
    }
    return 0;
}
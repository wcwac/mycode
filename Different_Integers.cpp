#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct query
{
    int l, r, id, ans;
} Q[N];
int a[N];
int cnt[N], now;
void insert(int x)
{
    if (++cnt[x] == 1)
        ++now;
}

void remove(int x)
{
    if (--cnt[x] == 0)
        --now;
}

int n, m, K;

bool cmp1(query x, query y)
{
    if (x.l / K == y.l / K)
    {
        if ((x.l / K) & 1)
        {
            return x.r > y.r;
        }
        else
        {
            return x.r < y.r;
        }
    }
    else
    {
        return x.l < y.l;
    }
}
bool cmp2(query x, query y)
{
    return x.id < y.id;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (cin >> n >> m)
    {
        now = 0;
        K = sqrt(n);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            cnt[i] = 0;
        }

        for (int i = 1; i <= m; ++i)
        {
            Q[i].id = i;
            cin >> Q[i].l >> Q[i].r;
        }
        sort(Q + 1, Q + 1 + m, cmp1);
        for (int i = 1; i <= n; ++i)
            insert(a[i]);
        int l = 1, r = 2, ansa = now;
        for (int i = 1; i <= m; ++i)
        {
            if (Q[i].r <= Q[i].l)
            {
                Q[i].ans = ansa;
            }
            while (r > Q[i].r)
                insert(a[r--]);
            while (l < Q[i].l)
                insert(a[l++]);
            while (r < Q[i].r)
                remove(a[r++]);
            while (l > Q[i].l)
                remove(a[l--]);
            Q[i].ans = now;
            // Q[i].ans = now;
            // cout << Q[i].l
            //      << " " << Q[i].r
            //      << " " << now << endl;
        }
        sort(Q + 1, Q + 1 + m, cmp2);
        for (int i = 1; i <= m; ++i)
        {
            cout << Q[i].ans << "\n";
        }
    }

    return 0;
}

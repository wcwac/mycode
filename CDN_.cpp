#include <bits/stdc++.h>
using namespace std;
const int N = 110;
inline int gint()
{
    int x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c))
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}
int s[N], l[N], now[N];
typedef pair<int, int> pii;
int main()
{
    // freopen("1.in", "r", stdin);
    int T = gint();
    while (T--)
    {
        int n = gint();
        int m = gint();
        long long ans = 0;
        priority_queue<pii> q;
        for (int i = 1; i <= n; ++i)
        {
            s[i] = gint();
            now[i] = 1;
            ans += s[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            l[i] = gint();
            if (l[i] != 1)
                q.push(pii(s[i] - s[i] / 2 - s[i] % 2, i));
        }
        while (!q.empty() && q.top().first != 0 && m != 0)
        {
            ans -= q.top().first;
            int u = q.top().second;
            q.pop();
            ++now[u];
            --m;
            if (now[u] != l[u])
                q.push(pii(s[u] / now[u] + (s[u] % now[u] != 0) - s[u] / (now[u] + 1) - (s[u] % (now[u] + 1) != 0), u));
        }
        priority_queue<pii, vector<pii>, greater<pii>> p;
        for (int i = 1; i <= n; ++i)
        {
            if (now[i] == l[i])
                continue;
            int t = s[i] / now[i];
            if (s[i] % now[i] == 0)
                --t;
            if (t != 0)
            {
                int need = s[i] / t;
                if (s[i] % need)
                    ++need;
                p.push(pii(need - now[i], i));
            }
        }
        while (!p.empty() && p.top().first <= m)
        {
            ans -= 1;
            m -= p.top().first;
            int u = p.top().second;
            now[u] += p.top().first;
            p.pop();
            if (now[u] != l[u])
            {
                int t = s[u] / now[u];
                if (s[u] % now[u] == 0)
                    --t;
                if (t != 0)
                {
                    int need = s[u] / t;
                    if (s[u] % need)
                        ++need;
                    p.push(pii(need - now[u], u));
                }
            }
        }
        printf("%d\n", ans);
    }
}
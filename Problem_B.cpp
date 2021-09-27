#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;

inline int gint()
{
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
    {
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x;
}

int q[2010];
int now, offset;
inline void init(int x)
{
    ++now;
    offset = x;
}

inline bool insert(int x)
{
    if (x > offset + 1000 || x < offset - 1000)
        return 0;
    if (q[x - offset + 1005] == now)
        return 0;
    q[x - offset + 1005] = now;
    return 1;
}

int s[N];
int ans[1010];

int main()
{
    puts("Case #1:");
    register int n, m;
    n = gint();
    m = gint();
    for (register int i = 1; i <= n; ++i)
    {
        s[i] = gint();
    }
    for (register int i = 1; i <= n; ++i)
    {
        register int mn, mx;
        mn = mx = s[i];
        init(s[i]);
        insert(s[i]);
        register int u = min(999, n - i);
        for (register int j = 1; j <= u; ++j)
        {
            if (insert(s[i + j]))
            {
                if (s[i + j] < mn)
                    mn = s[i + j];
                if (s[i + j] > mx)
                    mx = s[i + j];
                if (mx - mn == j)
                    ++ans[j];
            }
            else
            {
                break;
            }
        }
    }
    while (m--)
    {
        register int k = gint();
        printf("%d\n", k == 1 ? n : ans[k - 1]);
    }
}
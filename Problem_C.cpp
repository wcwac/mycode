#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5 + 10;
int a[N];

bool check(int n, int d)
{
    int now = a[1] - d;
    for (int i = 2; i <= n; ++i)
    {
        ++now;
        if (a[i] < now - d)
            return 0;
        if (a[i] > now + d)
            now = a[i] - d;
    }
    return 1;
}

int main()
{
    int T = gint();
    for (int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:\n", cas);
        int n = gint();
        for (int i = 1; i <= n; ++i)
            a[i] = gint();
        int l = 0, r = 1e6, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(n, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
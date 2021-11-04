#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 100;

char s[maxN + 1];
int n, m, p, sa[maxN + 1], rk[maxN + 1];
int bin[maxN + 1], tp[maxN + 1];
int height[maxN + 1];

inline void Qsort()
{
    for (int i = 0; i <= m; i++)
        bin[i] = 0;
    for (int i = 1; i <= n; i++)
        bin[rk[i]]++;
    for (int i = 1; i <= m; i++)
        bin[i] += bin[i - 1];
    for (int i = n; i >= 1; i--)
        sa[bin[rk[tp[i]]]--] = tp[i];
}

inline void work()
{
    m = 300;
    for (int i = 1; i <= n; i++)
        tp[i] = i, rk[i] = s[i];
    Qsort();
    for (int w = 1; p < n; m = p, w <<= 1LL)
    {
        p = 0;
        for (int i = n - w + 1; i <= n; i++)
            tp[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] - w > 0)
                tp[++p] = sa[i] - w;
        Qsort();
        memcpy(tp, rk, sizeof(rk));
        rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
            rk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p;
    }
}

inline void solve()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k)
            k--;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k])
            k++;
        height[rk[i]] = k;
    }
}

#undef int
int main()
#define int long long
{
    scanf("%lld %s", &n, s + 1);
    work();
    solve();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n - sa[i] + 1 - height[i];
    printf("%lld", ans);
    return 0;
}
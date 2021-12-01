#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N], sz[N];
long long sum = 0, cnt;
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
long long gcd(long long a, long long b)
{
    return !a ? b : gcd(b % a, a);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i, sz[i] = 1;
    sum = cnt = n;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d%d", &x, &y);
            int a = find(x), b = find(y);
            if (a != b)
            {
                sum -= sz[a] * sz[a] + sz[b] * sz[b];
                sz[a] += b;
                fa[b] = a;
                sum += sz[a] * sz[a];
                --cnt;
            }
        }
        else
        {
            long long t = gcd(sum, cnt);
            printf("%lld/%lld\n", sum / t, cnt / t);
        }
    }
}
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
inline int f(int now)
{
    return a[now];
}

vector<int> v[10];

void dfs(int now, int i, int cnti, int cnt)
{
    if (i > 7)
        return;
    if (now > 1e7)
        return;
    v[cnt].push_back(now);
    dfs(now * f(i), i, cnti + 1, cnt + (cnti == 0));
    dfs(now, i + 1, 0, cnt);
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.ans", "w", stdout);
    dfs(1, 0, 0, 0);
    for (int i = 0; i <= 8; ++i)
    {
        v[i].push_back(0);
        v[i].push_back(1e9);
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    for (int i=0;i<9;++i)
    printf("%d\n",v[i].size());
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long L, R, K;
        scanf("%lld%lld%lld", &L, &R, &K);
        if (K > 8)
        {
            printf("0\n");
            continue;
        }
        auto l = lower_bound(v[K].begin(), v[K].end(), L);
        auto r = lower_bound(v[K].begin(), v[K].end(), R + 1);
        printf("%d\n", r - l);
    }
    return 0;
}
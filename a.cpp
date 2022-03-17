#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7;
const int M = 3200;
int t, l, r, cnt;
ll k;
int f[2 * N], prime[2 * M], ans[20][2 * N];
bool judge(int x)
{
    for (int i = 2; i <= sqrt(x) + 0.5; ++i)

        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    clock_t start = clock();
    for (int i = 2; i < M; ++i)

        if (judge(i))
            prime[++cnt] = i;
    f[1] = 1, ans[0][1] = 1;
    for (int i = 2; i <= N; ++i)
    {

        int p = i;

        for (int j = 1; j <= cnt && prime[j] <= p; ++j)

            if (p % prime[j] == 0)
            {

                f[i]++;

                while (p % prime[j] == 0)
                    p /= prime[j];
            }

        if (p != 1)
            f[i]++;

        for (int j = 0; j <= 8; ++j)
        {

            if (j == f[i])
                ans[j][i] = ans[j][i - 1] + 1;

            else
                ans[j][i] = ans[j][i - 1];
        }
    }
    scanf("%d", &t);
    while (t--)
    {

        scanf("%d%d%lld", &l, &r, &k);

        if (k > 8)
            printf("0\n");

        else
            printf("%d\n", ans[k][r] - ans[k][l - 1]);
    }
    clock_t end = clock();
    cerr << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    return 0;
}
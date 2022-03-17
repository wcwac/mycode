#include <iostream>
using namespace std;
int point[25][2];
typedef long long ll;
ll cal(ll n, ll m)
{
    return n * (n + 1) / 2 * m * (m + 1) / 2;
}

int popcount(int x)
{
    int cnt = 0;
    while (x)
    {
        ++cnt;
        x -= (x & (-x));
    }
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; ++i)
            scanf("%d%d", &point[i][0], &point[i][1]);
        ll sum = cal(n, m);
        for (int i = 1; i < (1 << k); ++i)
        {
            int u = n, d = 1, l = m, r = 1;
            ll flag = 1;
            for (int j = 0; j < k; ++j)
            {
                if ((i >> j) & 1)
                {
                    u = min(u, point[j][0]);
                    l = min(l, point[j][1]);
                    d = max(d, point[j][0]);
                    r = max(r, point[j][1]);
                }
            }

            if (popcount(i) & 1)
            {
                sum -= 1ll * u * l * (n - d + 1) * (m - r + 1);
            }
            else
            {
                sum += 1ll * u * l * (n - d + 1) * (m - r + 1);
            }
        }
        cout << sum << endl;
    }
    return 0;
}